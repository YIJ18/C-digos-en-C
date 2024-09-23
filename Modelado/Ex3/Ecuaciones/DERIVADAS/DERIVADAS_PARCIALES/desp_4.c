#include <stdio.h>
#include <math.h>

#define h 0.01F

double F(double x, double y, double z, double w);

double y_derivada_atras(double x, double y, double z, double w, int n);
double x_derivada_atras(double x, double y, double z, double w, int n);
double z_derivada_atras(double x, double y, double z, double w, int n) double w_derivada_atras(double x, double y, double z, double w, int n)

    double diferencia(double x, double y, double z, double w, double *x2, double *y2, double *z2, double *w2);
double diferencia_derivada_dW(double x, double y, double z, double w, double x2, double y2, double z2, double w2);
double diferencia_derivada_deltaW(double x, double y, double z, double w, double x2, double y2, double z2, double w2);

int main(void)
{
    double i, x = 1, y = 4, z = 2, x1 = 1.02, y1 = 3.97, z1 = 1.96;
    printf("------------------------------------------------------\n");
    printf("           Cálculos de Desplazamiento\n");
    printf("------------------------------------------------------\n");
    printf("Punto inicial: (%lf, %lf, %lf)\n", x, y, z);
    printf("Punto dezplazado:    (%lf, %lf,%lf)\n", x1, y1, z1);
    printf("------------------------------------------------------\n");
    diferencia(x, y, z, &x1, &y1, &z1);
    printf("Resultados:  en x = %lf  en y = %lf en z = %lf \n", x1, y1, z1);
    printf("------------------------------------------------------\n");
    printf("El desplazamiento es de:\n");
    printf("dW = %lf\n", diferencia_derivada_dW(x, y, z, x1, y1, z1));
    printf("Delta W = %lf\n", diferencia_derivada_deltaW(x, y, z, x1, y1, z1));
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
double F(double x, double y, double z, double w)
{
    return pow(x, 2) + (3 * y * z) + (2 * pow(x, 3));
}

/**
 * Función que calcula la derivada de x-ésimo orden respecto a x.
 *
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @param n Orden de la derivada.
 * @return Derivada de x-ésimo orden respecto a x.
 */
double x_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (x_derivada_atras(x, y, z, n - 1) - x_derivada_atras(x - h, y, z, n - 1)) / h;
}

/**
 * Función que calcula la derivada de x-ésimo orden respecto a y.
 *
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @param n Orden de la derivada.
 * @return Derivada de x-ésimo orden respecto a y.
 */
double y_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (y_derivada_atras(x, y, z, n - 1) - y_derivada_atras(x, y - h, z, n - 1)) / h;
}

/**
 * Función que calcula la derivada de x-ésimo orden respecto a y.
 *
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @param n Orden de la derivada.
 * @return Derivada de x-ésimo orden respecto a y.
 */
double z_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (z_derivada_atras(x, y, z, n - 1) - z_derivada_atras(x, y, z - h, n - 1)) / h;
}
/**
 * Función que calcula la derivada de x-ésimo orden respecto a w.
 *
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @param n Orden de la derivada.
 * @return Derivada de x-ésimo orden respecto a y.
 */
double w_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z, w);
    else
        return (z_derivada_atras(x, y, z, w, n - 1) - z_derivada_atras(x, y, z, w - h, n - 1)) / h;
}
/**
 * Función que calcula la diferencia entre dos puntos y actualiza los valores de x2 e y2.
 *
 * @param x Coordenada x inicial.
 * @param y Coordenada y inicial.
 * @param x2 Coordenada x final (se actualiza).
 * @param y2 Coordenada y final (se actualiza).
 */
double diferencia(double x, double y, double z, double *x2, double *y2, double *z2)
{
    *x2 = *x2 - x;
    *y2 = *y2 - y;
    *z2 = *z2 - z;
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
double diferencia_derivada_dW(double x, double y, double z, double x2, double y2, double z2)
{
    return (x_derivada_atras(x, y, z, 1) * x2) + (y_derivada_atras(x, y, z, 1) * y2) + (z_derivada_atras(x, y, z, 1) * z2);
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
double diferencia_derivada_deltaW(double x, double y, double z, double x2, double y2, double z2)
{
    return F(x + x2, y + y2, z + z2) - F(x, y, z);
}