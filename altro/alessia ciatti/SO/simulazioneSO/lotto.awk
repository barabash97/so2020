#!/usr/bin/awk

BEGIN{
printf("Numero ordinazioni:\n")
}

{
test=0
for(i=2;i<8;i++){
if($i<0 || $i>90){
test=1
break
}
else{
estrazioni[$i]++
}
}
}

END{
ordina = "sort -k 1n"
for(i in estrazioni){
printf("%d %d\n", i, estrazioni[i]) | ordina
}
}
