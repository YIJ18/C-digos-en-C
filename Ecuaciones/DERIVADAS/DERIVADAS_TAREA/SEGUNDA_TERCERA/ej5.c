#include <stdio.h>
#include <math.h>

#define h 0.1F

float F(float x);

float derivada_adelante(float a); // la que usamos comunmenete
float derivada_atras(float a);
float derivada_central(float a);

float segunda_derivada_adelante(float a);
float segunda_derivada_atras(float a);
float segunda_derivada_central(float a);

float tercera_derivada_adelante(float x);
float tercera_derivada_atras(float x);
float tercera_derivada_central(float x);

int main(void)
{
    float i, x;

    printf("------------------------------------------------------\n");

    for (x = 1; x <= 5; x++)
    {
        printf("------------------------------------------------------\n");
        printf("Para x = %.0lf:\n", x);

        printf("    PRIMERA DERIVADA:\n");
        printf("        Adelante: %.6lf\n", derivada_adelante(x));
        printf("        Atras: %.6lf\n", derivada_atras(x));
        printf("        Central: %.6lf\n", derivada_central(x));

        printf("\n    SEGUNDA DERIVADA:\n");
        printf("        Adelante: %.6lf\n", segunda_derivada_adelante(x));
        printf("        Atras: %.6lf\n", segunda_derivada_atras(x));
        printf("        Central: %.6lf\n", segunda_derivada_central(x));

        printf("\n    TERCERA DERIVADA:\n");
        printf("        Para x = %.0lf:\n", x);
        printf("        Adelante: %.6lf\n", tercera_derivada_adelante(x));
        printf("        Atras: %.6lf\n", tercera_derivada_atras(x));
        printf("        Central: %.6lf\n", tercera_derivada_central(x));
        printf("\n");
    }

    printf("------------------------------------------------------\n");

    return 0;
}

/* -------------------------- evaluacion de la función ----------------------------------*/
float F(float x)
{
    return sqrt(x);
}

/* -------------------------- primera_derivada ----------------------------------*/
float derivada_adelante(float a)
{
    return (F(a + h) - F(a)) / h;
}

float derivada_atras(float a)
{
    return (F(a) - F(a - h)) / h;
}

float derivada_central(float a)
{
    return (F(a + h) - F(a - h)) / (2 * h);
}

/* -------------------------- segunda_derivada ----------------------------------*/
float segunda_derivada_adelante(float a)
{
    return (F(a + 2 * h) - (2 * F(a + h)) + F(a)) / (h * h);
}

float segunda_derivada_atras(float a)
{
    return (F(a) - 2 * F(a - h) + F(a - 2 * h)) / (h * h);
}

float segunda_derivada_central(float a)
{
    return (F(a + h) - 2 * F(a) + F(a - h)) / (h * h);
}

/* -------------------------- tercera_derivada ---------------------------------- */
float tercera_derivada_adelante(float x)
{
    return (F(x + 3 * h) - 3 * F(x + 2 * h) + 3 * F(x + h) - F(x)) / (h * h * h);
}

float tercera_derivada_atras(float x)
{
    return (F(x) - 3 * F(x - h) + 3 * F(x - 2 * h) - F(x - 3 * h)) / (h * h * h);
}

float tercera_derivada_central(float x)
{
    return (F(x + 2 * h) - 2 * F(x + h) + 2 * F(x - h) - F(x - 2 * h)) / (2 * h * h * h);
}