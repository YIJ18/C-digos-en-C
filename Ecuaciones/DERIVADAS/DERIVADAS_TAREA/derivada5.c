#include <stdio.h>
#define h 0.01F

float F(float x);

int main(void)
{
    float a, df;
    printf("\n-----------PUNTOS DE LA DERIVADA----------------");
    for (a = 0; a < 5; a += 0.5)
    {
        df = (F(a + h) - F(a)) / h;
        printf("\nD(%.2lf): %lf", a, df);
    }
    printf("\n\n-----------PUNTOS DE LA ECUACIÓN----------------\n");
    for (a = 0; a < 5; a += 0.5)
        printf("F(%.2lf): %lf\n", a, F(a));
    printf("\n");
}

float F(float x)
{
    return (x * x * x) + x;
}
