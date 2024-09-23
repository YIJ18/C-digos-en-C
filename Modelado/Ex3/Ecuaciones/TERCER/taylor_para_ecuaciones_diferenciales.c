#include <stdio.h>
#include <math.h>

#define h 0.5
#define num 4

double F(double x);
double n_derivada_central(double x, int n);
double Taylor(double x, double y);

int main(void)
{
    double x;
    double y = 1.0; // Valor inicial de y

    for (x = 0.0; x <= 4.0; x += h)
    {
        printf("y(%.2lf) = %.6lf\n", x, y);
        y += h * Taylor(x, y); // Método de Taylor de primer orden
    }

    return 0;
}

double F(double x)
{
    return -2 * pow(x, 3) + 12 * pow(x, 2) - 20 * x + 8.5;
}

double n_derivada_central(double x, int n)
{
    if (n == 0)
    {
        return F(x);
    }
    else
    {
        return (n_derivada_central(x + h / 2, n - 1) - n_derivada_central(x - h / 2, n - 1)) / h;
    }
}

double Taylor(double x, double y)
{
    return F(x);
}
