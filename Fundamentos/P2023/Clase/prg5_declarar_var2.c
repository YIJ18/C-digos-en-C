/*
@file: prg5_declarar_var.c
@brief: Ejemplo de declarar variable
@details: En este programa se declaran diferentes tipos de variables, se es asigna un valor y, posteriormente, se imprime.

Para ejemplificar las partes de la memoria, vamos a imprimir las direcciones de memoria de las variables.

@author: Iris Yulit Jasso Cortes
@date: 31 de enero 2023
*/

#include<stdio.h>
//Constantes

//Declaración de los encabeados de las finciones

int main(void){
    int var_Entero;
    float var_Flotante;
    char var_Caracter;

//----------------------------------------------------
/*Aqui se mandan a lamar funciones, se utilisan los diferentes tipos de sentencias(asignación, seleccion, iterativa, entre otras), entre otras*/
    
  printf("Se imprimen los valores déspues de declarar los valores\n");  
  printf("var_Entero: %d, &var_Entero = %p\n",var_Entero, &var_Entero);
  printf("var_Flotante: %f, &var_Flotante = %p\n",var_Flotante,&var_Flotante);
  printf("var_Caracter: %c, &car_Caracter = %p\n\n",var_Caracter, &var_Caracter);

    var_Entero=5;
    var_Flotante=4.5;
    var_Caracter='a';

   printf("Se imprimen los valores iniciales de las variables\n");   
   printf("var_Entero: %d, var-Flotante: %.2f, var_Caracter: %c\n\n", var_Entero, var_Flotante, var_Caracter);

   var_Caracter='b';
   printf("Se imprimen los valores déspues de que se cambio alguna\n");
   printf("var_Entero: %d, var-Flotante: %.2f, var_Caracter: %c\n\n", var_Entero, var_Flotante, var_Caracter);
   
   return 0;
}