#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

#define max 10

void gestore_att(int sig) {
	printf("%d: sono stato attivato!\n", getpid());
	return;
}

void figlio(char *com) {

	int miopid;
	miopid = getpid();
	if((miopid%2) == 0)
		signal(SIGUSR1, gestore_att);
	else
		signal(SIGUSR2, gestore_att);
	pause();
	execlp(com, com,(char *)0);

}

int main(int argc, char *argv[]) {

	int ppid, pid[max], pf;
	int status, i;
	
	if(argc == 1){
		printf("Sintassi sbagliata!\n");
		exit(1);
	}

	ppid = getpid();

	for(i=0; i<argc-1; i++) {
		pid[i] = fork();
		if(pid[i] == 0) {
			figlio(argv[i+1]);
			exit(0);
		}
		else
			printf("%d: creato figlio %d\n", ppid, pid[i]);
	}

	sleep(2);
	if((ppid%2) == 0) 
		for(i=0; i<argc-1; i++) 
			kill(pid[i], SIGUSR1);
	else
		for(i=0; i<argc-1; i++)
			kill(pid[i], SIGUSR2);
	for(i=0; i<argc-1; i++){
		pf = wait(&status);
		if((char)status == 0)
			printf("terminato %d con status %d\n", pf, status);
		else
			printf("terminato %d involontariamente (segnale %d)", pf, status);
	}
	
	exit(0);
}
