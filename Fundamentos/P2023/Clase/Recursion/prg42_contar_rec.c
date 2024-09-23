/*
  @file: prg42_contar_rec.c
  @brief: Contar del 1 al n utilizando recursion
  @details: Este programa ejemplifica el caso más sensillo de la recursión. En este caso no se va a utilizar un parametro de  salida para guardar el valor que se va a imprimir

  @author: Iris Yulit Jasso Cortes
  @date: 02-Mayo-2023
*/

#include <stdio.h>
#include <stdio_ext.h>

void Pedir_n(int *Numero);
void Contar(int n);

int main(void)
{
    int n;
    Pedir_n(&n);
    Contar(n);
    return 0;
}

void Pedir_n(int *Numero)
{
    do
    {
        printf("Dame número: ");
        scanf("%d", Numero);
        if (*Numero < 0 || *Numero > 100)
        {
            printf("Número fuera de rango. Intenta nuevamente...\n");
        }
    } while (*Numero < 0 || *Numero > 100);
}

void Contar(int n)
{
    printf("Entrada de recusión -> n = %d, &n =%p\n ", n, &n);
    if (n > 0)
    {
        getchar();
        __fpurge(stdin);
        Contar(n - 1);
        printf("Entrada de recusión -> n = %d, &n =%p\n ", n, &n);
    }
}
