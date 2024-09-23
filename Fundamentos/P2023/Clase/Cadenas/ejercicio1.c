/*
  @file: ejercicio1.c
  @brief: Ejercicio 1 de pruebas para el examen
  @details: Escriba  un  programa  que  permita  calcular  el  cuadrado  de  los  100 primeros  números  enteros positivos(1  al  100)y  que despliegueal  finaluna  tabla  con el  cuadrado  de  cada  uno  de  estos números. El  programa debe  hacerse en  dos  fases: en la primera  fase,calcularel cuadrado decada uno delos 100 primeros números enteros positivosy en la segunda faseimprimirla tabla que  incluya  tanto  el  número  como  su  cuadrado.Utilizar  un  arreglo  bidimensional.

  @author: Iris Yulit Jasso  Cortes
  @date: 20-abril-2023
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <strings.h>
#include <string.h>
#include <math.h>

#define MAX 100

int Rellenar(int *arr);
int Desplegar(int *arr);

int main(void)
{
  int arr[MAX];
  Rellenar(arr);
  Desplegar(arr);
  return 0;
}

int Rellenar(int *arr)
{
  int i, j = 1;
  for (i = 0; i < MAX; i++)
  {
    arr[i] = pow(j, 2);
    j++;
  }
}

int Desplegar(int *arr)
{
  int i, j, k = 0;
  for (j = 0; j < 10; j++)
  {
    for (i = 0; i < 10; i++)
    {

      printf("%d = %2.2d", k + 1, arr[k]);
      printf("\t");
      if (j == 0)
        printf("\t");
      k++;
    }
    printf("\n");
  }
}