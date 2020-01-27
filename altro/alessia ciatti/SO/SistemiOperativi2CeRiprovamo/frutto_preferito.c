#include <stdlib.h>
#include <stdio.h>
#include <unist.h>

typedef char string [30];

typedef struct {
	string nome;
	int flag;
	
} record;

int creaBinario(string nome_file, string frutto) {
	int count, fg;
	string f1, f2, f3, nome;
	FILE* fp = fopen("frutto_preferito.dat", "ab");
	FILE* fp2 = fopen(nome_file, "r");

	while(!feof(fp2)) {
		fscanf(fp, "%s %s %s %s\n", nome, f1, f2, f3);
		record rb;
		fg = strcmp(frutto, f1) ||
			 strcmp(frutto, f2) ||
			 strcmp(frutto, f3);
		if(fg) 
			count++;
		strcpy(rb.nome, nome);
		rb.flag = fg;
		fwrite(&rb, 1, sixeof(record), fp);
	}
	fclose(fp);
	fclose(fp2);
	return count;
}

int main {

}