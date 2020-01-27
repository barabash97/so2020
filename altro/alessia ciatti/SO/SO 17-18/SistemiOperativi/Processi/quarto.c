#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	pid_t pid;
	FILE *fp;

	fp = fopen("test.txt", "a+");

	pid = fork();

	if (pid < 0) {
		perror("fork");
		exit(2);
	}

	if (pid == 0) {
		printf("[Figlio] Attendo 4 secondi\n");
		sleep(4);
		printf("Offset del file %ld\n", ftell(fp));
		fseek(fp, 0, SEEK_SET);

		char c;
		printf("Contenuto del file: ");
		c = fgetc(fp);

		while (!feof(fp)) {
			printf("%c", c);
			c = fgetc(fp);
		}

		printf("\n[Figlio] Chiudo il file\n");
		fclose(fp);
		exit(2);
	}

	else {
		printf("[Padre] Inserimento stringa nel file\n");
		fprintf(fp, "Sono il padre");

		printf("Offset del file: %ld\n", ftell(fp));
		printf("[Padre] Chiudo il file e lo cancello\n");

		int status;
		wait(&status);
		
		fclose(fp);
		remove("test.txt");		
	}
}
