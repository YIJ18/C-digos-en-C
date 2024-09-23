#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define h 0.01

double F(double x, double y, double z);

double x_derivada_atras(double x, double y, double z, int n);
double y_derivada_atras(double x, double y, double z, int n);
double x_y_derivada_atras(double x, double y, double z, int n);
double y_x_derivada_atras(double x, double y, double z, int n);
double z_derivada_atras(double x, double y, double z, int n);

int main(void)
{
    double x = 0.0, y = 0.0, z = 0.0;
    int i = 1;

    printf("Dame el valor de x: ");
    scanf("%lf", &x);
    printf("Dame el valor de y: ");
    scanf("%lf", &y);
    printf("Dame el valor de z: ");
    scanf("%lf", &z);

    printf("\n--------------------------------------\n");
    printf(" Derivada (x = %.2lf) (y = %.2lf) (z = %.2lf)\n", x, y, z);
    printf("--------------------------------------\n");
    printf("\t Fx = %.6lf\n", x_derivada_atras(x, y, z, 1));
    printf("\t Fy = %.6lf\n", y_derivada_atras(x, y, z, 1));

    printf("\t Fxx = %.6lf\n", x_derivada_atras(x, y, z, 2));
    printf("\t Fyy = %.6lf\n", y_derivada_atras(x, y, z, 2));

    printf("\t Fxy = %.6lf\n", x_y_derivada_atras(x, y, z, 1));
    printf("\t Fyx = %.6lf\n", y_x_derivada_atras(x, y, z, 1));

    printf("\t Fxz = %.6lf\n", z_derivada_atras(x, y, z, 1));

    printf("\n");
    return 0;
}

/**
 * Función para evaluar F(x, y, z)
 *
 * @param x Valor de x
 * @param y Valor de y
 * @param z Valor de z
 * @return El resultado de F(x, y, z)
 */
double F(double x, double y, double z)
{
    return pow((x * x) + (y * y) + (z * z), 0.5);
}

/**
 * Calcula la derivada de x derivada atrás de F(x, y, z) en los puntos x, y, z
 *
 * @param x Punto en el que se calcula la derivada
 * @param y Punto en el que se calcula la derivada
 * @param z Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada atrás
 */
double x_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (x_derivada_atras(x, y, z, n - 1) - x_derivada_atras(x - h, y, z, n - 1)) / h;
}

/**
 * Calcula la derivada de y derivada atrás de F(x, y, z) en los puntos x, y, z
 *
 * @param x Punto en el que se calcula la derivada
 * @param y Punto en el que se calcula la derivada
 * @param z Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la derivada hacia atrás
 */
double y_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (y_derivada_atras(x, y, z, n - 1) - y_derivada_atras(x, y - h, z, n - 1)) / h;
}

/**
 * Calcula la derivada de y derivada atrás de F(x, y, z) en los puntos x, y, z
 *
 * @param x Punto en el que se calcula la derivada
 * @param y Punto en el que se calcula la derivada
 * @param z Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la derivada hacia atrás
 */
double x_y_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
    {
        if (n == 1)
            return (y_derivada_atras(x, y, z, n - 1) - y_derivada_atras(x, y - h, z, n - 1)) / h;
        else
            return (x_derivada_atras(x, y, z, n) - x_derivada_atras(x - h, y, z, n)) / h;
    }
}

/**
 * Calcula la derivada de y derivada atrás de F(x, y, z) en los puntos x, y, z
 *
 * @param x Punto en el que se calcula la derivada
 * @param y Punto en el que se calcula la derivada
 * @param z Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la derivada hacia atrás
 */
double y_x_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
    {
        if (n == 1)
            return (x_derivada_atras(x, y, z, n - 1) - x_derivada_atras(x - h, y, z, n - 1)) / h;
        else
            return (y_derivada_atras(x, y, z, n) - y_derivada_atras(x, y - h, z, n)) / h;
    }
}

/**
 * Calcula la derivada de z derivada atrás de F(x, y, z) en los puntos x, y, z
 *
 * @param x Punto en el que se calcula la derivada
 * @param y Punto en el que se calcula la derivada
 * @param z Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada atrás
 */
double z_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (z_derivada_atras(x, y, z, n - 1) - z_derivada_atras(x, y, z - h, n - 1)) / h;
}
