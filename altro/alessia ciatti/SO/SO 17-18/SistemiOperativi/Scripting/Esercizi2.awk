#!/usr/bin/awk -f

/^A:/ {
	
	for (i = 1; i < NF; i++) {
		if ($i !~ /^[0-9]+/) printf ("%s ", $i) >> "doppio.txt"
		else printf ("%d ", $i * 2) >> "doppio.txt"
	}

	printf("\n") >> "doppio.txt"

}

/^[B-Z]:/ {
	print >> "doppio.txt"
}