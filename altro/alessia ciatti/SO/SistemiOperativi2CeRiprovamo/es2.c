#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

//questo handler stampa il messaggio di terminazione
void handler(int sig) {
	printf("\nTerminator\n");
	exit(0);
}

int main() {
	/*si invoca la funzione signal() per catturare il segnale
	SIGINT(CTRL+C), la quale attiverà l'handler una volta 
	generato il segnale*/
	signal(SIGINT, handler);

	/*si crea un ciclo infinito oer poter esequire la stampa-sleep
	all'infinito*/
	while(1) {
		//stampa e aspetta un secondo prima di stampare ancora
		printf("Bella cojo'! me blocchi?!\n");
		sleep(1);
		/*quando verra premuto CTRL+C, verrà generato il segnale
		SIGINT e si attiverà la funzione handler*/
	}
}