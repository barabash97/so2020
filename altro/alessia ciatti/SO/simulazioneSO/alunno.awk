#!/usr/bin/awk

BEGIN{
printf("Codice alunno : media dei suoi voti\n")
}

{
test = 0
voto = 0
for(i=2;i<NF;i++){
if($i <19)
voto++
}
if(voto<2){
for(i=2;i<NF;i++){
count[$1]++
somma[$1]+=$i }
}	
}

END{
ordina = "sort -k 1n"
for(i in count){
printf("%s %d\n", i, somma[i]/count[i]) | ordina
}
}
