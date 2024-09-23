/*
  @file: prg29_matriz_suma_promedio
  @brief: Función strcmp (string compare)
  @details: Se ejemplifica el uso de una función strcpy, la cual compara dos cadenas pa indetificar cual de las dos tiene un mayor valor en código ascii.
  @author: Iris Yulit Jasso  Cortes
  @date: 20-abril-2023
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

#define MAX 100

void Pedir_frase (char *Frase);
int Validar_frase (char Frase1[], char Frase2[MAX]);
void Imprimir_validacion (int Resultado);

int main (void)
{
  char Frase1[MAX], Frase2[MAX];

  Pedir_frase (Frase1);
  Pedir_frase (Frase2);
  Imprimir_validacion (Validar_frase (Frase1, Frase2)); // Imprimir_validacion (1);

  return 0;
}

void Pedir_frase (char *Frase)
{
  printf ("Dame frase: ");
  fgets (Frase, MAX, stdin);
  Frase[strlen(Frase)-1]=0;
  __fpurge(stdin);
}

int Validar_frase (char Frase1[], char Frase2[MAX])
{
  /*
    int strcmp (char *s1, char *s2);

    0 -> son iguales
    positivo-> cadena 1 es alfabéticamente mayor que la cadena 2
    negativo -> cadena 1 es alfabéticamente menor que la cadena 2
  */

  if (strcmp(Frase1, Frase2)==0)
    return 1;
  else
    {
      if (strcmp(Frase1, Frase2)>0)
        return 2;
      else
        {
          if (strcmp(Frase1, Frase2)<0)
            return 3;
        }
    }
}

void Imprimir_validacion (int Resultado)
//void Imprimir_validacin (1)
{
  switch (Resultado)
    {
    case 1:
      printf ("Ambas cadenas son iguales.\n");
      break;
    case 2:
      printf ("Cadena 1 es mayor alfabéticamente que cadena 2.\n");
      break;
    case 3:
      printf ("Cadena 1 es menor alfabéticamente que cadena 2.\n");
      break;
    default:
      printf ("No aplica\n");
      break;
    }
}
