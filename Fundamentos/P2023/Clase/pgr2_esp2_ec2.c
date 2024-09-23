/*
  @file: prg2_esp2_ec2.c
  @brief: En este archivo se genera la segunda especificación de requerimientos básica del semestre. El problema a resolver la ecuación de segundo grado.
  @details: Revisar las secciones de la especificación de requerimientos que se va a desrrollar a continuación. Aqui vamos a realizar una transformación, estran 3 variables y regresa solo 2.

 

  @author: Iris Yulit Jasso Cortes
  date: 24-enero-2023

 

  **************************************************************************************
ESPECIFICACIÓN DE REQUERIMIENTOS

 

Título: Ecuación de segundo grado

 

Descripción general:

 

Se desea un programa que resuelva una ecuación de segundo grado. El programa solicita los datos a (a), b (b) y c(c) de la fórmula y posteriormente, el programa despliega los resultados de x1 y x2 en la pantalla.

 

El programa será utilizado para comprobar un problema de álgebra lineal. Es un requerimiento que se resuelva con la fórmula ---- , y que tanto a, b y c sean números enteros.

 

Comportamiento detallado:

 

1) El programa solicita y lee los valores de la a. b y c.
2) El programa calcula x1 y x2 usando la fórmula general-----.
3) El programa despliega los dos resultados.

 

                ----------------------------------
(No importa el orden del desarrollo de estas secciones)

 

Entradas

 

a (a),  b (b), c(c)

 

Salidas

 

El resultado de x1 (x1)
El resultado de x2 (x2)

 

Procesos

 

1) Solicitar a (a), b (b) y c (c)
2) Resolver la formula general (x1), (x2)
3) Desplegar los (x1), (x2).

                ----------------------------------
Alcances y limitaciones

 

El programa solo sirve para calcular cuando a es diferente de 0 y se diferente a una raíz imaginaria, en donde sus entradas son de tipo entero.

 

El programa no hace ningún tipo de validación. Si el usuario introduce una a y/o b y/o c negativos, el programa desplegará un resultado incorrecto.

 

Diseño de pantalla

 

$./area_trian

 

   Bienvenido. Este programaresuelve una ecuación general.
 

   Dame a: 5
   Dame b: 3
   Dame c: 10

 

   Tu resultado 1 es: 7.5
   Tu resultado 2 es: 10

 

   Adiós. Vuelve pronto...
$
*/

