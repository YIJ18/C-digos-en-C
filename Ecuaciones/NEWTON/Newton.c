#include <stdio.h>
#include <math.h>

#define h 0.01F

float F(float x);
float Newton(float xn);
float derivada(float a);

int main(void)
{
    float i, x, y;
    printf("---------------------------\n");
    x = 3;
    y =  Newton(x);
    while (x != y)
    {
        x = y;
        y = Newton(x);
        printf("%lf\n", y);
    }

    printf("\n");
}

float derivada(float a)
{
    return (F(a + h) - F(a)) / h;
}

float F(float x)
{
    return (x * x) - 7;
}

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