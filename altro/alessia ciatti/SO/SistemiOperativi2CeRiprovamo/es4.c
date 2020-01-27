#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define max 10

//questo handler serve a specificare che un certo figlio sia stato attivato
void handler(int sig) {
	printf("%d: sono stato attivato\n", getpid());
}

/*questa funzione viene implementata per demanare un attività
al singlo processo figlio.
l'idea è che un processo figlio prenderà un comando(ovvero uno degli
n che sono stati catturati)*/
void figlio(char* com) {
	int miopid;
	miopid = getpid();
	/*ci si chiede se il pid di questo figlio sia pari o dispari
		-se è pari aspetta il segnale SIGUSR1
		-se è dispari aspetta il segnale SIGUSR2

		-il processo padre con il pid pari manderà il segnale SIGUSR1
		-il processo padre con il pid disp manderà il segnale SIGUSR2
	in entrambi i casi i segnale saranno gestiti dall'handler*/

	if(miopid%2==0) 
		signal(SIGUSR1, handler);
	else 
		signal(SIGUSR2, handler);

	/*a questo punto, il processo figlio si mette in pausa,
	inquanto deve aspettare l'attivazione. A seconda che sia
	pari o dispari dovrà ricevere il segnale*/
	pause();

	/*a questo punto, l'ennesimo processo figlio invocherà la funzione
	execlp per eseguire l'ennesimo comando inserito dall'utente*/
	execlp(com, com,(char*)0);
}

int main(int argc, char* argv[]) {
	int ppid, pid[max], pf, i, status;
	/*si fa un ciclo for per catturare i vari comandi*/
	for(i=0; i<argc-1; i++) {
		pid[i] = fork();

		if(pid[i] == 0) {
			/*il processo figlio invoca la funzione passando il comando
			i-esimo che si vuol fare eseguire dall'iesimo figlio.
			come parametro della funzione si passa argv[i+1].
			QUESTO PERCHE' argv[0] E' IL NOME DELL'ESEGUIBILE*/
			figlio(argv[i+1]);
			exit(0);
		}
		else
			printf("[%d] Creato figlio %d\n", ppid, pid[i]);
	}

	sleep(2);

	if(ppid%2==0) {
		for(i=0; i<argc-1; i++) {
			/*bisognerà invocare l'invio del segnale SIGUSR1.
			Con il ciclo, si manda il segnale SIGUSR1 a tutti
			i processi figli. I processi figli che hanno pid pari;
			*/
			kill(pid[i], SIGUSR1);
		}
	}

	else {
		for(i=0; i<argc-1; i++) {
			kill(pid[i], SIGUSR2);
		}
	}
}