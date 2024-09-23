#include <stdio.h>
#include <math.h>

#define h 0.01F

float F(float x);

int main(void)
{
    float a, df = (F(a + h) - F(a)) / h;
    printf("\nLa derivada del sistema es: %lf\n", df);
    printf("---------------------------\n");
    for (a = 0; a < 5; a += 0.5)
        printf("F(%.2lf): %lf\n", a, F(a));
    printf("\n");
}

float F(float x)
{
    return (9.0 * x) - 2;
}
