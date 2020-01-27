#!/usr/bin/awk

BEGIN{
printf("Alunno con media:\n")
}

{
for(i=2;i<8;i++){
if($i<19)
voto++
}
for(i=2;i<8;i++){
if(voto<2){
somma[$1] +=$i
count++
}
}
}

END{
for(i in count){
printf("%s %d\n", i, somma[i]/count[i])
}
}
