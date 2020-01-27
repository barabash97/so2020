/* Cattura i segnali definiti dall'utente e stampa un messaggio di errore.
 Per cui:
 - l'idea è che un utente invochi determinati segnali da terminale. -
 - A questo punto Il processo in esecuzione catturerà questi segnali e farà capire all'utente di aver compreso quali segnali egli 
 stia invocando tramite una stampa */


// INIZIO INTESTAZIONE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Definizione del prototipo dell'handler sig_usr. Più avanti c'è la sua implementazione
static void sig_usr(int);

// FINE INTESTAZIONE

int main(void){

	/* Ci sono queste due tipologie di segnali, che si chiamano SIGUSR1 e SIGUSR2. Questi sono 2 tipologie di segnali
	che sono proprio invocati dall'utente e sono solo all'ppaggio. 
	La funzione signal(SIGUSR1,sig_usr) utilizza l'handler sig_usr e serve a catturare SIGUSR1. Quando questo segnale SIGUSR1
	viene catturato, si attiva l'handler sig_usr
	Se l'utente dovesse invocare o SIGUSR1 o SIGUSR2, sig_usr sarà l'handler incaricato di gestirli.*/

	// Se l'invocazione del segnale SIGUSR1 restituisce un errore
	if(signal(SIGUSR1,sig_usr) == SIG_ERR){

			// Stampa dell'errore tramite la perror
			perror("can't catch SIGUSR1");

	}// end if 

	// Se l'invocazione del segnale SIGUSR2 restituisce un errore
	if(signal(SIGUSR2,sig_usr) == SIG_ERR){

			// Stampa dell'errore tramite la perror
			perror("can't catch SIGUSR1");

	}// end if 

	
	// Si crea un ciclo infinito e si mette in pausa il processo che invoca questa esecuzione. Lui starà in attesa all'infinito
	for(;;){

		pause();

	}// end for 

}// end main

/* Questa è l'implementazione dell'handler sig_usr. Questo handler, indipendentemente che sia il SIGUSR1 o SIGUSR2, si va solo a 
stampare il messaggio che si è ricevuto uno o l'altro segnale */
static void sig_usr(int signo){
	
	// Se il segnale ricevuto è uguale a SIGUSR1
	if(signo == SIGUSR1){
		
		// Stampa messaggio di ricezione di SIGUSR1
		printf("received SIGUSR1\n");

	}// end if

	//Altrimenti, o il segnale ricevuto è SIGUSR2 oppure c'è un errore
	else{
		
		//Se il segnale ricevuto è uguale a SIGUSR2
		if(signo == SIGUSR2) {

			// Stampa messaggio di ricezione di SIGUSR2
			printf("received SIGUSR2\n");

		}// end if

		//Altrimenti, c'è un errore
		else{

			// Stampa del messaggio che si è ricevuto
			printf("received signal %d\n",signo);

			// Si invoca la abort, per dire che c'è stata un terminazione anomala
			abort();

			// Termina l'esecuzione del processo corrente
			exit(1);

		}// end else

	}//end else 

	return;

}// end sig_usr 


