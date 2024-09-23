#include <stdio.h>
#include <math.h>

#define h 0.01

double F(double x);
/* ------ DERIVADAS ------ */
// 1ra Derivada
double derivada_adelante(double a); // se usa para n derivada y para derivada 1
double derivada_atras(double a);
double derivada_central(double a);
double F(double x);

// n Derivada
double n_derivada_adelante(double x, int n);
double n_derivada_atras(double x, int n);
double n_derivada_central(double x, int n);

// Derivadas parciales
double F_parcial(double x, double y);
double DfXX_Central(double x, double y);
double DfYY_Central(double x, double y);
double DfXY_Central(double x, double y);
double DfYX_Central(double x, double y);

// NEWTON
float F_Newton(float x);
float Newton(float xn);
float derivada(float a);
float problema_newton();

// ERRORES Y DESPLAZAMIENTO
double F_des(double x, double y);
double y_derivada_atras(double x, double y, int n);
double x_derivada_atras(double x, double y, int n);
void diferencia(double x, double y, double *x2, double *y2);
double diferencia_derivada_dW(double x, double y, double x2, double y2);
double diferencia_derivada_deltaW(double x, double y, double x2, double y2);

double problema_desplazamiento();

int main(void)
{

    return 0;
}

/* --------Funciones-------*/
double F(double x)
{
    return sqrt(1 + pow(x, 3));
}

double F_parcial(double x, double y)
{
    return x + y;
}

/* ------ DERIVADAS ------ */

// 1RA
double F(double x)
{
    return (9.0 * x) - 2;
}


/**
 * Calcula la derivada de F en un punto utilizando diferencia adelante.
 *
 * @param a Punto en el que se evalúa la derivada.
 * @return El valor de la derivada en el punto a.
 */
double derivada_adelante(double a)
{
    return (F(a + h) - F(a)) / h;
}


/**
 * Calcula la derivada de F en un punto utilizando diferencia ATRAS.
 *
 * @param a Punto en el que se evalúa la derivada.
 * @return El valor de la derivada en el punto a.
 */
double derivada_atras(double a)
{
    return (F(a) - F(a - h)) / h;
}


/**
 * Calcula la derivada de F en un punto utilizando diferencia CENTRO.
 *
 * @param a Punto en el que se evalúa la derivada.
 * @return El valor de la derivada en el punto a.
 */
double derivada_central(double a)
{
    return (F(a + h) - F(a - h)) / (2 * h);
}

// N DERIVADA

/**
 * Calcula la n-ésima derivada adelante de F(x) en el punto x
 *
 * @param x Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada adelante
 */
double n_derivada_adelante(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_adelante(x + h, n - 1) - n_derivada_adelante(x, n - 1)) / h;
}

/**
 * Calcula la n-ésima derivada adelante de F(x) en el punto x
 *
 * @param x Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada adelante
 */
double n_derivada_atras(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_atras(x, n - 1) - n_derivada_atras(x - h, n - 1)) / h;
}

/**
 * Calcula la n-ésima derivada adelante de F(x) en el punto x
 *
 * @param x Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada adelante
 */
double n_derivada_central(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_central(x + h, n - 1) - n_derivada_central(x - h, n - 1)) / (2 * h);
}

// DERIVADA PARCIAL

/**
 * Calcula la segunda derivada parcial respecto a x en un punto dado (usando diferencia central).
 *
 * @param x Valor de la coordenada x.
 * @param y Valor de la coordenada y.
 * @return El valor de la segunda derivada parcial respecto a x en el punto (x, y).
 */
double DfXX_Central(double x, double y)
{
    return (F_parcial(x + h, y) - (2 * F_parcial(x, y)) + F_parcial(x - h, y)) / (h * h);
}

/**
 * Calcula la segunda derivada parcial respecto a y en un punto dado (usando diferencia central).
 *
 * @param x Valor de la coordenada x.
 * @param y Valor de la coordenada y.
 * @return El valor de la segunda derivada parcial respecto a y en el punto (x, y).
 */
double DfYY_Central(double x, double y)
{
    return (F_parcial(x, y + h) - (2 * F_parcial(x, y)) + F_parcial(x, y - h)) / (h * h);
}

/**
 * Calcula la derivada cruzada de segunda orden en un punto dado (usando diferencia central).
 *
 * @param x Valor de la coordenada x.
 * @param y Valor de la coordenada y.
 * @return El valor de la derivada cruzada de segunda orden en el punto (x, y).
 */
double DfXY_Central(double x, double y)
{
    return (F_parcial(x + h, y + h) - F_parcial(x + h, y - h) - F_parcial(x - h, y + h) + F_parcial(x - h, y - h)) / (4 * h * h);
}


/**
 * Calcula la derivada cruzada de segunda orden en un punto dado (usando diferencia central).
 *
 * @param x Valor de la coordenada x.
 * @param y Valor de la coordenada y.
 * @return El valor de la derivada cruzada de segunda orden en el punto (x, y).
 */
double DfYX_Central(double x, double y)
{
    return (F_parcial(x + h, y + h) - F_parcial(x + h, y - h) - F_parcial(x - h, y + h) + F_parcial(x - h, y - h)) / (4 * h * h);
}

// NEWTON

float problema_newton()
{
    float x = 0, y = 1, c = (x + y) / 2;

    printf("---------------------------\n");

    if (F_Newton(x) * F_Newton(y) >= 0)
        printf("El producto de f(a) y f(b) no cumple la condición f(a) * f(b) < 0. \nNo se garantiza la existencia de una raíz en el intervalo [%f,%f].\n", x, y);
    else if (derivada(x) == 0 || derivada(y) == 0)
        printf("La derivada en al menos uno de los extremos del intervalo es cero. No se garantiza la existencia del punto de cruce.\n");
    else if (F_Newton(c) / derivada(c) > y - x)
        printf("La tangente de f(x) no cruza en algún punto del intervalo [a,b].\n");
    else
    {
        y = Newton(x);
        while (x != y)
        {
            x = y;
            y = Newton(x);
            printf("%lf\n", y);
        }
    }
    printf("\n");
}

/**
 * Calcula la derivada de la función F en un punto dado.
 *
 * @param a Punto en el que se evalúa la derivada.
 * @return El valor de la derivada en el punto a.
 */
float derivada(float a)
{
    return (F_Newton(a + h) - F_Newton(a)) / h;
}

/**
 * Calcula el valor de la función F en un punto dado.
 *
 * @param x Punto en el que se evalúa la función.
 * @return El valor de la función en el punto x.
 */
float F_Newton(float x)
{
    return exp(-x) - x;
}

/**
 * Aplica el método de Newton para encontrar una raíz de la función F.
 *
 * @param xn Valor inicial para el método de Newton.
 * @return La aproximación de la raíz de F.
 */
float Newton(float xn)
{
    float fxn = F(xn), df = derivada(xn);
    return (xn - (fxn / df));
}

/*
xn = valor inicial
fxn = valor de ecuacion
derivada
*/

// DESPLAZAMINETO

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