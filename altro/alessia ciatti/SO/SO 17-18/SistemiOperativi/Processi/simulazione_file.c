#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Stringa[30];
typedef struct {
	Stringa name;
	int preferito;
} preferenza;

int creaBinario(Stringa nome_file, Stringa frutto) {
	FILE *fp;

	fp = fopen(nome_file, "r");
	FILE *fb = fopen("frutto_preferito.dat", "ab");
	Stringa nome, frutto1, frutto2, frutto3;
	int cont = 0;
	int test;

	while(!feof(fp)) {
		test = 0;

		fscanf(fp, "%s %s %s %s\n", nome, frutto1, frutto2, frutto3);

		if (strcmp(frutto, frutto1) == 0 || strcmp(frutto, frutto2) == 0 || strcmp(frutto, frutto3) == 0) {
			test = 1;
			cont++;
		}

		preferenza corrente;
		strcpy(corrente.name, nome);
		corrente.preferito = test;
		fwrite(&corrente, sizeof(preferenza), 1, fb);
	}

	fclose(fp);
	fclose(fb);

	return cont;
}

void leggiBinario(){
	preferenza corrente;
	FILE *fp = fopen("frutto_preferito.dat", "rb+");

	while(!feof(fp)) {
		fread(&corrente, sizeof(preferenza), 1, fp);
		printf("%s %d\n", corrente.name, corrente.preferito);
	}

	fclose(fp);
}

int main(int argc, char ** argv) {
	printf("%d\n", creaBinario("persone_frutta.txt", "pera"));
	leggiBinario();
	exit(0);	
}