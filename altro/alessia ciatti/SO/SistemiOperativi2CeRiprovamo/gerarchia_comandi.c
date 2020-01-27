#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIM 20

typedef char string[80];
typedef string strvett[DIM];

void get_stato(int S, int pid) {

	printf("\nterminato processo numero %d\n", pid);
	if(S==0)
		printf("terminazione volontaria con stato %d\n", S);
	else
		printf("terminazione involontaria per segnale %d\n", S);
}


int gestoreSequenza(int N, strvett vett) {
	int stato, pid;
	pid = fork();

	if(pid<0) {
		perror("fork");
		exit(2);
	}

	if(pid==0) {
		if(N==-1) {
			printf("\nfoglia %d\n", getpid());
			exit(0);
		}
		else
			pid=gestoreSequenza(N-1, vett);
	}

	else {
		if(N!=-1) {
			printf("\nprocesso %d per comando %s", pid, vett[N]);
			pid=wait(&stato);
			get_stato(stato, pid);

			if(execlp(vett[N], vett[N], (char*)0)<0) {
				perror("exec");
				exit(-1);
			}
			exit(0);
		}

	}
}


int main() {
	int pid, ncom, stato, i;
	strvett vstr;
	printf("quanti comandi?\n");
	scanf("%d", &ncom);
	for(i=0; i<ncom; i++) {
		printf("\ndammi il prossimo comando(senza argomenti)\n");
		scanf("%s\n", vstr[i]);
	}

	gestoreSequenza(ncom-1, vstr);
	pid=wait(&stato);
	get_stato(stato, pid);
	exit(0);

}