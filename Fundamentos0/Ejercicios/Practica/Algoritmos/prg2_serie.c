#include <stdio.h>

#define MAX 99

int suma_acumulada(int i, int suma);
void Desplegar(int i, int suma);

int main(void)
{
    int suma = 0, i;
    for (i = 0; i <= MAX; i++)
    {
        if (i % 3 == 0)
        {
            suma = suma_acumulada(i, suma);
            Desplegar(i, suma);
        }
    }
    return 0;
}

int suma_acumulada(int i, int suma)
{

    suma = suma + i;

    return suma;
}

void Desplegar(int i, int suma)
{
    printf("%d", i);
    if ( i != MAX)
    printf(" + ");
    else
    printf(" =  %d\n", suma);

}