#!/usr/bin/awk

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
