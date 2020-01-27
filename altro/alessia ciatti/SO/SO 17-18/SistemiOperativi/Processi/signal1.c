#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void handlerCtrlC() {
	printf("\nTerminated\n");
	exit(0);
}
int main (int argc, char **argv) {

	signal(SIGINT, handlerCtrlC);
	while(1) {
		printf("Hello World\n");
		sleep(1);
	}

	return 0;
}