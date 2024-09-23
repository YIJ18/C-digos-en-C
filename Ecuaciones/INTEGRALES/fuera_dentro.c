// regla del trapezoide
#include <stdio.h>
#include <math.h>
#define inicio 1.0
#define fin 3.0
#define valor_real 0.31236

double F(double x);
double integral_centro(double delta);
double integral_izquierda(double dx);
double integral_derecha(double dx);
double trapezoide(double dx);
void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual);

int main(void)
{
    double delta = 0, numCuad, error_a = 0.0, error_p = 0.0;

    for (numCuad = 3; numCuad <= 10; numCuad++)
    {
        delta = (fin - inicio) / numCuad;
        error_a = 0.0, error_p = 0.0;
        error_r_p(integral_izquierda(delta), &error_a, &error_p);
        if (error_p < 0.0)
            error_p = error_p * -1;
        printf("|   - El resultado de la izquierda : %.5lf, error_r = %.5lf, error_p = %.5lf    \n", integral_izquierda(delta), error_a, error_p);
        error_a = 0.0, error_p = 0.0;
        error_r_p(integral_derecha(delta), &error_a, &error_p);
        if (error_p < 0.0)
            error_p = error_p * -1;
        printf("|   - El resultado de la derecha   : %.5lf, error_r = %.5lf, error_p = %.5lf    \n", integral_derecha(delta), error_a, error_p);
        error_a = 0.0, error_p = 0.0;
        error_r_p(integral_centro(delta), &error_a, &error_p);
        if (error_p < 0.0)
            error_p = error_p * -1;
        printf("|   - El resultado del centro      : %.5lf, error_r =  %.5lf, error_p = %.5lf    \n", integral_centro(delta), error_a, error_p);
        error_a = 0.0, error_p = 0.0;
        error_r_p(trapezoide(delta), &error_a, &error_p);
        if (error_p < 0.0)
            error_p = error_p * -1;
        printf("|   - El resultado del trapezoide  : %.5lf, error_r = %.5lf, error_p = %.5lf    \n", trapezoide(delta), error_a, error_p);

        printf("+-----------------------------------------------+\n");
    }
    return 0;
}

double F(double x)
{
    return 1 / (x * sqrt(9 + (x * x)));
}

/*
** Calcula la integral usando el método del centro.
** @param delta Ancho de los intervalos.
** @return Aproximación de la integral.
*/
double integral_centro(double delta)
{
    double i = 0, a = 0;

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
    double i = 0, a = 0;

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
    double i = 0, a = 0;

    for (i = inicio + (dx); i <= fin; i += dx)
        a += (F(i) * dx);
    return a;
}

double trapezoide(double dx)
{
    double i, res = 0;
    for (i = inicio + dx; i <= (fin-dx-0.01)|| i <= (fin-dx+0.01); i += dx)
    {
        res += F(i);
    }
    return (F(inicio) + (2 * res) + F(fin)) * (dx / 2);
}

/*
** Calcula el error relativo y porcentual
** @param valor_aprox manda el valor de la integral.
**@param error_relativo regresa el error relativo
**@param error_porcentual  regresa el error porcentual
** @return vacío
*/
void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual)
{
    *error_relativo = (valor_real - valor_aprox) / valor_real;
    *error_porcentual = *error_relativo * 100;
}