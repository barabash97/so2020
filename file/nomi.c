#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char Stringa[30];

typedef struct {
    Stringa nome;
    float media;
} record_binario;

void creaBinarioNegativo() {
    FILE *fp = fopen("nomi.txt", "r");
    FILE *fp2 = fopen("persone.dat", "wb");

    Stringa nome;

    if (fp == NULL) {
        printf("file non esiste\n");
        exit(0);
    }

    while (!feof(fp)) {
        int count = 0;
        int somma = 0;
        int a1, a2, a3 = 0;
        fscanf(fp, "%s %d %d %d\n", nome, &a1, &a2, &a3);

        if (a1 < 0) {
            somma += a1;
            count++;
        }

        if (a2 < 0) {
            somma += a2;
            count++;
        }

        if (a3 < 0) {
            somma += a3;
            count++;
        }

        if (count > 0) {
            record_binario rb;
            strcpy(rb.nome, nome);
            rb.media = (float) (somma / count);
            fwrite(&rb, sizeof(rb), 1, fp2);
        }
    }

    fclose(fp);
    fclose(fp2);
}

void leggiBinario() {
    FILE *fp = fopen("persone.dat", "rb");
    if (fp == NULL) {
        printf("file non esiste\n");
        exit(0);
    }
    printf("\nSTAMPA\n\n\n");
    while (!feof(fp)) {
    
        record_binario rb;
        fread(&rb, sizeof(rb), 1, fp);
        printf("%s %.2f\n", rb.nome, rb.media);
    }

    fclose(fp);
}

int main() {
    creaBinarioNegativo();
    leggiBinario();
    return 0;
}