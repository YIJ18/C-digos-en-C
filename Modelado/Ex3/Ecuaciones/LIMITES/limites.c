#include <stdio.h>
#define LIMITE 1

float funcion(int x);

int main (void)
{
  float y;
  y = funcion(LIMITE);
  printf("\n%f\n", y);
}

float funcion (int x)
{
  float r;
  r = (x*x -1)/(x+1);
  return r;
}
