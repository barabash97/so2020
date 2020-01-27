#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handler() {

	printf("\nhai sbagliato coglione??????eh!!eh!!!\n");
	printf("se hai sbagliato premi enne sennò esse! coglione!\n");
	char c;
	scanf("%c\n", &c);

	if(c!='y'||c!='Y'||c!='n'||c!='N'){
		printf("\nA COJONE DEVI RISPONNE BENE!!!\n");
		c=getchar(); 
		if(c=='y'||c=='Y')
			exit(0);
		else signal(SIGINT, handler);
	}

}

int main() {

	signal(SIGINT, handler);

	while(1) {

		printf("ahahahahahaha te puzza il culo!! ahahahahah\n");

		pause();
	}

}