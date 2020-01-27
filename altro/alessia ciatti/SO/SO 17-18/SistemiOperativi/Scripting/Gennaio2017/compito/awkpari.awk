#!/usr/bin/awk -f

BEGIN {
	printf("------------------------------------------------------------------------------\n")
	printf("User\t\tUID\t\tGID\t\tHome Directory\t\tShell\n")
	printf("------------------------------------------------------------------------------\n")
	FORMAT = "%-18s%-14s%-14s%-14s%-14s"
	FS = ":"
}

{
	if (NR <= 12) {
		test = 0
		printf FORMAT, $1, $3, $4, $6, $7 "\n"

		for(i = 1; i <= NR; i++) {
			if (gid[i] == $4) {
				contatore[i] += 1
				test = 1
			}
		}

		if (test == 0) {
			gid[NR] = $4
			contatore[NR] = 1
		}
	}
}

END {
	for(j = 0; j <= NR; j++) {
		if (gid[j] && contatore[j] >= 2) {
			printf("GID: %s with %d users\n", gid[j], contatore[j])
		}
	}
}

#grep -E '^[0-8]{3}-[0-8]{3}-[0-8]{4} x[0-9]{4}$' indirizzi.txt