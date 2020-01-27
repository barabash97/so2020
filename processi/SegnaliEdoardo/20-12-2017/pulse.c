// INIZIO INTESTAZIONE

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// FINE INTESTAZIONE

int main(void){

	// si creano due variabili pid
	int pid1;
	int pid2;

	// Si genera il primo processo figlio
	pid1= fork();

	// Se pid1 = 0, è attivo il primo processo figlio
	if(pid1 == 0){

		// Si crea un ciclo for infinito dove il secondo processo figlio stampa e si mette a dormire di continuo
		while(1){

			// Stampa il messaggio nel quale il primo processo figlio dice di essere attivo
			printf("pid1 is alive");

			// Il primo processo figlio si mette a dormire per 1 secondi
			sleep(1);

		}//end while
	
	}// end if pid == 1
	
	// Si genera il primo processo figlio
	pid2= fork();

	// Se pid2 = 0, è attivo il secondo processo figlio
	if(pid2 == 0){

		// Si crea un ciclo for infinito dove il secondo processo figlio stampa e si mette a dormire di continuo
		while(1){

			// Stampa il messaggio nel quale il secondo processo figlio dice di essere attivo
			printf("pid2 is alive");

			// Il secondo processo figlio si mette a dormire per 1 secondi
			sleep(1);

		}//end while
	
	}// end if pid2 == 0

	// Il processo padre si mette a dormire 2 secondi
	sleep(2);

	/* Quando si risveglia, il processo padre invoca la funzione kill. La funzione kill invia il segnale SIGSTOP (che è il segnale
	che fa sospendere il processo al quale viene spedito tale segnale) al primo processo figlio, quello con pid1 */
	kill(pid1, SIGSTOP);

	// Dopo aver sospeso il primo processo figlio, il processo padre si mette a dormire 2 secondi
	sleep(2);

	/* Quando si risveglia, il processo padre invoca la funzione kill. La funzione kill invia il segnale SIGCONTINUE (che è il segnale
	che fa riattivare il processo (sospeso in precedenza), al quale viene inviato tale segnale al primo 
	processo figlio, quello con pid1 */
	kill(pid1, SIGCONT);

	// Dopo aver riattivato il primo processo figlio, il processo padre si mette a dormire 2 secondi
	sleep(2);

	/* Quando si risveglia, il processo padre invoca la funzione kill. La funzione kill invia il segnale SIGINT (che è il segnale
	che simula il CTRL-c, ovvero termina completamente l'esecuzione) al primo processo figlio (pid1) e al secondo (pid2) */
	kill(pid1, SIGINT);
	kill(pid2, SIGINT);

	// Il processo padre ritornerà 0 e finirà l'esecuzione del programma
	return 0;

}// end main