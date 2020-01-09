#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	pid_t my_pid, pid_fork_return, child_pid;
	int status;

	pid_fork_return = fork();
	if (pid_fork_return > 0) {	// Parent process
		my_pid = getpid();
		/* A call to wait() blocks the calling process until one of its child processes exits or a signal is received. */
		child_pid = wait(&status);
		printf("Wait status is %d\n", status);
		printf("Parent process pid is %d, child process pid is %d\n", my_pid, child_pid);
	}
	else if (pid_fork_return == 0) {	// Child process
		my_pid = getpid();
		printf("Child process pid is %d\n", my_pid);
		printf("Child finished.\n");
	}
	else {
		printf("Fork failed!\n");
		exit(1);
	}
}
