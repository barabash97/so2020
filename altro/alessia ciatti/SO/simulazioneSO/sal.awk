#!/usr/bin

BEGIN{
printf("Codice impiegato numero salari:\n")
}

{
for(i=2;i<8;i++){
if($i<0)
count[$1]++
}
}

END{
for(i in count)
printf("%s %d\n", i , count[i])
}