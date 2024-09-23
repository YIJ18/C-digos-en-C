/*
@file: prg13_ec2_while.c
@brief: Contar del 1 al 10
@details: Este programa se implementa la solucion de una ecuacion de segundo grado y solicita nuevamente los coeficientes de la ecuación. se agrega la validación con la sentencia de iteración do-while.
@author: Iris Yulit Jasso Cortes
@date: 07-Marzo-2023



DISEÑO ARQUITECTÓNICO



Diagrama IPO de alto nivel
a, b , c(ENTRADAS)->Calcular la ecuación de segundo gradp (PROCESO) -> x1, x2 (SALIDA)



Diagrama IPO de bajo nivel
Pedir coeficientes(PROCESO)-> (SALIDAS)a, b , c(ENTRADAS)->Calcular la ecuación de segundo gradp (PROCESO) -> (SALIDA) x1, x2 (PROCESO) -> Imprimir resultado(PROCESO)
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <math.h>

void Pedir_Coeficientes(int *a, int *b, int *c);
void Calcular_ecuacion(int a, int b, int c, double *x1, double *x2);
void Imprimir_resultado(double x1, double x2);

int main(void)
{
    int a, b, c, Discriminante;
    double x1, x2;
    while (a == 0)
    {
        printf("Los coeficientes dados no corresponden a una ecuación de segungo grado");
        Pedir_Coeficientes(&a, &b, &c);
    }

    Discriminante = (b * b) - (4 * a * c);

    if (Discriminante >= 0)
    {
        Calcular_ecuacion(a, b, c, &x1, &x2);
        Imprimir_resultado(x1, x2);
    }
    else
    {
        printf("Se generan raices imaginarias");
    }
    return 0;
}

void Pedir_Coeficientes(int *a, int *b, int *c)
{
    printf("Dame a: ");
    scanf("%d", a);
    __fpurge(stdin);

    printf("Dame b: ");
    scanf("%d", b);
    __fpurge(stdin);

    printf("Dame c: ");
    scanf("%d", c);
    __fpurge(stdin);
}
void Calcular_ecuacion(int a, int b, int c, double *x1, double *x2)
{
    *x1 = (-b + sqrt(b * b - a * a * c)) / (2 * a);
    *x2 = (-b - sqrt(b * b - a * a * c)) / (2 * a);
}

void Imprimir_resultado(double x1, double x2)
{
    printf("Los resultados de la raices son: \n ");
    printf("x1 = %.2f y x2 = %.2f", x1, x2);
}