#include <stdio.h>
#include <string.h>
#include <math.h>
int error(char num[], int arr[], int a);
int cal(int arr[], int a);
int main(void)
{
    char num[100];
    int a, arr[100];
    printf("Ingresa un número base octal: ");
    scanf("%s", num);
    a = strlen(num);
    if (error(num, arr, a) == 0)
    {
        printf("%d", cal(arr, a));
    }
    return 0;
}
/* Está función convierte un Octal a Decimal.
 *@param arr: arreglo tipo entero; arreglo de con decimales.
 *@param a: variable tipo entero; número de veces que se ejecuta.
 *@return regresa el número en decimal.
 */
int cal(int arr[], int a)
{
    int x, y = 0, suma = 0, cal, j;
    for (x = (a - 1); x > -1; x--)
    {
        cal = arr[x] * pow(8, y);
        suma = cal + j;
        cal = j;
        j = suma;
        y++;
    }

    return suma;
}

/* Está función evalua la cadena ingresada.
 *@param num: arreglo tipo caracter; num cadena inicial.
 *@param arr: arreglo tipo entero; nueva cadena;
 *@param a: variable tipo entero; número de veces que se ejecuta.
 *@return regresa un '0', si esta bien la cadena.
 *@return regresa un '1', si  no esta bien la cadena.
 */
int error(char num[], int arr[], int a)
{
    int x;
    for (x = 0; x < a; x++)
    {
        if (num[x] >= '0' && num[x] <= '7')
        {
            arr[x] = num[x] - 48;
        }
        else
        {
            printf("Ingresa un número valido");
            return 1;
        }
    }
    return 0;
}
