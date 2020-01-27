#!/bin/bash 

BEGIN {
	printf("---------------------\n")
	printf("Numero Estrazioni\n")
	printf("---------------------\n")
}

{
	test = 0
	for ( i=2; i<8; i++)
		if(($i<1) || ($i>90)) {
			test = 1
			break
		}

	if(test == 0)
		for(i=2;i<8; i++)
			estrazioni[$i]++
}

END {
	ordina = "sort -k 1n"
	print ""
	print "-----------------"
	for(i in estrazioni)
		printf("%d %d\n", i, estrazioni[i] )| ordina
	print ""
}