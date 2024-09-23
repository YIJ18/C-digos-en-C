#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
int main (void)
{
  FILE *archivo;
  char frase[200];
  printf("Dame una frase: \n");
  gets (frase);
  archivo = fopen("frases.txt", "at");
  //fputs(frase, archivo);
  fprintf(archivo, "%s\n", frase);
  fclose(archivo);
}
