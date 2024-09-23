#include <stdio.h>
#include <math.h>

#define inicio 0.5
#define fin 2.0

double F(double x);
double Integral(float dx);

int main()
{
    float dx = 0;
    for (int i = 3; i <= 10; i++)
    {
        dx = (fin - inicio) / i;
        printf("Para dx = %.10f, Integral = %.10f\n", dx, Integral(dx));
    }
    return 0;
}

double F(double x)
{
    return 1 / x;
}

double Integral(float dx)
{
    double i = 0;
    double a = 0;

    for (i = inicio + (dx); i <= fin; i += dx)
        a += (F(i) * dx);
    return a;
}
