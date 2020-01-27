#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef char stringa[20];

int main(int argc, char **arg) {
	pid_t pid;

	stringa comandi[20];
	int n, i, k;

	printf("Comandi da eseguire: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Comando da esguire: ");
		scanf("%s", comandi[i]);
	}

	printf("\n");
	int status;

	for (i = 0; i < n; i++) {
		pid = fork();

		if (pid < 0) {
			perror("fork");
			exit(2);
		}

		if (pid == 0) {
			system(comandi[i]);
			exit(0);
		}
		else {
			pid = wait(&status);
		}
	}

	exit(0);
}