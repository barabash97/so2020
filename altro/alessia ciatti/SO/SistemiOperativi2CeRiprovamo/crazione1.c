#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX 10

void gestore_att(int sig) {
	if(sig==SIGUSR1)
		printf("Processo attivato: %d\n", getpid());
	else
		printf("Processo non attivato: %d\n", getpid());
	exit(0);
}

int main(int argc, char* argv[]) {
	int pid[MAX], pf, i, status;
	char request;

	int N = atoi(argv[1]);
	if(argc==1) {
		printf("Sintassi sbagliata!\n");
		exit(1);
	}

	for(i=0; i<N; i++) {
		pid[i] = fork();
		if(pid[i] == 0) {
			signal(SIGUSR1, gestore_att);
			signal(SIGUSR2, gestore_att);
			pause();
		}
		else {
			printf("Creato processo figlio: %d\n", pid[i]);
			printf("Attivare processo %d? [y/n]\n", pid[i]);

			request = getchar();

			if(request=='y' || request=='Y')
				kill(pid[i], SIGUSR1);
			else
				kill(pid[i], SIGUSR2);

			request = getchar();  //RICORDATELO PER DIOOOOOOOO

			pf = wait(&status);
		}
	}

	exit(0);
}
