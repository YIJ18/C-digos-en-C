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
void Pedir_Dato(float *dato, int i);
void Sumar_acumulada(float dato, float *suma);
void Calcular_prom(float suma, int i, float *prom);
void Desplegar(float prom);

int main(void)
{
    float suma = 0;
    float dato, prom;
    int i = 0;

    do
    {
        i++;
        Pedir_Dato(&dato, i);
        Sumar_acumulada(dato, &suma);
    } while (i < 4);

     Calcular_prom( suma, i, &prom);
     Desplegar(prom);
    return 0;
}

void Pedir_Dato(float *dato, int i)
{
    printf("Ingresa el número %d: ", i);
    scanf("%f", dato);
}

void Sumar_acumulada(float dato, float *suma)
{
    *suma = dato + *suma;
}
void Calcular_prom(float suma, int i, float *prom)
{
*prom = suma / i;
}
void Desplegar(float prom)
{
    printf("El promedio es: %.2f\n", prom);
}