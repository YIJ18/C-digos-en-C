/*
@file : prg17_menu.c
@brief : Ejemplo de menu
@details : Este programa ejemplifica un memnu de opciones para que el usuario pueda seleccionar. Las opciones del menu :
1) Ecuaciones de segundo grado
2) Promedio de n cantidad de números
3) Imprimir un cuadrado

@author : Iris Yulit Jasso Cortes
@date: 14 - Marzo - 2023

+*********+**+++************************************************************************+++++++++++++*+++
Diseño Arquitectonico

(Menu)

Diagrama IPO de alto nivel

Opcion (ENTRADA) -> Menu (PROCESO)

Diagrama IPO de bajo nivel

Opcion (ENTRADA) -> Menu (PROCESO)

*/

#include <stdio.h>
#include <stdio_ext.h>
#include <math.h>

// Menu
void Instrucciones_y_menu(void);
void Pedir_opcion(int *Opcion);

// Ecuación de segundo grado
void Problema_1(void);
void Pedir_Coeficientes(int *a, int *b, int *c);
void Calcular_ecuacion(int a, int b, int c, double *x1, double *x2);
void Imprimir_resultado(double x1, double x2);

// promedio de n cantidad de números
void Problema_2(void);
void Pedir_Cantidad(int *n);
void Pedir_numero(float *Num);
void Sumar_acumulado(float Num, float *Suma);
void Calcular_promedio(float Suma, int n, float *Promedio);
void Imprimir_Resultado(int n, float Promedio);

// Imprimir un cuadrado

int main(void)
{

    // Menu
    int Opcion;
    printf(" B I E N V E N I D O ");
    printf("Este programa es un ejemplo de un menú para ejecutar diversas soluciones de problemas\n\n");
    do
    {
        Instrucciones_y_menu();
        Pedir_opcion(&Opcion);
        if (Opcion == 1)
        {
           Problema_1();
        }
        else
        {
            if (Opcion == 2)
            {
                Problema_2();
            }
            else
            {
                if (Opcion == 3)
                {
                    printf("Imprimir cuadrado\n");
                }
                else
                {
                    if (Opcion == 4)
                    {
                        printf("Termina el programa. Adios...\n");
                    }
                    else
                        printf("Opcion invalida. Intenta nuevamnete...\n\n");
                }
            }
        }
        printf("\n\nPresiona <ENTER> para continuar...\n\n");
        getchar(); //Se incluye esta función para el <ENTER> de continuar
        __fpurge(stdin);

    } while (Opcion != 4);

    return 0;
}

// Menu
void Instrucciones_y_menu(void)
{
    printf(" ---------------------------- M E N Ú ----------------------------\n\n ");
    printf("Las opciones del menú son las siguientes: \n");
    printf("1) Resolver una ecuación de segundo gradro\n");
    printf("2) Promedio de n cantidad de números dados por el usuaro\n");
    printf("3) Imprimir un cudrado de asteriscos\n");
    printf("4) Salir del programa\n\n");
}
void Pedir_opcion(int *Opcion)
{
    printf("---Dame Opción: ");
    scanf("%d", Opcion);
    __fpurge(stdin);
}
//Problema 1
void Problema_1 (void)
{
    int a, b, c, Discriminante;
    double x1, x2;
    Pedir_Coeficientes(&a, &b, &c);

    while (a == 0)
    {
        printf("Los coeficientes dados no corresponden a una ecuación de segungo grado");
        Pedir_Coeficientes(&a, &b, &c);
    }

    Discriminante = (b * b) - (4 * a * c);

    if (Discriminante >= 0)
    {
        Calcular_ecuacion(a, b, c, &x1, &x2);
        Imprimir_resultado(x1, x2);
    }
    else
    {
        printf("Se generan raices imaginarias");
    }
}

void Pedir_Coeficientes(int *a, int *b, int *c)
{
    printf("Dame a: ");
    scanf("%d", a);
    __fpurge(stdin);

    printf("Dame b: ");
    scanf("%d", b);
    __fpurge(stdin);

    printf("Dame c: ");
    scanf("%d", c);
    __fpurge(stdin);
}

void Calcular_ecuacion(int a, int b, int c, double *x1, double *x2)
{
    *x1 = (-b + sqrt(b * b - a * a * c)) / (2 * a);
    *x2 = (-b - sqrt(b * b - a * a * c)) / (2 * a);
}

void Imprimir_resultado(double x1, double x2)
{
    printf("Los resultados de la raices son: \n ");
    printf("x1 = %.2f y x2 = %.2f", x1, x2);
}


//Problema 2
void Problema_2 (void)
{ 
     int n, i;
    float Num, Suma, Promedio;
    i = 0;
    Pedir_Cantidad(&n);
    do{
        Pedir_numero(&Num);
        i = i + 1;
        Sumar_acumulado( Num,  &Suma);
    }
    while(i < n);

     Calcular_promedio( Suma,  n, &Promedio);
     Imprimir_Resultado( n,  Promedio);
}

void Pedir_Cantidad(int *n)
{
    printf("Dame la cantidad de números a los que quieras calcular el promedio: ");
    scanf("%d", n);
    __fpurge(stdin);
}

void Pedir_numero(float *Num)
{
    printf("Dame número: ");
    scanf("%f", Num);
    __fpurge(stdin);
}

void Sumar_acumulado(float Num, float *Suma)
{
    *Suma = *Suma + Num;
}

void Calcular_promedio(float Suma, int n, float *Promedio)
{
    *Promedio = Suma / n;
}

void Imprimir_Resultado(int n, float Promedio)
{
    printf("El promedio de los %d números es: %.2f ", n, Promedio);
}
