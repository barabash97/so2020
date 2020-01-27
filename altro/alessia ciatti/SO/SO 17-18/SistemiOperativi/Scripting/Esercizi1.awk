#!/usr/bin/awk -f

{
	for (i=1; i <= NF; i++) {
		vettore[i] += $i
	}
}

END {
	for (j=1; j <= NF; j++) {
		printf("%d\n", vettore[j])
	}
}