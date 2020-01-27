#!/bin/bash

BEGIN{

}

{	
	test = 0

	for(i=2; i<=NF; i++) {
		for(j=i+1; j<=NF; j++){
			if($i==$j) {
				test = 1
			}
		}
	}

	if(test==0) {
		estra[NR] = $1
	}

}

END {

	for(i in estra) {
			print estra[i]
		}

}