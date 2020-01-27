#!/usr/bin/awk -f

{
	test = 0

	for (i=2; i <= NF; i++) {
		for (j = i+1; j <= NF; j++) {
			if ($i == $j)
				test = 1
		}
	}

	if (test == 1)
		non_valide[NR] = $1
}

END {
	for (k=1; k <= NR; k++) {
		if (non_valide[k]) 
			printf("%s\n", non_valide[k])
	}
}