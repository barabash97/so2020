#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX 10

void gestore_att(int signal) {
	if(signal==SIGUSR1)
		printf("Processo attivato: %d\n", getpid());
	else
		printf("Processo non attivato: %d\n", getpid());
	exit(0);
}

int main(int argc, char* argv[]) {
	int pid[MAX], pf;
	int i, status;
	char request;

	int N = atoi(argv[1]);
	if(argc == 1) {
		printf("sintassi sbagliata!\n");
		exit(1);
	}

	for(i = 0; i < N; i++) {
		pid[i] = fork();
		if(pid[i] == 0) {
			signal(SIGUSR1, gestore_att);
			signal(SIGUSR2, gestore_att);
			pause();
		}

		else {
			printf("Cercato processo figlio: %d\n", pid[i]);

			printf("Attivare il processo %d? [y/n]", pid[i]);

			request = getchar();  //serve ad andare a capo quando premi invio

			pf = wait(&status);
		}
	}

	exit(0);
}