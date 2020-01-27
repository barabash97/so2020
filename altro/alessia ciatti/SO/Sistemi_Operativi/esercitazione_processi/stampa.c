/* -SCRIVERE stampa.c, UN PROGRAMMA PER IL CONTROLLO DEI PROCESSI IN CUI
	UN PROCESSO PADRE GENERA UN PROCESSO FIGLIO:
		-IL PROCESSO PADRE, SENZA ASPETTARE LA CONCLUSIONE DEL PROCESSO 
		 FIGLIO STAMPERÀ SU OUTPUT IL MESSAGGIO "sono il processo padre"
		 (exit status 0)

		-IL PROCESSO FIGLIO STAMPERÀ SU OUTPUT IL MESSAGGIO "sono il 
		 processo figlio" E POI USCIRÀ DAL PROGRAMMA (exit status 0)

		-NEL CASO DI ERRORE(NELLA CREAZIONE DEL PROCESSO FIGLIO) CATTURARE
		 L'ERRORE STAMPANDO UN MESSAGGIO DI ERRORE (SI UTILIZZA perror)
		 E POI USCIRE DAL PROGRAMMA (exit status 2) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

	pid_t pid;
	pid = fork();

	if(pid<0) {
		perror("fork");
		exit(2);
	}

	if(pid==0) {
		printf("Sono il processo figlio\n");
		exit(0);
	}

	else {

		printf("Sono il processo padre\n");
		exit(0);
	}
}

