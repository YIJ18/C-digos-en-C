// Declaraciones de funciones de euler predictor
double derivada(double x, double y);
double Euler_predictor_corrector(double x, double y, double h, double *y_predictor);
double y_exacto(double x, double y);
void imprimir_tabla(double x, double y, double y_predictor);
void resolver_edo(double x0, double y0, double h, double x_fin);

/**** ----------------PM-------------*****/
void euler_metodo(double (*funcion_derivada)(double, double), double x_inicial, double y_inicial, double x_final, double h);
double derivada2(double x, double y);
double eulerPuntoMedio(double x, double y, double h);
double f_pm(double x, double y);
double error(double y_real, double y_aprox);

#include <stdio.h>
#include <math.h>

// Declaraciones de funciones de euler predictor
#define inicio 0.5
#define fin 1.0
#define paso 0.1

/**
 * Calcula la derivada de una función definida por la ecuación diferencial ordinaria (EDO).
 *
 * @param x Valor de la variable independiente.
 * @param y Valor de la función dependiente.
 * @return Valor de la derivada en el punto (x, y).
 */
double derivada(double x, double y)
{
    return 2 * x * (1 - x / 5.0);
}

/**
 * Realiza un paso del método de Euler predictor-corrector para resolver una EDO.
 *
 * @param x Valor de la variable independiente.
 * @param y Valor de la función dependiente.
 * @param h Tamaño del paso.
 * @param y_predictor Puntero a la variable que almacenará la predicción del próximo valor de y.
 * @return Nueva aproximación de y utilizando el método de Euler predictor-corrector.
 */
double Euler_predictor_corrector(double x, double y, double h, double *y_predictor)
{
    *y_predictor = y + h * derivada(x, y);
    return y + (h / 2.0) * (derivada(x, y) + derivada(x + h, *y_predictor));
}

/**
 * Imprime una tabla con los resultados de la solución de una EDO utilizando el método de Euler predictor-corrector.
 *
 * @param x Valor de la variable independiente.
 * @param y Valor de la función dependiente predicho.
 * @param y_predictor Valor de la función dependiente calculado con el predictor.
 */
void imprimir_tabla(double x, double y, double y_predictor)
{
    printf("%.2lf   %.10lf  %.10lf\n", x, y_predictor, y);
}

/**
 * Resuelve una EDO utilizando el método de Euler predictor-corrector e imprime una tabla con los resultados.
 *
 * @param x0 Valor inicial de la variable independiente.
 * @param y0 Valor inicial de la función dependiente.
 * @param h Tamaño del paso.
 * @param x_fin Valor final de la variable independiente.
 */
void resolver_edo(double x0, double y0, double h, double x_fin)
{
    FILE *dataFile1 = fopen("eu_y.txt", "w");
    FILE *dataFile2 = fopen("eu_y_corrector.txt", "w");

    if (!dataFile1 || !dataFile2)
    {
        fprintf(stderr, "Error al abrir los archivos de datos.\n");
        return;
    }
    double x = x0;
    double y = y0;
    double y_predictor = 0.0;

    while (x <= x_fin)
    {
        imprimir_tabla(x, y, y_predictor);
        fprintf(dataFile1, "%.6lf %.6lf\n", x, y);
        fprintf(dataFile2, "%.6lf %.6lf\n", x, y_predictor);
        y = Euler_predictor_corrector(x, y, h, &y_predictor);
        x += h;
    }
    fclose(dataFile1);
    fclose(dataFile2);
}

/*-------PM------------*/

/**
 * Resuelve una EDO utilizando el método de Euler predictor-corrector e imprime una tabla con los resultados.
 *
 * @param x0 Valor inicial de la variable independiente.
 * @param y0 Valor inicial de la función dependiente.
 * @param h Tamaño del paso.
 * @param x_fin Valor final de la variable independiente.
 */
void euler_metodo(double (*funcion_derivada)(double, double), double x_inicial, double y_inicial, double x_final, double h)
{
    FILE *dataFile1 = fopen("y.txt", "w");
    FILE *dataFile2 = fopen("pm.txt", "w");
    FILE *dataFile3 = fopen("error.txt", "w");
    FILE *dataFile4 = fopen("error_pm.txt", "w");
    FILE *dataFile5 = fopen("real.txt", "w");

    if (!dataFile1 || !dataFile2 || !dataFile3 || !dataFile4 || !dataFile5)
    {
        fprintf(stderr, "Error al abrir los archivos de datos.\n");
        return;
    }
    double x_actual = x_inicial;
    double y_actual = y_inicial;
    double y_predictor;
    double p_m = 0.0;
    double y_real = 0.0;

    printf("x        y        pm         error    error pm    Valor Real\n");
    printf("%.2lf    %.5lf   %.5lf    0.00000   0.00000    %.5lf\n", x_actual, y_actual, y_actual, f_pm(x_actual, y_actual));

    fprintf(dataFile1, "%.6lf %.6lf\n", x_actual, y_actual);
    fprintf(dataFile2, "%.6lf %.6lf\n", x_actual, y_actual);
    fprintf(dataFile3, "%.6lf %.6lf\n", x_actual, 0.00000);
    fprintf(dataFile4, "%.6lf %.6lf\n", x_actual, 0.00000);
    fprintf(dataFile5, "%.6lf %.6lf\n", x_actual, f_pm(x_actual, y_actual));
    while (x_actual < x_final)
    {
        y_predictor = y_actual + h * funcion_derivada(x_actual, y_actual);

        // punto medio y error
        p_m = eulerPuntoMedio(x_actual, y_actual, h);
        y_actual = y_actual + h * (funcion_derivada(x_actual, y_actual) + funcion_derivada(x_actual + h, y_predictor)) / 2.0;
        x_actual += h;
        y_real = f_pm(x_actual, y_actual);
        printf("%.2lf    %.5lf   %.5lf    %.5lf   %.5lf    %.5lf \n", x_actual, y_actual, p_m, error(y_real, y_actual), error(y_real, p_m), y_real);
        fprintf(dataFile1, "%.6lf %.6lf\n", x_actual, y_actual);
        fprintf(dataFile2, "%.6lf %.6lf\n", x_actual, p_m);
        fprintf(dataFile3, "%.6lf %.6lf\n", x_actual, error(y_real, y_actual));
        fprintf(dataFile4, "%.6lf %.6lf\n", x_actual, error(y_real, p_m));
        fprintf(dataFile5, "%.6lf %.6lf\n", x_actual, y_real);
    }
    fclose(dataFile1);
    fclose(dataFile2);
    fclose(dataFile3);
    fclose(dataFile4);
    fclose(dataFile5);
}

/**
 * Función derivada para la segunda ecuación diferencial.
 *
 * @param x Valor de la variable independiente.
 * @param y Valor de la función dependiente.
 * @return Valor de la derivada en el punto dado.
 */
double derivada2(double x, double y)
{
    return ((pow(x, 3) * exp(-2 * x)) - (2 * y));
}

/**
 * Implementación del método de Euler punto medio para resolver ecuaciones diferenciales.
 *
 * @param x Valor de la variable independiente en el punto actual.
 * @param y Valor de la función dependiente en el punto actual.
 * @param h Tamaño del paso.
 * @return Valor aproximado de la función dependiente en el siguiente paso.
 */
double eulerPuntoMedio(double x, double y, double h)
{
    return y + h * derivada2(x + h / 2, y + h / 2 * derivada2(x, y));
}

/**
 * Función para la solución real de la segunda ecuación diferencial.
 *
 * @param x Valor de la variable independiente.
 * @param y Valor de la función dependiente.
 * @return Valor real de la función dependiente.
 */
// funcion para ver si esta bien o no
double f_pm(double x, double y)
{
    return exp(-2 * x) / 4.0 * (pow(x, 4) + 4);
}

/**
 * Función para calcular el error relativo porcentual entre el valor real y el valor aproximado.
 *
 * @param y_real Valor real de la función dependiente.
 * @param y_aprox Valor aproximado de la función dependiente.
 * @return Valor del error relativo porcentual.
 */
double error(double y_real, double y_aprox)
{
    return fabs((y_real - y_aprox) / y_real) * 100;
}
