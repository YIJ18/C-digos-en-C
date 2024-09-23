#include <stdio.h>
#include <stdio_ext.h>

void Solicitar(int *Cant);
void Calcular(int Cant);
void Imprimir(int Cant);

int main(void)
{
    int Cant;
    Solicitar(&Cant);
    Calcular(Cant);
    return 0;
}

void Solicitar(int *Cant)
{
    printf("Ingresa la cantidad de numeros que quiere visualizar: ");
    scanf("%d", Cant);
    __fpurge(stdin);
}

void Calcular(int Cant)
{

    if (Cant == 0)
    {
        printf("f(0)= 0");
    }
    
    if (Cant == 1)
    {
        printf("f(1)= 1");
    }

    int suma, i, fn2, fn1;
    suma = 0;
    fn2 = 1;
    fn1 = 0;
    for (i = 1; i <= Cant; i++)
    {
        suma = fn1 + fn2;
        fn2 = fn1;
        fn1 = suma;
        printf("%d", suma);
    }
    
}

void Imprimir(int Cant)
{
}