#include <stdio.h>
#include <stdlib.h>

typedef char string[20];

typedef struct pisello
{
	string nome;
	int posColori;
	
};

int creaBinario(string nome_file, string colore) {
	string nome, c1, c2, c3;
	int pos;
	FILE* fp = fopen(nome_file, "rb+");
	FILE* bin;

	if(!fp) {
		printf("NON ESISTE PORCO DE DIOOOOOOOOO\n");
		return -1;
	}
	while(!feof(fp)) {
		bin = fopen("posColori.dat", "ab");
		fscanf(fp, "%s %s %s %s", nome, c1, c2, c3);

	}

}


int main() {

}



