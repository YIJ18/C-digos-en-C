#include <stdio.h>
#include <math.h>

double derivada(double x, double y);
double runge_kutta(double (*derivada)(double, double), double x, double y, double h);
void resolver(double (*derivada)(double, double), double x_inicial, double y_inicial, double x_final, double h);
void llamar_runge();

int main(void)
{
    llamar_runge();
    return 0;
}

/**
 ** Llama a la función que utiliza el método de Runge-Kutta para resolver una ecuación diferencial.
 ** Param: No recibe nada
 ** Return: no retorna nada
 **/
void llamar_runge()
{
    double x_inicial = 0.0; // inicio
    double fin2 = 4.0;      // fin
    // Resuelve la ecuación diferencial con h = 0.2
    // El tercer parametro que se le manda es donde inicia la y, en este caso es 1
    resolver(derivada, x_inicial, 1.0, fin2, 0.25);
}

/**
 * Resuelve una ecuación diferencial ordinaria (EDO) utilizando el método de Runge-Kutta de cuarto orden.
 * Imprime una tabla con los resultados.
 *
 * @param funcion_derivada Puntero a la función que define la derivada de la EDO.
 * @param x_inicial Valor inicial de la variable independiente.
 * @param y_inicial Valor inicial de la función dependiente.
 * @param x_final Valor final de la variable independiente.
 * @param h Tamaño del paso.
 * @return no retorna nada
 */
void resolver(double (*funcion_derivada)(double, double), double x_inicial, double y_inicial, double x_final, double h)
{
    double x_actual = x_inicial;
    double y_actual = y_inicial;
    double runge;

    printf("x        rungen\n");
    printf("%.2lf\t\t%.5lf\n", x_actual, y_actual);

    while (x_actual < x_final)
    {
        runge = runge_kutta(funcion_derivada, x_actual, y_actual, h);
        x_actual += h;
        y_actual = runge;

        printf("%.2lf\t\t%.5lf\n", x_actual, y_actual);
    }
}

/**
 * Define la derivada de la función que se desea resolver.
 *
 * @param x Valor de la variable independiente.
 * @param y Valor de la función dependiente.
 * @return Valor de la derivada en el punto (x, y).
 */
double derivada(double x, double y)
{
    return pow(x, 3) * exp(-2 * x) - 2 * y;
}

/**
 * Implementa el método de Runge-Kutta de cuarto orden para resolver una EDO.
 *
 * @param derivada Puntero a la función que define la derivada de la EDO.
 * @param x Valor de la variable independiente.
 * @param y Valor de la función dependiente.
 * @param h Tamaño del paso.
 * @return Nueva aproximación de y utilizando el método de Runge-Kutta.
 */
double runge_kutta(double (*derivada)(double, double), double x, double y, double h)
{
    double k1 = h * derivada(x, y);
    double k2 = h * derivada(x + h / 2.0, y + k1 / 2);
    double k3 = h * derivada(x + h / 2.0, y + k2 / 2);
    double k4 = h * derivada(x + h, y + k3);
    return y + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
}
