#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef char Stringa[80];

Stringa voti[11] = {"0", "1", "3", "4", "5", "6", "7", "8", "9", "10"};

int inserisci(Stringa nome, int voto, Stringa nomeFile) {
	int count = 0;
	Stringa temp;
	if((voto>=0) && (voto<=10)) {
		FILE* fp = fopen(nomeFile, "a+");
		fprintf(fp, "%s %d\n", nome, voto);

		//riporto il puntatore in posizione 0
		fseek(fp, 0, SEEK_SET);
		while(!feof(fp)) {
			fscanf(fp, "%s %d\n", temp, &voto);
			count++;	
		}
		fclose(fp);
	}
	else
		count = -1;   //errore di inserimento
	return count;
}

void cambiaVoto(Stringa nome, int vecchio_voto, int nuovo_voto, Stringa nomeFile) {
	int voto;
	Stringa temp;
	long pos;
	int test = 0;

	if((nuovo_voto>=0) && (nuovo_voto<=10)){
		FILE* fp = fopen(nomeFile, "r+");
		while((!feof(fp)) && (!test)){
			pos = ftell(fp);
			if(fscanf(fp, "%s %d\n", temp, &voto)!=EOF){
				if(strcmp(nome, temp)==0 && vecchio_voto == voto) {
					fseek(fp, pos, SEEK_SET);
					fprintf(fp, "%s %d\n", nome, nuovo_voto);
					test = 1;
				}
			}

		}

		fclose(fp);
	}

	else 
		printf("Voto non corretto!"); //errore di inserimento

}

int maxVoto(Stringa nomeFile) {
	FILE* fp = fopen(nomeFile, "r");
	int max = 0;
	int voto;
	Stringa nome;

	if(!fp) 
		return -1; //il file non esiste

	while(!feof(fp)){
		fscanf(fp, "%s %d\n", nome, &voto);
		if(voto>max) {
			max = voto;
		}
	}

	fclose(fp);

	return max;
}

void creaFiles(Stringa nomeFile) {

	Stringa temp;
	int voto;

	FILE* fp = fopen(nomeFile, "r");

	while(!feof(fp)) {
		fscanf(fp, "%s %d\n", temp, &voto);
		Stringa newFile;
		strcpy(newFile, nomeFile);
		strcat(newFile, "-");
		strcat(newFile, voti[voto]);
		strcat(newFile, ".txt");
		inserisci(temp, voto, newFile);
	}
	fclose(fp);
}

int main(int argc, char** argv) {
	printf("\n %d\n", inserisci("Andrea", 10, "Voti.txt"));
	printf("\n %d\n", inserisci("Andrea", 8, "Voti.txt"));
	printf("\n %d\n", inserisci("Girgio", 1, "Voti.txt"));
	printf("\n %d\n", inserisci("Girgio", 10, "Voti.txt"));
	printf("\n %d\n", inserisci("Sara", 10, "Voti.txt"));
	printf("\n %d\n", inserisci("Sara", 1, "Voti.txt"));
	printf("\n %d\n", inserisci("Andrea", 10, "Voti.txt"));
	creaFiles("Voti.txt");
	printf("\n %d\n", maxVoto("Voti.txt"));
	cambiaVoto("Girgio", 1, 0, "Voti.txt");
}