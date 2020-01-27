// INIZIO INTESTAZIONE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// Si definisce una costante max che vale 10, che è proprio il numero di processi figli che possono essere generati
#define max 10

// FINE INTESTAZIONE

// Questo è un handler che serve a catturare i vari segnali che può inviare il processo padre
void gestore_att(int sig){

	// SIGUSR1 rappresenta il fatto che il processo padre voglia attivare il processo figlio
	// Se il segnale inviato è SIGUSR1
	if(sig==SIGUSR1){

		// Stampa del messaggio che il processo figlio è stato attivato
		printf("Processo attivato: %d\n",getpid());

	}// end if

	// SIGUSR2 rappresenta il fatto che il processo padre NON voglia attivare il processo figlio
	// Altrimenti, il segnale è SIGUSR2
	else {

		// Stampa del messaggio che il processo figlio non è stato attivato
		printf("Processo non attivato: %d\n",getpid());

	}// end else 

	// Terminazione dell'esecuzione
	exit(0);

}// end gestore_att

int main(int argc, char*argv[]){

	int pid[max];
	int pf;
	int i;
	int status;
	int N;
	char request;

	/* La funzione atoi prende l'argomento 1 (argv[1] che è la stringa che rappresenta il numero di processi figli da creare)
	e lo converte in un numero intero */
	N = atoi(argv[1]);

	/* Se c'è solo un argomento in input (che corrisponde ad arg[0] ovvero al nome dell'eseguibile del file),
	vuol dire che non è stato specificato il numero di processi figli da creare */
	if(argc==1){

		// Stampa un messaggio in cui si fa notare che la sintassi di esecuzione del file è sbagliata 
		printf("Sintassi sbagliata \n");
		exit(1);

	}// end if 

	// Si crea un ciclo for che genera un numero di processi figli che va da 0 a N, ovvero al numero specificato in input
	for(i=0;i<N;i++){

		// Si genera l'i-esimo processo figlio 
		pid[i] = fork();

		// Se pid[i]=0, è attivo l'i-esimo processo figlio
		if(pid[i]==0){// Sono l'i-esimo processo figlio

			/*L'i-esimo processo figlio invoca la funzione signal, attivando il monitoraggio dei segnali SIGUSR1 e SIGUSR2.
			Quando uno dei due segnali verrà generato, si attiverà l'handler gestore_att.
			Dopodiché, l'i-esimo processo figlio si mette in pausa per poter ricevere il segnale dal processo
			padre che gli dica se possa essere attivato o meno */
			signal(SIGUSR1,gestore_att);
			signal(SIGUSR2,gestore_att);
			pause();
	
		}// end if

		// Altrimenti, è attivo il processo padre 
		else{ // Sono il processo padre

			// Stampa della creazione del processo
			printf("Creato processo figlio %d\n",pid[i]);

			// Stampa della domanda di attivazione all'utente
			printf("Attivare il processo %d? [y/n]: \n",pid[i]);

			/* A questo punto, l'utente digita il carattere se vuol attivare o meno l'i-esimo processo figlio.
			La funzione getchar() serve a prendere il carattere digitato in input dall'utente*/
			request = getchar();

			// Se il carattere è y o Y
			if(request == 'y' || request == 'Y'){

				// Il processo padre manda al processo figlio il segnale SIGUSR1
				kill(pid[i],SIGUSR1);

			}// end if

			//Altrimenti, è stato digitato n
			else{

				// Il processo padre manda al processo figlio il segnale SIGUSR2
				kill(pid[i],SIGUSR2);

			}// end else

			/* Si mette un getchar() a vuoto per problemi con la scanf. Quindi:
			- se c'è una scanf in un ciclo, si fanno tutte le operazioni che si devono fare. 
			- Fatte tutte le operazioni del ciclo, prima della parentesi della chiusura del 
			  ciclo stesso si mette un getchar a vuoto */
			request = getchar();

			/* Il processo padre si mette in attesa del i-esimo processo figlio, aspettando che faccia quello che deve fare
			per poter poi passare a creare il successivo i-esimo+1 processo figlio */
			pf = wait(&status);

		}// end else 
		
	}// end for

	// Terminazione dell'esecuzione
	exit(0);

}// end main