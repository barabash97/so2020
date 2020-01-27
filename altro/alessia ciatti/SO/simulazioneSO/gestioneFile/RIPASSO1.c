#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct{
    String nome;
    int flag;
}record_bin;

int creaBinario(String nomeFile, String frutto){
    String f1,f2,f3;
    String nome;
    int count = 0;
    FILE* fp = fopen(nomeFile, "r");
    FILE* fp2 = fopen("blabla.dat","ab");
    
    while(!feof(fp)){
        int fg = 0;
        fscanf(fp, "%s %s %s %s", nome, f1, f2, f3);
        record_bin rb;
        
        if(f1 == frutto){
            fg = 1;
            count++;
        }
        
        if(f2 == frutto){
            fg = 1;
            count++;
        }
        
        if(f3 == frutto){
            fg = 1;
            count++;
        }
        
        strcpy(rb.nome, nome);
        rb.flag = fg;
        
        fwrite(&rb,1,sizeof(record_bin),fp2);
    }
    fclose(fp);
    fclose(fp2);
    return count;
}

void LeggiBinario(){
    FILE *fp = fopen("blabla.dat","rb");
    while(!feof(fp)){
        record_bin rb;
        fread(&rb,1,sizeof(record_bin), fp);
        printf("%s %d\n", rb.nome, rb.flag);
    }
    fclose(fp);
}

int main (void){
    creaBinario("blabla.txt","pero");
    LeggiBinario();
    exit(0);
}
