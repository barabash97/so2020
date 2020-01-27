
/* Copia il contenuto di un file in un altro */

#include <stdio.h>

int main() {
	FILE *ifp, *ofp;

	int c;

	ifp=fopen("dati.txt", "r");
	ofp=fopen("copia.txt", "w");

	while((c=fgetc(ifp))!=EOF)
		fputc(c, ofp);

	fclose(ofp);
	fclose(ifp);
}