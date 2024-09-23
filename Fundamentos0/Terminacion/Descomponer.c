/*Descompone el numero ingresado*/

#include <stdio.h>
void Pedir_Num(int *n);
void Calcular_Num(int n);

int main(void)
{
    int n;
    Pedir_Num(&n);
    Calcular_Num(n);
    return 0;
}

void Pedir_Num(int *n)
{
    printf("Ingresa el número a descomponer: ");
    scanf("%d", n);
}

void Calcular_Num(int n)
{
    int res;

    for (int i = 0; n != 0; i++)
    {
        res = n % 10;
        n = n / 10;
        printf("%d x 10 ^ %d\n", res, i);
    }
}