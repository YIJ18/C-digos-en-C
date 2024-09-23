#include <stdio.h>

void factorial(int n, int *fact);

int main(void)
{
  int n, fact;
  printf("Ingresa el factorial que quieres calcular: ");
  scanf("%d",&n);
  factorial(n, &fact);
  printf("El factorial es: %d\n",fact);
}

void factorial(int n, int *fact)
{
  int temp;
  if(n>1)
    {
      factorial(n-1, fact);
      *fact=n*(*fact);
    }
  else
    *fact=1;
}
