#include <math.h>
#include <stdio.h>
#define h 0.5

double F(double x, double y);
double runge_kutta(double x, double y);

int main(void)
{
    double i, x = 0, y = 1;

    for (i = 0; i <= 4.0; i += 0.5)
    {
        printf("En %.2lf es %.5lf\n", i, y);
        y = runge_kutta(i, y);
    }

    return 0;
}

double F(double x, double y)
{
    return (-2 * pow(x, 3)) + (12 * pow(x, 2)) - (20 * x) + 8.5;
}

double runge_kutta(double x, double y)
{
    double k1, k2, k3, k4;
    k1 = h * F(x, y);
    k2 = h * F(x + h / 2.0, y + k1 / 2);
    k3 = h * F(x + h / 2.0, y + k2 / 2);
    k4 = h * F(x + h, y + k3);

    return y + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
}
