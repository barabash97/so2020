
/* Stampa i primi 10 caratteri di un file */

#include <stdio.h>

int main() {
	FILE *fp;

	char str[11];

	if((fp=fopen("dati.txt", "r")) == NULL)
		printf("Errore di I/O");
	
	else if(fgets(str, sizeof(str), fp)!=NULL)
		printf("%s\n", str);

	fclose(fp);
}