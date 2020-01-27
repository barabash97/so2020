#!/usr/bin/awk

BEGIN{
printf("Numero estrazioni:\n")
}

{
test = 0
for(i=2;i<8;i++)
if($i<1 && $i>90){
test = 0
break
}
else{
estrazioni[$i]++
}
}

END{
ordina = "sort -k 1n"
if(test == 0)
for(i in estrazioni)
printf("%d %d\n", i, estrazioni[i]) | ordina
}
