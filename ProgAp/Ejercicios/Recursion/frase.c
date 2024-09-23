#include <stdio.h>
#include <string.h>

void Ingresar(char *cadena);
void voltea(char *cadena, int cont, int cont2, char *cadena2);

int main (void)
{
  char cadena[100], cadena2[100];
  int cont = 0, cont2;
  Ingresar(cadena);
  cont2=strlen(cadena)-1;
  voltea(cadena,cont, cont2, cadena2);
  puts(cadena2);
  return 0;
}
void Ingresar(char *cadena)
{
  printf("Ingresa la cadena: ");
  gets(cadena);
}

void voltea(char *cadena, int cont, int cont2, char *cadena2)
{
  char temp;
  if (cadena[cont] != '\0')
    {
      cadena2[cont]=cadena[cont2];
      voltea(cadena, cont+1, cont2-1, cadena2);
    }
  
}
