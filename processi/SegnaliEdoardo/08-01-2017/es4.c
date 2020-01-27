// INIZIO INTESTAZIONE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


#define max 10 // si definisce una costante per catturare al massimo 10 comandi

// FINE INTESTAZIONE

/* Questo handler va a specificare che un certo figlio si stato attivato*/
void gestore_att(int sig){

	// Stampa il messaggio in cui dice che u ncerto processo è stato attivato 
	printf("%d: sono stato attivato! \n", getpid());

}// end gestore_att

/* Questa funzione viene implementata per demandare un attività al singolo processo figlio.
L'idea è che un processo figlio prenderà un comando (ovvero uno degli n che sono stati catturati). */
void figlio (char *com){

	int miopid;
	miopid = getpid();

	/*Ci si va a chiedere se il pid di questo figlio generato sia pari o dispari:
		- Se è pari (parte if), aspetta il segnale SIGUSR1
		- Se è dispari (parte else), aspetta il segnale SIGUSR2
	L'idea è che: 
		- il processo padre con il pid pari manderà il segnale SIGUSR1
		- il processo padre con il pid dispari manderà il segnale SIGUSR2

	In entrambi i casi, i segnali saranno gestiti dall'handler gestore_att*/

	if(miopid%2 == 0){

		signal(SIGUSR1, gestore_att);

	}// end if 

	else{

		signal(SIGUSR2, gestore_att);

	}// end else 

	/* A questo punto, il processo figlio si mette in pausa, i nquanto deve aspettare l'attivazione. A seconda che sia
	pari o dispari dovrà riceve il segnale */
	pause();

	/*A questo punto, l'ennesimo processo figlio vinvocherà la funzione execlp per eseguire l'ennesimo comando inserito 
	dall'utente */
	execlp(com,com,(char *)0);

}// end figlio


int main(int argc, char *argv[]){

	//Si creano una serie di variabili intere
	int ppid;
	int pid[max]; // creazione di un array di interi, lungo al massimo MAX, ovveo 10, dove contenere i pid dei vari figli
	int pf;
	int i;
	int status;

	/* Se il numero di argomenti è uguale a 1 (vorrà dire che è stato inserito solo il nome del'eseguibile, senza passare nessun
	parametro che in questo caso sono comandi)*/
	if(argc == 1){

		// Stampa messaggio di errore di uso scorretto della sintassi di input 
		printf("sintassi sbagliata! \n");
		exit(1);

	}// end if

	// Si cattura il pid del padre
	ppid = getpid();

	/* Si fa un ciclo for per catturare i vari comandi (che in numero saranno da 0 ad argc-1, ovvero da 0 al numero
	totale di argomenti tolto argv[0], che è il nome dell'eseguibile) */
	for(i=0; i <argc-1;i++){

		// Si genera l'-esimo processo figlio
		pid[i] = fork();

		// Se il pid[i] = 0, vuol dire che è attivo l'i-esimo processo figlio 
		if(pid[i] == 0){ // sono il processo figlio 
		
			/* Il processo figlio invoca la funzione passando il comando i-esimo che si vuol far eseguire all'i-esimo
			processo figlio. COme parametro della funzione si passa argv[i+1]. Ovvero si parte dall'argomento argv[1], in quanto
			l'argomento precedente che è argv[0] va escluso in quanto rappresenta il nome dell'esegubile e quindi non è un comando
			da dover eseguire */
			figlio(argv[i+1]);

			// Il processo figlio termina
			exit(0);

		}// end pid[i] == 0

		/* Altrimenti, il o è attivo il processo padre (pid[i]>0) o c'è stato un errore (pid[i]<0) (qui l'errore
		non viene gestito esplicitamente)*/
		else{ // sono il processo padre

			// Stampa da parte del processo padre del messaggio in cui dice quale figlio ha creato
			printf("[%d] Creato figlio %d\n", ppid, pid[i]);

		}// end else

	}// end for 

	// Si addormenta per 2 secondi per dare il tempo di creare tutti i possibili figli
	sleep(2);

	// Se il processo padre ha pid pari
	if((ppid%2) == 0){
		
		// Si vanno ad attivare tutti i figli con pid pari
		for(i=0; i<argc-1; i++){
			
			/*Bisognerà invocare il inviare il segnale SIGUSR1. Con il ciclo, si manda il segnale SIGUSR1
			a tutti i processi figli. I processi figli che prenderanno il segnale SIGUSR1 (quindi i processi figli che hanno pid pari; 
			è stata fatta partire la cattura del segnale solo per quelli) saranno attivati.*/
			kill(pid[i],SIGUSR1);

		}// end for

	}// end if 

	// Altrimenti il processo padre ha pid dispari
	else{

		/*Bisognerà invocare il inviare il segnale SIGUSR2. Con il ciclo, si manda il segnale SIGUSR2
		a tutti i processi figli. I processi figli che prenderanno il segnale SIGUSR2 (quindi i processi figli che hanno pid dispari; 
		è stata fatta partire la cattura del segnale solo per quelli) saranno attivati.*/
		for(i=0; i<argc-1; i++){

			kill(pid[i],SIGUSR2);

		}// end for

	}// end else

	// Il processo padre si mette in attesa per ogni singolo comando lo stato di ritorno 
	for(i=0;i<argc-1;i++){
        
        // Il processo padre aspetta il valore dello status di ritorno dell'i-esimo processo figlio 
        pf = wait(&status);

        /* Se il lo stato di ritorno è 0 (infatti, tutti i processi figli che avranno fatto exit(0), vuol dire che saranno terminato con s
        uccesso) */
        if((char) status == 0){


        	// Stampa del messaggio in cui lo stato è terminato con successo
        	printf("terminato %d con stato %d\n", pf, status);

        }// end if

        // Altrimenti, lo status di ritorno dell'i-esimo figlio sarà diverso da 0
        else{

        	// Stampa del messaggio in cui lo stato è terminato involontariamente
        	printf("terminato %d involontariamente (segnale %d) \n", pf, status);

        } // end else 

	}// end for

	exit(0);

}// end main

