#include <stdio.h>
#include <stdlib.h>

typedef char Stringa[30];

typedef struct {
	Stringa nome;
	int giorni;
} mese;

int main (int argc, char ** argv) {
	mese corrente;
	FILE *fp = fopen("mesi.dat", "rb+");
	fread(&corrente, sizeof(mese), 1, fp);
	fclose(fp);

	printf("%s %d\n", corrente.nome, corrente.giorni);
}