#include <stdio.h>
#include <math.h>
#include <string.h>
void cal(int dec, char arr[]);
int main(void)
{
    int dec;
    char arr[100];
    printf("Ingresa un número decimal: ");
    scanf("%d", &dec);
    cal(dec, arr);
    return 0;
}
/* Está función convierte un Decimal a Hexadecimal.
 *@param arr: arreglo tipo entero; cadena donde se guardan los valores.
 *@param dec: variable tipo entero; número decimal a convertir.
 */
void cal(int dec, char arr[])
{
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

