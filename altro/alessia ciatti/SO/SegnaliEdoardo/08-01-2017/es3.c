// INIZIO INTESTAZIONE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// FINE INTESTAZIONE

// Handler che cattura il segnale 
void INThandler(int sig){

	// si crea uan variabile char
	char c;
	
	/* Si utilizza la funzione signal ed il segnale sig, passato come parametro, dovrà essere ignorato da SIG_IGN
	Il fatto che si faccia CTRL-c la prima volta infatti, dovrà essere ignorato. 
	Se non fosse ignorato, interromperebbe l'esecuzione. Una volta che è stato ignorato, subito dopo verrà fatta la stampa*/
	signal(sig, SIG_IGN);

	// Stampa il messaggio in cui chiede se, dopo la prima volta che si è premuto CTRL-c, ci si fosse sbagliati
	printf("\n Forse hai premuto per sbaglio Ctrl-C?\n Vuoi realmente sospendere l'esecuzione? [y/n]\n");

	// La funzione getchar() prende il carattere digitato dall'utente come risposta alla domanda
	c = getchar();

	// Se il carattere c è uguale a 'y' o uguale a 'y'
	if(c == 'y' || c == 'Y'){

		// Termina l'esecuzione
		exit(0);

	}// end if 

	/* Altrimenti, viene ripristinato quella che è la cattura del segnale. Per cui, CTRL-C non deve essere
	più ignorato bensì, nel caso in cui venga richiamato SIGINT bisognare richiamare il vecchio handler INThandler */
	else{

		/* Si invoca la  funzione signal che catturerà il segnale SIGINT. Quando sarà generato il segnale, verrà attivato
		 INThandler */
		signal(SIGINT, INThandler);

	} // end else 

}// end INThandler

int main(void){

	/* Si invoca la funzione signal per catturare il segnale SIGINT (CTRL-c), la quale attiverà INThandler una volta
	generato il segnale */
	signal(SIGINT, INThandler);
	
	// Si crea un ciclo infinito dove viene messo in pausa il sistema
	while(1){

		pause();

	}// end while

}// end main 