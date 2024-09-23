// regla del trapezoide
#include <stdio.h>

// INTERVALOS EN LOS QUE SE CALCULA LA INTEGRAL
#define inicio 0.5
#define fin 2.0

// INTEGRAL
double F(double x);

// RIEMANN
double integral_centro(double delta);
double integral_izquierda(double dx);
double integral_derecha(double dx);

// TRAPEZOIDE
double trapezoide(double dx);

// ERROR
void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual);

int main(void)
{
    
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
** @param dx Ancho de los intervalos.  delta = (inicio-fin)/numCuad o intervalos
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

// ERRORES
/**
 * Calcula el error relativo y el error porcentual de una aproximación respecto al valor real.
 *
 * @param valor_aprox Valor aproximado.
 * @param error_relativo Puntero a la variable donde se almacenará el error relativo.
 * @param error_porcentual Puntero a la variable donde se almacenará el error porcentual.
 */
void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual)
{
    double valor_real = 1.5566; // es el valor esperado
    *error_relativo = (valor_real - valor_aprox) / valor_real;
    *error_porcentual = *error_relativo * 100;
}
