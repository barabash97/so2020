
/* Restituisce i mesi che hanno 31 giorni (non tutti LOL) */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char nome[20];

	int giorni;

	FILE *f;

	f=fopen("mesi.txt", "r");

	if(f==NULL) {
		printf("Il file non esiste! coglione figlio di puttana");
		exit(1);
	}

	while(fscanf(f, "%s %d\n", nome, &giorni)!=EOF) {

		if(giorni==31)
			printf("%s\n", nome);
	}

	fclose(f);
}