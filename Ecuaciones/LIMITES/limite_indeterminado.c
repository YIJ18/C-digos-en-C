#include <stdio.h>

#define LIMITE 0.5

float funcion(double x);

int main(void)
{
    int i;
    float y, matriz_x[10], matriz_y[10], limite = 0.5 - 0.10;
    for (i = 0; i < 10; i++)
    {
        matriz_x[i] = funcion(limite);
        matriz_y[i] = limite;
        limite = limite - 0.01;
        printf("y = %.2lf, x = %.2lf\n", matriz_x[i], matriz_y[i]);
    }
printf("\n\n");
limite = 0.51;
        for (i = 0; i < 10; i++)
    {
        matriz_x[i] = funcion(limite);
        matriz_y[i] = limite;
        limite = limite + 0.01;
        printf("y = %.2lf, x = %.2lf\n", matriz_x[i], matriz_y[i]);
    }
}

float funcion(double x)
{
    float r, temp;
    temp = (2 * x) - 1;
    r = 1 / temp;
    return r;
}
