// INIZIO INTESTAZIONE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// FINE INTESTAZIONE

// Si crea una variabile globale int
int val = 10; 

// Questo è un handler
void handler(int sig){

	val = val + 8;

}// end handler

int main(void){

	// Si crea una varaibile pid
	pid_t pid;

	/* Si invoca la funzione signal, la quale cattura il segnale che viene lanciato quando si genera il figlio  ed attiverà l'handler
	che abbiamo chiamato handler. 
	Per cui, prenderà il valore di val, che è 10 e ci sommerà 8, avendo così val = 18 */
	signal(SIGCHLD,handler);

	// Si genera un processo figlio
	pid = fork();

	// Se il pid = 0, è attivo il processo figlio 
	if(pid == 0){ // Sono il processo figlio

		// Si sottrae 3 alla variabile var e si termina l'esecuzione
		val = val - 3;
		exit(0);

	}// end pid == 0

	// Il processo padre, prima di far la stampa, aspetta che il processo figlio termini la sua esecuzione
	waitpid(pid, NULL, 0);

	// Stampa il valore della variabile val
	printf("val = %d\n", val);

}// end main

/* Quindi, il fatto che il processo figlio vada a modificare la variabile val sottraendo 3 è "irrilevante" per il padre per il fatto
che quando il processo figlio viene creato con la fork() c'è la funzione signal che cattura il segnale SIGCHLD ed attiva handler
Per cui viene bypassata la modifica che può fare il figlio e quindi la stampa finale sarà "val = 18".

Riassumendo:

- Quando viene fatta la fork(), si genera il segnale SIGCHLD
- Il processo padre tramite la funzione signal cattura l'evento 
- A questo punto, il blocco di istruzioni inerenti al processo figlio, dove viene svolto val-3, verrà bypassato