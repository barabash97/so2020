#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef char stringa[30];

void handler(int sig) {
	printf("\nTerminato\n");
	exit(0);
}

int main(int argc, char **argv) {
	pid_t pid;
	stringa comando;

	while(1) {
		printf("myShell# ");
		scanf("%s", comando);

		signal(SIGINT, handler);
		pid = fork();

		if (pid < 0) {
			perror("fork");
			exit(0);
		}
		if (pid == 0) {
			execlp(comando, comando, NULL);
			exit(2);
		}
		else {
			int status;
			pid = wait(&status);
		}
	}
}