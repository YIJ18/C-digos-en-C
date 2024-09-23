/*Escriba un programa que solicite al usuario una frase. Posteriormente, despliegue una lista de
las letras que aparecen en dicha frase. Por último, indique cuántas veces apareció cada una
de estas letras en la frase*/

#include <stdio.h>
#include <string.h>

void solicitar(char *Frase);
void desplegar(char *Frase);

int main(void)
{
  char Frase[100];
  solicitar(Frase);
  desplegar(Frase);
  return 0;
}

void solicitar(char *Frase)
{
  printf("Ingrese una frase (Maximo 100 caracteres): ");
  gets(Frase);
}

void desplegar(char *Frase)
{
  int i, j, k, cont = 0, temp;
  for (i = 0; i < strlen(Frase); i++)
  {
    temp = 2;
    cont = 0;
    for (j = 0; j < strlen(Frase); j++)
    {
      for (k = i - 1; k >= 0; k--)
      {
        if (Frase[i] == Frase[k])
          temp = 1;
      }
      if (Frase[i] == Frase[j])
      {
        cont++;
      }
    }
    if (temp == 2 && Frase[i] != ' ')
      printf("La letra %c, se repite %d veces\n", Frase[i], cont);
  }
}
