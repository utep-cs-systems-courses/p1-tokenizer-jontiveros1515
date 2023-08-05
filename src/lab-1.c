#include <stdio.h>
#include <string.h>

int main(void){
  char type[30];

  printf("enter something\n");

  fgets(type, sizeof(type),stdin);

  printf("you typed: %s", type); 
}

