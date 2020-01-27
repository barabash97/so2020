#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
	int pid;
	int status;
	int i;

	for(i = 1; i <= 10; i++) {
		pid = fork();

		if(pid < 0) {
			perror("fork");
		}

		if (pid == 0) {
			sleep(1);
			printf("Sono il processo figlio numero #%d\n", i);
			sleep(1);
			exit(100 + i);
		}
		else {
			printf("Ho generato il figlio numero %d con pid = %d\n", i, pid);
		}
	}

	for (i = 1; i <= 10; i++) {
		int status;
		wait(&status);
		printf("Figlio terminato con codice %d\n", WEXITSTATUS(status));
	}

}