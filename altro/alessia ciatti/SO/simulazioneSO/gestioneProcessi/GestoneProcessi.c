//COMANDO DA TERMINALE:
// gcc nomeFile.c -o test
// ./test

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv){
    pid_t pid;
    int n = 10;
    if(argc == 1)
        exit(1);
    
    if(n>10)
        exit(1);
    
    if(pid<0)
        exit(1);
    
    if(pid==0){
        int targa = atoi(argv[i]);
        if(targa>=1 && targa<=90){
            printf("Codice valido generato dal processo figlio %d: %s", getpid(), argv[i]);
            exit(0);
        }
        else{
            exit(0);
        }
        else{
            printf("Il padre %d ha gneerato il seguente figlio:%d", getpid(), pid);
            wait(NULL);
        }
    }
        
}
