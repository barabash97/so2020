
/* scrive in un file i caratteri in input */

#include <stdio.h>

int main() {
	FILE *fp;
	int c;

	fp=fopen("dati.txt", "w");

	if(fp==NULL)
		printf("Errore di I/O");
	else
		while((c=getchar())!='\n')
			fputc(c, fp);
		fclose(fp);
}