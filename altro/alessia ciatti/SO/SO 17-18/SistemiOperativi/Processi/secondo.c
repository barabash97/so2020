#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) {
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0) {
		perror("fork");
		exit(2);
	}

	if (pid == 0) {
		printf("Sono il processo figlio con ID = %d\nMio padre ha ID = %d\n", getpid(), getppid());
		exit(24);
	}
	else {
		printf("Sono il processo padre, attendo che mio figlio abbia finito..\n");
		pid = wait(&status);
		printf("Mio figlio ha finito con ID = %d e stato = %d\n", pid, status/256);
		exit(0);
	}
}