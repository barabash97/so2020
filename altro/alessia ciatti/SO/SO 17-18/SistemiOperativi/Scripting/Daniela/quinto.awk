#!/usr/bin/awk -f

{
	
	if ($3>$4)
		classifica[$1] +=3

	else if ($4>$3)
		classifica[$2] +=3
	
	else {
		classifica[$1]+=1
		classifica[$2]+=1
	}					

}


END {
	ordina = "sort -k 2nr"
	for (k in classifica){
		printf ("%s %d\n", k, classifica[k]) | ordina
	}
}