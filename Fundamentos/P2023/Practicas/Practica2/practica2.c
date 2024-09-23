/*
@file: practica2.c
@brief: Ordenamiento de número menor a número mayor
@details: Programa que, dada una serie de números por el usuario, cada número sea insertado en un arreglo en el lugar que le corresponda, ya sea en orden ascendente o descendente, en  el  momento  en  que  cada  valor  es  insertado.

@author: Iris Yulit Jasso Cortes, Zara Natalia Sánchez Montiel
@date: 18-Abril-2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

// Se declaran las funciones
void Menu();
void Nombre();
int Numeros();
void Ingresar(int *Opcion);
void Ingresar_numeros(int Opcion, int Cantidad, float arr[100]);
void Ordenar_ascendente(int i, float arr[100]);
void Ordenar_descendente(int i, float arr[100]);

int main(void)
{
    int Opcion, Cantidad;
    float arr[100];
    Nombre();
    do
    {
        Menu();
        Ingresar(&Opcion);
        if (Opcion == 1 || Opcion == 2)
        {
            system("clear");
            Cantidad = Numeros();
            Ingresar_numeros(Opcion, Cantidad, arr);
        }
        else
        {
            if (Opcion == 3)
            {
                system("clear");
                printf("Termina el programa. Adiós...\n\n");
            }
            else
            {
                system("clear");
                printf("Opción invalida. Intenta nuevamente...\n\n");
            }
        }
    } while (Opcion != 3);
    printf("\n\nPresiona <ENTER> para continuar...\n\n");
    getchar();
    __fpurge(stdin);
    system("clear");
    return 0;
}

/*
Esta función sirve para hacer la impresión de nuestros nombres y las instrucciones generales.
@param: No cuenta con parámetros.
@return: Esta función no retorna nada.
*/
void Nombre()
{
    printf("\nLas creadoras del programa son: Iris Yulit Jasso Cortes, Zara Natalia Sánchez Montiel.\n");
    printf("\nPresione <ENTER> para continuar.\n");
    getchar();
    system("clear");
    printf("\nPrograma que, dada una serie de números por el usuario, cada número sea insertado en un arreglo en el lugar que le corresponda, ya sea en orden ascendente o descendente, en  el  momento  en  que  cada  valor  es  insertado.\n");
    printf("\nPresione <ENTER> para continuar.\n");
    getchar();
    system("clear");
}

/*
Esta función sirve para hacer la impresión de las opciones del menú
@param: No cuenta con parámetro
@return: Esta función no retorna nada
*/
void Menu()
{
    printf("1. Ordenar una lista de números de manera ascendente.\n");
    printf("2. Ordenar   una   lista   de   números   de   manera   descendente.\n");
    printf("3. Terminar el programa.\n");
}

/*
Esta función sirve para que el usuario ingrese alguna opción de las que nos proporciona el menú
@param: Cuenta con un parámetro de salida, que es la opción que el usuario introduce.
@return: Esta función no retorna nada.
*/
void Ingresar(int *Opcion)
{
    printf("---Dame la opción a elegir: ");
    scanf("%d", Opcion);
    __fpurge(stdin);
}

/*
Esta función sirve para que el usuario ingrese la cantidad de números que quiere ordenar.
@param: Cuenta con un parámetro de salida, que es la opción que el usuario introduce.
@return: Esta función no retorna nada.
*/
int Numeros()
{
    int Cantidad;
    do
    {
        printf("\nCuantos numeros vas a ordenar: ");
        scanf("%d", &Cantidad);
        if (Cantidad < 5 || Cantidad > 100)
            printf("Ingrese un número dentro del rango indicado");
    } while (Cantidad < 5 || Cantidad > 100);
    printf("\n");
    return Cantidad;
}

/*
Esta función sirve para que el usuario ingrese los números y mandar a llamar las funciones de ordenamiento.
@param: Cuenta con un parámetro de entrada, que es la opción que el usuario introduce, la cantidad de números que va a introducir el usuario y el arreglo donde se van a guardar los números.
@return: Esta función no retorna nada.
*/

void Ingresar_numeros(int Opcion, int Cantidad, float arr[100])
{
    int i, k, j = 1;
    printf("\nDame tus números: \n");

    for (i = 0; i < Cantidad; i++)
    {
        // Se solicitan los números necesarios
        printf("\nDame valor de Lista[%i]: ", j);
        scanf("%f", &arr[i]);
        getchar();
        j++;
        // Se válida para ver qué función pidio el usuario
        if (Opcion == 1)
            Ordenar_ascendente(i, arr);
        if (Opcion == 2)
           Ordenar_descendente(i, arr);

        // Se imprime el diseño de pantalla del arreglo, ya con los números ordenados
        printf("(Contenido parcial del Arreglo: [ ");
        for (k = 0; k < Cantidad; k++)
        {
            if (k <= i)
            {

                printf("%.3f", arr[k]);
            }
            else
                printf("x");

            if (k < Cantidad - 1)
            {
                printf(" , ");
            }
        }
        printf(" ])\n");
    }

    printf("\nTu lista ordenada es: ");

    for (i = 0; i < Cantidad; i++)
    {
        printf("%.3f ", arr[i]);

        if (i < Cantidad - 1)
        {
            printf(" , ");
        }
    }

    printf("\n\n Presione <ENTER> para continuar\n");
    getchar();
    system("clear");
}

/*
Esta función sirve para ordenar ascendentemente
@param: Cuenta con dos parámetro de entrada, que es el primer contador de la función donde es llamado y el arreglo que será editado conforme el usuario va ingresando el valor.
@return: NO retorna nada
*/
void Ordenar_ascendente(int i, float arr[100])
{
    // temp = Variable entera, sirve para que no se pierda el número del arreglo que será reemplazado
    //  j = nuevo contador ||
    float temp;
    int j;
    for (j = 0; j < i + 1; j++)
    {
        if (i == 0 || j == 0)
            arr[j] = arr[j];
        else
        {
            if (arr[i] < arr[j - 1])
            {
                temp = arr[i];
                arr[i] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

/*
Esta función sirve para ordenara descendente
@param: Cuenta con dos parámetro de entrada, que es el primer contador de la función donde es llamado y el arreglo que será editado conforme el usuario va ingresando el valor.
@return: NO retorna nada
*/
void Ordenar_descendente(int i, float arr[100])
{
    // temp = Variable entera, sirve para que no se pierda el número del arreglo que será reemplazado
    //  j = nuevo contador ||
    float temp;
    int j;
    for (j = 0; j < i + 1; j++)
    {
        if (i == 0 || j == 0)
            arr[j] = arr[j];
        else
        {
            if (arr[i] > arr[j - 1])
            {
                temp = arr[i];
                arr[i] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}