#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>



void handerProcesso(int sig){
	char c;
	int processo;
	int numero;

	processo = getpid();
	printf("Vuoi davvero uscire chiudere process %d [y/n]?\n", processo);
	scanf("%d", &numero);
	if(numero == processo){
		printf("bye bye.\n");
		exit(0);
	}
}

int main(int argc, char * argv[]){

	int N, status, i;
	char c;

	if(argv[1] == NULL){
		printf("Sintassi sbagliata!\n");
		exit(0);
	}
 N = atoi(argv[1]);
 	i = 0;
	
	while(i < N){
		if(signal(SIGINT, handerProcesso)){
			i++;
			pause();
		}
	}

	printf("Finito numero di cicli.\n");
	return 0;
}