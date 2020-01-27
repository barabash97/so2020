#!bin/bash

BEGIN {
	printf("\n\nQuesto programma legge tutte le tabelline\n");
	printf("Fino a quella del 10\n");
	printf("E stampa a schermo tutti i multipli di 3\n");
	printf("Stampa 0 se non lo è\n");
	printf("-------------------------------------------------------\n\n");
	o = 0
}

{
	for(i=1; i<=NF; i++) {
		if($i%3 == 0) {
			count[NR, i]=$i;
		}
	}
}

END {

	for(i=0; i<=NR; i++) {
		for(j=1; j<=NF; j++) {
			printf("%d ", count[i, j]);
		}
		printf("\n");
	}
	printf("\n\n--------------------------------------------------------\n\n");

}