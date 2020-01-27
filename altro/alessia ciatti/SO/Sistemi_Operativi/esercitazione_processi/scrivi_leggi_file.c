/* SCRIVERE scrivi_leggi_file.c  PER IL CONTROLLO DEI PROCESSI IN
   CUI UN PROCESSO PADRE GENERA UN PROCESSO FIGLIO:
   		-IL PROCESSO PADRE:
   			1. STAMPA IN OUTPUT IL MESSAGGIO "[padre] inserimento
   			   stringa nel file"
   			2. POI SCRIVE LA STRINGA "sono il padre" NEL FILE DI
   			   TESTO testo.txt (APERTO PRIMA DI GENERARE IL PROCESSO
   			   FIGLIO)
   			3. STAMPA IN OUTPUT IL VALORE DELL'OFFSET DEL FILE (TRAMITE
   			   LA FUNZIONE ftell)
   			4. STAMPA IN OUTPUT IL MESSAGGIO "[padre] chiudo il file e 
   			   lo cancello" E SUCCESSIVAMENTE CHIUDE E RIMUOVE IL FILE
   			   CREATO; IN LINGUAGGIO C ESISTE LA FUNZIONE 
   			   int remove(char* nomefile)
   		-IL PROCESSO FIGLIO:
   			1. STAMPA IN OUTPUT IL MESSAGGIO "[figlio] attendo 4 secondi"
   			2. ATTENDE 4 SEC E POI STAMPA IN OUTPUT IL VALORE DELL'OFFSET
   			   DEL FILE (TRAMITE ftell) CREATO DAL PROCESSO PADRE
   			3. RIPORTA IL FILE ALL'INIZIO E STAMPA IN OUTPUT IL CONTENUTO
   			   DEL FILE
   			4. STAMPA IN OUTPUT IL MESSAGGIO "[figlio] chiudo il file" E
   			   SUCCESSIVAMENTE CHIUDE IL FILE
   			5. USCIRÀ DAL PROGRAMMA (exit status 0)
   IN CASO DI ERRORE(NELLA CREAZIONE DEL PROCESSO FIGLIO) CATTURARE L'ERRORE
   STAMPANDO UN MESSAGGIO DI ERRORE(perror()) E POI USCIRE DAL PROGRAMMA
   (exit status 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	pid_t pid;

	int i;
	char c;

	//SI APRE IL FILE IN SCRITTURA

	FILE * textFile = fopen("./test.txt", "w+");

	if(textFile!=NULL) {
		//SI RICHIAMA LA FUNZIONE FORK
		//PER CREARE UN FIGLIO

		pid = fork();
		
		if(pid<0) {
			perror("fork");
			exit(2);
		}
		
		if(pid==0) {

			printf("[figlio] attendo 4 secondi...\n");
			sleep(4);

			printf("\n[figlio] Posizione attuale puntatore file: %ld\n", ftell(textFile));

			// SI RIPORTA ALL'INIZIO IL CURSORE

			fseek(textFile, 0, SEEK_SET);

			//SI STAMPA IL CONTENUTO TESTUALE DEL FILE,
			//CARATTERE PER CARATTERE

			printf("[figlio] Stampo contenuto del file di testo: ");

			c=fgetc(textFile);

			while(!feof(textFile)) {

				printf("%c", c);
				c = fgetc(textFile);
			}

			printf("\n");

			//SI CHIUDE IL FILE APERTO E SI ESCE DAL PROCESSO

			printf("[figlio] Chiudo il file ed esco.\n");
			fclose(textFile);
			exit(0);

			//SI NOTA CHE, NONOSTANTE IL PROCESSO PADRE ABBIA
			//GIÀ CANCELLATO IL FILE, IL PROCESSO FIGLIO È
			//COMUNQUE IN GRADO DI LEGGERNE IL CONTENUTO!
		}

		else {

			//SONO IL PADRE
			printf("[padre] Inserimento stringa nel file\n");
			fprintf(textFile, "%s\n", "sono il padre");

			//SI STAMPA LA POSIZIONE ATTUALE DEL CURSORE SUL FILE

			printf("[padre] Posizione attuale puntatore file: %ld\n", ftell(textFile));

			//SI CHIUDE IL FILE APERTO E LO SI CANCELLA DAL FILESYSTEM

			printf("[padre] Chiudo il file e lo cancello\n");
			fclose(textFile);
			remove("test.txt");
		} //FINE ELSE PADRE
	}//FINE ELSE SUL CONTROLLO DEL FILE

	else {
		printf("Errore! Non è stato possibile aprire il file.\n");
	}	
}