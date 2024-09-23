// Declaraciones de funciones de simpson
double simpson_3_8_intervalos(double a, double b, int n);
double f(double x);
double simpson_1_3(double a, double b);
double simpson_3_8(double a, double b);
double simpson_compuesta(double a, double b, int n);
void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual);
void imprimir_resultados(double a, double b, int n);

// Declaraciones de funciones de taylor
double factorial(int n);
double F(double x);
double n_derivada_central(double x, int n, double h);
double Maclaurin(double a, double x, double h);

// Runge
double derivada_runge(double x, double y);
double runge_kutta(double (*derivada)(double, double), double x, double y, double h);
void resolver(double (*derivada)(double, double), double x_inicial, double y_inicial, double x_final, double h);
void llamar_runge();

// Declaraciones de funciones de taylor
#define num 4
#include <stdio.h>
#include <math.h>

/**
 * Imprime los resultados de las aproximaciones de la integral utilizando diferentes métodos de integración.
 *
 * @param a Extremo inferior del intervalo.
 * @param b Extremo superior del intervalo.
 * @param n Número de subintervalos para la Regla compuesta de Simpson.
 */
// Declaraciones de funciones de simpson, siempre se le manda 10 y a como inicio, b como fin
void imprimir_resultados(double a, double b, int n)
{
    double error_relativo = 0, error_porcentual = 0;

    printf("+---------------------------------------------+\n");
    printf("| Método          | Aproximación   | Error %%  |\n");
    printf("+---------------------------------------------+\n");

    // Regla de Simpson 1/3
    error_r_p(simpson_1_3(a, b), &error_relativo, &error_porcentual);
    printf("| Simpson 1/3     | %.6lf       | %.3lf   |\n", simpson_1_3(a, b), fabs(error_porcentual));

    // Regla compuesta de Simpson
    error_r_p(simpson_compuesta(a, b, n), &error_relativo, &error_porcentual);
    printf("| Compuesta       | %.6lf       | %.3lf    |\n", simpson_compuesta(a, b, n), fabs(error_porcentual));

    // Regla de Simpson 3/8
    error_r_p(simpson_3_8(a, b), &error_relativo, &error_porcentual);
    printf("| Simpson 3/8     | %.6lf       | %.3lf    |\n", simpson_3_8(a, b), fabs(error_porcentual));

    // Regla de Simpson 3/8 con intervalos
    error_r_p(simpson_3_8_intervalos(a, b, n), &error_relativo, &error_porcentual);
    printf("| 3/8 con inter.  | %.6lf       | %.3lf    |\n", simpson_3_8_intervalos(a, b, n), fabs(error_porcentual));

    printf("+---------------------------------------------+\n");
}

/**
 * Calcula la aproximación de la integral de la función f(x) usando la Regla de Simpson 3/8 con intervalos.
 *
 * @param a Extremo inferior del intervalo.
 * @param b Extremo superior del intervalo.
 * @param n Número de subintervalos para la aproximación.
 * @return Aproximación de la integral usando la Regla de Simpson 3/8 con intervalos.
 */
double simpson_3_8_intervalos(double a, double b, int n)
{
    double h =  0.2;
    double resultado = f(a) + f(b);
    int i;
    for (i = 1; i < 3 * n; i++)
    {
        if (i % 3 == 0)
            resultado += 2 * f(a + i * h);
        else
            resultado += 3 * f(a + i * h);
    }

    return ((3 * h) / 8.0) * resultado;
}

/**
 * Definición de la función a integrar en las reglas de Simpson y Maclaurin.
 *
 * @param x Valor de la variable independiente.
 * @return Valor de la función a ser integrada.
 */
double f(double x)
{
    return exp(x)*cos(x);
}

/**
 * Calcula la aproximación de la integral de la función f(x) en un solo segmento usando la Regla de Simpson 1/3.
 *
 * @param a Extremo inferior del segmento.
 * @param b Extremo superior del segmento.
 * @return Aproximación de la integral usando la Regla de Simpson 1/3.
 */
double simpson_1_3(double a, double b)
{
    double h =  0.2;
    return (h / 3) * (f(a) + 4 * f((a + b) / 2) + f(b));
}

/**
 * Calcula la aproximación de la integral de la función f(x) usando la Regla compuesta de Simpson.
 *
 * @param a Extremo inferior del intervalo.
 * @param b Extremo superior del intervalo.
 * @param n Número de subintervalos para la aproximación compuesta.
 * @return Aproximación de la integral usando la Regla compuesta de Simpson.
 */
double simpson_compuesta(double a, double b, int n)
{
    double h = 0.2;
    double resultado = f(a) + f(b);
    int i;

    for (i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            resultado += 2 * f(a + i * h);
        }
        else
        {
            resultado += 4 * f(a + i * h);
        }
    }

    return (h / 3) * resultado;
}

/**
 * Calcula la aproximación de la integral de la función f(x) en un solo segmento usando la Regla de Simpson 3/8.
 *
 * @param a Extremo inferior del segmento.
 * @param b Extremo superior del segmento.
 * @return Aproximación de la integral usando la Regla de Simpson 3/8.
 */
double simpson_3_8(double a, double b)
{
    double h = 0.2;
    return ((3 * h) / 8) * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(b));
}

/**
 * Calcula los errores relativo y porcentual comparando un valor aproximado con un valor real esperado.
 *
 * @param valor_aprox Valor aproximado.
 * @param error_relativo Puntero a la variable que almacenará el error relativo.
 * @param error_porcentual Puntero a la variable que almacenará el error porcentual.
 */
void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual)
{
    double valor_real = 1.3220; // es el valor esperado o valor real
    *error_relativo = (valor_real - valor_aprox) / valor_real;
    *error_porcentual = *error_relativo * 100;
}

/*----------------TAYLOR-----------------*/

/**
 * Calcula el factorial de un número entero no negativo.
 *
 * @param n Número entero no negativo.
 * @return El factorial de n.
 */
double factorial(int n)
{
    if (n == 0 || n == 1)
        return 1.0;
    else
        return n * factorial(n - 1);
}

/**
 * Calcula la n-ésima derivada central de la función F(x) en un punto x usando una aproximación numérica.
 *
 * @param x Punto en el cual se evalúa la derivada.
 * @param n Orden de la derivada.
 * @param h Tamaño del paso para la aproximación numérica de la derivada.
 * @return Valor aproximado de la n-ésima derivada central de F(x) en x.
 */
double n_derivada_central(double x, int n, double h)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_central(x + h, n - 1, h) - n_derivada_central(x - h, n - 1, h)) / (2 * h);
}

/**
 * Calcula la aproximación de la serie de Maclaurin para la función F(x) centrada en el punto a.
 * Maclaurin siempre inicia en 0, por lo que 'a' debe ser 0 en este contexto.
 *
 * @param a Punto de centro para la serie de Maclaurin (debería ser 0).
 * @param x Valor en el cual se evalúa la serie.
 * @param h Tamaño del paso para la aproximación de derivadas.
 * @return Aproximación de la serie de Maclaurin para F(x).
 *
// Maclaurin siempre inicia en 0, o sea que a siempre es 0
// Taylor siempre se evalua en un número
// Para llamar esta función se encesita declarar una variable iniciada en el punto 0 o un numero como primer parametro
// Para el segundo parametro se en el que incia x evaluada en un punto
 */
double Maclaurin(double a, double x, double h)
{
    int i;
    double maclaurin = F(a);
    for (i = 1; i <= num; i++)
        maclaurin += ((n_derivada_central(a, i, h) * pow(x, i)) / factorial(i));
    return maclaurin;
}

/**
 * Función que define la función matemática F(x) a ser aproximada por la serie de Maclaurin.
 * En este ejemplo, se utiliza la función coseno.
 *
 * @param x Valor de la variable independiente.
 * @return Valor de la función F(x).
 */
double F(double x)
{
    return cos(x); // aqui va la funcion
}

/*---------RUNGE-----------*/
/**
 ** Llama a la función que utiliza el método de Runge-Kutta para resolver una ecuación diferencial.
 ** Param: No recibe nada
 ** Return: no retorna nada
 **/
void llamar_runge()
{
    double x_inicial = 0.0; // inicio
    double fin2 = 5;      // fin
    // Resuelve la ecuación diferencial con h = 0.2
    // El tercer parametro que se le manda es donde inicia la y, en este caso es 1
    resolver(derivada_runge, x_inicial, 0.0, fin2, 0.2);
}

/**
 * Resuelve una ecuación diferencial ordinaria (EDO) utilizando el método de Runge-Kutta de cuarto orden.
 * Imprime una tabla con los resultados.
 *
 * @param derivada_runge Puntero a la función que define la derivada de la EDO.
 * @param x_inicial Valor inicial de la variable independiente.
 * @param y_inicial Valor inicial de la función dependiente.
 * @param x_final Valor final de la variable independiente.
 * @param h Tamaño del paso.
 * @return no retorna nada
 */
void resolver(double (*derivada_runge)(double, double), double x_inicial, double y_inicial, double x_final, double h)
{
    FILE *dataFile = fopen("runge_kutta.txt", "w");
    if (!dataFile)
    {
        fprintf(stderr, "Error al abrir el archivo de datos.\n");
        return;
    }

    double x_actual = x_inicial;
    double y_actual = y_inicial;
    double runge;

    // Imprime encabezados en la consola y en el archivo
    printf("  x              runge\n");

    while (x_actual < x_final)
    {
        runge = runge_kutta(derivada_runge, x_actual, y_actual, h);
        x_actual += h;
        y_actual = runge;

        // Imprime resultados en la consola y en el archivo
        printf("%.2lf\t\t%.5lf\n", x_actual, y_actual);
        fprintf(dataFile, "%.6lf %.6lf\n", x_actual, y_actual);
    }

    fclose(dataFile);
}

/**
 * Define la derivada de la función que se desea resolver.
 *
 * @param x Valor de la variable independiente.
 * @param y Valor de la función dependiente.
 * @return Valor de la derivada en el punto (x, y).
 */
double derivada_runge(double x, double y)
{
    return (2) * x * (1 - x / 5.0);
}

/**
 * Implementa el método de Runge-Kutta de cuarto orden para resolver una EDO.
 *
 * @param derivada Puntero a la función que define la derivada de la EDO.
 * @param x Valor de la variable independiente.
 * @param y Valor de la función dependiente.
 * @param h Tamaño del paso.
 * @return Nueva aproximación de y utilizando el método de Runge-Kutta.
 */
double runge_kutta(double (*derivada_runge)(double, double), double x, double y, double h)
{
    double k1 = h * derivada_runge(x, y);
    double k2 = h * derivada_runge(x + h / 2.0, y + k1 / 2);
    double k3 = h * derivada_runge(x + h / 2.0, y + k2 / 2);
    double k4 = h * derivada_runge(x + h, y + k3);
    return y + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
}
