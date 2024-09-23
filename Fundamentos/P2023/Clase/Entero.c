/*
  @file: Entero.c
  @brief: Ve si es un número entero o un número flotante
  @details: Ve si es un número entero o un número flotante, entra un número, compara con un número

  @author: Iris Yulit Jasso Cortes
  @date: 23-febrero-2023

Diagrama IPO de alto nivel
  Número  (ENTRADAS) -> Ver entero o flotante(PROCESO)

Diagrama IPO de bajo nivel
    Pedir número (PROCESO) -> (ENTRADA) n (SALIDA) -> Ver entero o flotante

Pseudocódigo

int main (void)
{
int n;
}
Función Pedir (float *n)
{

}
Función Entero_Flotante(float n)
{

}

*/

#include <stdio.h>

void Pedir(float *n);
void Entero_Flotante(float n);

int main(void)
{
    float n;
    Pedir(&n);
    Entero_Flotante(n);
    return 0;
}
// Definición de la función
void Pedir(float *n)
{
    printf("Ingresa el número: ");
    scanf("%f", n);
}

void Entero_Flotante(float n)
{
    int entero;
    entero = n;

    if (n != entero)
    {
        printf("Es un número flotante\n");
    }
    else
    {
        printf("Es entero\n");
    }
}