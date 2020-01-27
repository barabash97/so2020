/* In questo codice, sincronizzando i processi, obbligheremo a stampare prima il padre e poi il figlio. Infatti, senza meccanismi di sincronizzazione
ci sarebbe la race condition e non saremmo in grado di dire quale dei due processi potrebbe stampare prima. 
Le funzioni TELL_WAIT(), WAIT_PARENT e TELL_CHILD sono nel file tellwait.c*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "tellwait.c"
#include <unistd.h>

int main(void){

	TELL_WAIT();

	// Si genera un processo figlio
	pid = fork();

	// Se il pid < 0, c'è stato un errore
	if(pid<0){

		// Stampa del messaggio tramite err_sys, uan funzione che altro non fa che richiamare la perror
		err_sys("fork error");

	}// end if 

	// Altrimento, o è attivo il processo padre o è attivo il proceso figlio
	else 
		// Se pid = 0, è attivo il processo figlio
		if(pid==0){// Sono il processo figlio

			/* Il processo figlio invoca la funzione WAIT_PARENT(). Per cui il figlio, prima di poter stampare,
			dovrà aspettare un segnale dal processo padre*/
			WAIT_PARENT();

			/* Dopo che il processo padre avrà mandato un segnale al processo figlio, il processo figlio potrà stampare 
			il suo messaggio */

			// Stampa il messaggio dell'output del figlio
			printf("output from child \n");
 
		 }// end if 

		// Altrimenti, è attivo il processo padre
		else{// Sono il processo padre 

			/* Il processo padre, prima stampa il suo messaggio e poi, invocando la funzione TELL_CHILD, invia un segnale
			al processo figlio affinché esso possa procedere */

			// Stampa il messaggio dell'output del figlio
			printf("output from parent \n");
			TELL_CHILD(pid);

		}// end else 

}// end main

