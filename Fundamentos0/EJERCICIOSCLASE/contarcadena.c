#include<stdio.h>
int cuenta(char arreglo[]);


int main(void){
  char arreglo[100];
  scanf("%[^\n]", arreglo);
  cuenta(arreglo);
  return 0;
}

int cuenta(char arreglo[]){
  int y, x;
  x=0;
  for(y=0;arreglo[y]!='\0';y++){
    x++;
  }
      printf("%d\n", x);
      return y;
}
