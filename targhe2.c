#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 10
int main(int argc, char *argv[]){
	
	int N;
	int pid[MAX];
	int targa;
	int status;
	int processo;
	if(argc == 1){
		printf("Errore sintassi\n");
		exit(0);
	}

	for(int i = 0; i < argc; i++){

		pid[i] = fork();

		if(pid[i]<0){
			perror("Errore PID");
			exit(0);
		}

		if(pid[i] == 0){
			 targa = atoi(argv[i]);
			 if(targa >= 1 && targa <= 90){
			 	printf("Codice valido associato al processo %d : %d\n", getpid(), targa);
			 } 
			 exit(0);
		} else {
			wait(&status);
			printf("%d: creato figlio %d\n", getpid(), pid[i]);
			
		}

	}

}