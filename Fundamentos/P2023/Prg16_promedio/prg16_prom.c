/*
@file: prg16_prom.c
@brief: Suma acumulada y promedio, calcular el promedio de n cantidad de números dados por el usuario
@details: Este programa calcula el promedio de la cantidad de número dadaos por el usiario. Este programa pide al principio cunato números quieres al introduciir y conforme da los números, se hace la suma acumulada.
@author: Iris Yulit Jasso Cortes
@date: 10-Marzo-2023

DISEÑO ARQUITECTONICO
Diagrama IPO de alto nivel
Cantidad, Numeros(ENTRADA) -> Suma acumulada (PROCESO) -> (SALIDA)suma(ENTRADA)

Diagrama IPO de bajo nivel

Pedir Cantidad de números(PROCESO) -> (SALIDA)Cantidad(ENTRADA) -> Pedir número(PROCESO) -> (SALIDA) Número (ENTRADA) -> Sumar acumuladamente (PROCESO) -> (SALIDA)Suma(ENTRADA) -> Calcular promedio(PROCESO) -> (SALIDA)Promedio(ENTRADA) -> Imprimir resultado(PROCESO)
*/

#include <stdio.h>
#include <stdio_ext.h>

void Pedir_Cantidad(int *n);
void Pedir_numero(float *Num);
void Sumar_acumulado(float Num, float *Suma);
void Calcular_promedio(float Suma, int n, float *Promedio);
void Imprimir_Resultado(int n, float Promedio);

int main(void)
{
    int n, i;
    float Num, Suma, Promedio;
    i = 0;
    Pedir_Cantidad(&n);
    do{
        Pedir_numero(&Num);
        i = i + 1;
        Sumar_acumulado( Num,  &Suma);
    }
    while(i < n);

     Calcular_promedio( Suma,  n, &Promedio);
     Imprimir_Resultado( n,  Promedio);

    return 0;
}

void Pedir_Cantidad(int *n)
{
    printf("Dame la cantidad de números a los que quieras calcular el promedio: ");
    scanf("%d", n);
    __fpurge(stdin);
}

void Pedir_numero(float *Num)
{
    printf("Dame número: ");
    scanf("%f", Num);
    __fpurge(stdin);
}

void Sumar_acumulado(float Num, float *Suma)
{
    *Suma = *Suma + Num;
}

void Calcular_promedio(float Suma, int n, float *Promedio)
{
    *Promedio = Suma / n;
}

void Imprimir_Resultado(int n, float Promedio)
{
    printf("El promedio de los %d números es: %.2f ", n, Promedio);
}