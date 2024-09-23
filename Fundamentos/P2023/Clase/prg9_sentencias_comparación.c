/*
  @file: prg9_sentencias_comparacion.c
  @brief: Ejemplificación de las sentencias de selección (IF-THEN e IF-THEN-ELSE)
  @details: Este programa explica en la función principal el funcionamiento de las sentencias de selección IF-THEN e IF-THEN-ELSE para identificar sus diferencias.
  @author: Iris Yulit Jasso Cortes
  @date: 10-febrero-2023
*/

#include <stdio.h>

int main(void)
{
    int a, b;

    a = 5;
    b = 8;
    // Ejemplo con IF-THEN en donde validamos dos números

    if (a > b)
    {
        printf("La variable a (valor: %d) es mayor a b (valor: %d).\n", a, b);
    }

    if (a < b)
    {
        printf("La variable a (valor: %d) es menor a b (valor: %d).\n", a, b);
    }

    if (a == b)
    {
        printf("La variable a (valor: %d) es igual a b (valor: %d).\n", a, b);
    }

    return 0;
}
