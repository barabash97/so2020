#!/bin/bash

BEGIN {

} 

{
	test = 0
	for(i=2; i<=NF; i++) {
		if($i<1 || $i>90)
			test = 1
			break
	}
	if(test == 0)
		for(j=2; j<=NF; j++) {
			count[$j]++
		}

}

END {

	for(i in count) {
		printf("%d %d\n", i, count[i])
	}

}