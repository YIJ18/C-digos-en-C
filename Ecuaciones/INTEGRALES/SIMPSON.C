#include <stdio.h>
#include <math.h>

// Declaraciones de funciones de simpson
double simpson_3_8_intervalos(double a, double b, int n);
double f(double x);
double simpson_1_3(double a, double b);
double simpson_3_8(double a, double b);
double simpson_compuesta(double a, double b, int n);
void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual);
void imprimir_resultados(double a, double b, int n);

int main()
{
    double a = 1.0; // inicio
    double b = 4.0; // fin

    imprimir_resultados(a, b, 10);

    return 0;
}

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

// Regla de Simpson 3/8 con intervalos
double simpson_3_8_intervalos(double a, double b, int n)
{
    double h = (b - a) / (3 * n);
    double result = f(a) + f(b);

    for (int i = 1; i < 3 * n; i++)
    {
        if (i % 3 == 0)
        {
            result += 2 * f(a + i * h);
        }
        else
        {
            result += 3 * f(a + i * h);
        }
    }

    return ((3 * h) / 8.0) * result;
}

// Función a integrar
double f(double x)
{
    return (x * sin(x));
}

// Regla de Simpson 1/3 para un solo segmento
double simpson_1_3(double a, double b)
{
    double h = (b - a) / 2;
    return (h / 3) * (f(a) + 4 * f((a + b) / 2) + f(b));
}

// Regla compuesta de Simpson
double simpson_compuesta(double a, double b, int n)
{
    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            result += 2 * f(a + i * h);
        }
        else
        {
            result += 4 * f(a + i * h);
        }
    }

    return (h / 3) * result;
}

// Regla de Simpson 3/8 para un solo segmento
double simpson_3_8(double a, double b)
{
    double h = (b - a) / 3;
    return ((3 * h) / 8) * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(b));
}

// Errores
void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual)
{
    double valor_real = 1.5566; // es el valor esperado
    *error_relativo = (valor_real - valor_aprox) / valor_real;
    *error_porcentual = *error_relativo * 100;
}
