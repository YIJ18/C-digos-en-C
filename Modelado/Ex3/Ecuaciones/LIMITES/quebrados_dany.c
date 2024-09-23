#include <stdio.h>

typedef struct Quebrados
{
    int denominador, numerador;
} tipoquebrados;

void Menu();
void Suma(tipoquebrados num1, tipoquebrados num2, tipoquebrados *res);
void Resta(tipoquebrados num1, tipoquebrados num2, tipoquebrados *res);
void Div(tipoquebrados num1, tipoquebrados num2, tipoquebrados *res);
void Mult(tipoquebrados num1, tipoquebrados num2, tipoquebrados *res);
void MCD(int num, int denom);

int main(void)
{

    tipoquebrados num1, num2, res;
    int op;

    printf("\nLa fraccion se debera ingresar de la siguiente manera: numerador/denominador \n\n");

    printf("Ingresa tu primer fraccion: ");
    scanf("%d/%d", &num1.numerador, &num1.denominador);

    printf("Ingresa tu segunda fraccion: ");
    scanf("%d/%d", &num2.numerador, &num2.denominador);

    Suma(num1, num2, &res);
    Resta(num1, num2, &res);
    Mult(num1, num2, &res);
    Div(num1, num2, &res);

    printf("\n");

    return 0;
}

void Menu()
{
    printf("\n1. Suma\n");
    printf("2. Resta\n");
    printf("3. Mult\n");
    printf("4. Div\n");
    printf("5. Salir\n");
}

void Suma(tipoquebrados num1, tipoquebrados num2, tipoquebrados *res)
{

    res->numerador = (num2.denominador * num1.numerador) + (num2.denominador * num2.numerador);
    res->denominador = (num1.denominador * num2.denominador);

    if (res->numerador == 0)
        printf("\nSuma: 0");
    else if (res->denominador == 0)
        printf("\nSuma: inexacta");
    else
    {
        printf("\nSuma: ");
        MCD(res->numerador, res->denominador);
    }
}

void Resta(tipoquebrados num1, tipoquebrados num2, tipoquebrados *res)
{

    res->numerador = (num2.denominador * num1.numerador) - (num2.denominador * num2.numerador);
    res->denominador = (num1.denominador * num2.denominador);

    if (res->numerador == 0)
        printf("\nResta: 0");
    else if (res->denominador == 0)
        printf("\nResta: inexacta");
    else
    {
        printf("\nResta: ");
        MCD(res->numerador, res->denominador);
    }
}

void Mult(tipoquebrados num1, tipoquebrados num2, tipoquebrados *res)
{

    res->numerador = (num2.numerador * num1.numerador);
    res->denominador = (num1.denominador * num2.denominador);

    if (res->numerador == 0)
        printf("\nMult: 0");
    else if (res->denominador == 0)
        printf("\nMult: inexacta");
    else
    {
        printf("\nMult: ");
        MCD(res->numerador, res->denominador);
    }
}

/*
Funcion que realiza la division en fracción
   @param dos numeros tipoquebrados
   @return
*/
void Div(tipoquebrados num1, tipoquebrados num2, tipoquebrados *res)
{

    res->numerador = (num1.numerador * num2.denominador);
    res->denominador = (num1.denominador * num2.numerador);

    if (res->numerador == 0)
        printf("\nDiv: 0");
    else if (res->denominador == 0)
        printf("\nDiv: inexacta");
    else
    {
        printf("\nDiv: ");
        MCD(res->numerador, res->denominador);
    }
}

/*
Funcion que Calcula El Maximo Comun Divisor
   @param dos numeros enteros
   @return
*/
void MCD(int num, int denom)
{
    int divisor, residuo;
    int n, d;
    n = num;
    d = denom;

    while (denom != 0)
    {
        /*
         *40/16 = 2  residuo= 8
         *40/8 = 5   residuo = 0
         *
         *mcd = 8
         *
         *47/15 = 3 residuo = 2
         *47/2 = 23 residuo = 1
         *47/1 = 47 residuo = 0
         *mcd = 1
         *
         */

        divisor = num / denom;
        residuo = num % denom;

        num = denom;
        denom = residuo;
    }

    n = n / num;
    d = d / num;

    if (n == d)
        printf(" %d", n);
    else
        printf(" %d/%d", n, d);
}