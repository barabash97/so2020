#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM 10

int main() {
	int i, pid;

	//genera 10 processi
	for(i=0; i<NUM; i++) {
		pid = fork();

		if(pid < 0) {
			perror("fork");
			exit(0);
		}

		if(pid == 0) {
			sleep(1);
			printf("sono il processo numero %d con pid %d\n", i +1, getpid());
			sleep(1);
			exit(101+i);
		}

		else {
			sleep(1);
			printf("sono il processo padre e ho generato il figlio %d con pid %d\n", i+1, pid);
			sleep(1);
		}

	}

	for(i=0; i<NUM; i++){
		int status;
		wait(&status);
		printf("status %d\n", status);
		printf("&status %p\n", &status);
		printf("Terminato processo %d\n", WEXITSTATUS(status));
	}

}