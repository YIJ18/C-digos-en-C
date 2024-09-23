#include <stdio.h>
#include <math.h>

#define h 0.01
#define inicio 0.0
#define fin 4.0
#define numCuad 100
#define PI 3.1416


double F(double x);
double integral_centro(double delta);

double integral_derecha(double dx);

int main (void)
{
  double delta =(fin-inicio)/numCuad;
  printf("El volumen del solido de rovolucion es %lf\n",  integral_derecha( delta));
}

double integral_derecha(double dx)
{
    double i = 0;
    double a = 0;

    for (i = inicio + (dx); i <= fin; i += dx)
        a += (F(i) * dx);
    return a;
}

/*
** Calcula el valor de la función F en el punto x.
** @param x Valor en el que se evalúa la función.
** @return El valor de la función en x.
*/
double F(double x)
{
  return pow( (6 - x), 2) * PI;
}
