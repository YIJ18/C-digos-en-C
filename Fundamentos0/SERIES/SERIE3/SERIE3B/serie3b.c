#include <math.h>
#include <stdio.h>
#include <string.h>

int error(char num[], int arr[]);
int res(int arr[], int pal);
int main(void)
{
    char num[100];
    int arr[100], pal;
    printf("Ingresa un número binario: ");
    scanf("%[^\n]", num);
    pal = strlen(num);
    if (error(num, arr) == 0)
    {
        printf("%d\n", res(arr, pal));
    }

    return 0;
}

/* Está función evalua la cadena ingresada.
 *@param num: arreglo tipo caracter; num cadena inicial.
 *@param arr: arreglo tipo entero; donde se guarda la nueva cadena.
 *@return regresa un '0', si esta bien la cadena.
 *@return regresa un '1', si  no esta bien la cadena.
 */
int error(char num[], int arr[])
{
    int x;
    for (x = 0; x < strlen(num); x++)
    {

        if (num[x] == '1' || num[x] == '0')
        {
            arr[x] = num[x] - 48;
        }
        else
        {
            printf("Ingresa un número valido. ");
            return 1;
        }
    }
    return 0;
}

/* Está función convierte un Binario a Decimal.
 *@param pal: variable tipo entero; número de veces que se repite.
 *@param arr; arreglo tipo entero; número binario
 *@return el resultado en decimal.
 */
int res(int arr[], int pal)
{
    int suma = 0, cont, i, j, x, y = 0;

    for (x = (pal - 1); x > -1; x--)
    {
        cont = arr[x] * pow(2, y);
        suma = cont + j;
        cont = j;
        j = suma;
        y++;
    }

    return suma;
}