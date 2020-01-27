
#include <stdio.h>
#include <stdlib.h>
typedef char String[20];

typedef struct { String nome ; int giorni;} mese;

int main() {

	int i=0;

	mese v [12]; /* al massimo saranno 12 */

	FILE *f=fopen("mesi.dat", "rb");

	if(f==NULL) {

		printf("Il file non esiste e SARA È NA COJONA\n");
		exit(1);
	}

	while(fread(&v[i], sizeof(mese), 1, f) != EOF) {

		if(v[i].giorni == 31){
			printf("%s\n", v[i].nome);
		}

		i++;
	}

	fclose(f);

}