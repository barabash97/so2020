#!/usr/bin/awk

BEGIN{
printf("Calcolo stipendio massimo per mese:\n\n")
}

{
for(i=2;i<=NF;i++){
if(max[i]<$i){
max[i] = $i
}
}
}

END{
for(i in max){
if(i==2){
mese = "Gennaio"
}
if(i==3){
mese = "Febbraio"
}
if(i==4){
mese = "Marzo"
}
if(i==5){
mese = "Aprile"
}
if(i==6){
mese = "Maggio"
}
if(i==7){
mese = "Giugno"
}
if(i==8){
mese = "Luglio"
}

printf("Nel mese di %s lo stipendio maggiore è:   %d\n", mese, max[i])
}
}
