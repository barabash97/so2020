#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void){
    
    pid_t pid;
    
    for(int i =0;i<10;i++){
        pid=fork();
        
        if(pid<0){
            printf("fork");
            exit(2);
        }
        if(pid==0){
            sleep(1);
            printf("Figlio: %d\n", i+1);
            sleep(1);
            exit(101+i);
        }
    }
        for(int i=0;i<10;i++){
            int status;
            pid = wait(&status);
            printf("Terminato processo con numero:%d\n", WEXITSTATUS(status));
            
        }

}
