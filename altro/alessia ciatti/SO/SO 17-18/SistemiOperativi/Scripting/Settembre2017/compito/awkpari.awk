#!/usr/bin/awk -f

{
	test = 1

	for (x = 2; x <= NF; x++) {
		if ($x < 1 || $x > 90) 
			test = 0
	}


	if (test) {
		for (i = 2; i <= NF; i++) {	
			if (numeri[$i])
				numeri[$i] += 1
			else
				numeri[$i] = 1
		}
	}
}

END {
	for (j = 1; j <= 90; j++) {
		if (numeri[j])
			printf("%d %d\n", j, numeri[j])
	}
}