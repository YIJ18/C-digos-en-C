/*
  @file: prg26_declarar_arr_uni.c
  @brief: Diferentes nomenclaturas para declarar arreglos unidimensionales
  @details: En este programa se demuestra y se explican las diferentes nomenclaturas que se utilizan para hacer referencia a un arreglo cuando se pasan como parámetros de una función
  @author: Adriana Lorena Fajardo Martos
  @date: 28-marzo-2023
  ********************************************************************************
Notas:

 

Lista (identificar del arreglo) -> es una variable que va a guardar la dirección de memoria del primer elemento de mi arreglo (pointer)

 

*Lista -> su equivalente es Lista[0] porque *Lista ve lo que contiene la dirección de memoria que almacena la variable Lista.

 

CUANDO SE PASA "TODO EL ARREGLO" A OTRA FUNCIÓN

 

Lo que se pone en el encabezado de la función en la sección de los parámetros es lo siguiente:

 

Lista[5] -> la nomenclatura ortodoxa (el pointer significa que va a ser tratado como un arreglo)
*Lista -> se manipula omo si fuera un parámetro de salida, pero sabemos que es el pointer de un arreglo
Lista[] -> la dirección de memoria se va a manipular como un arreglo

 

Anotación: etas tres nomenclaturas significan lo mismo porque todas guardan una dirección de emoria que apunta a la primera casilla del arreglo
*/

#include <stdio.h>
