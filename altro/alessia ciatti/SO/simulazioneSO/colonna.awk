#!/usr/nin/awk

BEGIN{
printf("Calcolo media stipendi negativi per mese:\n")
}

{
for(i=2;i<=NF;i++){
if($i<0){
somma[i] += $i
count[i] ++
media[i] = somma[i]/count[i]
}
}
}

END{
for(i in media){
if(i == 2){
mese = "Gennaio"
}
if(i == 3){
mese = "Febbraio"
}
if(i == 4){
mese = "Marzo"
}
if(i == 5){
mese == "Aprile"
}
if(i == 6){
mese == "Maggio"
}
if(i == 7){
mese == "Giugno"
}
printf("%s media: %0.1f valori contati:%d\n", mese, media[i], count[i])
}
}
