#include <stdio.h>
#include <math.h>

#define inicio 0.5
#define fin 1.0
#define paso 0.1

// Declaraciones de funciones de euler predictor
double derivada(double x, double y);
double Euler_predictor_corrector(double x, double y, double h, double *y_predictor);
void imprimir_tabla(double x, double y, double y_predictor);
void resolver_edo(double x0, double y0, double h, double x_fin);

int main(void)
{
    double x0 = inicio;
    double y0 = 1.0;
    double h = paso;
    double x_fin = fin;

    printf("x       y       y_predictor\n");

    resolver_edo(x0, y0, h, x_fin);

    return 0;
}

double derivada(double x, double y)
{
    return x + 2 * x * y;
}

double Euler_predictor_corrector(double x, double y, double h, double *y_predictor)
{
    *y_predictor = y + h * derivada(x, y);
    return y + (h / 2.0) * (derivada(x, y) + derivada(x + h, *y_predictor));
}


void imprimir_tabla(double x, double y, double y_predictor)
{
    printf("%.2lf   %.10lf  %.10lf\n", x, y_predictor, y);
}

void resolver_edo(double x0, double y0, double h, double x_fin)
{
    double x = x0;
    double y = y0;
    double y_predictor = 0.0;

    while (x <= x_fin)
    {
        imprimir_tabla(x, y, y_predictor);
        y = Euler_predictor_corrector(x, y, h, &y_predictor);
        x += h;
    }
}
