#include <stdio.h>
#include <math.h>

#define inicio 0.0
#define fin 4.0
#define paso 0.25

double derivada(double x);
double Euler(double x, double y, double h);
double Error(double y1, double y2);
double funcion(double x);
double Error_local(double y1, double y2);

int main(void)
{
  double x = inicio;
  double y = 1.0;
  double h = paso;
  double y_calculada, error;
  printf("X   	Y   	Ycalcu   Error\n");

  while (x <= fin)
  {
    y_calculada = funcion(x);
    error = Error(y, y_calculada);
    printf("%.1lf %.5lf  %.5lf  %.2lf%%\n", x, y, y_calculada, error);
    y = Euler(x, y, h);
    x += h;
  }

  return 0;
}

double derivada(double x)
{
  return (-2 * x * x * x) + (12 * x * x) - (20 * x) + 8.5;
}

double Euler(double x, double y, double h)
{
  return y + h * derivada(x);
}

double funcion(double x)
{
  return -0.5 * pow(x, 4) + 4 * pow(x, 3) - 10 * pow(x, 2) + 8.5 * x + 1;
}

double Error(double y1, double y2)
{
  return fabs((y2 - y1) / y2) * 100.0;
}