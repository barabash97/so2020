/* SCRIVERE sequenza_comandi.c IN CUI UN PROGRAMMA PADRE CONTROLLA
   UNA SEQUENZA DI PROCESSI FIGLIO:
   		- IL PROCESSO PADRE(P0) DEVE ACQUISIRE DA INPUT UNA SEQUENZA
   		  DI "N" COMANDI (PER SEMPLICITÀ, SENZA ARGOMENTI E SENZA 
   		  OPZIONI), CON "N" DATO DA INPUT("N" AL MASSIMO È 20)
   		- UNA VOLTA LETTI GLI "N" COMANDI, P0 DEVE DARE ORIGINE AD UNA
   		  SEQUENZA LINEARE DI "N" PROCESSI FIGLIO(FIGLIO P1, FIGLIO P2,
   		  ..., FIGLIO PN+1):
   		  		- OGNI PROCESSO FIGLIO DOVRÀ ESEGUIRE UN DIVERSO COMANDO
   		  		  DELLA SEQUENZA DATRA E POI TERMINARE (exit status 0)
   		  		- IL PROCESSO PADRE DEVE ATTENDERE LA FINE DELL'ESECUZIONE
   		  		  DI UN PROCESSO FIGLIO PER GENERARE IL SUCCESSIVO
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIM 20

typedef char stringa[80];
typedef stringa strvett[DIM];

int gestoreSequenza(int N, strvett vett);

int main() {

	int pid, ncom, stato, i;

	strvett vstr;

	printf("quanti comandi?\n");
	scanf("%d", &ncom);

	for(i=0; i<ncom; i++) {

		printf("\ndammi il prossimo comando (SENZA ARGOMENTI)\n");
		scanf("%s", vstr[i]);
	}

	gestoreSequenza(ncom, vstr);
	exit(0);
}

int gestoreSequenza(int N, strvett vett) {

	int stato;
	int pid, i;

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
			pid=wait(&stato);
		}
	}
}