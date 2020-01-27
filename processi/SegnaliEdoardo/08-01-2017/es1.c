// INIZIO INTESTAZIONE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


// FINE INTESTAZIONE 

// Si creano due variabili globali
pid_t pid;
int counter = 0;

// Questo handler incrementa counter di 1 e stampa il valore di counter
void handler1(int sig){

	// Somma +1 a counter e stampa il valore di counter
	counter++;
	printf("counter = %d\n", counter);

	// Viene mandato un segnale al processo che ha un certo pid (pid) il cui segnale è proprio SIGUSR1
	kill(pid, SIGUSR1);

}// end handler1

// Questo handler incrementa counter di 3 e stampa il suo valore
void handler2 (int sig){

	// Somma +3 a counter e stampa il valore di counter
	counter = counter + 3;
	printf("counter = %d\n", counter);
	exit(0);

}// end handler2

int main(void){

	// si crea una varaibile pid e una variabile int
	pid_t p;
	int status;

	// Il processo padre invoca la funzioen signal e cattura il segnale SIGUSR1 attivando handler1
	signal(SIGUSR1,handler1);
	
	// Si genera un processo figlio
	pid = fork();

	// Se il pid = 0, è attivo il processo figlio
	if (pid == 0){ // Sono il processo figlio

		// Il processo figlio invoca la funzione signale e cattura il segnale SIGUSR1 attivando questa volta handler2
		signal(SIGUSR1, handler2);

		// II processo figlio manda al processo padre (getppid() è il pid del padre) il segnale SIGUSR1
		kill(getppid(),SIGUSR1);
		while(1);

	}// end if pid == 0

	// Il processo padre sta aspettando che il processo figlio termin la sua esecuzione 
	if(p = wait(&status) > 0){

		 // Somma +4 a counter e stampa il suo valore
		 counter =  counter + 4;
		 printf("counter = %d\n", counter);

	}// end p = wait(&status)

}// end main 