#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	pid_t parent_pid, my_pid, pid_fork_return;
	int i = 0;

	parent_pid = getpid();
	printf("Parent pid is %d\n", parent_pid);
	
	pid_fork_return = fork();
	/* fork() returns 0 to the child process and returns the process ID of the child process to the parent process. Otherwise, -1 is returned to the parent process, no child process is created, and errno is set to indicate the error. */
	if (pid_fork_return > 0) {	// Parent process
		my_pid = getpid();
		/* my_pid is the same as parent_pid */
		printf("Parent process pid is %d, child process pid is %d\n", my_pid, pid_fork_return);

		while (i < 3)
			printf("i of parent is now %d\n", i++);
	}
	else if (pid_fork_return == 0) {	// Child process
		my_pid = getpid();
		printf("Child process pid is %d\n", my_pid);

		while (i > -3)
			printf("i of child is now %d\n", i--);
		/* Child gets a complete copy of parent, so now i is different variable in child and parent, they won't mess with each other */
	}
	else {
		printf("Fork failed!\n");
		exit(1);
	}
}
