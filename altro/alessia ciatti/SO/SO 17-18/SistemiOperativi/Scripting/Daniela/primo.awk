#!/usr/bin/awk -f

{
	printf("%s ", $0)
}

END {
	printf("\n")
}