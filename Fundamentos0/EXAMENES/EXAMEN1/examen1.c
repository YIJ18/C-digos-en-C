/*
@file: Examen 1
@brief:Imprime un triangulo y cuadrado
@details:Programa que imprime un triangulo con t, con entrada 1 y 2 o un cuadrado con entrada 1 y 2
@author:Iris Yulit Jasso Cortes
@date: 27-Octubre-2022
*/

#include <stdio.h>

void cua(int b, char ca1, char ca2, char n);
void tri(int b, char ca1, char ca2, char n);

/*
@Parametro: Esta función es la principal, pide los datos necesarios y llama a las funciones
@Return: retorna un 0
 */

int main(void)
{
  int b;
  char ca1, ca2, n;
  // Introduce los datos necesarios
  printf("Introduce la letra t  para un triangulo, o la c para un cuadrado: ");
  scanf("%c", &n);
  printf("\nIntroduce la base de la figura a iprimir: ");
  scanf("%d", &b);
  printf("\nIntroduce el primer cáracter para la impresión: ");
  getchar();
  ca1 = getchar();
  printf("\nIntroduce el segundo cáracter para la impresión: ");
  getchar();
  ca2 = getchar();
  getchar();
  // Llama a las funciones
  cua(b, ca1, ca2, n);
  tri(b, ca1, ca2, n);
  return 0;
}

/*@Parametro: Esta función hace un cuadrado con los datos que e usuario intriduce en el main
  @Parametro b: Este se usa para el tamaño del triangulo, ya que este es el que nos dice cuantas veces se repite el for, ya que se repite hasta llegar a este
  @Parametro ca1: Es el caracter que imprime primero si es par
  @Parametro ca2: Es el caracter que imprime primero si no es par
  @Parametro n: Si este no es igual a la letraque pide el programa, nunca entra a este if, por tanto no hace nada
  @Return: No retorna nada*/
void cua(int b, char ca1, char ca2, char n)
{
  int x, y, re, r1;
  if (n == 'c' || n == 'C')
  {

    for (x = 0; x < b; x++)
    {
      r1 = x % 2;
      if (r1 == 0)
      {
        for (y = 0; y < b; y++)
        {
          re = y % 2;
          if (re == 0)
          {
            printf("%c", ca1);
          }
          else
          {
            printf("%c", ca2);
          }
        }
      }

      if (r1 != 0)
      {
        for (y = 0; y < b; y++)
        {
          re = y % 2;
          if (re == 0)
          {
            printf("%c", ca2);
          }
          else
          {
            printf("%c", ca1);
          }
        }
      }

      printf("\n");
    }
  }
}

/*@Parametro: Esta función hace un triangulo con los datos que e usuario intriduce en el main
 @Parametro b: Este se usa para el tamaño del triangulo, ya que este es el que nos dice cuantas veces se repite el for, ya que se repite hasta llegar a este
 @Parametro ca1: Es el caracter que imprime primero si es par
 @Parametro ca2: Es el caracter que imprime primero si no es par
 @Parametro n: Si este no es igual a la letraque pide el programa, nunca entra a este if, por tanto no hace nada
 @Return: La función no retorna nada*/
void tri(int b, char ca1, char ca2, char n)
{

  int x, y, re, r1;

  if (n == 't' || n == 'T')
  {
    for (x = 0; x <= b; x++)
    {
      r1 = x % 2;

      if (r1 == 0)
      {
        for (y = 0; y < x; y++)
        {
          re = y % 2;
          if (re == 0)
          {
            printf("%c", ca1);
          }
          else
          {
            printf("%c", ca2);
          }
        }
      }

      else if (r1 != 0)
      {
        for (y = 0; y < x; y++)
        {
          re = y % 2;
          if (re == 0)
          {
            printf("%c", ca2);
          }
          else
          {
            printf("%c", ca1);
          }
        }
      }
      printf("\n");
    }
  }
}
