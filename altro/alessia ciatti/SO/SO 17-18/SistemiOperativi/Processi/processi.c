#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char **argv) {
	int N = atoi(argv[1]);
	char c;

	if (N < 0 || N > 10)
		return 0;
	
	pid_t pid[N];
	int i;
	int status;

	for(i = 0; i < N; i++) {
		pid[i] = fork();

		if (pid[i] < 0) {
			perror("fork");
			exit(0);
		}

		if (pid[i] == 0) {
			scanf("%c", &c);

			if (c == 'y') {
				printf("Processo %d attivato.\n", getpid());
				exit(1);
			}
			else if (c == 'n') {
				printf("Processo %d non attivato.\n", getpid());
				exit(1);
			}
		}
		else {
			printf("Creato processo figlio: %d\n", getpid());
			printf("Attivare il processo %d? [y/n]\n", getpid());
			wait(&status);
		}
	}
}