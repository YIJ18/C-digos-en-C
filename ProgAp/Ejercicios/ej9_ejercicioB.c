#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
int main (void)
{
  FILE *archivo;
  char frase[200];
  printf("Las frases del archivo son: \n");
  archivo = fopen("frases.txt", "rt");
  while( fgets(frase, 199, archivo)!=NULL)
    {
      frase[strlen(frase)-1] = '\0';
      puts(frase);
    }
  fclose(archivo);
}
