#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_callback_handler(int sig_num) {
	printf("Caught signal %d.\n", sig_num);
	exit(1);
}

int main() {
	signal(SIGINT, signal_callback_handler);

	while(1) {}
}
