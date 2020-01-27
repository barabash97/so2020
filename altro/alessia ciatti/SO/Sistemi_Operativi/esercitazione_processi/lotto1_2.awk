#!/bin/bash

{
	test = 0
	for(i=2; i<=NF; i++){
		if(($i<1)||($i>90)){
			test = 1
			break
		}
	}

	if(test==0) {
		for(i=2; i<=NF; i++){
			estrazioni[$i]++
		}
	}
}

END {

	ordina = "sort -k 1n"

	for(i in estrazioni) {
		printf("%d %d\n", i, estrazioni[i]) | ordina

	}
}