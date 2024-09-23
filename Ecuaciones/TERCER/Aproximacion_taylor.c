#include <stdio.h>
#include <math.h>

#define h 0.01
#define num 7
#define op 2

double factorial(int n);
double F(double x);
double n_derivada_central(double x, int n);
double Maclaurin(double a, double x);

int main(void)
{
    int i = 0;
    double x;

    if (op == 1)
        x = M_PI / 3.0;
    else if (op == 2)
        x = 0.2;
    else if (op == 3)
    {
        x = 0.2;
        i = 1;
    }
    printf("Aproximación es = %lf en %d\n", Maclaurin(i, x), i);
    return 0;
}

/**
 * Calcula el factorial de un número entero.
 *
 * @param n Número entero para calcular el factorial.
 * @return El factorial de n.
 */
double factorial(int n)
{
    if (n == 0 || n == 1)
        return 1.0;
    else
        return n * factorial(n - 1);
}

/**
 * Calcula la n-ésima derivada central de F(x) en el punto x.
 *
 * @param x Punto en el que se calcula la derivada.
 * @param n Orden de la derivada.
 * @return El valor de la n-ésima derivada central.
 */
double n_derivada_central(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_central(x + h, n - 1) - n_derivada_central(x - h, n - 1)) / (2 * h);
}



/**
 * Calcula la aproximación de la función usando la serie de Maclaurin.
 *
 * @param a Término inicial de la serie.
 * @param x Punto en el que se evalúa la serie.
 * @return La aproximación de la función en el punto x usando Maclaurin.
 */
double Maclaurin(double a, double x)
{
    int i;
    double maclaurin = F(a);
    for (i = 1; i <= num; i++)
        maclaurin += ((n_derivada_central(a, i) * pow(x-a, i)) / factorial(i));
    return maclaurin;
}

/**
 * Calcula el valor de la función F en un punto dado.
 *
 * @param x Punto en el que se evalúa la función.
 * @return El valor de la función en el punto x.
 */
double F(double x)
{
    if (op == 1)
        return sin(x);
    if (op == 2 || op == 3)
        return exp(-x);
}