
#include <stdio.h>

int main() {

	FILE *ifp, *ofp;

	int c;

	ifp=fopen("dati.txt", "r");

	if(ferror(ifp)) {

		perror("Errore di I/O");
		return 0;
	}

	ofp=fopen("copia.txt", "w");

	if(ferror(ofp)) {

		perror("Errore di I/O");
		return 0;
	}

	c = fgetc(ifp);

	while(!feof(ifp)) {
		fputc(c, ofp);
		c = fgetc(ifp);
	}

	fclose(ofp);
	fclose(ifp);
}