#include <stdio.h>
#include <math.h>

#define h 0.01F

float F(float x);

float derivada_adelante(float a); // la que usamos comunmenete
float derivada_atras(float a);
float derivada_central(float a);

int main(void)
{
    float i, x;
    printf("---------------------------\n");
    printf("Dame el valor en el que quiere evaluar: ");
    scanf("%f", &x);
    printf("--------- ------------------\n");
    printf("La derivada hacia adelante es: %lf\n", derivada_adelante(x));
    printf("La derivada hacia atras es: %lf\n", derivada_atras(x));
    printf("La derivada hacia centro es: %lf\n", derivada_central(x));
    printf("\n");
}

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

float F(float x)
{
    return 1  / (x * x);
}
