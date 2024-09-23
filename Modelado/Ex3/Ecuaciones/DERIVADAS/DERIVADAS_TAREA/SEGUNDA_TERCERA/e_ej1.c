#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define h 0.0001

double F(double x);

double n_derivada_adelante(double x, int n);
double n_derivada_atras(double x, int n);
double n_derivada_central(double x, int n);

int main(void)
{
    double x = 0.0;
    int i = 0;

    printf("Dame el valor de x: ");
    scanf("%lf", &x);
    system("clear");
    printf("\n--------------------------------------------------------------------------\n");
    printf(" Derivada (x = %.2lf)     Adelante\t  Atras\t\tCentral\n", x);
    printf("--------------------------------------------------------------------------\n");
    for (i = 1; i < 4; i++)
    {

        printf("\t%d\t   ", i);
        printf("     %.6lf\t", n_derivada_adelante(x, i));
        printf(" %.6lf\t", n_derivada_atras(x, i));
        printf("%.6lf\n", n_derivada_central(x, i));
    }
    printf("\n");
    return 0;
}

/**
 * Función para evaluar F(x)
 *
 * @param x Valor de x
 * @return El resultado de F(x)
 */
double F(double x)
{
    return sqrt(x);
}

/**
 * Calcula la n-ésima derivada adelante de F(x) en el punto x
 *
 * @param x Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada adelante
 */
double n_derivada_adelante(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_adelante(x + h, n - 1) - n_derivada_adelante(x, n - 1)) / h;
}

/**
 * Calcula la n-ésima derivada atrás de F(x) en el punto x
 *
 * @param x Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada atrás
 */
double n_derivada_atras(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_atras(x, n - 1) - n_derivada_atras(x - h, n - 1)) / h;
}

/**
 * Calcula la n-ésima derivada central de F(x) en el punto x
 *
 * @param x Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada central
 */
double n_derivada_central(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_central(x + h, n - 1) - n_derivada_central(x - h, n - 1)) / (2 * h);
}