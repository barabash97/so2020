#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    pid_t pid;
    int status = 0;
    
    if(argc==1)
        exit(1);
    
    for(int i=1;i<argc;i++){
        pid = fork();
        if(pid==0){
            if(atoi(argv[i])<=0 && atoi(argv[i])>=90){
                printf("Codice valido associato al figlio %d: %s", getpid(), argv[i]);
                exit(0);
            }
            else
                exit(0);
        }
            else{
                pid = wait(&status);
                printf("%d ha creato %d", pid, getpid());
                WEXISTATUS(status);
            }
    }
}
