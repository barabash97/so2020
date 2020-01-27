#!/usr/bin/awk -f

{
	nomi[NR]=$0
}

END{
	for (i=NR; i>=1; i--){
		printf("%s \n", nomi[i])
	}
}