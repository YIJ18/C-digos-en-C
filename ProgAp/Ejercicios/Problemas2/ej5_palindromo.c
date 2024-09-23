/*
Escriba un programa que sea capaz de determinar si una frase es o no un palíndromo. Un
palíndromo es una frase que se lee igual de izquierda a derecha que de derecha a izquierda,
por ejemplo, “Anita lava la tina”
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

void Ingresar(char *Frase);
void Minus(char *Frase);
int Palindromo(char *Frase);
void Desaplegar(char *Frase, int Bandera);

int main(void)
{
  char Frase[100];
  int Bandera;
  Ingresar(Frase);
  Minus(Frase);
  Bandera = Palindromo(Frase);
  Desaplegar(Frase, Bandera);
  return 0;
}

void Ingresar(char *Frase)
{
  printf("Ingresa una frase: ");
  __fpurge(stdin);
  gets(Frase);
}

void Minus(char *Frase)
{
  char Frase2[100];
  int i, j = 0;
  for (i = 0; i < strlen(Frase); i++)
  {
    if (Frase[i] >= 'A' && Frase[i] <= 'Z')
    {
      Frase[i] = Frase[i] + 32;
    }
  }
  for (i = 0; i < strlen(Frase); i++)
  {
    if (Frase[i] == ' ')
      i++;
    Frase2[j] = Frase[i];
    j++;
  }
  for (i = 0; i < strlen(Frase); i++)
    Frase[i] = Frase2[i];
}

int Palindromo(char *Frase)
{
  int i, j = strlen(Frase);
  for (i = 0; i < strlen(Frase); i++)
  {
    j--;
    if (Frase[i] != Frase[j])
    {
      return 1;
    }
  }
  return 0;
}

void Desaplegar(char *Frase, int Bandera)
{
  if (Bandera == 0)
    printf("La sigiente frase es un palindromo: %s\n", Frase);
  else
    printf("La sigiente frase no es un palindromo: %s\n", Frase);
}