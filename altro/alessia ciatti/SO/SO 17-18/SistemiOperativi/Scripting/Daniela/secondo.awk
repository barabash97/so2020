#!/usr/bin/awk -f

{
	for (i=1; i<=NF; i++){
		printf("%s ", $i)
		if ($i == "crine.")
			exit
	}
	printf("\n")
}
END{
	printf("\n")
}