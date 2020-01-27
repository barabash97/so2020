/* SCRIVERE gerarchia_comandi.c PER IL CONTROLLO DI PROCESSI:
		- IL PROCESSO INIZIALE P0 DEVE ACQUISIRE DA INPUT UNA 
		  SEQUENZA DI "N" COMANDI, CON "N" DATO DA INPUT (MAX 20)
		- UNA VOLTA LETTI GLI "N" COMANDI, P0 DEVE DARE ORIGINE 
		  AD UNA GERARCHIA LINEARE DI PROCESSI DI PROFONDITÀ N+1
		  (FIGLIO P1, NIPOTE P2, BISNIPOTE P3, ..., PN+1):
		  		- OGNI PROCESSO DELLA GERARCHIA DOVRÀ ESEGUIRE UN
		  		  DIVERSO COMANDO DELLA SEQUENZA DATA (SI STAMPI
		  		  SU OUTPUT INFORMAZIONI RIGUARDO IL PID E IL NOME
		  		  DEL COMANDO CHE SI STA PER ESEGUIRE)
		  		- L'ULTIMO PROCESSO DELLA GERARCHIA, INVECE, DOVRÀ
		  		  SEMPLICEMENTE STAMPARE IL SUO PID E TERMINARE 
		  		  (exit status 0)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIM 20

typedef char stringa [80];
typedef stringa strvett[DIM];

int gestoreSequenza(int N, strvett vett);
void get_stato(int S, int pid);

int main() {

	int pid, ncom, stato, i;
	strvett vstr;
	printf("Quanti comandi?\n");
	scanf("%d", &ncom);

	for(i=0; i<ncom; i++) {

		printf("\nDammi il prossimo comando\n");
		scanf("%s", vstr[i]);
	}
	gestoreSequenza(ncom-1, vstr);
	pid = wait(&stato);
	get_stato(stato, pid);
	exit(0);
}

void get_stato(int S, int pid) {
	printf("\nTerminato processo n.%d", pid);
	if(S==0) 
		printf("\nTerminazione volontaria con stato %d\n", S);
	else
		printf("\nTerminazione involontaria per segnale%d\n", S);
}

int gestoreSequenza(int N, strvett vett) {

	int stato, pid;

	pid = fork();

	if(pid<0) {
		perror("fork");
		exit(2);
	}

	if(pid==0) {
		if(N==-1) { //PROCESSO FOGLIA
			printf("\nfoglia %d \n", getpid());
			exit(0);
		}

		else  //ATTIVAZIONE DI UN NUOVO COMANDO
			pid=gestoreSequenza(N-1, vett);
	}//FINE ELSE FIGLIO

	else {
		if(N!=-1) {
			printf("\nProcesso %d per comando %s", pid, vett[N]);
			pid = wait(&stato);
			get_stato(stato, pid);

			if(execlp(vett[N], vett[N], (char*)0)<0) {
				perror("exec");
				exit(-1);
			}
			exit(0);
		}
	}
}
