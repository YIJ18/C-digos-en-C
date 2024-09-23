#include <stdio.h>

void Fib_0_1(int num);
void Error (int num);
int Fibbonacci(int num);

int main(void)
{
    int num, x, y, fib;
    do
    {
        printf("Ingresa el número: ");
        scanf("%d", &num);
        Error (num);

    } while (num < 0);

    if (num == 0 || num == 1)
    {
        Fib_0_1 (num);
    }

    for (x = 0; x < num; x++)
    {
        for (y = 0; y < x; y++)
        {
            fib = Fibbonacci(y);
            printf("%d ", fib);
        }
        printf("\n");
    }
    return 0;
}

int Fibbonacci(int num)
{
    int suma, i, fn2, fn1;
    suma = 0;
    fn2 = 1;
    fn1 = 0;
    for (i = 1; i <= num; i++)
    {
        suma = fn1 + fn2;
        fn2 = fn1;
        fn1 = suma;
    }
    return suma;
}

void Fib_0_1 (int num)
{
    if (num == 0)
    {
        printf("f(0)= 0");
    }
    if (num == 1)
    {
        printf("f(1)= 1");
    }
}

void Error (int num)
{
    if (num < 0)
    {
        printf("Ingresa Un número valido\n");
    }
}
