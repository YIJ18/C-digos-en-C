#include <stdio.h>
#include <string.h>

void Ingresar(char *cadena);
void voltea(char *cadena, int cont);

int main (void)
{
  char cadena[100];
  int cont = 0;
  Ingresar(cadena);
  voltea(cadena,cont);
  return 0;
}
void Ingresar(char *cadena)
{
  printf("Ingresa la cadena: ");
  gets(cadena);
}

void voltea(char *cadena, int cont)
{
  char temp;
  if (cadena[cont] != '\0')
    {
      voltea(cadena, cont+1);
      printf("%c", cadena[cont]);
    }
  
}
