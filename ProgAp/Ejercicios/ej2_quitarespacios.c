#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

void Solicitar (char Cadena1[]);
void quitarespacios (char Cadena1[], char Cadena2[]);
void Desplegar(char *Cadena1, char *Cadena2);

int main (void)
{
  char  Cadena1[200], Cadena2[200];
  Solicitar (Cadena1);
  quitarespacios (Cadena1, Cadena2);
  Desplegar(Cadena1, Cadena2);
  return 0;
}

void Solicitar (char Cadena1[])
{
  printf("Ingresa una frase: ");
  gets(Cadena1);
  __fpurge(stdin);
}

void quitarespacios (char Cadena1[], char Cadena2[])
{
  int i, j = 0;
  for(i = 0; i < strlen(Cadena1); i++)
    {
      if ( Cadena1[i] == 32 )
	i++;
      Cadena2[j] = Cadena1[i];
      j++;
    }
}

void Desplegar(char *Cadena1, char *Cadena2)
{
    printf("La cadena 1 es : ");
    puts(Cadena1);
    printf("La cadena 2 es : ");
    puts(Cadena2);
}
