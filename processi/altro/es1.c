#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

//si creano  due variabili globali
pid_t pid;
int counter = 0;

//Questo handler incrementa counter di 1 e stampa il valore di counter
void handler1(int sig) {
	//somma +1 a counter e stampa il valore di counter
	counter++;
	printf("H1 counter = %d\n", counter);

	//viene mandato un segnale al processo che ha un certo pid (pid)
	//il cui segnale è proprio SIGUSR1
	kill(pid, SIGUSR1);
}

//Questo handler incrementa il counter di 3 e stampa il suo valore
void handler2(int sig) {
	counter = counter + 3;
	printf("H2 counter = %d\n", counter);
	exit(0);
}

int main() {
	//si crea una variabile pid e una int
	pid_t p;
	int status;

	//il processo padre invoca la funzione signal() e cattura il 
	//segnale SIGUSR1 attivando handler1
	signal(SIGUSR1, handler1);

	//si genera il processo figlio
	pid = fork();

	if(pid == 0) {
		/*il processo figlio invoca la funzione signal()
		e cattura il segnale SIGUSR1 attivando questa volta 
		handler2*/
		signal(SIGUSR1, handler2);

		//il processo figlio manda al processo padre (getppid())
		//il segnale SIGUSR1
		kill(getppid(), SIGUSR1);

		while(1); // perche sta cosa dio bono?!?!?!?!?!?
	}

	//il processo padre sta aspettando che il processo figlio termini
	//la sua esecuzione
	if(p = wait(&status)>0) {
		//somma +4 a counter e stampa il suo valore
		sleep(4);
		counter = counter + 4;
		printf("counter = %d\n", counter);
	}
}