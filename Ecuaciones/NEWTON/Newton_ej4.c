#include <stdio.h>
#include <math.h>

#define h 0.01F

float F(float x);
float Newton(float xn);
float derivada(float a);
float problema_newton();

int main(void)
{
    problema_newton();
}

float problema_newton()
{
    float x = 0, y = 1, c = (x + y) / 2;

    printf("---------------------------\n");

    if (F(x) * F(y) >= 0)
        printf("El producto de f(a) y f(b) no cumple la condición f(a) * f(b) < 0. \nNo se garantiza la existencia de una raíz en el intervalo [%f,%f].\n", x, y);
    else if (derivada(x) == 0 || derivada(y) == 0)
        printf("La derivada en al menos uno de los extremos del intervalo es cero. No se garantiza la existencia del punto de cruce.\n");
    else if (F(c) / derivada(c) > y - x)
        printf("La tangente de f(x) no cruza en algún punto del intervalo [a,b].\n");
    else
    {
        y = Newton(x);
        while (x != y)
        {
            x = y;
            y = Newton(x);
            printf("%lf\n", y);
        }
    }
    printf("\n");
}

/**
 * Calcula la derivada de la función F en un punto dado.
 *
 * @param a Punto en el que se evalúa la derivada.
 * @return El valor de la derivada en el punto a.
 */
float derivada(float a)
{
    return (F(a + h) - F(a)) / h;
}

/**
 * Calcula el valor de la función F en un punto dado.
 *
 * @param x Punto en el que se evalúa la función.
 * @return El valor de la función en el punto x.
 */
float F(float x)
{
    return exp(-x) - x;
}

/**
 * Aplica el método de Newton para encontrar una raíz de la función F.
 *
 * @param xn Valor inicial para el método de Newton.
 * @return La aproximación de la raíz de F.
 */
float Newton(float xn)
{
    float fxn = F(xn), df = derivada(xn);
    return (xn - (fxn / df));
}

/*
xn = valor inicial
fxn = valor de ecuacion
derivada
*/