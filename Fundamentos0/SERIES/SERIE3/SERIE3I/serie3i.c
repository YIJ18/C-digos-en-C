#include <stdio.h>
#include <math.h>
#include <string.h>

void evaluarArgumentos(int argc, char *argv[]);
// Hexa a Bin
int error(char num[]);
void nuv(char num[], int arr[]);
int cal(char num[], int *sum);
void calcu(int dec);

int main(int argc, char *argv[])
{
    int i;
   /* printf("\n%d", argc);
    for (i = 0; i < argc; i++)
    {
        printf("\n%s", argv[i]);
    }
    printf("\n\n");*/

    evaluarArgumentos(argc, argv);
    FILE *archivo;
    archivo = fopen(argv[5], "archivo");

    printf("\n\n");

    return 0;
}

void evaluarArgumentos(int argc, char *argv[])
{
    int i;
    char temp[20];
    char num[20];

    strcpy(temp, argv[1]);

    if (strcmp("-f", argv[4]) == 0)
    {
        printf("Se introdujo -F\n");
    }

    // hex a binarios
    if (temp[0] == '0' && temp[1] == 'x')
    {
        int dec;

        if (strcmp("b", argv[2]) == 0)
        {
            strcpy(num, temp);
            printf("De hex a bin\n");

            if (error(num) == 0)
            {
                cal(num, &dec);
            }
            calcu(dec);
        }
    }

    if (temp[0] == '0' && temp[1] <= '9' && temp[1] > '0')
    {

        if (strcmp("b", argv[2]) == 0)
        {
            printf("De oct a bin\n");
        }
    }

    if (temp[0] <= '9' && temp[0] > '0')
    {

        if (strcmp("b", argv[2]) == 0)
        {
            printf("De dec a bin\n");
        }
    }

    // a hexadecimal

    // a decimal
    if (temp[0] == '0' && temp[1] == 'x')
    {
        int dec;

        if (strcmp("b", argv[2]) == 0)
        {
            strcpy(num, temp);
            printf("De dec a bin\n");

            if (error(num) == 0)
            {
                cal(num, &dec);
                printf("%d", dec);
            }
        }
    }
}

int cal(char num[], int *sum)
{
    int arr[100], suma, j = 0, x, y, neg;
    nuv(num, arr);
    neg = strlen(num) - 1;

    for (x = 2; x < strlen(num)-2; x++)
    {
        y = arr[x] * pow(16, neg);
        suma = j + y;
        y = j;
        j = suma;
        neg--;
    }
*sum=suma;
    return suma;
}

/* Está función convierte un Hexadecimal a Decimal.
 *@param num: arreglo tipo caracter; num cadena inicial.
 *@param *sum: variable tipo puntero de entero; apunta al valor del número decimal.
 *@return regresa el número en decimal.
 */
int cal(char num[], int *sum)
{
    int arr[100], suma, j = 0, x, y, neg;
    nuv(num, arr);
    neg = strlen(num) - 1;

    for (x = 2; x < strlen(num); x++)
    {
        y = arr[x] * pow(16, neg);
        suma = j + y;
        y = j;
        j = suma;
        neg--;
    }
    *sum = suma;
    return 0;
}

/* Está función convierte una cadena de caracteres a cadena de números enteros 
 *@param num: arreglo tipo caracter; num cadena inicial.
 *@param arr: arreglo tipo caracter; cadena donde se guardan los nuevos valores de forma entera.
 *@return no regresa nada
 */

void nuv(char num[], int arr[])
{
    int x;
    for (x = 2; x < strlen(num); x++)
    {
        if (num[x] <= 'F' && num[x] >= 'A')
        {
            arr[x] = num[x] - 55;
        }
        if (num[x] <= '9' && num[x] >= '0')
        {
            arr[x] = num[x] - 48;
        }
    }

}

/* Está función evalua la cadena ingresada.
 *@param num: arreglo tipo caracter; num cadena inicial.
 *@return regresa un '0', si esta bien la cadena.
 *@return regresa un '1', si  no esta bien la cadena.
 */
int error(char num[])
{
    int x;
    for (x = 2; x < strlen(num); x++)
    {
        if (num[x] <= 'F' && num[x] >= 'A' || num[x] <= '9' && num[x] >= '0')
        {
        }
        else
        {
            printf("Ingresa un número valido");
            return 1;
        }
    }
    return 0;
}
/* Está función convierte un Decimal a Binario.
 *@param dec: variable tipo entero; decimal que se convierte.
 *@return no regresa nada.
 */

void calcu(int dec)
{
    int arr[100];
    int res, cicl, x = 0;
    cicl = dec;
    do
    {
        res = cicl % 2;
        cicl = cicl / 2;
        arr[x] = res;
        x++;
    } while (cicl != 0);

    for (int i = x - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }

    printf("\n");
}