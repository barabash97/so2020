
/* Appende una stringa in un file */

#include <stdio.h>

int main() {
	FILE *fp;

	if((fp=fopen("dati.txt", "a")) == NULL)
		printf("Errore di I/O");

	else if(fputs(" Fine\n", fp) == EOF)
		printf("Errore in scrittura");

	fclose(fp);
}