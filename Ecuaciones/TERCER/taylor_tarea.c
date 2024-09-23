#include <stdio.h>
#include <math.h>
#define h 0.1

void Factorial(int Num, int *Res);
double n_derivada_central(double x, double y, int n);
double Maclaurin(double a, double b, double x, int max_iter);
double F(double x, double y);

int main()
{
    double x0 = 0.5, y0 = 1.0;
    double result = Maclaurin(x0, y0, x0, 4);
    printf("Resultado: %.10lf\n", result);
    return 0;
}

double F(double x, double y)
{
    return x + (2 * x * y);
}

void Factorial(int Num, int *Res)
{
    *Res = 1; // Inicializar el resultado a 1
    if (Num > 1)
        Factorial(Num - 1, Res);
    *Res *= Num;
}

double n_derivada_central(double x, double y, int n)
{
    if (n == 0)
        return F(x, y);
    else
        return (n_derivada_central(x + h, y, n - 1) - n_derivada_central(x - h, y, n - 1)) / (2 * h);
}

double Maclaurin(double a, double b, double x, int max_iter)
{
    int i;
    double resultado = F(a, b);
    for (i = 1; i <= max_iter; i++)
    {
        int fact = 0;
        Factorial(i, &fact);
        resultado += (n_derivada_central(a, b, i) * pow(x - a, i)) / fact;
        printf("Resultado en iteración %d: %.10lf\n", i, resultado);
    }
    return resultado;
}
