// regla del trapezoide
#include <stdio.h>
#define inicio 0.5
#define fin 2.0

double F(double x);
double integral_centro(double delta);
double integral_izquierda(double dx);
double integral_derecha(double dx);
double trapezoide(double dx);

int main(void)
{
    double delta = 0, numCuad, error_a = 0.0, error_p = 0.0;
    for (numCuad = 3; numCuad <= 10; numCuad++)
    {
        delta = (fin-inicio) / numCuad;

        printf("\n+-----------------------------------------------+\n");

        if (numCuad == 10)
            printf("| Con %.0lf cuadrados                              |\n", numCuad);
        else
            printf("| Con %.0lf cuadrados                               |\n", numCuad);
        printf("|   - El resultado de la izquierda : %.5lf    |\n", integral_izquierda(delta));
        printf("|   - El resultado de la derecha   : %.5lf    |\n", integral_derecha(delta));
        printf("|   - El resultado del centro      : %.5lf    |\n", integral_centro(delta));
        printf("|   - El resultado del trapezoide  : %.5lf    |\n", trapezoide(delta));

        printf("+-----------------------------------------------+\n");
    }
    return 0;
}

/*
** Calcula el valor de la función F en el punto x.
** @param x Valor en el que se evalúa la función.
** @return El valor de la función en x.
*/
double F(double x)
{
    return (1 / x);
}

/*
** Calcula la integral usando el método del centro.
** @param dx Ancho de los intervalos.
** @return Aproximación de la integral.
*/
double integral_centro(double delta)
{
    double i = 0;
    double a = 0;

    for (i = inicio + delta / 2; i < fin; i += delta)
        a += (F(i) * delta);
    return a;
}

/*
** Calcula la integral usando el método de la izquierda.
** @param dx Ancho de los intervalos.
** @return Aproximación de la integral.
*/
double integral_izquierda(double dx)
{
    double i = 0;
    double a = 0;

    for (i = inicio; i < fin; i += dx)
        a += (F(i) * dx);

    return a;
}

/*
** Calcula la integral usando el método de la derecha.
** @param dx Ancho de los intervalos.
** @return Aproximación de la integral.
*/
double integral_derecha(double dx)
{
    double i = 0;
    double a = 0;

    for (i = inicio + (dx); i <= fin; i += dx)
        a += (F(i) * dx);
    return a;
}

/*
** Calcula la integral usando el método del trapecio.
** @param dx Ancho de los intervalos.
** @return Aproximación de la integral.
*/
double trapezoide(double dx)
{
    double i, res;
    res = 0;
    for (i = inicio + dx; i <= fin - dx; i += dx)
        res += F(i);
    return (F(inicio) + (2 * res) + F(fin)) * (dx / 2);
}