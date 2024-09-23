#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rellen '#'

void dif(char d, int *x, int *y);
void tablero();

int minas();

int main(void)
{

    tablero();
    minas();
    return 0;
}

void tablero()
{
    int num;
    int i, j, h = '`', k = 'A';

    int x = 0, y = 0;
    int c = 0, c1 = 0;
    c = '@';
    char d;
    printf("Ingrese la dificultad: ");
    scanf("%c", &d);
    dif(d, &x, &y);

    char arr[20][20];
    printf("%d, %d\n", x, y);

    // rellenar arreglo
    for (i = 0; i <= x; i++)
    {

        for (j = 0; j < y; j++)
        {
arr[x][0]= c;
arr[0][y]= c1;
c++;
c1++;
        }
        printf("\n");
    }
    // imprimir arreglo
    for (i = 0; i <= x; i++)
    {

        for (j = 0; j < y; j++)
        {

    printf("%d", arr[i][j]);

        }
        printf("\n");
    }
}

void dif(char d, int *x, int *y)
{
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
