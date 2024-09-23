/*
@file: prg19_char.c
@brief: onvertir una letra dada de mayusculas o viceversa, segun sea el caso
@details: Este programa ejemplifica el uso de código ascii. La solución del problema es el que nos va a dar un caracter y va a validar si lo que nos dio es una letra mayuscula o minuscula para convertirla a su conttrario, es decir, si es mayuscula se transforma a minuscula o viceversa. En caso de uqe el usuario nos de otro caracter que no es una letra, imprimira un mensaje indicado que no se puede convertit.
Aunado a esto, se va a inclur el tema de banderas que nos va a servir como indicadpres para defiir el comportamiento del programa.
@author: Iris Yulit Jasso Cortes
@date: 20-Marzo-2023

Diagrama IPO alto nivel
Caracter (ENTRADA) -> Convertir Letra (PROCESO)-> Letra convertida (SALIDA)

Diagrama IPO bajo nivel
Pedir Carcter (PROCESO) -> (SALIDA) Caracter (ENTRADA) -> Validar caracter(PROCESO) -> Convertir Letra (PROCESO)-> Letra convertida (SALIDA)
*/

#include <stdio.h>
#include <stdio_ext.h>

void Pedir_caracter(char *Caracter);
void Validar_caracter(char Caracter, char *Bandera);
void Convertir_letra(char Caracter, char Bandera, char Letra_convertida);
void Imprimir_conversion(char Letra_convertida);

int main(void)
{
    char Carcater, Letra_convertida;
    int Bandera;
    return 0;
}

void Pedir_caracter(char *Caracter)
{
    printf("Dame la letra que quieres convertir: ");
    scanf("%c", Caracter);
    __fpurge(stdin);
}

void Validar_caracter(char Caracter, char *Bandera)
{

}

void Convertir_letra(char Caracter, char Bandera, char Letra_convertida)
{

}

void Imprimir_conversion(char Letra_convertida)
{

}