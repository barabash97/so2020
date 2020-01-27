/* SCRIVERE dieci_figli.c  PERI IL CONTROLLO DEI PROCESSI IN CUI UN 
   UN PROCESSO PADRE GENERI DIECI PROCESSI FIGLI ED ATTENDA IL LORO
   TERMINE:
   		-IL PROCESSO PADRE STAMPERÀ IL CODICE DI TERMINAZIONE PER
   		 OGNI PROCESSO FIGLIO CHE TERMINA

   		-OGNI PROCESSO GENERATO, CHE SVOLGE IL COMPITO DEL PROCESSO
   		 FIGLIO SARÀ NUMERATO DA 1 A 10; DOPO UNA BREVE ATTESA(UN 
   		 SECONDO) OGNI FIGLIO STAMPERÀ UN MESSAGGIO DI PRESENTAZIONE
   		 CONTENENTE L'INDICE DEL FIGLIO ("Figlio:#indice"). A SEGUIRE
   		 DI NUOVO UN SECONDO DI ATTESA E POI IL PROCESSO FIGLIO
   		 TERMINERÀ DANDO COME CODICE DI TERMINAZIONE 100 + L'INDICE

   		-NEL CASO DI ERRORE (NELLA CREAZIONE DEL PROCESSO FIGLIO)
   		 CATTURARE L'ERRORE (perror)  E POI USCIRE DAL PROGRAMMA
   		 (exit status 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUMP 10 //NUMERO DI FIGLI DA GENERARE

int main() {

	int i, pid;

	//genera 10 processi
	for(i=0; i<NUMP; i++) {

		pid = fork();

		if(pid<0) {
			perror("fork");
			exit(2);
		}

		if(pid==0) {  //figlio

			sleep(1);  //PER FARE UN RITARDO BREVE IN MANIERA SEMPLICE
					   //SI USA LA FUNZIONE "sleep()"
			printf("Figlio:%d\n", i+1); //stampa messaggio del figlio
			sleep(1); //ritardo finale
			exit(101+i); //termina con codice di ritorno
		}

		else { // padre (IL PID È QUELLO DEL FIGLIO)

			printf("Ho generato il figlio %d con pid %d\n", i+1, pid);

		}
	}//fine del for

	//Attende che dieci processi terminino

	for(i=0; i<NUMP; i++) {

		int status;
		wait(&status);  //Attende il termine di un figlio(uno qualunque)
		printf("Terminato processo %d\n", WEXITSTATUS(status)); //PER CONOSCERE
																//IL CODICE DI TERMINAZIONE
																//USIAMO LA MACRO(WEXITSTATUS(status))

	}

} // fine main