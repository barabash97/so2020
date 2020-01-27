// INIZIO INTESTAZIONE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// FINE INTESTAZIONE

/* Questo handler sig_int */
static void sig_int(int signo){

	// Stampa il messaggio di cattura del segnale SIGINT
	printf("caught SIGINT \n");

	/* Invocando la funzione signale e mettendo SIG_DFL si sta ripristinando l'azione di default quando viene catturato
	il segnale SIG_INT */
	if(signal(SIGINT, SIG_DFL) == SIG_ERR){
		
		// Stampa dell'errore tramite la perror ne lcaso non fosse possibile ripristinare l'handler di default
		perror("can't reset SIGINT");

	}// end if

	return;

}// end sig_int

int main(void){

	// SI creano alcune variabili sigset_t
	sigset_t newmask;
	sigset_t oldmask;
	sigset_t pendmask;

	// Si invoca la funzione signal sul segnale SIGINT utilizzando l'handler sig_int
	if(signal(SIGINT,sig_int) == SIG_ERR){

		// Stampa dell'errore tramite la perror nel caso in cui non si fosse grado di catturare un segnale
		perror("can't catch SIGINT");

	}// end if

	/* Ora stiamo andando a settare la maschera di questo processo */

	// Si invoca la funzione sigemptyset, che consente di creare un set di segnali vuoto
	sigemptyset(&newmask);

	// Si invoca la funzione sigaddset, che consente di aggiungere ad un certo set di segnali (newmask) un altro segnale (SIGINT)
	sigaddset(&newmask, SIGINT);

	// Si invoca la funzione sigprocmask, che consente di settare l maschera del process corrente passando questo set di segnali
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0){

		perror("SIG_BLOCK error");

	}// end if 

	// Il processo si addormenta per 5 secondi
	sleep(5);

	if(sigpending(&pendmask) < 0){

		perror("sigpending error");

	}// end if 

	if(sigismember(&pendmask, SIGINT)){

		printf("\n SIGINT pending \n");

	}// end if 

	if(sigprocmask(SIG_MASK, &oldmask, NULL) < 0){

		perror("SIG_SETMASK error");

	}// end if 

	printf("SIGINT unblocked \n");

	sleep(5);
	exit(0);

}// end main