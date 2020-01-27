#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char Stringa[30];

int inserisci(char* nome, int voto, char *nomefile) {
	FILE *fp;

	fp = fopen(nomefile, "a+");

	if (fp == NULL)
		return 0;

	fprintf(fp,"%s %d\n", nome, voto);
	fclose(fp);

	return 1;
}

int maxVoto(Stringa nomefile) {
	FILE *fp;

	fp = fopen(nomefile, "r");

	if (fp == NULL)
		return 0;

	Stringa persona;
	int max = 0;
	int vot;
	while (fscanf(fp, "%s %d\n", persona, &vot) != EOF) {
		if (vot > max)
			max = vot;
	}

	fclose(fp);
	return max;
}



void cambiaVoto (Stringa nome, int vecchio_voto, int nuovo_voto, Stringa nomefile) {
	FILE *f = fopen(nomefile, "r+");

	if (f == NULL)
		exit(0);

	long posi;
	Stringa buffer;
	int voto;
	int test = 0;

	while (!feof(f) && !test) {
		posi = ftell(f);
 
		if (fscanf(f, "%s %d\n", buffer, &voto) != EOF) {
			if (!strcmp(buffer, nome) && vecchio_voto == voto) {
				fseek(f, posi, SEEK_SET);
				fprintf(f, "%s %d\n", buffer, nuovo_voto);
				test = 1;
			}
		}

	}

	fclose(f);
}

void creaFile(Stringa nomefile) {

	FILE *fp = fopen(nomefile, "r");
	Stringa persona;
	int voto;
	Stringa voti[11] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

	while(!feof(fp)) {
		if (fscanf(fp, "%s %d\n", persona, &voto) != EOF) {
			Stringa temp;
			strcpy(temp, nomefile);
			strcat(temp, "-");
			strcat(temp, voti[voto]);
			inserisci(persona, voto, temp);
		}

	}

	fclose(fp);
}


int main(int argc, char **argv) {
	//inserisci("Chiara", 80, "dati.txt");
	//inserisci("Daniela", 9, "dati.txt");
	//inserisci("Agostino", 6, "dati.txt");
	//inserisci("Alessio", 2, "dati.txt");
	//inserisci("Lorenzo", 10, "dati.txt");
	cambiaVoto("Giorgio", 4, 5, "dati.txt");
	printf("Voto massimo: %d\n", maxVoto("dati.txt"));
}