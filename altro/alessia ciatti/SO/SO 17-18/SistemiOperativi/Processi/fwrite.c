#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Stringa[30];

typedef struct {
	Stringa nome;
	int giorni;
} mese;

int main(int argc, char ** argv) {
	mese corrente;
	strcpy(corrente.nome, "Gennaio");
	corrente.giorni = 31;
	FILE *fp = fopen("mesi.dat", "ab+");
	fwrite(&corrente, sizeof(mese), 1, fp);
	fclose(fp);
}