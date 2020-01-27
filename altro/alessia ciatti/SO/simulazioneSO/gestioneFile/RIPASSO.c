#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[30];

typedef struct {
    String nome;
    int flag;
}record_bin;

void creaBinario(){
    int count;
    int n1,n2,n3;
    String nome;
    
    FILE* fp = fopen("blabla.txt", "r");
    FILE* fp = fopen("bubu.dat", "ab");
    
    while(!feof(fp)){
        int fg = 0;
        fscanf(fp, "%s %d %d %d", nome, &n1, &n2, &n3);
        record_bin rb;
        
        //codice bla bla
        if(n1<0){
            count++;
            fg = 1;
        }
      //...
        strcpy(rb.nome, nome);
        rb.flag = fg;
        fwrtie(&rb, 1, sizeof(record_bin), fp2);
    }
    fclose(fp);
    fclose(fp2);
    exit(0);
}

void leggiBinario(){
    FILE* fp = fopen("bubu.dat", "rb");
    while(!feof(fp)){
        record_bin rb; v
        fread(&rb, 1, sizeof(record_bin), fp);
        printf("%s %d",rb.nome, rb.flag);
    }
    fclose(fp);
}

int main(void){
    creaBinario();
    leggiBinario();
    exit(0);
}
