#include <stdio.h>
#include <math.h>

#define h 0.01
#define inicio 0.0
#define fin 2.0

float n_derivada_central(float x, int n);
float F_Newton(float x);
float Newton(float xn);
float derivada(float a);
void problema_newton();

int main()
{
    float i;
    problema_newton();
}

void problema_newton()
{
    float x = 2, y;

    printf("---------------------------\n");

    y = Newton(x);
    while (x != y)
    {
       // printf("Iterando...\n");
        x = y;
        y = Newton(x);
    }

    printf("La raiz es = %lf\n", y);

    printf("\n");
}

/**
 * Calcula el valor de la función F en un punto dado.
 *
 * @param x Punto en el que se evalúa la función.
 * @return El valor de la función en el punto x.
 */
float F_Newton(float x)
{
    return x - cos(x);
}

/**
 * Aplica el método de Newton para encontrar una raíz de la función F.
 *
 * @param xn Valor inicial para el método de Newton.
 * @return La aproximación de la raíz de F.
 */
float Newton(float xn)
{
    return (xn - (n_derivada_central(xn, 2) / n_derivada_central(xn, 3)));
}

/**
 * Calcula la n-ésima derivada adelante de F(x) en el punto x
 *
 * @param x Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada adelante
 */
float n_derivada_central(float x, int n)
{
    if (n == 0)
        return F_Newton(x);
    else
        return (n_derivada_central(x + h, n - 1) - n_derivada_central(x - h, n - 1)) / (2 * h);
}
