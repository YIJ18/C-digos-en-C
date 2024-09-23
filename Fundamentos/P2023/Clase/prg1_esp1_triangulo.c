/*
  @file: prg1_esp1_triangulo.c
  @brief: En este archivo se genera la primera especificación de requerimientos básica del semestre. El problema a resolver es calcular el área de un triángulo rectángulo.
  @details: Revisar las secciones de la especificación de requerimientos que se va a desrrollar a continuación. Son 8 secciones las que se deben de considerar: título, descripción general, comportamiento detallado, salidas, entradas, procesos, alcances y limitaciones, y diseño de pantalla.

 

  @author: Iris Ylit Jasso Cortes
  date: 24-enero-2023

 

**************************************************************************************
ESPECIFICACIÓN DE REQUERIMIENTOS

 

Título: Área de un triángulo rectángulo

 

Descripción general:

 

Se desea un programa que calcule el área de un triángulo rectángulo. El programa solicita la base (b) y la altura (h) del triángulo rectángulo y posteriormente, el programa despliega el resultado del área en la pantalla.

 

El programa será utilizado para las clases de geometría de secundaria. Es un requerimiento que el área de un triánulo se calcule con la fórmula (b*h)/2, y que tanto la base como la altura sean números enteros.

 

Comportamiento detallado:

 

1) El programa solicita y lee los valores de la base (b) y la altura (h).
2) El programa calcula el área del triángulo rectángulo usando la fórmula (b*h)/2.
3) El programa despliega el área calculada en pantalla.

 

                ----------------------------------
(No importa el orden del desarrollo de estas secciones)

 

Entradas

 

Base (b) y altura (h)

 

Salidas

 

Área del triángulo (A)

 

Procesos

 

1) Solicitar base (b) y altura (h)
2) Calcular el área (A)
3) Desplegar el área (A) calculada
                ----------------------------------
Alcances y limitaciones

 

El programa solo sirve para calcular áreas de triángulos rectángulo, en donde sus entradas son de tipo entero.

 

El programa no hace ningún tipo de validación. Si el usuario introduce una base y/o altura negativos, el programa desplegará un resultado incorrecto.

 

Diseño de pantalla

 

$./area_trian

 

   Bienvenido. Este programa calcula el área de un triángulo rectángulo.

 

   Dame base: 5
   Dame altura: 3

 

   El área resultante es: 7.5

 

   Adiós. Vuelve pronto...
$
**************************************************************************************
DISEÑO ARQUITECTÓNICO

Alto nivel

b,h (ENTRADAS) -> Área de un triángulo rectangulo (PROCESO) -> A (SALIDAS)

Bajo nivel

Pedir b y a (PROCESO)  -> (SALIDAS) b, h (ENTRADAS) -> calcular área (PROCESOS) -> (SALIDAS) A (ENTRADAS) -> Imprimir  resultado (PROCESO)


*/

#include <stdio.h>

int main(void){
int b, A, a;
printf("Bienvenido. Este programa calcula el área de un triángulo rectángulo. \n");

    return 0;
}