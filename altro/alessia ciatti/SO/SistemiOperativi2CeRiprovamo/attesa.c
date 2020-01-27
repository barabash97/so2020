#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

	pid_t pid;
	int status;

	// si richiama la funzione fork() per creare il figlio
	pid = fork();

	if(pid<0) {
		perror("fork");
		exit(2);
	}

	if(pid == 0) {
		// quello che segue è il codice eseguito dal figlio
		// si stampano le info richieste

		printf("[figlio]: Il mio pid è %d e quello del processo che mi ha invocato è %d\n", getpid(), getppid());

		exit(24); // èer che cazzo deve essere 24???? per diooooo
	}

	else {
		//segue il codice del processo padre
		printf("[padre]: In attesa della terminazione del processo figlio...\n");
		pid = wait(&status);

		//OK: si sblocca il padre perchè il figlio ha terminato

		printf("[padre]: Il figlio, con il pid %d, ha terminato il lavoro con il seguente codice di ritorno: %d\n", pid, status/256);

	}
}