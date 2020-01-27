#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char String[30];

typedef struct{
    String nome;
    int flag;
}record_bin;

int creaBinario(String nomeFile, int pos, int num){
    int count;
    int n1,n2,n3;
    String nome;
    
    FILE* fp = fopen(nomeFile, "r");
    FILE* fp2 = fopen("blabla.dat", "ab");
    
    while(!feof(fp)){
        int fg = 0;
        fscanf(fp,"%s %d %d %d", nome, &n1, &n2, &n3);
        record_bin rb;
        
        //Codie blabla
        
        strcpy(rb.nome, nome);
        rb.flag = fg;
        fwite(&rb,1,sizeof(record_bin),fp2);
    }
    fclose(fp);
    fclose(fp2);
    return count;
}

void leggiBinario(){
    FILE*fp = fopen("blabla.dat", "rb");
    while(!feof(fp)){
        record_bin rb;
        fread(&rb,1, sizeof(record_bin), fp);
        printf("%s %d\n", rb.nome, rb.flag);
    }
    fclose(fp);
}
