// INIZIO INTESTAZIONE

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// FINE INTESTAZIONE

/* Questa funzione gestisce la maschera di un processo, che stamperà la maschera dei segnali che sta gestendo un certo processo*/
void pr_mask(){

	// Si crea un set di segnali
	sigset_t sigset;

	// Si crea una variabile int
	int errno_save;

	// Si assegna alla variabile errno_save quello che sarà l'identificatore del segnale di errore
	errno_save = errno;

	/* Quesllo che si fa è invocare la funzione sigprocmask. Essa viene inizializzata passando il set di segnali sigset
	 che all'inizio è vuoto */

	// Se il valore di ritono di questa funzione è minore di 0 
	if(sigprocmask(0,NULL,&sigset) < 0){

		// Stampa messaggio di errore tramite la perror
		perror("sigprocmask error");

	}// end if 

	/* Ora, si invoca la funzione sigismember che verifica se all'interno di un certo set di segnali (sigset nel nostro caso) esistano
	certi segnali (SIGINT e SIGQUIT nel nostro caso). Per cui, nel nostro caso, si vuole verificare che qualcuno abbia invocato:
	- CTRL-C (associato al segnale con nome simbolico SIGINT)
	- CTRL-\ (associato a segnale con nome simbolico SIGQUIT)
	Stiamo cercando di capire quindi se, nella maschera del processo che è in esecuzione vi siano questi due segnali SIGINT e SIGQUIT.
	Il processo quindi, strarà gestendo contemporaneamente, il segnale SIGINT e il segnale SIGQUIT*/

	// Se il segnale SIGINT è contenuto nel set di segnali sigset
	if(sigismember(&sigset,SIGINT)){

		// Stampa della presenza del segnale SIGINT all'interno del set di segnali sigset
		printf("SIGINT");

	}// end if 


	// Se il segnale SIGQUIT (CTRL-/ invoca l'uscita dal terminale) è contenuto nel set di segnali sigset
	if(sigismember(&sigset,SIGQUIT)){

		// Stampa della presenza del segnale SIGQUIT all'interno del set di segnali sigset
		printf("SIGQUIT");

	}// end if 

	// Stampa a capo
	printf("\n");
	errno = errno_save;

}// end pr_mask