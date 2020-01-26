#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAX 10

int main(int argc, char * argv[]){

	int pid[MAX];
	int status;
	printf("\n\n\n\n");
	for(int i = 1; i < argc && i < MAX; i++){
		pid[i] = fork();

		if(pid[i] < 0){
			perror("Errore creazione processo\n");
			exit(0);
		}

		if(pid[i] == 0){
			int targa = atoi(argv[i]);

			if(targa > 0 && targa <= 90){
				printf("Codice valido associato %d : %d.\n", getpid(), targa);
			}

			exit(0); 
		} else {
			wait(&status);
			printf("%d : creato figlio %d\n", getpid(), pid[i]);

			
		}
	}

}