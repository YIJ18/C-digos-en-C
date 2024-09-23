/*
@file: prg6_scanf_var_local.c
@brief: Utilización de la variable scanf conmo una variable local.
@details: Este  programa es un ejempo que utiliza la función scanf para guardar valores ingresados a traves del teclado en una variable declarada dentro de una función

@author: Iris Yulit Jasso Cortes
@date: 2 de Febrero del 2023

 DISEÑO ARQUITECTÓNICO

 (tanto la función printf como scanf son los unicos casos en donde su diseño arquitectonico tanto de alto como de baj nivel van a tener la misma forma)

 Diagrama de alto nivel
 scanf(PROCESO) -> a (SALIDA)

 Diagrama de bajo nivel
 scanf(PROCESO) -> a (SALIDA)
*/

#include<stdio.h>
#include<stdio_ext.h>

int main(void){

//Declarar la variable
int a;
float b;
char c;

printf("-----ANTES DE SOLICITAR UN VALOR AL USUARIO-----\n\n");
printf("a = %d, &a = %p\n", a , &a);
printf("b = %.2f, &b = %p\n", b , &b);
printf("c = %c, &c = %p\n", c , &c);
printf("\n\n");

printf("-----SOLICITAMOS LOS VALORES AL USUARIO-----\n\n");
printf("Dame el valor de a (entero): ");
scanf("%d", &a);
__fpurge(stdin);

printf("Dame el valor de b (flotante): ");
scanf("%f", &b);
__fpurge(stdin);

printf("Dame el valor de c (caracter): ");
scanf("%c", &c);
__fpurge(stdin);

printf("-----LOS VALORES GUARDADOS EN LAS VARIABLES-----\n\n");
printf("a = %d, &a = %p\n", a , &a);
printf("b = %.2f, &b = %p\n", b , &b);
printf("c = %c, &c = %p\n", c , &c);
printf("\n\n");
    return 0;
}