/*
@file: Ejercicio D
@brief: Cuadrado
@details:Programa que imprime un cuadrado, excluyendo el área, el contorno del cuadrado
@author:Iris Yulit Jasso Cortes
@date: 20-Octubre-2022
*/

#include <stdio.h>

/*@Parametro vacio, función que no retorna nada, hace el contorno del cuadrado*/
void cuadrado(int n);

/*@qFunción principal, en la que pedimos el número  y llamamos la función cuadrado*/
int main(void)
{
  int n;
  printf("Ingresa los lados del cuadrado: ");
  scanf("%d", &n);
  cuadrado(n);
  return 0;
}

/*@Parametro vacio, hace el contorno del cuadrado*/
void cuadrado(int n)
{
  int y, x, z;
  /*Este if es el que hace el cuadrado*/
  for (x = 1; x <= n; x++)
  {
    /*Este if es el que imprime las esquinas del cuadrado, e imprime un espacio dentro de este*/
    for (y = 1; y <= n; y++)
    {
      if (x == 1 || x == n || y == 1 || y == n)
      {
        printf("*");
      }
      else
      {
        printf(" ");
      }
    }

    printf("\n");
  }
  /*@Return, no retorna nada*/
}
