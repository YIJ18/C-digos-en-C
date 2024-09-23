#include <stdio.h>
#include <math.h>

#define inicio 0.0
#define fin 2.0
#define paso 0.1

double derivada(double x, double y);
double Euler_predictor_corrector(double x, double y, double h, double *y_predictor);
double y_exacto(double x, double y);

int main(void)
{
    double x = inicio;
    double y = 3.0;
    double h = paso;
    double y_predictor = 3.0;

    printf("x       y       y_predictor     y real\n");

    while (x <= fin)
    {
        printf("%.5lf   %.5lf  %.5lf    %.5lf\n", x, y_predictor, y, y_exacto(x, y));
        y = Euler_predictor_corrector(x, y, h, &y_predictor);
        x += h;
    }

    return 0;
}

double derivada(double x, double y)
{
    return 2 * x * y + 1;
}

double Euler_predictor_corrector(double x, double y, double h, double *y_predictor)
{
    *y_predictor = y + h * derivada(x, y);
    return y + (h / 2.0) * (derivada(x, y) + derivada(x + h, *y_predictor));
}

double y_exacto(double x, double y)
{
    return exp(x * x) + sqrt(3.1416) * exp(x * x) / 2;
}