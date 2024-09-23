#include <stdio.h>
#include "integrales.h"
#include "ecuaciones.h"
#include "gnuplot.h"

int main(void)
{
    double x0 = 0.0;        
    double y0 = 8.33;
    double h = 0.2;          
    double x_fin = 5;
    printf("x       y       y_predictor\n");
    resolver_edo(x0, y0, h, x_fin);
    graficar_2_lineas("eu_y.txt", "eu_y_corrector.txt");
    return 0;
}
