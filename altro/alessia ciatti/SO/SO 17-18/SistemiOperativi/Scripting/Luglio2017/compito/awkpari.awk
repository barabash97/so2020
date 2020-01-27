#!/usr/bin/awk -f

{
	somma = 0

	for (i=2; i <= NF; i++)
		somma += $i

	media = somma/(NF-1)

	if (media > 24) {
		min = $2
		max = $2

		for(k=2; k < NF; k++) {
			if ($k < min)
				min = $k
			if ($k > max)
				max = $k
		}

		risultato[NR] = $1 " " min " " max
	}
}

END {
	for(j=1; j <= NR; j++) {
		if (risultato[j]) {
			printf("%s\n", risultato[j])
		}
	}
}

#grep -E '^[^AEIOUa-z0-9].*[.:] .. .*;$'