/* SCRIVERE attesa.c PER IL CONTROLLO DEI PROCESSI IN CUI UN PROCESSO
   PADRE GENERA UN PROCESSO FIGLIO:
   		-IL PROCESSO PADRE ATTENDE LA TERMINAZIONE DEI COMPITI ASSEGNATI
   		 AL PROCESSO FIGLIO(STAMPANDO IN OUTPUT UN MESSAGGIO) E POI 
   		 STAMPA IN OUTPUT IL "PID" DEL FIGLIO CHE HA TERMINATO E IL 
   		 CODICE DI RITORNO

   		-IL PROCESSO FIGLIO STAMPA A STANDAR OUTPUT IL PROPRIO "PID" E 
   		 IL "PID DEL PADRE" E POI TERMINA (exit status 24)

   		-NEL CASO DI ERRORE (NELLA CREAZIONE DEL PROCESSO FIGLIO) CATTURARE
   		 L'ERRORE STAMPANDO UN MESSAGGIO DI ERRORE (SI UTILIZZI perror) E 
   		 POI USCIRE DAL PROGRAMMA (exit status 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	pid_t pid;

	int status;

	pid = fork();

	if(pid<0) {

		perror("fork");
		exit(2);
	}

	if(pid==0) {

		printf("[figlio] Il mio PID è %d e quello del processo che mi ha invocato è %d\n", getpid(), getppid());
		
		exit(24);
	}

	else {
		// segue il codice eseguito dal processo padre

		printf("[padre] In attesa della terminazione del processo figlio...\n");

		//si attende che il processo figlio termini la computazione

		pid = wait(&status);

		//OK: si sblocca il padre perchè il figlio ha terminato

		printf("[padre] Il figlio, con PID %d, ha terminato il lavoro con il seguente codice di ritorno: %d\n", pid, status/256);

	}
		
}