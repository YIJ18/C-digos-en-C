#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int elementos, i;
  int *arreglo;

  printf("Cuantos elementos tienes?");
  scanf("%d", &elementos);
  arreglo = (int *)malloc(sizeof(int) * elementos);
  for (i = 0; i < elementos; i++)
  {
    printf("Dame el dato %d: ", i + 1);
    scanf("%d", &arreglo[i]);
  }
  printf("Los datos son: \n");
  for (i = 0; i < elementos; i++)
    printf("%d", arreglo[i]);
  printf("\n");
  free(arreglo);
  return 0;
}
