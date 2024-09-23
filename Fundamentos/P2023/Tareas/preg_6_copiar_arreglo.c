/*
strcat: Pega una frase a otra || arr1 = Hola    arr2 = Iris     con strcat: arr = Hola Iris
strcopy: Copia un arreglo en otro || arr1 = Hola  con strcopy arr2 = Hola
*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#define MAX_REN 10
#define MAX_COL 10
#define MIN_REN 2
#define MIN_COL 2

int Pedir_tamanio (int Min, int Max);
void Pedir_numero (int Renglon, int Columna,float Matriz[MAX_COL][MAX_REN]);
void Copiar_arreglo(int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN], float Matriz_2[MAX_COL][MAX_REN]);
void Desplegar_matriz (int Renglon, int Columna,float Matriz[MAX_COL][MAX_REN], float Matriz_2[MAX_COL][MAX_REN]);

int main (void)
{
    int Renglon, Columna;
    float Matriz[MAX_COL][MAX_REN];
    float Matriz_2[MAX_COL][MAX_REN];
    printf("Ingresa el tamaño de los renglones\n");
    Renglon = Pedir_tamanio(MIN_REN, MAX_REN);
    printf("Ingresa el tamaño de los columnas\n");
    Columna = Pedir_tamanio(MIN_COL, MAX_COL);
    printf("Renglon = %d, Columna = %d\n", Renglon, Columna);

    Pedir_numero (Renglon, Columna, Matriz);
    Copiar_arreglo(Renglon, Columna, Matriz,  Matriz_2);
    Desplegar_matriz (Renglon, Columna, Matriz, Matriz_2);
    return 0;
}

int Pedir_tamanio (int Min, int Max)
{
    int Numero;
    do 
    {
        printf("Dame tamaño (entre 2 y 10): ");
        scanf("%d", &Numero);
        __fpurge(stdin);
        if (Numero < Min || Numero > Max)
        {
            printf("Numero fuera de rango.");
        }
    } while (Numero < Min || Numero > Max);
}

void Pedir_numero (int Renglon, int Columna,float Matriz[MAX_COL][MAX_REN])
{
    int x, y;
    for( y = 0; y < Renglon; y++)
    {
        for(x = 0; x < Columna; x++)
        {
            printf("Matriz[%d][%d]: ", x, y);
            scanf("%f", &Matriz[x][y]);
            __fpurge(stdin);
            getchar();
        }
    }
}

void Copiar_arreglo(int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN], float Matriz_2[MAX_COL][MAX_REN])
{
    int x, y;
    for( y = 0; y < Renglon; y++)
    {
        for(x = 0; x < Columna; x++)
        {
            Matriz_2[x][y] = Matriz[x][y];
        }
    }
}

void Desplegar_matriz (int Renglon, int Columna,float Matriz[MAX_COL][MAX_REN], float Matriz_2[MAX_COL][MAX_REN])
{
    int x, y;
    printf("\nPrimer Arreglo\n");
    for( y = 0; y < Renglon; y++)
    {
        for(x = 0; x < Columna; x++)
        {
            printf("%2.2f\t", Matriz[x][y]);
        }
        printf("\n");
    }

    printf("\nArreglo destino\n");
    for( y = 0; y < Renglon; y++)
    {
        for(x = 0; x < Columna; x++)
        {
            printf("%2.2f\t", Matriz_2[x][y]);
        }
        printf("\n");
    }
}
