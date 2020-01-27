#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

//si crea una variabile globale int
int val = 10;

//questo è un handler
void handler(int sig) {
	val = val + 8;
}

int main() {
	//si crea una variabile pid
	pid_t pid;

	/*si invoca la funzione signal(), la quale cattura il segnale
	viene lanciato quando si genera il figlio ed attiva l'handler
	che abbiamo creato prima. Percui prenderà il valore di val,
	che è 10 e ci sommerà 8, avendo così val = 18*/
	signal(SIGCHLD, handler);

	//si genera un processo figlio
	pid = fork();

	//se il pid = 0, è attivo il processo figlio
	if(pid == 0) {
		//si sottrae 3 alla variabile val e si termina l'esecuzione
		val = val -3;
		exit(0);
	}

	//il processo padre, prima di far la stampa, aspetta che
	//il figlio termini la sua esecuzione
	waitpid(pid, NULL, 0);

	//stampa il valore della variabile val
	printf("val = %d\n", val);
}
/*Quindi, il fatto che il processo figlio vada a modificare la variabile
val sottraendo 3 è "irrilevante" per il padre per il fatto che quando
il processo figlio viene creato con la fork() c'è la funzione signal()
che cattura il segnale SIGCHLD ed attiva l'handler. Percui viene
bypassata la modifica che può fare il figlio e quindi la stampa finale 
sarà val = 18!!*/

/*RIASSUMENDO:
	-Quando viene fatta la fork(), si genera il segnale SIGCHLD
	-Il processo padre, tramite la funzione signal() cattura l'evento (lo rubba proprio??? BOH!!)
	-A questo punto, il blocco di istruzioni inerenti al processo figlio,
	dove viene svolto val = val -3, verrà bypassato(Quindi si, lo rubba proprio!!! che ladro!!)*/