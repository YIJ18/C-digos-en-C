#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  FILE *archivo;
  archivo = fopen("datos.txt", "at");
  fprintf(archivo, "Hola perenganito\n");
  fclose(archivo);
  return 0;
}
