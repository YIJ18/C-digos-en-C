#include <stdio.h>
#include <math.h>

#define inicio 0.0
#define fin2 1.0
#define h 0.1 //0.1 y 0.05

void euler_metodo(double (*funcion_derivada)(double, double), double x_inicial, double y_inicial, double x_final);
double derivada2(double x, double y);
double eulerPuntoMedio(double x, double y);
double f(double x, double y);
double error(double y_real, double y_aprox);

int main(void)
{
    double x_inicial = inicio;

    // Resuelve la segunda ecuación diferencial
    printf("\nSolución de la segunda ecuación diferencial:\n");
    euler_metodo(derivada2, x_inicial, 1.0, fin2);

    return 0;
}

void euler_metodo(double (*funcion_derivada)(double, double), double x_inicial, double y_inicial, double x_final)
{
    double x_actual = x_inicial;
    double y_actual = y_inicial;
    double y_predictor;
    double p_m = 0.0;
    double y_real = 0.0;

    printf("x        y        pm         error    error pm    Valor Real\n");
    printf("%.2lf    %.5lf   %.5lf    0.00000   0.00000    %.5lf\n", x_actual, y_actual, y_actual, f(x_actual, y_actual));

    while (x_actual < x_final)
    {
        y_predictor = y_actual + h * funcion_derivada(x_actual, y_actual);

        // punto medio y error
        p_m = eulerPuntoMedio(x_actual, y_actual);
        y_actual = y_actual + h * (funcion_derivada(x_actual, y_actual) + funcion_derivada(x_actual + h, y_predictor)) / 2.0;
        x_actual += h;
        y_real = f(x_actual, y_actual);
        printf("%.2lf    %.5lf   %.5lf    %.5lf   %.5lf    %.5lf \n", x_actual, y_actual, p_m, error(y_real, y_actual), error(y_real, p_m), y_real);
    }
}

double derivada2(double x, double y)
{
    return ((pow(x, 3) * exp(-2 * x)) - (2 * y));
}

double eulerPuntoMedio(double x, double y)
{
    return y + h * derivada2(x + h / 2, y + h / 2 * derivada2(x, y));
}

double f(double x, double y)
{
    return exp(-2 * x) / 4.0 * (pow(x, 4) + 4);
}

double error(double y_real, double y_aprox)
{
    return fabs((y_real - y_aprox) / y_real)*100;
}