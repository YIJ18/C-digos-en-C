#include <stdio.h>

#define LIMITE -3

float funcion(int x);

int main (void)
{
  float y;
  y = funcion(LIMITE);
  printf("%f\n", y);
}

float funcion(int x)
{
  float r;
  r = ((r*r)-9)/(x + 3);
    return r; 
}
