#include <stdio.h>

void ordenar(int arr[]);

int main(void)
{
  int arr[100];
  ordenar(arr);
  return 0;
}

/*
 * Esta función lee los 10 números y los almacena en un número
 * @param arreglo tipo entero; arr conjunto de números
 * @return no regresa nada
 */
void ordenar(int arr[])
{

  int x, y, z, i, num = 11;

  for (i = 1; i <= 10; i++)
  {
    printf("\nIngresa el número: ");
    scanf("%d", &arr[i]);
  }

  for (x = 1; x < (num - 1); x++)
  {
    for (y = x + 1; y < num; y++)
    {
      if (arr[y] < arr[x])
      {
        z = arr[y];
        arr[y] = arr[x];
        arr[x] = z;
      }
    }
  }

  printf("\nLos números son:\n");
  for (x = 1; x < num; x++)
  {
    printf("%i, ", arr[x]);
  }
}