#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Stringa[30];

typedef struct{
    Stringa nome;
    double media;
}record_bin

void creaBinarioNegativo(){
    int n1, n2, n3;
    Stringa nome;
    double somma,count;
    
    FILE* fp = fopen("nomi.txt", "r");
    FILE*fp = fopen("persone.dat", "ab");
    
    while(!feof(fp)){
        double media;
        
        fscanf(fp, "%s %d %d %d", nome, &n1, &n2, &n3)
        record_bin rb;
        if(n1<0){
            somma +=n1;
            count ++;
        }
        if(n2<0){
            somma +=n2;
            count ++;
        }
        if(n3<0){
            somma +=n3;
            count ++;
        }
        media = somma/count;
        strcpy(rb.media, media);
        rb.nome = nome;
        
        fwrite(&rb, 1, sizeof(record_bin), fp2);
    }
    fclose(fp);
    fclose(fp2);
}

void leggiBinario(){
    FILE*fp = fopen("persone.dat", "rb");
    while(!feof(fp)){
        fread(&rb, 1, sizeof(record_bin), fp);
        printf("%d %s\n", rb.nome, rb.media);
    }
    fclose(fp);
}
int main(void){
    creaBinarioNegativo();
    leggiBinario();
    exit(0);
}
