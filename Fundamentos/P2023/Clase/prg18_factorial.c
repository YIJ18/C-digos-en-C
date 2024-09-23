/*
@file: prg18_factorial.c
@brief: Factorial con while y con for
@details: Este programa se implementa la solucion de un factorial
@author: Iris Yulit Jasso Cortes
@date: 17-Marzo-2023
*/

#include <stdio.h>
#include <stdio_ext.h>

void Solicitar(int *Num);
void Calcular_for(int Num, int *mult);
void Calcular_while(int Num, int *Fact);
void Desplegar(int Mult, int Fact);

int main (void)
{
    int Num, Res, Mult, Fact;

 Solicitar(&Num);
 Calcular_for(Num, &Mult);
 Calcular_while(Num, &Fact);
 Desplegar( Mult,  Fact);


    return 0;
}

void Solicitar(int *Num)
{
    printf("Ingresa el número del factorial: ");
    scanf("%d", Num);
    __fpurge(stdin);
}

void Calcular_for (int Num, int *mult)
{
    int i;
    int multi = 1;
    for (i = Num; i >= 1; i--)
    {
        multi = multi * i; // 
    
    }
    *mult = multi;
}

void Calcular_while(int Num, int *Fact)
{
    int i = 1;
    int multi = 1;
    while (i <= Num)
    {
        multi = multi * i; // 
        i++;
    }
    *Fact = multi;
}

void Desplegar(int Mult, int Fact)
{
    printf("El Resultado con for es: %d\n", Mult);
    printf("El Resultado con while es: %d\n", Fact);
}