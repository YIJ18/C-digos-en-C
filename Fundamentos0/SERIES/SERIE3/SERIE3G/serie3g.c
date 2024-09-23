#include <math.h>
#include <stdio.h>
#include <string.h>

int error(char num[], int arr[]);
int res(int arr[], int pal, int *sum);
void cal(int dec);
int main(void)
{
    char num[100];
    int arr[100], pal, dec;
    printf("Ingresa un número binario: ");
    scanf("%[^\n]", num);
    pal = strlen(num);
    if (error(num, arr) == 0)
    {
        res(arr, pal, &dec);
    }
cal(dec);
    return 0;
}

/* Está función evalua la cadena ingresada y la concierte a cadena de enteros.
 *@param num: arreglo tipo caracter; num cadena inicial.
 *@param arr: arreglo tipo entero; se guarda en tipo entero. 
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
/* Está función convierte un Decimal a Octal.
 *@param dec: variable tipo entero; decimal que se convierte.
 *@param arr: arreglo tipo entero; se guarda el valor octal.
 *@return no regresa nada.
 */
int res(int arr[], int pal, int *sum)
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
    *sum = suma;
    return suma;
}
/* Está función convierte un Decimal a Octal.
 *@param dec: variable tipo entero; decimal que se convierte.
 *@param arr: arreglo tipo entero; se guarda el valor octal.
 *@return no regresa nada.
 */
void cal(int dec)
{
    char arr[100];
    int res, cicl, x = 0;
    cicl = dec;
    do
    {
        res = cicl % 16;
        cicl = cicl / 16;

        if (res > 9 && res < 16)
        {
            arr[x] = res + 55;
        }
        else if (res >= 0 && res < 10)
        {
            arr[x] = res + 48;
        }
        x++;
    } while (cicl != 0);

    for (int i = x; i >= 0; i--)
    {
        printf("%c", arr[i]);
    }

    printf("\n");

}