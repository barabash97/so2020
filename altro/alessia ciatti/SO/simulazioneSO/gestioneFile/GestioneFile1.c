#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct{
    String nome;
    int flag;
}record_bin;

int creaBinario(String nomeFile, String frutto){
    String f1, f2, f3;
    String nome;
    int count;
    
    FILE*fp=fopen(nomeFile, "r");
    FILE*fp=fopen("blabla.dat","ab");
    
    while(!feof(fp)){
        int fg = 0;
        fscanf(fp,"%s %s %s %s",nome, f1, f2, f3);
        record_bin rb;
        
        if(frutto==f1){
            fg = 1;
            count++;
        }
        
        if(frutto==f2){
            fg = 1;
            count++;
        }
        
        if(frutto==f3){
            fg = 1;
            count++;
        }
        
        strcpy(rb.nome,nome);
        rb.flag = rb;
        fwrite(&rb,1,sizeof(record_bin),fp);
    }
    fclose(fp);
    fclose(fp2);
    return count;
}

void leggiBinario(){
    FILE*fp=fopen("fruttoPreferito.dat","rb");
    while(!feof(fp)){
        record_bin rb;
        fread(&rb,1,sizeof(record_bin),fp);
        printf("%s %d",rb.nome,rb.flag);
    }
    
    flcose(fp);
}

int main(void){
    creaBinario(".txt","pera");
    leggiBinario();
    exit(0);
}
