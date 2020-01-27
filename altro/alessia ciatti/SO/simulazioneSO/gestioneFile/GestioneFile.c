#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[30];

typedef struct {
    Stringa nome;
    int flag;
} record_bin

int creaBinario (Stringa nome_file, int numero, int pos){
    
    FILE* fp = fopen(nome file, "r");
    FILE* fp2 = fopen("nomefile.boh", "ab");
    
    while(!fopen(fp)){
        int fg = 0;
        fscanf(fp, "%s %d %d %d", nome, &n1; &n2,&n3);
        record_bin rb;
        
        //CODICE
        
        strcpy(rb.nome, nome);
        rb.flag = fg;
        
        fwrite(&rb, sizeof(record_bin), fp2);
    }
    fclose(fp);
    fclose(fp2);
    return count;
}

void leggiBinario(){
    FILE *fp = fopen("file.dat", "rb");
    while(!feof(fp)){
        record_bin rb;
        fread(&rb,1, sizeof(record_bin), fp);
        printf("%s %d", rb.nome, rb.flag);
    }
    fclose(fp);
}

int main(void){
    creaBinario("persone.txt",40,2);   //datoDaLui
    leggiBinario();
    exit(0);
}
