#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void handler() {

	printf("\nno ciao\n");
	exit(0);
}

int main() {

	signal(SIGINT, handler);

	while(1) {

		printf("ciao\n");
		sleep(1);
	}

	return 0;

}