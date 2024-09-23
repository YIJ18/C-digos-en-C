#include <stdio.h>
#include <math.h>
#define h 0.001F

float F(float r);

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

float F(float r)
{
    return pow(5*r-4, -2);
}
