/*
  @file: ejercicio1.c
  @brief: Ejercicio 1 de pruebas para el examen
  @details: En una matriz de5x5 generala siguiente espiral

  @author: Iris Yulit Jasso  Cortes
  @date: 20-abril-2023
*/

#include <stdio.h>

#define MAX 5

void Imprimir(int **Arreglo);

int main(void)
{
    int Arreglo[MAX][MAX];
    Imprimir(Arreglo);

    return 0;
}

void Imprimir(int **Arreglo)
{
    int i, j, inicio = 25;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            Arreglo[j][i] = inicio;
            inicio = inicio -1;
        }
    }
}