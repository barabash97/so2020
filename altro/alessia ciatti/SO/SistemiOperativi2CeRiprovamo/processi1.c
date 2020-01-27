#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t pid;
int counter = 0;

void handler1(int sig) {
	counter++;
	printf("1 counter = %d\n", counter);
	kill(pid, SIGUSR1);
}

void handler2(int sig) {
	counter += 3;
	printf("2 counter = %d\n", counter);
	exit(0);
}

int main() {
	pid_t p;
	int status;
	signal(SIGUSR1, handler1);
	if((pid = fork())== 0 ) {
		signal(SIGUSR1, handler2);
		kill(getpid(), SIGUSR1);
		while(1);
	}

	if((p = wait(&status)) > 0) {
		counter += 4;
		printf("main counter = %d\n", counter);
	}
}