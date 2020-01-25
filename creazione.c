#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX 10
void signalHandler(int sig){
	if(SIGUSR1 == sig){
		printf("PROCESSO ATTIVATO %d \n", getpid());
	} else {
		printf("processo non attivato %d \n", getpid());
	}
	exit(0);
}

int main(int argc, char * argv[]){
	int N,i;
	int pid[MAX];
	int status;
	char c;
	if(argv[1] == NULL){
		printf("sintassi errata\n");
		exit(0);
	}

	N = atoi(argv[1]);

	for(i = 0; i < N; i++){

		pid[i] = fork();

		if(pid[i] < 0){
			perror("Errore pid\n");
			exit(0);
		}

		if(pid[i] == 0){
				signal(SIGUSR1, signalHandler);
				signal(SIGUSR2, signalHandler);
				pause();
		} else {
			
			printf("Creato processo figlio %d\n", pid[i]);
			printf("Vuoi attivare il processo figlio y/Y?\n");
			c = getchar();

			if(c == 'y' || c=='Y'){
				kill(pid[i], SIGUSR1);
			} else {
				kill(pid[i], SIGUSR2);
			}

			c = getchar();

			wait(&status);
		}

	}

}