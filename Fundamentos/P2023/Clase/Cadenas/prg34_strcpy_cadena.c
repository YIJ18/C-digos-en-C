/*
  @file: prg34_strcpy_cadena.c 
  @brief: Función strcpy
  @details: Se ejemplifica el uso de una función strcpy, la cual copia elemento poir elmento en contenido de un arreglo tipo cadena.
  @author: Iris Yulit Jasso  Cortes
  @date: 20-abril-2023

*/
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

void Pedir_frase (char *Frase);
void Copiar_frase (char *Frase, char *Frase2);

int main (void)
{
  char Frase[100], Frase2[100];

  Pedir_frase(Frase);
  Copiar_frase (Frase, Frase2);

  return 0;
}

void Pedir_frase (char Frase[])
{
  printf ("Dame frase: ");
  fgets (Frase, 100, stdin);
  __fpurge(stdin);
  Frase[strlen(Frase)-1]=0;
}

void Copiar_frase (char *Frase, char *Frase2)
{
  strcat (Frase, "yay");
  printf ("Frase con yay:\n");
  puts (Frase);
  strcpy (Frase2, Frase);
  printf ("El valor de Frase2 al copiarse:\n");
  puts (Frase2);
 }
