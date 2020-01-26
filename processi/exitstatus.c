#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>




int main(int argc, char * argv[]){

	int pid;
	int status;

	pid = fork();

	if(pid == 0){
		printf("Figlio con processo %d.\n", getpid());
		exit(31);
	} else {
		pid = wait(&status);
		printf("Terminato processo %d del padre %d con stato di terminazione %d.\n",
			pid, getpid(), WEXITSTATUS(status));
	}

	return 0;
}