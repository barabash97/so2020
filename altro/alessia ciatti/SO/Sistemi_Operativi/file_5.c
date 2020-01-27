
#include <stdio.h>

int main() {
	FILE * pf;

	char v[30];

	pf=fopen("pippo.txt", "w");

	fprintf(pf, "%s", "ciao");

	fclose(pf);

	pf=fopen("pippo.txt", "r");

	fscanf(pf, "%s", v);

	fclose(pf);

	printf("%s", v);
}