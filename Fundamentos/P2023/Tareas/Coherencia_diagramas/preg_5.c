/*

@file: preg_5.c
@brief: Generaemos un número random, el usuario intrduce un número itentando adivinarlo
@details: En este programa aprenderemos a usar dos nuevas librerias: stdlib.h y time.h | al igual que lograremos aprender a generar un número random
@author: Iris Yulit Jasso Cortes
@date: 16-febrero-2023

******************************
DISEÑO ARQUITECTÓNICO

Alto nivel
Generar un Número aleatorio (PROCESO)
Num_adivinar (ENTRADAS) -> Adivinar Número (PROCESO) -> Mensaje (SALIDAS)

Bajo nivel
Generar un Número aleatorio (PROCESO)
Pedir numero a adivinar (PROCESO)  -> (SALIDAS) Num_adivinar (ENTRADAS) -> Imprimir  resultado (PROCESO)


******************************
DISEÑO DETALLADO(PSEUDOCÓDIGO)

FUNCIÓN PRINCIPAL(|) 
INICIO

    int Rand, Num_adivinar;
    
    //Llamadas a las funciones
    Generar_rand(  | &Rand);
    Ingresar (| &Num_adivinar);
    Mensaje (Rand, Num_adivinar| );

FIN

Función Generar_rand(|int *Rand)
INICIO
 *Rand = rand() % 15;
FIN

Función Ingresar (|int *Num_adivinar)
INICIO
 printf("Ingresa el número correcto: ");
 scanf("%d", Num_adivinar);
FIN

 Función Mensaje(Rand, Num_adivinar|) 
INICIO
 if (Rand == Num_adivinar)
 {
    printf("El número ingresado es correcto");
 }
 if (Rand != Num_adivinar)
 {
    printf("El número ingresado es incorrecto");
 }
FIN
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Generar_rand(int *Rand);
void Ingresar (int *Num_adivinar);
void Mensaje (int Rand, int Num_adivinar);

int main (void){
    int Rand, Num_adivinar;
    
    //Llamadas a las funciones
    Generar_rand(&Rand);
    Ingresar (&Num_adivinar);
    Mensaje (Rand, Num_adivinar);

}

void Generar_rand(int *Rand){
srand(time(NULL));
 *Rand = rand() % 15;
}

void Ingresar (int *Num_adivinar)
{
 printf("Ingresa el número correcto: ");
 scanf("%d", Num_adivinar);
}

void Mensaje(int Rand, int Num_adivinar) 
{
 if (Rand == Num_adivinar)
 {
    printf("El número ingresado es correcto");
 }
 if (Rand != Num_adivinar)
 {
    printf("El número ingresado es incorrecto");
 }
}