#!/bin/bash

BEGIN {
	printf("Questo programma dovrebbe leggere tutte le matricole\n");
	printf("E stampare a video la più alta e la più bassa\n");
	printf("----------------------------------------------------\n");
	min = 999999999;
	max = 0;
}

{
	for(i=1; i<=NF; i++) {

		if(max<$2) {
			max = $2;
			propMax = $1;
		}
		if(min>$2) {
			min = $2;
			printf("%s %d\n", $1, $2);
			propMin = $1;
		}
	}
}

END {
	printf("La matricola più alta è di quel coglione di %s ed è %d \n", propMax, max);
	printf("La matricola più bassa invece è di %s ed è %d \n", propMin, min);
	printf("----------------------------------------------------------------\n");
}	