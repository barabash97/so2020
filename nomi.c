#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char Stringa[30];

typedef struct 
{
	Stringa nome;
	float media;
} record_binario;

void creaBinarioNegativo(){
	FILE *fp = fopen("nomi.txt", "r");
	FILE *fp2 = fopen("persone.dat", "ab");
	int a1,a2,a3;
	Stringa nome;
	int count, somma = 0;
	float media;
	if(fp == NULL){
		printf("file non esiste\n");
		exit(0);
	}

	while(!feof(fp)){
		record_binario rb;
		 count = 0;
		 media = 0;
		 somma = 0;
		fscanf(fp, "%s %d %d %d\n", nome, &a1,&a2,&a3);

		if(a1 < 0){
			somma += a1;
			count++;
		}

		if(a2 < 0){
			somma += a2;
			count++;
		}

		if(a3 < 0){
			somma += a3;
			count++;
		}

		media = somma / count;

		strcpy(rb.nome, nome);
		rb.media = media;

		fwrite(&rb, sizeof(rb), 1, fp2);

	}

	fclose(fp);
	fclose(fp2);
}

void leggiBinario(){
	FILE *fp = fopen("persone.dat", "rb");
	if(fp == NULL){
		printf("file non esiste\n");
		exit(0);
	}
	printf("\nSTAMPA\n\n\n");
	while(!feof(fp)){
		record_binario rb;

		fread(&rb, 1, sizeof(rb), fp);
		printf("%s %f\n", rb.nome, rb.media);
	}

	fclose(fp);
}
int main(){
	creaBinarioNegativo();
	leggiBinario();
	return 0;
}