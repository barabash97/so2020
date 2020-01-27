#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// si definisce una costante max che vale 10, che è proprio il numero
// di processi figli che possono essere generati
#define max 10

// Questo è un handler che serve a catturare i vari segnali che può
// inviare il processo
void gestore_att(int sig) {
	// SIGUSR1 rappresenta il fatto che il processo padre voglia
	// attivare il processo figlio

	// se il segnale inviato è SIGUSR1
	if(sig == SIGUSR1)
		// stampa del messaggio che il processo figlio è stato attivato
		printf("Processo attivato: %d\n", getpid());

	// SIGUSR2 rappresenta il fatto che il processo padre NON voglia
	// attivare il processo figlio
	else 
		printf("Processo non attivato: %d\n", getpid());
	exit(0);
}

int main(int argc, char* argv[]) {
	int pid[max], pf, i, status, N;
	char request;

	// la funzione atoi prende l'argomento 1(argv[1] che è la stringa
	// che rappresenta il numero di processi figli da creare)
	N = atoi(argv[1]);

	// se c'è solo un argomento in input (che corrisponde ad argv[0]
	// ovvero al nome dell'eseguibule del file), viol dire che non è
	// stato specificato il numero di processi figli da creare
	if(argc == 1) {
		printf("Sintassi sbagliata!\n");
		exit(1);
	}

	// si crea un ciclo for che genera un numero di processi figli 
	// che va da 0 a N, ovvero il numero specificato da input
	for(i=0; i<N; i++) {

		// si genrea l'i-esimo processo figlio
		pid[i] = fork();

		// se il pid[i]==0, è attivo l'i-esimo figlio
		if(pid[i] == 0) {
			// l'i-esimo processo figlio invoca la funzione signal
			// attivando il monitoraggio dei segnali SIGUSR1 e SIGUSR2
			// quando uno dei due segnali verrà generato, si attiverà
			// l'handler gestore_att.
			// dopodichè, l'i-esimo processo figlio si mette in pausa
			// per poter ricevere il segnale del processo padre che gli 
			// dica che possa essere attivato o meno
			signal(SIGUSR1, gestore_att);
			signal(SIGUSR2, gestore_att);
			pause();
		}
		else {
			// altrimenti, è attivo il processo padre
			printf("Creato processo figlio: %d\n", pid[i]);

			//stampa la domanda se attivare o no
			printf("Attivare il processo %d? [Y/N]\n", pid[i]);

			// a questo punto, l'utente digita il carattere se 
			// vuole attivare o meno il processo
			// la funzione getchar() serve a prendere il carattere
			// digitato in input dall'utente

			request = getchar();

			if(request == 'y' || request == 'Y')
				kill(pid[i], SIGUSR1);
			else
				kill(pid[i], SIGUSR2);

			// si mette un getchar() a vuoto per problemi con lo 
			// scanf. Quindi: -- se c'è una scanf in un ciclo,
			//		 si fanno tutte le operazioni che si devono fare
			//                -- fatte tutte le operazione del ciclo,
			//		 prima della parentesi chiusa si mette un getchar() a vuoto
			request = getchar();

			// il processo padre si mette in attesa dell' i-esimo
			// processo figlio, aspettando che faccia quello che deve fare
			// per poter poi passare a creare il successivo i-esimo+1 processo figlio
			pf = wait(&status);
		}
	}

	exit(0);
}

