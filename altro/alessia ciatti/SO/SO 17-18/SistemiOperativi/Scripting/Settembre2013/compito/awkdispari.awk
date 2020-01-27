#!/usr/bin/awk -f

BEGIN {
	FS = "\n"
	RS = "\n\n"
}

{
	test = 0

	for (i = 1; i <= NF; i++) {
		if ($i ~ /^Priority: optional/ || $i ~ /^Priority: extra/) {
			test = 1
		}
	}

	if (test) {
		for (j = 1; j <= NF; j++) {
			if ($j ~ /^Size: [0-9]+/) {
				split($j, a, " ")
				sum += a[2]
			}
		}
	}
}

END {
	printf("Somma totale: %d\n", sum)
}