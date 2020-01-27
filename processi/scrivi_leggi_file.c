#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef char string[90];

int main() {
	pid_t pid;
	int i;
	char c;

	FILE* fp = fopen("test.txt", "a+");
	if(fp!=NULL) {
		pid = fork();
		if(pid<0) {
			perror("fork");
			exit(2);
		}

		if(pid==0) {
			printf("[Figlio]Attendo 4 secondi...\n");
			sleep(4);
			long pos = ftell(fp);
			printf("\n[Figlio] posizione attuale puntatore file: %ld\n", pos);
			fseek(fp, 0, SEEK_SET);
			printf("[Figlio] stampo contenuto del file di testp:\n");
			c = fgetc(fp);
			while(!feof(fp)) {
				printf("%c", c);
				c = fgetc(fp);
			}
			printf("\n");

			printf("[Figlio] chiudo il file ed esco\n");
			fclose(fp);
			exit(0);
		}

		else {
			string abph;
			printf("[Padre] inserimento stringa nel file\n");

			printf("[Padre]ciccio, che ci scrivo?\n");
			scanf("%s\n", abph);

			fprintf(fp, "%s\n", abph);

			printf("[Padre] posizione attuale puntatore file: %ld\n", ftell(fp));
			sleep(6);
			printf("[Padre] chiudo il file e lo cancello\n");
			fclose(fp);
			printf("[Padre] EHHHHHH VOLEVIIII, col cazzo che lo cancello\n");
		}
	}
	else {
		printf("Errore! non è stato possibile aprire il file.\n");
	}
	exit(0);
}