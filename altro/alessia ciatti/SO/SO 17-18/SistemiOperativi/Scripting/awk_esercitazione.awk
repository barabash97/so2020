#!/usr/bin/awk -f
 
{
	test = 1

	for(i=2; i <= NF; i++) {
		if ($i < 0 || $i > 90)
			test = 0
	}

	if (test) {
		for (i=2; i <= NF; i++)
			cont[$i]++
	}
}

END {
	for (i=1; i <= 90; i++) {
		if (cont[i])
			printf("%d %d\n", i, cont[i])
	}
}