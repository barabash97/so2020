// INIZIO INTESTAZIONE

#include <signal.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

//FINE INTESTAZIONE

// Questo handler stampa il messaggio di terminazione
void handle_sigint(int sig){

	// Stampa il messaggio di terminazione e termina l'esecuzione
	printf("\nTerminated\n");
	exit(0);

}// end handle_sigint

int main(void){

	/* Si invoca la funzione signal per catturare il segnale SIGINT (CTRL-c), la quale attiverà handle_signint una volta
	generato il segnale */
	signal(SIGINT, handle_sigint);

	// Si crea un ciclo infinito per poter eseguire la sequenza stampa-sleep all'infinito
	while(1){

		// Stampa, aspetta un secondo, stampa, aspetta un secondo, ecc.
		printf("hello world\n");
		sleep(1);
		// Quando verrà premuto CTRL+C, verrà generato il segnale SIGINT e si attiverà la funzione handle_sigint

	}// end while

}// end main 

