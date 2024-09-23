/*Escriba un programa que sea capaz de separar una frase en palabras. Después de que el
programa lea la frase, que se despliegue cada palabra en una línea.*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

void ingresar(char *Frase);
void dividir(char *Frase, char Frases[50][50], int *num);
void imprimir(char Frases[50][50], int num);

int main(void)
{
  char Frase[100], Frases[50][50];
  int num = 0;
  ingresar(Frase);
  dividir(Frase, Frases, &num);
  imprimir(Frases, num);
  return 0;
}

void ingresar(char *Frase)
{
  printf("Ingresa una frase (maximo 100 caracteres): ");
  gets(Frase);
}

void dividir(char *Frase, char Frases[50][50], int *num)
{
  int i, j = 0, k = 0;
  *num = 0;
  for (i = 0; i <= strlen(Frase); i++)
  {
    if (Frase[i] == 32 || i == strlen(Frase))
    {
      Frases[j][k] = '\0';
      j++;
      k = 0;
    }
    else
    {
      Frases[j][k] = Frase[i];
      k++;
    }
  }

  *num = j;
}

void imprimir(char Frases[50][50], int num)
{
  int i, j;
  for (i = 0; i < num; i++)
    puts(Frases[i]);
}
