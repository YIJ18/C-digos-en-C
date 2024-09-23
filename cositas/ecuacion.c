#include <stdio.h>
#include <math.h>

void general(float a, float b, float c);

float op2(float x, float am);

int main(void) {
    float a, b, c, x, am;

    printf("Este programa calcula las siguientes ecuaciones:\n\n");
    printf("\tx1 = (-b + sqrt(pow(b, 2) - 4*a*c)) / (2*a)\n");
    printf("\tx2 = (-b - sqrt(pow(b, 2) - 4*a*c)) / (2*a)\n");
    printf("\tm = ((pow(x, 2) + sin(x + am)) / cos(x)) + (sqrt(x/am)) * 180 / pi\n\n");
    printf("Para la operación 'm', los valores se darán en grados, convirtiendo de radianes a grados utilizando *180/pi.\n\n");

    printf("Ingresa el valor de 'a' para la fórmula general: ");
    scanf("%f", &a);
    printf("Ingresa el valor de 'b' para la fórmula general: ");
    scanf("%f", &b);
    printf("Ingresa el valor de 'c' para la fórmula general: ");
    scanf("%f", &c);

    general(a, b, c);

    printf("\n\nAhora se realizará la operación 'm':\n\n");
    printf("m = ((pow(x, 2) + sin(x + a)) / cos(x)) + (sqrt(x/a)) * 180 / pi\n\n");
    printf("Ingresa el valor de 'x': ");
    scanf("%f", &x);
    printf("Ingresa el valor de 'a': ");
    scanf("%f", &am);

    printf("\nEl resultado de la operación 'm' es: %.2f grados\n", op2(x, am));

    getchar();
    return 0;
}

void general(float a, float b, float c) {
    float x1, x2;

    x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

    printf("\nx1 = (-%.2f + sqrt(pow(%.2f, 2) - 4*%.2f*%.2f)) / (2*%.2f)", b, b, a, c, a);
    printf("\n\nx2 = (-%.2f - sqrt(pow(%.2f, 2) - 4*%.2f*%.2f)) / (2*%.2f)", b, b, a, c, a);
    printf("\n\nEl valor de x1 es: %.2f", x1);
    printf("\nEl valor de x2 es: %.2f", x2);
}

float op2(float x, float am) {
    float m, pi = 3.1416;
    m = ((pow(x, 2) + sin(x + am)) / cos(x)) + (sqrt(x / am)) * 180 / pi;
    return m;
}
