/*In questo codice, il processo padre comuncia al processo figlio una stringa. E il figlio la stamperà */

// INIZIO INTESTAZIONE 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Si definisce una costante lunga 1024 al massimo
#define MAXLINE 1024

// FINE INTESTAZIONE 

// Questa funzione serve a gestire eventuali errori affidandosi alla perror
void err_sys(const char* t){

		perror(t);
		exit(0);

}// end err_sys

int main(void){

	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];

	/* Si invoca la funzione pipe. Verrà creato un canale. 
	Se ritorna un numero negativo vuol dire che c'è stato un errore*/
	if(pipe(fd) < 0){

		// Invocazione della funzione err_sys che stamperà un messaggio di errore
		err_sys("pipe error");

	}// end if 

	// SI genera un processo figlio
	pid = fork();

	// Se il pid < 0, c'è stato un errore
	if(pid < 0){

		// Invocazione della funzione err_sys che stamperà un messaggio di errore
		err_sys("fork error");

	}// end if 

	// Altrimenti, è attivo o il processo padre o il processo figlio 
	else{

		// Se il pid > 0, è attivo il processo padre
		if(pid > 0){// Sono il processo padre

			/* Il processo padre svolgere due operazioni:

			- Si invoca la funzione close per chiudere il descrittore fd[0], che è il 
			descrittore del processo padre per la lettura.
			- Si invoca la funzione write per scrivere sul 
			descrittore fd[1], che è il descrittore del processo padre per la scrittura. Viene passata anche la stringa da scrivere
			che è "hello world" e viene passata anche la sua lunghezza.

			L'idea quindi è che venga chiuso il canale di lettura(fd[0]) e venga scritta sul canale di scrittura fd[1] 
			la stringa "hello world"*/
			close(fd[0]);
			write(fd[1],"hello world\n",12);

		}// end if 

		// Altrimenti, è ativvo il processo figlio
		else{// Sono il processo figlio

			/* Il processo figlio svolgere due operazioni:
			- Si invoca la funzione close per chiudere il descrittore fd[1], che è il 
			descrittore del processo padre per la scrittura
			- Si invoca la funzione read per leggere sul 
			descrittore  fd[0], che è il descrittore del processo figlio per la lettura. 
			L'idea quindi è che viene chiuso il canale di scrittura (fd[1]) e venga letta sul canale di lettura fd[0] 
			la stringa scritta dal processo padre*/
			close(fd[1]);
			n = read(fd[0], line, MAXLINE);
			write(STDOUT_FILENO, line, n);

		}// end else 

	}// end else 

	exit(0);
}// end main

