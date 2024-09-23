/*
@file: prg19_char.c
@brief: Aprenderemos la tabla ascci y el cambio de mayusculas y minusculas
@details: El usuario introducira una letra y con base en la tabla ascci haremos una transformación a mayusculas o minusculas
@author: Iris Yulit Jasso Cortes
@date: 20-Marzo-2023
*/

#include <stdio.h>

void Solicitar(char *Letra);
void Mayus(char Letra, char *Letra_1);
void Minus(char Letra, char *Letra_1);
void Desplegar(char Letra, char Letra_1);

int main(void)
{
    char Letra, Letra_1;
    Solicitar(&Letra);
    if(Letra >= 65 && Letra <= 90)
        Mayus(Letra, &Letra_1);
    else if(Letra >= 97 && Letra <= 122)
        Minus(Letra, &Letra_1);
    
    Desplegar(Letra, Letra_1);

    return 0;
}

void Solicitar(char *Letra)
{
    printf("\nIngresa una letra : ");
    scanf("%c", Letra);
}

void Mayus(char Letra, char *Letra_1)
{
    *Letra_1 = Letra + 32;
}

void Minus(char Letra, char *Letra_1)
{
    *Letra_1 = Letra - 32;
}

void Desplegar(char Letra, char Letra_1)
{
    if(Letra >= 65 && Letra <= 90)
        printf("La letra ingresada es %c, su letra minúscula %c\n", Letra, Letra_1);
    else if(Letra >= 97 && Letra <= 122)
        printf("La letra ingresada es %c, su letra mayúscula %c\n", Letra, Letra_1);
    else
        printf("Ingrese una letra válida.\n");
} 