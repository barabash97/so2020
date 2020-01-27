#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void handler(int sig) {
	signal(sig, SIG_IGN);
	printf("\nHai premuto Ctrl+C per sbaglio?\n");
	printf("Vuoi realmente sospendere l'esecuzione? [Y/y]");

	char c = getchar();
	if (c == 'Y' || c == 'y')
		exit(0);
	else
		signal(SIGINT, handler);
}
int main(int argc, char **argv) {
	signal(SIGINT, handler);
	while(1) {
		printf("Hello World\n");
		sleep(1);
	}

	return 0;
}