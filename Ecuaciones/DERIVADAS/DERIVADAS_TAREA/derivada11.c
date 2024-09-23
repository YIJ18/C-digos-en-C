#include <stdio.h>
#include <math.h>
#define h 0.001F

float F(float x);

int main(void)
{
    float a, df;
    printf("\n-----------PUNTOS DE LA DERIVADA----------------");
    for (a = 2.3; a < 3; a += 0.1)
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
    return (pow((3 * x - 8), -2) * pow((7 * x * x + 4), -3));
}
