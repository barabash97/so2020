
/* memorizza una sequenza di interi in un file, scrivendoli (APPENDENDOLI) uno per riga */

#include <stdio.h>

int main() {

	FILE *fp;

	int dato, n, i;

	if((fp=fopen("dati.txt", "a")) == NULL)
	printf("Errore di I/O");

	else {
		printf("N.dati da inserire:\n");
		scanf("%d", &n);

		for(i=0; i<n; i++) {
			printf("Dato n. %d:", i+1);
			scanf("%d", &dato);
			fprintf(fp, "%d\n", dato);
		}

		fclose(fp);
	}	
}