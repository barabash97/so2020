#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef char string[90];

typedef struct {
	string nome;
	int flag;
}record;

void creaBinario(string nomeFile, string colore) {
	FILE* fp = fopen(nomeFile, "r");
	string nome, c1, c2, c3;
	FILE* fp2 = fopen("colori.dat", "ab");

	while(!feof(fp)) {

		if(fscanf(fp, "%s %s %s %s\n", nome, c1, c2, c3)!=EOF){
			int cont = 0;
			if(strcmp(colore, c1) == 0||
				strcmp(colore, c2) == 0||
				strcmp(colore, c3) == 0) {
				cont++;
			}

			record a;
			strcpy(a.nome, nome);
			a.flag = cont;

			fwrite(&a, 1, sizeof(record), fp2);
		}

	}
	fclose(fp);
	fclose(fp2);
}

void leggiBinario() {
	record b;
	FILE* fp = fopen("colori.dat", "rb+");
	while(!feof(fp)) {
		fread(&b, 1, sizeof(record), fp);
		printf("%s %d\n", b.nome, b.flag);
	}
	fclose(fp);
}

int main() {
	creaBinario("colori.txt", "blu");
	leggiBinario();
	exit(0);
}