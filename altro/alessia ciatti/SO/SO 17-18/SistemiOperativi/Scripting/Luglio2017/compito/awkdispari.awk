#!/usr/bin/awk -f

{
	test = 0
	for (i=2; i <= NF; i++) {
		if ($i > 23)
			test = 1
	}

	if (test) {
		somma = 0
		for (k=2; k <= NF; k++) {
			somma += $k
		}

		media = somma/(NF-1)
		medie[NR] = $1 " " media
	}
	else {
		medie[NR] = 0
	} 
}

END {
	for (j=1; j <= NR; j++) {
		if (medie[j])
			printf("%s\n", medie[j])
	}
}

#grep -E '.{1,3}.* of [AEIOUaeiou].*[,]$' toBe.txt