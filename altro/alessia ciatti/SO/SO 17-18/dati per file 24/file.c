#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char Stringa[30];

typedef struct {
    Stringa nome;
    int flag;
} record_bin;


int creaBinario (Stringa nome_file, Stringa frutto){
    int fg, count;
    Stringa nome, f1, f2, f3;
    FILE* fp = fopen(nome_file,"r");
    FILE* fp2 = fopen("frutto_preferito.dat","ab");
    
    while (!feof(fp)) {
        fscanf (fp, "%s %s %s %s\n", nome, f1, f2, f3);
        record_bin rb;
        fg = (strcmp(frutto,f1)==0) || (strcmp(frutto,f2)==0) || (strcmp(frutto,f3)==0);
        
        if (fg) count++;
        
        strcpy(rb.nome, nome);
        rb.flag = fg;
        
        fwrite(&rb, 1, sizeof(record_bin), fp2);
        
    } 
    
    fclose(fp);
    fclose(fp2);
    
    return count;
    
}

void leggibinario(){
    FILE* fp = fopen("frutto_preferito.dat","rb");
    
    while (!feof(fp)) {
        record_bin rb;
        fread(&rb, 1, sizeof(record_bin), fp);
        printf("%s %d\n",rb.nome,rb.flag);
        
    }
    
    
    fclose(fp);
}
        
        
int main(void) {
    creaBinario("persone_frutta.txt","pera");
    leggibinario();
    exit(0);

       }
