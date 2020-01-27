#!/usr/bin/awk -f

BEGIN {
	FS=";"
}

{
	for (i=1; i<=NF; i++){
		if ($i == "Luigi")
			cont++
	}
}

END {
	printf ("%d \n", cont)
}