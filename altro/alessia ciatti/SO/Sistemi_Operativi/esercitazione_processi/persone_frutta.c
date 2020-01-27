#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char stringa[30];

typedef struct {
	stringa nome;
	int flag;
} record_bin;

int creaBinario(stringa nome_file, stringa frutto) {

	int fg, count;
	stringa nome, f1, f2, f3;

	FILE* fp = fopen(nome_file, "r");
	FILE* fp2 = fopen("frutto_preferito.dat", "ab");

	while(!feof(fp)) {
		fscanf(fp, "%s %s %s %s\n", nome, f1, f2, f3);
		record_bin rb;
		fg = (strcmp(frutto, f1)==0)||
			 (strcmp(frutto, f2)==0)||
			 (strcmp(frutto, f3)==0);
		if(fg) 
			count++;
		strcpy(rb.nome, nome);
		rb.flag = fg;
		fwrite(&rb, 1, sizeof(record_bin), fp2);
	}

	fclose(fp);
	fclose(fp2);
	return count;
}

void leggiBinario() {
	FILE* fp = fopen("frutto_preferito.dat", "rb");

	while(!feof(fp)) {
		record_bin rb;
		fread(&rb, 1, sizeof(record_bin), fp);
		printf("%s %d\n", rb.nome, rb.flag);
	}

	fclose(fp);
}

int main() {
	creaBinario("persone_frutta.txt", "pera");
	leggiBinario();
	exit(0);
}