/*
@file: preg_3.c
@brief: Dados 3 números, identificaremos cual es el número menor
@details: Este programa lograremos identificar de manera correcta el uso de los if, y los if anidados
@author: Iris Yulit Jasso Cortes
@date: 16-febrero-2023

******************************
DISEÑO ARQUITECTÓNICO

Alto nivel

n1, n2, n3 (ENTRADAS) -> Calcular el número menor(PROCESO) -> Menor (SALIDAS)

Bajo nivel

Pedir números (PROCESO)  -> (SALIDAS) n1, n2, n3 (ENTRADAS) ->  Calcular el número menor (PROCESOS) -> (SALIDAS) Menor (ENTRADAS) -> Imprimir  resultado (PROCESO)


******************************
DISEÑO DETALLADO(PSEUDOCÓDIGO)

FUNCIÓN PRINCIPAL(|) // int main (void)
INICIO

    int n1, n2, n3, menor;
    
    //Llamadas a las funciones
    Pedir_Numeros (| &n1, &n2, &n3)
    Calcular_Menor( n1, n2, n3 | &Menor)
    Desplegar_Menor( Menor |)

FIN//}


  Pedir_Numeros (| *n1, *n2, *n3)

INICIO
  printf("Dame número 1:");
  scanf("%d",n1);
  printf("Dame número 2: ");
  scanf("%d",n2);
  printf("Dame número 3: ");
  scanf("%d",n3);
FIN


Función Calcular_Menor(int n1, int n2, int n3 | int *Menor)
INICIO
 if(n1<n2){
    if(n1<n3){
        *Menor = n1;
    }
 }

 if(n1>n2){
    if(n2<n3){
        *Menor = n2;
    }
 }

 if(n3<n2){
    if(n3<n1){
        *Menor = n3;
    }
 }
FIN

Función Desplegar_Menor(int Menor |)
INICIO
 printf("El númeor menor es: %d", Menor);
FIN

*/
#include <stdio.h>
void Pedir_Numeros (int *n1, int *n2, int *n3);
void Calcular_Menor(int n1, int n2, int n3, int *Menor);
void Desplegar_Menor( int Menor);

int main (void){

    int n1, n2, n3, Menor;
    
    Pedir_Numeros (&n1, &n2, &n3);
    Calcular_Menor( n1, n2, n3, &Menor);
    Desplegar_Menor( Menor );

return 0;
}


void Pedir_Numeros (int *n1, int *n2, int *n3){
  printf("Dame número 1:");
  scanf("%d",n1);
  printf("Dame número 2: ");
  scanf("%d",n2);
  printf("Dame número 3: ");
  scanf("%d",n3);
}

void Calcular_Menor(int n1, int n2, int n3, int *Menor){
 if(n1<n2){
    if(n1<n3){
        *Menor = n1;
    }
 }

 if(n1>n2){
    if(n2<n3){
        *Menor = n2;
    }
 }

 if(n3<n2){
    if(n3<n1){
        *Menor = n3;
    }
 }
}

void Desplegar_Menor(int Menor){
 printf("El númeor menor es: %d", Menor);
}