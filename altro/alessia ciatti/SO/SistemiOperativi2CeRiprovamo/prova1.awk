#!/bin/bash

BEGIN {
	printf("\n\nQuesto programma calcola la somma\n");
	printf("Di tutte le matricole pari\n");
	printf("---------------------------------\n");
	i = 1;
}

{
	if($2%2==0){
		count += $2;
		quali[i] = $1;
		i++;
	}

}

END {

	printf("\nLe persone con la matricola pari sono \n")
	for(i=0; i<NR; i++) {
		if(quali[i]!="")
			printf("%s, ", quali[i] );
	}
	printf("\nLa somma delle loro matricole è %d\n\n", count);
	printf("------------------------------------------\n");

}