#include <stdio.h>
#include <math.h>

#define h 0.01
#define fin 8

double factorial(int n);
double F(double x);
double n_derivada_central(double x, int n);
double Maclaurin(double x);

int main(void)
{
    int i;
    for (i = 0; i < fin; i++)
        printf("Maclaurin es = %lf en %i", Maclaurin(i), i);
    
    return 0;
}

double factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

double n_derivada_central(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_central(x + h, n - 1) - n_derivada_central(x - h, n - 1)) / (2 * h);
}

double Maclaurin(double a)
{
    return F(a) + n_derivada_central(a, 1) + (n_derivada_central(a, 2) / factorial(2)) * pow(a, 2) + (n_derivada_central(a, 3) / factorial(3)) * pow(a, 3);
}

double F(double x)
{
    return cos(x);
}