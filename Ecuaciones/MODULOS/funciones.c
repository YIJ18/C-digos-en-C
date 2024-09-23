/*** PARTE PUBLICA ***/

/**
 * Módulo funciones.c
 *
 * Contiene tres funciones matemáticas.
 *
 */

 
double f1(double x);
double f2(double x);
double f3(double x);


/*** PARTE PRIVADA ***/
#include <math.h>

double f1(double x)
{
  return pow(x,4) + 2*pow(x,3) - 3*pow(x,2) - 3*x + 1;
}

double f2(double x)
{
  return pow(x,4) + 2*pow(x,3) - 3*pow(x,2) - 3*x + 2;
}

double f3(double x)
{
  return pow(x,4) + 2*pow(x,3) - 3*pow(x,2) - 3*x + 3;
}

