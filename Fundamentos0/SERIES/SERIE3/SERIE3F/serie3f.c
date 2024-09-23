#include <stdio.h>
#include <math.h>
#include <string.h>
void cal(int dec, int arr[]);
int main(void)
{
    int dec;
    int arr[100];
    printf("Ingresa un número decimal: ");
    scanf("%d", &dec);
    cal(dec, arr);
    return 0;
}
/* Está función convierte un Decimal a Octal.
 *@param dec: variable tipo entero; decimal que se convierte.
 *@param arr: arreglo tipo entero; se guarda el valor octal.
 *@return no regresa nada.
 */
void cal(int dec, int arr[])
{
    int res, cicl, x = 0;
    cicl = dec;
    do
    {
        res = cicl % 8;
        cicl = cicl / 8;
        arr[x] = res;
        x++;
    } while (cicl != 0);

    for (int i= x-1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }

    printf("\n");

}

