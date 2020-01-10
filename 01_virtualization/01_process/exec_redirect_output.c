#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
	pid_t my_pid, pid_fork_return, child_pid;

	pid_fork_return = fork();
	if (pid_fork_return > 0) {	// Parent process
		my_pid = getpid();
		/* A call to wait() blocks the calling process until one of its child processes exits or a signal is received. */
		child_pid = wait(NULL);
		printf("Parent process pid is %d, child process pid is %d\n", my_pid, child_pid);
	}
	else if (pid_fork_return == 0) {	// Child process
		my_pid = getpid();
		printf("Child process pid is %d\n", my_pid);

		/* Use exec to run a different program */
		// redirect standard output to a file
		close(STDOUT_FILENO);
		/* UNIX systems start looking for free file descriptors at zero. STDOUT FILENO will be the first available one and thus get assigned when open() is called. */
		open("./exec_redirect_output.output.out", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);	// read man 2 open

		char *my_args[3];
		my_args[0] = "wc";	// program: "wc" (word count)
		my_args[1] = "exec.c";	// argument: file to count
		my_args[2] = NULL;	// marks end of array
		execvp(my_args[0], my_args);	// runs word count
		/* a successful call to exec() never returns. */
		printf("This line shouldn't be printed.\n");
	}
	else {
		fprintf(stderr, "Fork failed!\n");
		exit(1);
	}
}
