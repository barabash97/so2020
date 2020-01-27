#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

//handler che cattura il segnale
void handler(int sig) {
	//si crea una variabile char
	char c;

	/*si utilizza la funzione signal() ed il segnale sig, passato come
	parametro, dovrà essere ignorato da SIG_IGN.
	il fatto che si faccia CTRL+C la prima volta inftti, dovrà essere
	ignorato.
	Se non fosse ignorato, interromperebbe l'esecuzione. Una volta che
	è stato ignorato, subito dopo verra fatta la stampa*/
	signal(sig, SIG_IGN);

	/*stampa il messaggio in cui chiede se, dopo la prima volta che 
	si è premuto CTRL+C, ci si fosse sbagliati*/
	printf("te sei sbagliato?[y/n]\n");

	c = getchar();
	if(c == 'n' || c == 'N')
		exit(0);
	/*altrimenti viene ripristinato quella che è la cattura del
	segnale. per cui CTRL+C non deve essere più ignorato, bensi
	nel caso in cui venga richiamato SIGINT bisognerebbe richiamare
	il vecchi handler*/
	else
		signal(SIGINT, handler);

}

int main() {
	/*si invoca la funzione per catturare il segnale SIGINT
	la quale attiverà l'handler una volta generato il segnale*/
	signal(SIGINT, handler);

	while(1) {
		printf("nope\n");
		pause();
	}
}