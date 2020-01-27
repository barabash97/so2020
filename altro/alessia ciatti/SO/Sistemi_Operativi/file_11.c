
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char matr[20];
	char matr2[20];

	int esami;
	int test = 0;

	long pos;

	scanf("%s\n", matr);

	FILE *f;

	f = fopen("alunni.txt", "r+");

	if(f==NULL) {

		printf("Il file non esiste!");
		exit(1);
	}

	while((!test) && (!feof)) {

		pos = ftell(f);
		fscanf(f, "%s %d\n", matr2, &esami);

		if(strcmp(matr, matr2)) {

			fprintf(f, "%s %d\n", matr2, esami);
			test = 1;
		}
	}

	fclose(f);
}