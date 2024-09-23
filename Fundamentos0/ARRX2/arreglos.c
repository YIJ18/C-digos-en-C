/*
  @file: prg27_leer_datos_arr.c
  @brief: Leer datos y guardarlos en un arreglo
  @details: En este programa se ejemplifica el cómo guardar valores en un arreglo
  @author: Adriana Lorena Fajardo Martos
  @date: 31-marzo-2023
  ********************************************************************************
 */

 

#include <stdio.h>
#include <stdio_ext.h>

 

/*Declaración de constantes*/
#define MAX 10

 

//En las declaraciones de las constants, nunca se pone unto y coma al final

 

void Desplegar (int Lista[MAX]); //void Desplegar (int Lista[10]);
void Leer_datos (int Lista[MAX]);

 


int main (void)
{
  int Lista[MAX];

 


  printf ("El contenido del arreglo antes de asignarle algún valor.\n\n");
  Desplegar (Lista); //Desplegar (&Lista[0]);

 

  printf ("Leer valores del teclado y guardarlos en el arreglo\n\n");
  Leer_datos (Lista);

 

  printf ("El contenido del arreglo después de asignarle algún valor.\n\n");
  Desplegar (Lista); //Desplegar (&Lista[0]);

 

  return 0;
}

 

void Desplegar (int Lista[MAX])
{
  int i;

 

  for (i=0; i<MAX; i++)
    {
      printf ("Lista[%d] = %d\n",i, Lista[i]);
    }
}

 

void Leer_datos (int Lista[MAX])
{
  int i;

 

  for (i=0; i<MAX; i++)
    {
      printf ("Dame valor de Lista[%d]: ", i);
      scanf ("%d", &Lista[i]);
      __fpurge(stdin);
      printf ("&Lista[%d]: %p\n\n", i, &Lista[i]);
      /*Los arreglos, aunque se pasan como parámetros de una función, se manipulan como variables locales al utilizar la sintaxis de los arreglos (con corchetes)*/
    }

 

}