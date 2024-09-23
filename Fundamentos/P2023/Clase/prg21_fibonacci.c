/*
@file: prg21_fibonacci.c
@brief: Número de fibonacci
@details: Este programa calcula el número de fibonacci, con una suma acumulada

@author: Iris Yulit Jasso Cortes
@date: 23-Marzo-2023

Diseño arquitectonico

Diagrama IPO de alto nivel

 Número (n) (ENTRADA) -> Calcular fibonacci (PROCESO) -> Número fibonacci (suma) (SALIDA)

Diagrama IPO de bajo nivel

  Pedir número a calcular (PROCESO) -> (SALIDA)  Número (n) (ENTRADA) -> Calcular fibonacci (PROCESO)  -> (SALIDA) Número Fibonacci (ENTRADA) -> Imprimir resultado (PROCESO)
*/

#include <stdio.h>

void Pedir(int *n);
int Calcular(int n);
void imprimir(int suma);

int main(void)
{
    int n, suma;
    Pedir(&n);
    suma = Calcular(n);
    imprimir(suma);
    return 0;
}

void Pedir(int *n)
{
    printf("\nIngresa hasta que número quiere el fibonacci: ");
    scanf("%d", n);
}
int Calcular(int n)
{
    int suma = 0, fib1 = 0, fib2 = 1, i;

    if (n == 1)
        suma = 1;

    else
    {
        for (i = 2; i <= n; i++)
        {
            suma = fib1 + fib2;
            fib1 = fib2;
            fib2 = suma;
        }
    }

    return suma;
}

void imprimir(int suma)
{
    printf("Número de fibonacci : %d\n\n", suma);
}