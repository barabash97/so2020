#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char stringa[30];

typedef struct{
    stringa nome;
    double media;
}record_bin;

void creaBinario(int soglia){
    int n1, n2, n3;
    stringa nome;
    int somma,count;
    
    FILE*fp = fopen("nomi.txt","r");
    FILE*fp2 = fopen("persone.dat","ab");
    
    while(!feof(fp)){
        double media = 0;
        fscanf(fp,"%s %d %d %d", nome, &n1, &n2; &n3);
        record_bin rb;
        
        if(n1>soglia){
            count++;
            somma += n1;
        }
        if(n2>soglia){
            count++;
            somma+=n2;
        }
        if(n3>soglia){
            count++;
            somma+=n3;
        }
        
        media = somma/count;
        strcpy(rb.nome, nome);
        rb.media = media;
        
        fwrite(&rb,1,sizeof(record_bin),fp2);
    }
    fclose(fp);
}

void leggiBinario(){
    FILE* fp= fopen("persone.dat","rb");
    while(!feof(fp)){
        record_bin rb;
        fread(&rb,1,sizeof(record_bin),fp);
        printf("%s %0.1f", rb.nome, rb.media);
    }
    flcose(fp);
}

int main(void){
    creaBinario(4);
    leggiBinario();
    exit(0);
}
