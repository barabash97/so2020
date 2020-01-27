#!/bin/bash

{
	for(i=1; i<=NF; i++) 
		count[i] += $i;
}

END {

	for(i=1; i<=NF; i++) {
		printf("%d ", count[i]);
	}
	printf("\n");
}