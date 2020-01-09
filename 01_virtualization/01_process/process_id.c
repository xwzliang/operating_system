#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t my_pid = getpid();	// Get current process id
	printf("My pid is %d\n", my_pid);
}
