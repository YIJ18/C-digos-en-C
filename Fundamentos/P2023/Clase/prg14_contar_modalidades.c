/*
@file: prg14_contar_modalidades.c
@brief: Contar del mayor a menor o de menor a mayor
@details: Este programa valida los limites que necesita y cual es menor y cual es mayor, dependiendo cual sea el maypr hace una cuenta regresiva o un aumento de número hasta llegar al establecido
@author: Iris Yulit Jasso Cortes
@date: 03-Marzo-2023

Diagrama IPO Bajo nivel
Pedir Datos (PROCESO) -> (SALIDAS)lim, lim2(ENTRADAS) -> Contar Ascendente (PROCESO)
Pedir Datos (PROCESO) -> (SALIDAS)lim, lim2(ENTRADAS) -> Contar Descendente (PROCESO)


Diagrama IPO Alto nivel
lim, lim2 -> Contar Descendente (PROCESO)
lim, lim2 -> Contar Ascendente (PROCESO)
*/
#include <stdio.h>
#include <stdio_ext.h>

void Pedir_limites(int *lim, int *lim2);
void Contar_ascendentemente(int lim, int lim2);
void Contar_descendentemente(int lim, int lim2);

int main(void)
{
    int lim, lim2;
    Pedir_limites(&lim, &lim2);
    if (lim < lim2)
        Contar_ascendentemente(lim, lim2);
    if (lim > lim2)
        Contar_descendentemente(lim, lim2);
    return 0;
}
void Pedir_limites(int *lim, int *lim2)
{
    printf("Ingresa el limite 1: ");
    scanf("%d", lim);
    __fpurge(stdin);
    printf("Ingrese el segundo limite: ");
    scanf("%d", lim2);
    __fpurge(stdin);
}
void Contar_ascendentemente(int lim, int lim2)
{
    int i = lim;

    while (i <= lim2)
    {
        printf("%d\n", i);
        i++;
    }
}
void Contar_descendentemente(int lim, int lim2)
{
    int i = lim;

    while (i >= lim2)
    {
        printf("%d\n", i);
        i--;
    }
}