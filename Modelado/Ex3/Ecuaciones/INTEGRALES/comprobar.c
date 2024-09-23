// funcion 1 / x
#include <math.h>
#include <stdio.h>

// intervalos de integracion
#define vf 2.0
#define vi 0.5
#define valor_real 2 * log(2)
#define valor_aprox

double F(double x);
double Riemann_Central(double inicio, double fin, double dx);
double Riemann_Izquierda(double inicio, double fin, double dx);
double Riemann_Derecha(double inicio, double fin, double dx);
double Trapezoide(double inicio, double fin, double dx);

int main(void)
{
  double dx;

  double n;

  for (n = 3; n <= 10; n++)
  {

    printf("---------------------------------\n");

    printf("N: %.1lf\n", n);

    dx = (vf - vi) / n;

    printf("Sumatoria Central: %lf \n", Riemann_Central(vi, vf, dx));
    printf("Sumatoria Izquierda: %lf \n", Riemann_Izquierda(vi, vf, dx));
    printf("Sumatoria Derecha: %lf \n\n", Riemann_Derecha(vi, vf, dx));
    printf("Trapezoide: %lf \n\n", Trapezoide(vi, vf, dx));
  }

  return 0;
}

double F(double x) { return (1 / x); }

double Riemann_Central(double inicio, double fin, double dx)
{
  double x, suma, ciclos;

  suma = 0;
  ciclos = 1;
  for (x = inicio; x <= fin; x += dx)
  {
    suma += F(x + (dx / 2.0));
    ciclos++;
  }
  // printf ("Ciclos hechos: %lf\n\n", ciclos);
  return suma * dx;
}

double Riemann_Izquierda(double inicio, double fin, double dx)
{
  double x, suma, ciclos;

  suma = 0;
  ciclos = 1;
  for (x = inicio; x < fin; x += dx)
  {
    suma += F(x);
    ciclos++;
  }
  //  printf ("Ciclos hechos: %lf\n\n", ciclos);
  return suma * dx;
}

double Riemann_Derecha(double inicio, double fin, double dx)
{
  double x, suma, ciclos;

  suma = 0;
  ciclos = 1;
  for (x = inicio; x < fin; x += dx)
  {
    suma += F(x + dx);
    ciclos++;
  }
  //  printf ("Ciclos hechos: %lf\n\n", ciclos);
  return suma * dx;
}

double Trapezoide(double inicio, double fin, double dx)
{
  double x, suma, ciclos;

  suma = 0;
  ciclos = 1;
  for (x = inicio + dx; x <= fin - dx; x += dx)
  {
    suma += F(x);
    ciclos++;
  }
  // printf ("Ciclos hechos: %lf\n\n", ciclos);
  return (F(inicio) + F(fin) + (2 * suma)) * (dx / 2);
}

void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual)
{
    *error_relativo = (valor_real - valor_aprox) / valor_real;
    *error_porcentual = *error_relativo * 100;
}