#include <stdio.h>
#include <math.h>

#define inicio 0.0
#define fin2 4.0
#define paso 0.5

void euler_metodo(double (*funcion_derivada)(double, double), double h, double x_inicial, double y_inicial, double x_final);
double derivada2(double x, double y);

int main(void)
{
    double h = paso;
    double x_inicial = inicio;

    // Resuelve la segunda ecuación diferencial
    printf("\nSolución de la segunda ecuación diferencial:\n");
    euler_metodo(derivada2, h, x_inicial, 1.0, fin2);

    return 0;
}

void euler_metodo(double (*funcion_derivada)(double, double), double h, double x_inicial, double y_inicial, double x_final)
{
    double x_actual = x_inicial;
    double y_actual = y_inicial;
    double y_predictor;

    printf("x       y       y_predictor       y_real\n");
    printf("%.2lf   %.10lf   %.10lf   %.10lf\n", x_actual, y_actual, y_actual, y_actual);

    while (x_actual < x_final)
    {
        y_predictor = y_actual + h * funcion_derivada(x_actual, y_actual);
        y_actual = y_actual + h * (funcion_derivada(x_actual, y_actual) + funcion_derivada(x_actual + h, y_predictor)) / 2.0;
        x_actual += h;

        printf("%.2lf   %.10lf   %.10lf   %.10lf\n", x_actual, y_actual, y_predictor, y_actual);
    }
}

double derivada2(double x, double y)
{
    return (-2 * pow(x, 3)) + (12 * pow(x, 2)) - (20 * x) + 8.5;
}