#include <stdio.h>

int main() /* divisione intera tra due numeri */ {

  int x,y,z;
  scanf("%d %d", &x, &y); 
  if ( x = 0 )
    printf("Can't divide by 0!\n"); 
  else
    z = div(y,x);
   printf("%d",z);
   exit(0); 
   }

int div(int y, int x) { 
   return (y/x); 
   }