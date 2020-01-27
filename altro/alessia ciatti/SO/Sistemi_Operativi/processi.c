#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
	int N = atoi(argv[1]);

	if(N<0 || N>10) 
		return 0;
	pid_t pid;

	int i;
	char c;
	for(i=0; i<N; i++) {
		pid = fork();

		if(pid<0) {
			perror("fork");
			exit(0);
			}

			if(pid==0) {
				if(c=='y')
					printf("Processo attivato\n");
				else if(c=='n')
					printf("Processo non attivato\n");
				exit(1);
				
			}

			else {
				printf("Creato processo figlio: %d\n", getpid());
				printf("Attivare processo creato?[y/n]\n");
				scanf("%c", &c);

				int status;
				pid=wait(&status);
			}
		}
}