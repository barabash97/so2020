#include <stdio.h>
#include <stdlib.h>

typedef char Stringa[30];

int modificaColore(Stringa nome_file, Stringa colore_corrente, Stringa colore_nuovo) {
	FILE *fp;

	fp = fopen(nome_file, "r+");
	Stringa colore1, colore2, colore3, nome_persona;
	long pos;
	int count = 0;

	while(!feof(fp)) {
		pos = ftell(fp);

		if (fscanf(fp, "%s %s %s %s\n", nome_persona, colore1, colore2, colore3) != EOF) {
			if (strcmp(colore_corrente, colore1) == 0) {
				fseek(fp, pos, SEEK_SET);
				fprintf(fp, "%s %s %s %s\n", nome_persona, colore_nuovo, colore2, colore3);
				count++;
			}
			if (strcmp(colore_corrente, colore2) == 0) {
				fseek(fp, pos, SEEK_SET);
				fprintf(fp, "%s %s %s %s\n", nome_persona, colore1, colore_nuovo, colore3);
				count++;
			}
			if (strcmp(colore_corrente, colore3) == 0) {
				fseek(fp, pos, SEEK_SET);
				fprintf(fp, "%s %s %s %s\n", nome_persona, colore1, colore2, colore_nuovo);
				count++;
			}
		}
	}

	fclose(fp);

	return count;
}

//grep -E '^[a-d][1-4].@.*[.]org$' indirizzi.txt
//grep -E '^[a-zA-Z]{2,9}, [ABD-Z]{2} [1-9]{5}$' indirizzi.txt

int main(int argc, char **argv) {
	printf("Numero di modifiche: %d\n", modificaColore("esercitazione.txt", "tappeto", "criceto"));
}