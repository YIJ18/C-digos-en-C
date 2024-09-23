#include <stdio.h>
#include <math.h>

#define inicio 0.0
#define fin2 2.0

void solve_differential_equation(double (*funcion_derivada)(double, double), double x_inicial, double y_inicial, double x_final, double h, const char *method_name);
double derivada(double x, double y);
double midpoint_method(double (*funcion_derivada)(double, double), double x, double y, double h);
double runge_kutta_method(double (*funcion_derivada)(double, double), double x, double y, double h);

int main(void)
{
    double x_inicial = inicio;

    // Resuelve la ecuación diferencial con h = 0.2
    solve_differential_equation(derivada, x_inicial, 3.0, fin2, 0.2, "Euler");

    // Resuelve la ecuación diferencial con h = 0.1
    solve_differential_equation(derivada, x_inicial, 3.0, fin2, 0.1, "Euler");

    // Resuelve la ecuación diferencial con h = 0.05
    solve_differential_equation(derivada, x_inicial, 3.0, fin2, 0.05, "Euler");

    return 0;
}

void solve_differential_equation(double (*funcion_derivada)(double, double), double x_inicial, double y_inicial, double x_final, double h, const char *method_name)
{
    double x_actual = x_inicial;
    double y_actual = y_inicial;

    printf("x        %s       Punto        Runge-Kutta\n", method_name);
    printf("%.2lf    %.5lf    %.5lf        %.5lf\n", x_actual, y_actual, y_actual, y_actual);

    while (x_actual < x_final)
    {
        double k1, k2, k3, k4;

        k1 = h * funcion_derivada(x_actual, y_actual);
        k2 = h * funcion_derivada(x_actual + h / 2.0, y_actual + k1 / 2);
        k3 = h * funcion_derivada(x_actual + h / 2.0, y_actual + k2 / 2);
        k4 = h * funcion_derivada(x_actual + h, y_actual + k3);

        // Euler's method
        y_actual = y_actual + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);

        // Midpoint method
        double midpoint = midpoint_method(funcion_derivada, x_actual, y_actual, h);

        // Runge-Kutta method
        double runge_kutta = runge_kutta_method(funcion_derivada, x_actual, y_actual, h);

        x_actual += h;

        printf("%.2lf    %.5lf    %.5lf            %.5lf\n", x_actual, y_actual, midpoint, runge_kutta);
    }
}

double derivada(double x, double y)
{
    return 1 + 2 * x * y;
}

double midpoint_method(double (*funcion_derivada)(double, double), double x, double y, double h)
{
    double k1 = h * funcion_derivada(x, y);
    double k2 = h * funcion_derivada(x + h / 2.0, y + k1 / 2);
    return y + k2;
}

double runge_kutta_method(double (*funcion_derivada)(double, double), double x, double y, double h)
{
    double k1 = h * funcion_derivada(x, y);
    double k2 = h * funcion_derivada(x + h / 2.0, y + k1 / 2);
    double k3 = h * funcion_derivada(x + h / 2.0, y + k2 / 2);
    double k4 = h * funcion_derivada(x + h, y + k3);
    return y + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
}
