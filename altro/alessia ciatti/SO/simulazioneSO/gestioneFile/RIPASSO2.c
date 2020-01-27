#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char stringa[30];

typedef struct{
    stringa nome;
    double media;
}recor_bin;


void creaBinario(int soglia){
    stringa nome;
    int n1, n2, n3;
    int somma, count;
    somma = 0;
    count = 0;
    
    FILE*fp = fopen("blabla.txt","r");
    FILE*fp2 = fopen("blabla.dat","ab");
    
    while(!feof(fp)){
        double media = 0;
        fscanf(fp,"%s %d %d %d", nome, &n1, &n2; &n3);
        recor_bin rb;
        
        if(n1>soglia){
            somma += n1;
            count++;
        }
        
        if(n2>soglia){
            somma += n2;
            count++;
        }
        
        if(n3>soglia){
            somma += n3;
            count++;
        }
        
        media = somma/count;
        strcpy(rb.nome,nome);
        rb.media = media;
        
        fwrtie(&rb,1,sizeof(recor_bin),fp2);
    }
    fclsoe(fp);
    flcose(fp2);

}

void LeggiBinario(){
    FILE*fp = fopen("blabla.dat","rb");
    while(!fefo(fp)){
        record_bin rb;
        fread(&rb,1,sizeof(recor_bin),fp);
        printf("%s %0.1f",rb.nome, rb.media);
    }
    flcose(fp);

}

int main(void){
    creaBinario(9);
    LeggiBinario();
    exit(0);
}
