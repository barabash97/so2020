#!/usr/bin/awk -f

BEGIN {
	FS = ";"
}

{
	test = 0

	for (i=0; i <= NR; i++) {
		if (dipartimenti[i] == $1) {
			test = 1
			spese[i] += $2
			contatore[i] += 1
		}
	}

	if (test == 0) {
		dipartimenti[NR] = $1
		spese[NR] = $2
		contatore[NR] = 1
	}

}

END {
	for (k=1; k <= NR; k++) {
		if (dipartimenti[k] && spese[k])
			printf("%s: %d\n", dipartimenti[k], spese[k]/contatore[k])
	}

	media_max = spese[1]/contatore[1]

	for (j=1; j <= NR; j++) {
		if (spese[j]/contatore[j] > media_max)
			media_max = spese[j]/contatore[j]
	}

	printf("Media massima: %d\n", media_max)
}

#sed '/.*:.*:.*:.*:.*Service .*/s?/var/empty?/home/empty?' passwd.txt