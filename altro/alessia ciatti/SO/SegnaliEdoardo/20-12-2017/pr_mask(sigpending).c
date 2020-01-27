// INIZIO INTESTAZIONE

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// FINE INTESTAZIONE

/* Questa funzione gestisce i segnali pendenti*/
void pr_mask(){

	// Si crea un set di segnali
	sigset_t sigset;

	// Si crea una variabile int
	int errno_save;

	// Si assegna alla variabile errno_save quello che sarà l'identificatore del segnale di errore
	errno_save = errno;

	/*Si invoca funzione sigpending. Essa viene inizializzata passando il set di segnali sigset
	 che all'inizio è vuoto */

	// Se il valore di ritono di questa funzione è minore di 0 
	if(sigpending(&sigset) < 0){

		// Stampa messaggio di errore tramite la perror
		perror("sigprocmask error");

	}// end if 

	/* Ora, si invoca la funzione sigismember che verifica se all'interno di un set segnali pendenti (sigset nel nostro caso) esistano
	certi segnali (SIGINT e SIGQUIT nel nostro caso).T*/

	// Se il segnale SIGINT è contenuto nel set di segnali pendenti sigset
	if(sigismember(&sigset,SIGINT)){

		// Stampa della presenza del segnale SIGINT all'interno del set di segnali pendenti sigset
		printf("SIGINT");

	}// end if 


	// Se il segnale SIGTQUIT è contenuto nel set di segnali pendenti sigset
	if(sigismember(&sigset,SIGQUIT)){

		// Stampa della presenza del segnale SIGINT all'interno del set di segnali pendenti sigset
		printf("SIGQUIT");

	}// end if 


	// Stampa a capo
	printf("\n");
	errno = errno_save;

}// end pr_mask