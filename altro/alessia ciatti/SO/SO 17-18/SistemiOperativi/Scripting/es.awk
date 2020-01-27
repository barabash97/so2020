#!/usr/bin/awk -f


BEGIN {
	print "\n.................."
	FORMAT = "\t%-18s%s\n"
	printf FORMAT,"SQUADRE","PUNTI"
}

{
	if ($3 > $4} {
		c[$1] += 3; c[$2] += 0
	}
	else if ($3 < $4) {
		c[$1] += 0; c[$2] += 3
	}
	else if ($3 == $4) {
		c[$1] += 1; c[$2] += 1
	}
}


