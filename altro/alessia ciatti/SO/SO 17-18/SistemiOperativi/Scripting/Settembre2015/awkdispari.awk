#!/usr/bin/awk -f

/Homepage: / {
	test = 0

	for (i=1; i <= NR; i++) {
		if (homepage[i] == 2) {
			contatore[i] += 1
			test = 1
		}
	}

	if (test == 0) {
		homepage[NR] = 2
		contatore[NR] = 1
	}

}

END {
	ordina = "sort -n"
	for (k=0; k <= NR; k++) {
		if (homepage[k])
			printf("%d %s\n", contatore[k], homepage[k]) | ordina
	}

}

#/Homepage: http:\/\/(.*)[.](.*)\// 