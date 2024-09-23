#include <stdio.h>
#include <math.h>

#define h 0.01F

double F_des(double x, double y);

double y_derivada_atras(double x, double y, int n);
double x_derivada_atras(double x, double y, int n);

void diferencia(double x, double y, double *x2, double *y2);
double diferencia_derivada_dW(double x, double y, double x2, double y2);
double diferencia_derivada_deltaW(double x, double y, double x2, double y2);

double problema_desplazamiento();

int main(void)
{
    problema_desplazamiento();
}

double problema_desplazamiento()
{
    // Y1 Y X1 YA NOS LO DAN ELLOS
    double i, x = -2, y = 3, y1 = 3.01, x1 = -2.02;
    printf("------------------------------------------------------\n");
    printf("           Cálculos de Desplazamiento\n");
    printf("------------------------------------------------------\n");
    printf("Punto inicial: (%lf, %lf)\n", x, y);
    printf("Punto dezplazado:    (%lf, %lf)\n", x1, y1);
    printf("------------------------------------------------------\n");
    diferencia(x, y, &x1, &y1);
    printf("Resultados:  en x = %lf  en y = %lf \n", x1, y1);
    printf("------------------------------------------------------\n");
    printf("El desplazamiento es de:\n");
    printf("dW = %lf\n", diferencia_derivada_dW(x, y, x1, y1));
    printf("Delta W = %lf\n", diferencia_derivada_deltaW(x, y, x1, y1));
    printf("------------------------------------------------------\n");

    return 0;
}

/**
 * Función que calcula el valor de la función F(x, y).
 *
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @return Valor de la función F(x, y).
 */
double F_des(double x, double y)
{
    return ((x * x) - (3 * pow(x, 3) * pow(y, 2)) + (4 * x) - (2 * pow(y, 3)) + 6);
    // return (3 * x * x) - (x * y);
}

/**
 * Función que calcula la derivada de x-ésimo orden respecto a x.
 *
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @param n Orden de la derivada.
 * @return Derivada de x-ésimo orden respecto a x.
 */
double x_derivada_atras(double x, double y, int n)
{
    if (n == 0)
        return F_des(x, y);
    else
        return (x_derivada_atras(x, y, n - 1) - x_derivada_atras(x - h, y, n - 1)) / h;
}

/**
 * Función que calcula la derivada de x-ésimo orden respecto a y.
 *
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @param n Orden de la derivada.
 * @return Derivada de x-ésimo orden respecto a y.
 */
double y_derivada_atras(double x, double y, int n)
{
    if (n == 0)
        return F_des(x, y);
    else
        return (y_derivada_atras(x, y, n - 1) - y_derivada_atras(x, y - h, n - 1)) / h;
}

/**
 * Función que calcula la diferencia entre dos puntos y actualiza los valores de x2 e y2.
 *
 * @param x Coordenada x inicial.
 * @param y Coordenada y inicial.
 * @param x2 Coordenada x final (se actualiza).
 * @param y2 Coordenada y final (se actualiza).
 */
void diferencia(double x, double y, double *x2, double *y2)
{
    *x2 = *x2 - x;
    *y2 = *y2 - y;
}

/**
 * Función que calcula la derivada de dW respecto a la diferencia de coordenadas.
 *
 * @param x Coordenada x inicial.
 * @param y Coordenada y inicial.
 * @param x2 Diferencia en la coordenada x.
 * @param y2 Diferencia en la coordenada y.
 * @return Derivada de dW respecto a la diferencia de coordenadas.
 */
double diferencia_derivada_dW(double x, double y, double x2, double y2)
{
    return (x_derivada_atras(x, y, 1) * x2) + (y_derivada_atras(x, y, 1) * y2);
}

/**
 * Función que calcula la diferencia en el valor de la función entre dos puntos.
 *
 * @param x Coordenada x inicial.
 * @param y Coordenada y inicial.
 * @param x2 Diferencia en la coordenada x.
 * @param y2 Diferencia en la coordenada y.
 * @return Diferencia en el valor de la función entre dos puntos.
 */
double diferencia_derivada_deltaW(double x, double y, double x2, double y2)
{
    return F_des(x + x2, y + y2) - F_des(x, y);
}