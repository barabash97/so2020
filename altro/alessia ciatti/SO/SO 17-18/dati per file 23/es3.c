#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void INThandler(int sig) {
    char c;
    signal(sig, SIG_IGN);
    printf("\nForse hai premuto per sbaglio Ctrl-C?\nVuoi realmente sospendere l'esecuzione [y/n]?");
    c = getchar();
    if (c == 'y' || c == 'Y')
        exit(0);
    else
        signal(SIGINT, INThandler);
}


int main(void) {
        signal(SIGINT, INThandler);
    while (1)
        pause();
}