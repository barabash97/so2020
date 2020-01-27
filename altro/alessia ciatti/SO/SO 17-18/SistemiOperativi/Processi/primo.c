#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) {
	pid_t pid;

	pid = fork();

	if (pid < 0) {
		perror("fork");
		exit(2);
	}

	if (pid == 0) {
		printf("Sono il processo figlio! ESKERE\n");
		exit(0);
	}
	else {
		printf("Sono il processo padre! TOPKEK\n");
		exit(0);
	}
}