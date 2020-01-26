#!/usr/bin/awk -f

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
}#!/usr/awk/bin -f 

BEGIN{
printf("Calcolo media stipendi per dipendente:\n");
}

{
for(i=2;i<=NF;i++){
if($i<0){
somma[$1] += $i
count[$1] ++
media[$1] = somma[$1]/count[$1]
}
}
}

END{
for(i in media){
printf("La media degli stipendi negativi di %s è di:  %0.1f\n", i, media[i])
}
}