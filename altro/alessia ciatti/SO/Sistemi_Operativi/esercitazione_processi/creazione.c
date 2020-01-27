#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define max 10

void gestore_att(int sig) {
	if(sig==SIGUSR1)
		printf("Processoo attivato: %d\n", getpid());
	else
		printf("Processo non attivato: %d\n", getpid());
	exit(0);
}

int main(int argc, char* argv[]) {
	int pid[max], pf;
	int i, status;
	char request;

	int N = atoi(argv[1]);
	if(argc==1){
		printf("sintassi sbagliata!\n");
		exit(1);
	}

	for(i=0; i<N; i++) {
		pid[i] = fork();
		if(pid[i]==0) {
			signal(SIGUSR1, gestore_att);
			signal(SIGUSR2, gestore_att);
			pause();
		}
		else {
			printf("Creato processo figlio: %d\n", pid[i]);

			printf("Attivare il processo %d [y/n]: ", pid[i]);

			request=getchar();

			if((request=='Y')||(request=='y'))
				kill(pid[i], SIGUSR1);
			else
				kill(pid[i], SIGUSR2);

			request=getchar(); //serve ad andare a capo quando premi invio

			pf=wait(&status);
		}
	}

	exit(0);
}
