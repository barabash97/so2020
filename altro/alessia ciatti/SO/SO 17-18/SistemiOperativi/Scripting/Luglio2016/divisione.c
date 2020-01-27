#include <stdio.h>

int main() /* divisione intera tra due numeri */ {

  int x,y,z;
  x = 79; y = 80;
  if ( z = 0 )
    printf("Can't divide by 0!\n"); 
  else
    x = div(y,z);
   printf("%d",x);
   exit(0); 
   }

int div(int y, int x) { 
   return (y/x); 
   }