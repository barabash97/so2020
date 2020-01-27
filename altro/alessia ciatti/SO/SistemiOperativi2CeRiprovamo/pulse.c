#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
	int pid1, pid2;
	pid1 = fork();
	if(pid1 == 0){ // primo figlio
		while(1) { // loop infinito
			printf("pid1 rompe il cazzo\n");
			sleep(1);
		}
	}

	pid2 = fork();
	if(pid2 == 0) { // secondo figlio
		while(1) { // loop infinito
			printf("pid2 rompe il cazzo\n");
			sleep(1);
		}
	}

	sleep(2);
	kill(pid1, SIGSTOP); // sospende il primo figlio
	printf("sospendo pid1\n\n");

	sleep(2);
	kill(pid1, SIGCONT); // riprende il primo figlio
	printf("riprendo pid2\n\n");

	sleep(2);
	kill(pid1, SIGINT); // uccide il primo figlio
	kill(pid2, SIGINT); // uccide il secondo figlio

	return 0;
}