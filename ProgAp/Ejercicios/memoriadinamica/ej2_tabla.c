#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int j, i, col, ren;
  int **tabla;

  printf("Dame el numero de renglones y columnas: ");
  scanf("%d, %d", &ren, &col);
  tabla = (int **)malloc(sizeof(int *) * ren);

  for (i = 0; i < ren; i++)
    tabla[i] = (int *)malloc(sizeof(int) * col);

  for (i = 0; i < ren; i++)
    for (j = 0; j < col; j++)
    {
      printf("Dato [%d][%d]: ", i, j);
      scanf("%d", &tabla[i][j]);
    }
  printf("La tabla es: \n");
  for (i = 0; i < ren; i++)
  {
    for (j = 0; j < col; j++)
      printf("%d\t", tabla[i][j]);
    printf("\n");
  }

  for (i = 0; i < ren; i++)
    free(tabla[i]);
  free(tabla);

  return 0;
}
