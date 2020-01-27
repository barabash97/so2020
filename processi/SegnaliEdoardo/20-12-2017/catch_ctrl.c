// Questo programma altro non fa che catturare il segnale di CTRL-c, che è associato al nome  simbolico SIGINT

// INIZIO INTESTAZIONE

#include <signal.h> // Libreria 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// FINE INTESTAZIONE


/* Questo handler gestisce il segnale SIGINT. Come  lavora? Quando si andrà a digitare sulla tastiera la combinazione CTRL-c (questo è l'evento che attivà il segnale SIGINT)
ci sarà una stampata. Cosa sta avvenendo? Stiamo "neutralizzando" l'effetto del CTRL-c, ovvero non sarà chiuso
il processo ma, ogni volta che verrà digitato CTRL-c (anche tutto il giorno), automaticamente verrà visualizzato sullo schermo il messaggio
"Don't do that (non farlo)"*/
void catch_int(int sig_num){

	// Stampa il messaggio di non farlo 
	printf("\n Don't do that \n");

	// QUesta funzione serve a pulire lo standard che viene passato come parametro
	fflush(stdout);

}// end catch_int


int main(void){

	/* Tramite la funzione signal si sta invocando il segnale SIGINT con handler catch_int (l'implementazione di questo handler
	si trova proprio all'interno di questo codice).Per cui, tramite l'invocazione della funzione signal, stiamo dicendo al 
	processo in esecuzione cosa debba fare una volta invocato SIGINT */
	signal(SIGINT,catch_int);

	/* Si crea un ciclo for dove non è stato messo nessun tipo di parametro o indice. Dunque, si sta facendo
	un ciclo infinito, dove all'interno c'è la funzione pause(). Per cui, una volta che è stato invocato il precedente segnale, il processo
	viene messo in pausa per un tempo infinito. Per cui, all'infinito, avremo il terminale in attesa e, premendo CTRL-c compare la scritta
	 */
	for(;;){

		pause();

	}// end for

}// end main

/* Riassumendo quindi:

 - 1) Con la funzione "signal(SIGINT,catch_int)", altro non facciamo che invocare un'interruzione dove viene esplicitato che tipo di interruzione (
 nel nostro caso SIGINT, associato alla pressione da tastiera di CTRL-c) ed eventualmente bisogna anche dire come reagire a questa 
 interruzione (nel nostro caso, verrà invocato l'handler catch_int che gestirà questa interruzione)

 - 2) Solitamente, dove c'è un handler definito dall'utente (catch_int nel nostro xaso), l'implementazione o si trova nello stesso 
 programmao si deve trovare in un libreria iesterna (ed avremo quindi un ulteriore include, dove si importa la libreria contenente
 l'implementazion e dell'handler)