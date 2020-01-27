#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIM 20

typedef char string[80];
typedef string strvett[DIM];

int gestoreSequenza(int N, strvett vett);

int main(int argc, char const *argv[]){
	int pid, ncom, stato, i;

	strvett vstr;

	printf("quanti comand?\n");
	scanf("%d", &ncom);

	for(i=0; i<ncom; i++) {
		printf("\nDammi il prossimo comando SENZA ARGOMENTI!\n");
		scanf("%s", vstr[i]);
	}

	gestoreSequenza(ncom, vstr);
	exit(0);
}

int gestoreSequenza(int N, strvett vett) {
	int stato, pid, i;

	for(i=0; i<N; i++) {
		printf("Comando %s con indice %d\n", vett[i], i);
		pid = fork();

		if(pid<0) {
			perror("fork");
			exit(2);
		}

		if(pid==0) {
			system(vett[i]);
			exit(0);
		}

		else {
			pid = wait(&stato);
		}
	}
}