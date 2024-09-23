#include <stdio.h>

void var01(int num);
void ram(int num);
int loque(int num);

int main(void)
{
  int num, x, y, fib;
  do
  {
    printf("Ingresa el número: ");
    scanf("%d", &num);
    ram(num);
  } while (num < 0);

  if (num == 0 || num == 1)
  {
    var01(num);
  }

  for (x = 0; x < num; x++)
  {
    for (y = 0; y < x; y++)
    {
      fib = loque(y);
      printf("%d ", fib);
    }
    printf("\n");
  }
  return 0;
}

int loque(int num)
{
  int suma, i, fn2, fn1;
  suma = 0;
  fn2 = 1;
  fn1 = 0;
  for (i = 1; i <= num; i++)
  {
    suma = fn1 + fn2;
    fn2 = fn1;
    fn1 = suma;
  }
  return suma;
}

void var01(int num)
{
  if (num == 0)
  {
    printf("f(0)= 0");
  }
  if (num == 1)
  {
    printf("f(1)= 1");
  }
}

void ram(int num)
{
  if (num < 0)
  {
    printf("Ingresa Un número valido\n");
  }
}
