/*Struttura dell'input:

 	argv[0]  argv[1]  argv[2]
	./limit   nsec	   cmd

*/


// INIZIO INTESTAZIONE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// FINE INTESTAZIONE

// Si crea la variabile globale delay
int delay;

/* Questo è l'handler che viene utilizzato nel momento in cui si vorrà gestire il segnale SIGCHLD*/ 
void childHandler(int sig){
	

	int childPid;
	int childStat;
	childPid = wait(&childPid);

	// Stampa del messaggio in cui si dice che il processo figlio a cui è stato dato il comando è terminato in un certo tempo
	printf("Child: %d terminated within %d seconds\n", childPid, delay);

	// Terminazione dell'esecuzione
	exit(0);

}// end childHandler


int main(int argc, char* argv[]){

	// Si crea una variabile pid
	int pid;

	// Si invoca la funzione signal per catturare il segnale SIGCHLD tramite l'handler childHandler
	signal(SIGCHLD,childHandler);

	// Si genera un processo figlio
	pid = fork();

	// Se il pid = 0, è attivo il processo figlio
	if (pid == 0){// Sono il processo figlio

		// Il figlio esegue tramite la funzione execvp il comando passato in input
		execvp(argv[2], &argv[2]);

		// stampa dell'eventuale errore tramite la funzione perror
		perror("limit");

	}// end pid 

	// Altrimenti è attivo il processo padre (pid > 0)
	else{

		/* La funzione sscanf (derivata della scanf) ha la seguente sintassi e semantica:
		- Parametro 1 (argv[1]): è la direttiva di sistema che si passa da input. In questo caso gli stiamo dicendo
		di prenderla da argv[1] che, nel nostro caso, era il numero di secondi che dovevamo esplicitare. Per cui, stiamo memorizzando dentro
		delay il numero di secondi che è stato passato in argv[1]
		- (come la scanf)Parametro 2 (%d): stringa di contesto
		- (come la scanf)Parametro 3 (&delay): variabile entro cui memorizzare il valore */
		sscanf(argv[1],"%d",&delay);

		// Il processo padre si mette a dormire per un tempo che è il delay
		sleep(delay);

		/* Aggiunto da me per vedere se riesce ad ucciderlo 
		printf("PADRE: Mi sono svegliato e uccido il processo figlio perchè ci ha messo più di %d secondi\n", delay); */

		/* A questo punto, se il processo padre si sveglia, vuol dire che il processo figlio ha impiegato troppo 
		tempo ad eseguire il comando e quindi il processo padre deve ucciderlo. Per cui, il processo padre
		invoca una kill su pid (che è il processo figlio) con il segnale SIGINT, ovvero stiamo simulando che il processo
		padre digiti CTRL-C. NB:La kill invia un certo segnale ad un certo pid. Nel nostro caso, il segnale inviato è SIGINT*/
		kill (pid,SIGINT);

	}// end else

}// end main