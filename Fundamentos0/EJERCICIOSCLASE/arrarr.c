#include <stdio.h>

int main(void)
{

  char arreglo[20][20];
  int y, x;

  for (y = 0; y < 20; y++)
  {
    scanf("%[^\n]", arreglo[y]);
    getchar();
  }
  x = 1;
  for (y = 0; y < 20; y++)
  {
    printf("%s", arreglo[y]);
    x = x + 1;
  }
  return 0;
}
