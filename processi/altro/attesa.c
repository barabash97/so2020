#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
int main(void){
    
    pid_t pid;
    pid = fork();
    int status;
    
    if(pid<0){
        printf("fork");
        exit(2);
    }
    if(pid==0){
        printf("%d %d\n", getpid(), getppid());
        exit(24);
    }
    else{
        pid = wait (&status);
        printf("il pid del figlio è %d, e lo stato è %d\n", pid, WEXISTATUS(status));
    }
}
