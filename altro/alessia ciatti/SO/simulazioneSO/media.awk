#!/usr/bin/awk

BEGIN{
printf("Media alunni con meno di due voti inferiori a 19:\n")
}

{
test = 0
for(i=2;i<8;i++)
if($i<19){
voto++
}
for(i=2;i<8;i++){
if(voto>2){
count[$i]++
somma[$i] += $i
}
}
}

END{
ordina = "sort -k 1n"
for(i in count)
printf("%s %d\n",i, somma[i]/count[i]) | ordina
}
