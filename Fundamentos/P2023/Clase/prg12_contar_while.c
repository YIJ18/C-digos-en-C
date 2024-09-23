/*
@file: prg12_contar_while.c
@brief: Contar del 1 al 10
@details: Este programa demuestra uno de los casos a utilizar el ciclo WHILE. El programa no solicitará nada y solamente desplegará en pantalla la contabilización del 1 al 10.
@author: Iris Yulit Jasso Cortes
@date: 23-febrero-2023

 

DISEÑO ARQUITECTÓNICO

 

Diagrama IPO de alto nivel
Contar (PROCESO) -> (SALIDA) Num

 

Diagrama IPO de bajo nivel
Contar (PROCESO) -> (SALIDA) Num
*/

#include <stdio.h>

int main(void)
{
    int i = 0, j = 1;
    printf("Contabiliza cuando i se inicia en 0\n");
    while (i < 10)
    {
        i++;
        printf("%d\n", i);
    }

    printf("Contabiliza cuando i se inicia en 1\n");
    while (j < 10)
    {
        printf("%d\n", j);
        j++;
    }

        return 0;
}