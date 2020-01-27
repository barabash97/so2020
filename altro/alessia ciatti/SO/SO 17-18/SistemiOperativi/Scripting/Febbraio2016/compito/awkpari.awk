#!/usr/bin/awk -f

BEGIN {
	FS = ":"
}

{
	somma = 0
	for (i=2; i <= NF; i++) {
		somma += $i
	}

	persona[NR] = $1
	media[NR] = somma/(NF-1)
}

END {
	for (k=1; k <= NR; k++) {
		printf("%s: %d\n", persona[k], media[k])
	}

	media_max = media[1]

	for(j=2; j <= NR; j++) {
		if (media[j] > media_max)
			media_max = media[j]
	}

	printf("Max: %d\n", media_max)
}

#sed /.*:.*:.*:.*:.*Daemon:.*/s/false/STOP/ passwd.txt