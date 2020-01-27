
#include <stdio.h>
#include <string.h>

typedef char string[30];

string voti[11] = {"0","1","2","3","4","5","6","7","8","9","10"};

/*inserisci un nome e un voto e ritorna il numero di elementi */

int inserisci(string nome, int voto, string nomeFile) {

	int numelem = 0;
	string temp;

	if((voto<=10) && (voto>=0)) {
		FILE* fp = fopen(nomeFile, "a+");
		fprintf(fp, "%s %d\n",nome, voto);

		/* conta il numero di elementi nel file */
		fseek(fp, 0, SEEK_SET);
		while(!feof(fp)) {
			fscanf(fp, "%s %d\n", temp, &voto);
			numelem++;
		}

		fclose(fp);
	}

	else 
		numelem = -1 //errore di inserimento

	return numelem;

}

/* cambia il voto all'occorenza col nome e voto corrente specificati */

void cambiaVoto(string nome, int vecchio_voto, int nuovo_voto, string nomeFile) {

	long pos,
	int voto;
	int test = 0;
	string temp;

	if((nuovo_voto<=10)&&(nuovo_voto>=0)) {
		FILE* fp = fopen(nomeFile, "r+");

		while((!feof(fp))&&(!test)) {

			pos = ftell(fp);
			if(fscanf(fp, "%s %d\n", temp, &voto)!=EOF)
				if(strcmp(nome, temp)==0 && voto==vecchio_voto) {
					fseek(fp, pos, SEEK_SET);
					fprintf(fp, "%s %d\n", nome, nuovo_voto);
					test = 1;
				}
		}

		fclose(fp);
	}
	else
		printf("errore specifica voto");
}

/* ritorna il valore max */

int maxVoto(string nomeFile) {
	int voto, max = 0;
	string nome;
	FILE* fp = fopen(nomeFile, "r");
	if(!fp)
		return -1;  // errore di lettura file
	while(!feof(fp) && max<10) {
		fscanf(fp, "%s %d\n", nome, &voto);
		if(voto>max)
			max = voto;
	}
	fclose(fp);
	return max;
}

/* crea file piccoli */

void creaFile(string nomeFile) {
	string temp;
	int voto;

	FILE* fp = fopen(nomeFile, "r");
	while(!feof(fp)) {
		fscanf(fp, "%s %d\n", temp, &voto);
		string newFile;
		strpy(newFile, nomeFile);
		strcat(newFile, "-");
		strcat(newFile, voti[voto]);
		strcat(newFile, ".txt");
		inserisci(temp, voto, newFile);
	}
}