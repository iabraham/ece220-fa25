#include <stdio.h>


int main(void){
  int x=10;

  printf("First while.\n");
  while (x < 10)
    printf("x=%d\n", x++); 


  printf("Second while.\n");
  do  
    printf("x=%d\n", x++); 
  while (x < 10); 

  return 0;
}

