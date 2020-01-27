#!/bin/bash

{
	test = 0;

	for(i=2; i<8; i++) {
		if(($i<1) || ($i>90)) {
			test = 1
			break
	}
}

	if(test == 0)
		for(i=2; i<8; i++)
			num[$i]++
}

END {
	ordina = "sort -k 1n"
	print""
	print"-----------"
	for(i in num)
		printf("%d %d\n", i, num[i]) | ordina
	print"" 


}