/*
  @file: examen1.c
  @brief: En este archivo calcula la cantidad que debes ahorrar para el retiro a cierta edad
  @details: Este archivo recibe dos valores enteros y se transforman en una cantidad que debes ahorrar para el retiro a cierta edad



  @author: Iris Ylit Jasso Cortes
  date: 2-Marzo-2023



**************************************************************************************
ESPECIFICACIÓN DE REQUERIMIENTOS



Título: Calculo del ahorro de la jubilación total



Descripción general:



Se desea un programa que calcule el monto mensual que te gustaria recibir cuando te retires. El programa solicita la edad a la que te quieres retirar (Edad) y la cantidad mensual que debes ahorrar (Monto)  y posteriormente, el programa despliega el resultado de la cantidad que tienes que ahorrar en pantalla.



El programa será utilizado para las personas que empiezan a trabajar y quieren asegurar un buen retiro. Es un requerimiento es que se calcule con la fórmula ahorro total= (Esperanza de Vida -  Edad de jubilación)*12*Monto deseado de la pension mensual, y que tanto el monto como la edad sean números enteros.



Comportamiento detallado:



1) El programa solicita y lee los valores de la edad (Edad) y el monto (Monto).
2) El programa calcula el monto total que debes ahorrar usando la fórmula ahorro total= (Esperanza de Vida -  Edad de jubilación)*12*Monto deseado de la pension mensua
3) El programa despliega el monto total que debes ahorrar calculada en pantalla.



                ----------------------------------

Entradas



Edad a la que se quiere retirar (Edad) y Monto que desea obtener (Monto)



Salidas



Ahorro T (Resultado)



Procesos



1) Solicitar edad a la que se quiere retirar (Edad) y monto que quiere recibir mensualmente (Monto)
2) Calcular ahorro total que debe hacer (Resultado)
3) Desplegar el ahorro total que se debe hacer (Resultado) calculado
                ----------------------------------
Alcances y limitaciones



El programa solo sirve para calcular el ahorro total, en donde sus entradas son de tipo entero.

 Si el usuario introduce Monto y Edad flotantes, el programa arroja un resultado incorrecto, este programa no recibe ni Edad, ni Monto negativos, por lo que este marcara un error si los introduce de esta manera.


Diseño de pantalla



$./area_trian


    Este  programa  realiza  una  estimación  de  cuanto  debe  de  ahorrar  una  persona en su vida profesional para su retiro.

    Dame    la edad a la que te quisieras retirar: 63

    Dame el monto mensual que te gustaría recibir cuando te retires: 30000

    En total debes de ahorrar $5400000 pesos para recibir una mensualidad de $30000 pesos.

    ¡¡¡Es tiempo de ahorrar!
$

*/

#include <stdio.h>
#include <stdio_ext.h>

void Pedir(int *Monto, int *Edad);
void Validar(int Monto, int Edad);
void Calcular(int Monto, int Edad, int *Resultado);
void Desplegar(int Resultado);

int main(void)
{
  int Monto, Edad, Resultado;

  return 0;
}

void Pedir(int *Monto, int *Edad)
{
  printf("Bienvenido.  Este  programa  realiza  una  estimación  de  cuanto  debe  de  ahorrar  una  persona en su vida profesional para su retiro.\n");
  printf("");
  scanf("%d", Edad);
  __fpurge(stdin);
  printf("");
  scanf("%d",Monto );
  __fpurge(stdin);
}
void Validar(int Monto, int Edad);
void Calcular(int Monto, int Edad, int *Resultado);
void Desplegar(int Resultado);