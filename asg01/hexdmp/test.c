#include<stdio.h>
#include<stdlib.h>

int main(){
  char *c;
  c=malloc(sizeof(char));
  *c='z';
  printf("%c",*c);
  return(0);
}


