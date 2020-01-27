// INIZIO INTESTAZIONE

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// FINE INTESTAZIONE

int main (void){

	// Si definisce questa struttura per poter salvare il vecchio handler associato a SIG_INT
	void (*oldHandler) (int);

	// Stampa in cui si dice di poter controllare il CTRL-c
	printf("I can be Control-C'ed\n");

	// Il processo, si mette a dormire per 3 secondi
	sleep(3);

	/* A questo punto, viene invocata la funzione signal sul segnale SIGINT. Ora, l'handler che stiamo richiamando non è
	una funzione realizzata da noi, bensì quella di default che è SIG_IGN. Dunque, stiamo dicendo al processo "Tranquillo, ignora".
	Che cosa ritorna da questa funzione? Ritorna l'handler precedente, ovvero quello che si faceva in precedenza quando veniva
	catturato il segnale SIGINT. Il risultato ritornato da questa funzione viene messo nel puntatotore oldHandler */
	oldHandler = signal(SIGINT,SIG_IGN);

	/*Stampa in cui si si dice che da adesso in poi CTRL-c è protetto. Per cui, anche premenedo CTRL-C, esso verrà ignorato
	per via del fatto che abbiamo definito, con la funzione signal, che esso (SIGINT) vada catturato dall'handler (SIG_IGN) ed ignorato */
	printf("I'm protected from Control-C now\n");

	// Il processo, si mette a dormire per 3 secondi
	sleep(3);

	/* Passati i 3 secondi, si invoca la funzione signal e si ripristina il vecchio handler (memorizzato in oldHandler, ovvero l'handler 
	precedente alla chiamata signal (SIGINT,SIG_IGN) in cui indicavamo di ignorare questo CTRL-C */
	signal (SIGINT,oldHandler);
	printf("I can be Control-c'ed again\n");
	sleep(3);
	printf("Bye!\n");

}// end main


