/*
 @file: ordenar_nombres.c
 @brief: Ordenar n cantidad de nombres dados al utilizar cadenas
 @details: Este programa ordena n cantidad de nombres dados por el usuario. Utiliza las funciones para manipular cadenas y las guarda en un arreglo de cadenas.
 @authors: iris yulit jassso cortes
 @date: 25-abril-2023
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

#define MAX_REN 50 // La cantidad máxima de nombres que tendrá la tabla
#define MAX_COL 6  // La longitud máxima del nombre

void Ordenar_nombres(int n, char Listado[MAX_REN][MAX_COL]);
void Imprimir_nombres(int n, char Listado[MAX_REN][MAX_COL]);

int main(int argc, char *argv[])
{
    char Listado[MAX_REN][MAX_COL];
    int n, i;

    n = argc; // n = Pedir_n(5, 50);
    for (i = 1; i < argc; i++)
    {
        strcpy(Listado[i - 1], argv[i]);
    }
    Ordenar_nombres(n-1, Listado);
    Imprimir_nombres(n-1, Listado);

    return 0;
}

//----------------------------------------------------------------------------

void Ordenar_nombres(int n, char Listado[MAX_REN][MAX_COL])
{
    int i, j;
    char Hoja[MAX_COL];

    for (i = 0; i <= n - 2; i++)
    {
        for (j = i + 1; j <= n - 1; j++)
        {
            if (strcmp(Listado[i], Listado[j]) > 0)
            {
                strcpy(Hoja, Listado[i]);
                strcpy(Listado[i], Listado[j]);
                strcpy(Listado[j], Hoja);
            }
        }
    }
}

void Imprimir_nombres(int n, char Listado[MAX_REN][MAX_COL])
{
    int i;

    printf("Los nombres ordenados son:\n");
    for (i = 0; i < n; i++)
        puts(Listado[i]);
}