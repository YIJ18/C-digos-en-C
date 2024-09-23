#include <stdio.h>
#include <math.h>

#define inicio 0.0
#define fin 1.0
#define paso 0.1

double derivada(double x, double y);
double Euler_predictor_corrector(double x, double y, double h, double *y_predictor);

int main(void)
{
    double x = inicio;
    double y = 1.0;
    double h = paso;
    double y_predictor = 1.0;

    printf("x           y          y_predictor\n");

    while (x <= fin)
    {
        printf("%.2lf   %.10lf  %.10lf\n", x, y_predictor, y);
        y = Euler_predictor_corrector(x, y, h, &y_predictor);
        x += h;
    }

    return 0;
}

double derivada(double x, double y)
{
    return -2 * pow(y, 2) + x * y + pow(x, 2);
}

double Euler_predictor_corrector(double x, double y, double h, double *y_predictor)
{
    *y_predictor = y + h * derivada(x, y);
    return y + (h / 2.0) * (derivada(x, y) + derivada(x + h, *y_predictor));
}