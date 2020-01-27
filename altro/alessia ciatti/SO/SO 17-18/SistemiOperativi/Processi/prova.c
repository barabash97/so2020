#include <stdio.h> 
#include <signal.h>
#include <unistd.h> 
#include <stdlib.h>
int val = 10;
void handler(int sig){
 val += 8;
}
int main(void){
 pid_t pid;
 signal(SIGCHLD, handler);
 val++;
 if ((pid = fork()) == 0) {
 printf("dfhsdhs %d\n", val);
 val -= 3;
 printf("asdrhkl %d\n", val);
 exit(0);
 }
 else if (pid > 0) {
 int status;
 waitpid(pid, NULL, 0);
 printf("val = %d\n", val);
 exit(0);
}
}