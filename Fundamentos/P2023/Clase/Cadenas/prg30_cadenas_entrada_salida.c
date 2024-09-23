/*
  @file: prg30_cadena_entrada_salida.c
  @brief: Funciones para leer y escribir cadenas
  @details: En este progama se desmuestra el funcionamiento de varias funciones de entrada y salida para el manejo de cadenas y la explicación de su eficiencia.
  Tambien se va a explicar la función que calcula la longituid de la cadena.
  @author: Iris Yulit Jasso Cortes
  @date: 14-Abril-2023
*/

// Funciones: scanf, printf, gets, fgets, fputs, strlen

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

int main(void)
{
  char Frase[51];
  // El tamaño de la frase debe de ser de 50 caraceres porque la ultima casilla(51) va a estar ocupaado por el caracter NULL('\0')
  int Longitud;

  printf("Dame frase (maximo 50 caracteres): ");
  /*-----------------Funciones de lectura (salida)-----------------*/
  /*Versión 1

  scanf("%s",Frase); //scanf ("%s", &Frase[0])
  __fpurge(stdin);

  Frase  almacena la dirección de memoria del primer elemento de mi arreglo Frase y scanf recibe la dirección de memoria de este primer elemento donde se iniciara el gurardado de mi frase que lea del teclado
  La limitación de scanf al leer una cadena es que no va a tomar el resto de los caracteres despues de encontrar el primer espacio*/

  /*Versión 2*/
  // gets(Frase);
  //__fpurge(stdin);

  /*Siempre que se utilice esta función va a aparecer un warning por que es una función peligrosa , ya que no sabemos el tamño de la frase que nos va a dar el usuario. El riesgo que corremos es que haya un aviolación al princiopio de la memoria, es decir, que se intente ocupar más memoria de la que se reservo */

  /*Versión 3*/
  // fgets (char *Cadena, Tamaño a leer, stdin);

  fgets(Frase, 51, stdin);
  Frase[strlen(Frase) - 1] = 0;
  __fpurge(stdin);

  /*-----------------Funciones de imprimir (entrada)-----------------*/
  printf("La frase dada con printf es: %s\n\n", Frase);

  printf("La frase dada con puts: ");
  puts(Frase);
  /*La función puts siempre va a agregar al final un salto de linea a la cadena que queremos imprimir*/

  printf("La frase dada con fputs: ");
  fputs(Frase, stdout);
  // puts (char *Cadena, *FILE) -> FILE correcponde al archivo de salida que es stdout
  /*La función puts siempre va a agregar al final un salto de linea a la cadena que queremos imprimir*/
 
  /*-----------------Función de longitud(Regresa el tamaño de la cadena)-----------------*/
  /*strlen(char *Cadena)*/
  Longitud = strlen(Frase);
  printf("\nLa longitud de la frase dada es: %d\n", Longitud);
  /*Nota: Al calcular la longitud de una cadena, no se toma en cuenta el caracter NULL*/
  
  return 0;
}