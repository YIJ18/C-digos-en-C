#include <stdio.h>
#include <math.h>

#define h2 0.01
#define num 4

// Declaraciones de funciones de taylor
double factorial(int n);
double F(double x);
double n_derivada_central(double x, int n);
double Maclaurin(double a, double x);

int main(void)
{
    int i = 0;
    double x = M_PI/4.0;
    printf("Maclaurin es = %lf en %d\n", Maclaurin(i, x), i);
    return 0;
}

double factorial(int n)
{
    if (n == 0 || n == 1)
        return 1.0;
    else
        return n * factorial(n - 1);
}

double n_derivada_central(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_central(x + h2, n - 1) - n_derivada_central(x - h2, n - 1)) / (2 * h2);
}

//Maclaurin siempre inicia en 0, o sea que a siempre es 0
//Taylor siempre se evalua en un número
double Maclaurin(double a, double x)
{
    int i;
    double maclaurin = F(a);
    for (i = 1; i <= num; i++)
        maclaurin += ((n_derivada_central(a, i) * pow(x, i)) / factorial(i));
    return maclaurin;
}

double F(double x)
{
    return cos(x);
}