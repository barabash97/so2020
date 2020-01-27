#!usr/bin/awk

BEGIN{
printf("Salari totali di un impiegato:\n")
}

{
for(i=2;i<8;i++){
if($i<0)
somma[$1]+= $i
}
}

END{
for(i in somma)
printf("%s, %d\n", i, somma[i])
}