#include <stdio.h>
#define MAX 100
void Solicitar_numero(int *n);
void Desplegar_numero(int *Guardar, int i);

int main (void)
{
    int numero, i = 0, Guardar[MAX];
    do 
    {
        Solicitar_numero(&numero);
        Guardar[i] = numero;
        i++;
    }while(numero!=0);
    
    Desplegar_numero(Guardar, i - 1);

    return 0;
}

void Solicitar_numero(int *n)
{
    printf("Ingresa un número: ");
    scanf("%d", n);
}

void Desplegar_numero(int *Guardar, int i)
{
    int j;
    for(j = 0; j < i; j++)
    printf("%d, ", Guardar[j]);
}