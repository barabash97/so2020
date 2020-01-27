#!/usr/bin/awk

BEGIN{
printf("Valore massimo per dipendente\n")
}

{
max[$1] = $2
for(i=3; i<=NF; i++){
if(max[$1]<$i){
max[$1] = $i
}
}
}
END{
for(i in max){
printf("%s %d\n", i, max[i])
}
}
