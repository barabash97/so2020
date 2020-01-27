
/*Crea un file.dat e inserisce una o più stringhe */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[20];

typedef struct 
{
	String nome;
	int giorni;
} mese;

int main(int argc, char **argv) {

	mese corrente[5];

	String nom;
	int giorn;

	int c = 0;;

	while(c<5){
		printf("inserisci mese:\n");
		scanf("%s", nom);
		printf("inserisci i giorni del mese:\n");
		scanf("%d", &giorn);

		strcpy(corrente[c].nome, nom);
		corrente[c].giorni = giorn;
		c++;
	}

	FILE *fp = fopen("mesi.dat", "ab+");
	fwrite(&corrente, sizeof(mese), 1, fp);
	
	int j = 0;

	while(j<5){
		
		fread(&corrente[j], sizeof(mese), 1, fp);
		printf("%s %d\n", corrente[j].nome, corrente[j].giorni);
		j++;
	}
	
	fclose(fp);
}