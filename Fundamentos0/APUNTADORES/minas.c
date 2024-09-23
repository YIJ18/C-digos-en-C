#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void dif(int *x, int *y);
void tablero();
int minas();

int main(void)
{
    tablero();
    return 0;
}

void tablero()
{
    int num, i, j;
    int x = 0, y = 0;
    dif(&x, &y);
    char arr[x][y];
    printf("%d, %d\n", x, y);
    // rellenar arreglos
    srand(time(NULL));
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            arr[x][y] = 1 + rand() % 2;
        }
    }
    srand(time(NULL));
    // mostrar arreglo
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d\t", arr[x][y]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void dif(int *x, int *y)
{
    char d;
    printf("Ingrese la dificultad: ");
    scanf("%c", &d);

    if (d == 'd')
    {
        *x = 15;
        *y = 20;
    }
    else if (d == 'm')
    {
        *x = 10;
        *y = 15;
    }
    else if (d == 'f')
    {
        *x = 5;
        *y = 10;
    }
}
