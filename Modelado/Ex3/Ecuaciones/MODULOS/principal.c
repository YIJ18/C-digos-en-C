#include <stdio.h>
#include "funciones.h"
#include "gnuplot.h"

int main(void)
{
  double x0, xf, h;
  printf("Dame x0, xf, y h separa por comas: \n");
  scanf("%lf, %lf, %lf", &x0, &xf, &h);
  datos_Graficar(f1, x0, xf, h, "grafica_1.txt");
  datos_Graficar(f2, x0, xf, h, "grafica_2.txt");
  datos_Graficar(f3, x0, xf, h, "grafica_3.txt");

  graficar_3_lineas("grafica_1.txt",  "grafica_2.txt", "grafica_3.txt");
  return 0;
}
