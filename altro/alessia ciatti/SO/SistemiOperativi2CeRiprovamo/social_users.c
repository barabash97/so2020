#include <stdio.h>
#include <string.h>

typedef char string[20];

int modificaColori(string nomeFile, string coloreCorrente, string coloreNuovo) {

	int count = 0;
	long pos;
	string nome, colore1, colore2, colore3;
	FILE* fp = fopen(nomeFile, "r+");

	if(!fp) {
		count = -1;  //errore di inserimento
		return count;
	}
	while(!feof(fp)) {
		
		pos = ftell(fp);
		fscanf(fp, "\n %s %s %s %s\n", nome, colore1, colore2, colore3);
		printf("%s\n", nome);

		if(strcmp(colore1, coloreCorrente)==0) {
			fseek(fp, pos, SEEK_SET);
			fprintf(fp, "\n %s %s %s %s\n", nome, coloreNuovo, colore2, colore3);
			count++;
			fseek(fp, 0, SEEK_SET);
		}

		if(strcmp(colore2, coloreCorrente)==0) {
			fseek(fp, pos, SEEK_SET);
			fprintf(fp, "\n %s %s %s %s\n", nome, colore1, coloreNuovo, colore3);
			count++;
			fseek(fp, 0, SEEK_SET);
		}
			
		if(strcmp(colore3, coloreCorrente)==0) {
			fseek(fp, pos, SEEK_SET);
			fprintf(fp, "\n %s %s %s %s\n", nome, colore1, colore2, coloreNuovo);
			count++;
			fseek(fp, 0, SEEK_SET);
		}

	}

	fclose(fp);

	return count;
}

int main() {

	int stronzi = modificaColori("social_users.txt", "nero", "1");

	printf("\nHo cambiato %d rossi, per mettere giusto %d stronzi\n", stronzi, stronzi);

	int negri =  modificaColori("social_users.txt", "bianco", "2");

	printf("\nE poi ho cambiato %d gialli, per mettere giusto %d negri\n\n", negri, negri);

}

