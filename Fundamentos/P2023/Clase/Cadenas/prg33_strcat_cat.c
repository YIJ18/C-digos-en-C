/*

  @file: prg33_strcat_cat.c
  @brief: Función strcat (concatenar)
  @details: Este programa demuestra el funcionamiento de la funcipon strcat que nos permite concatenar (juntar o agrgar) dos cadenas
  @author: Iris Yulit Jasso Cortes
  @date: 14-Abril-2023

*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

#define MAX 61

void Pedir_frase(char *Frase, int i);
void Concatenar_frase(char *Frase1, char *Frase2);

int main (void)
{
    char Frase1[MAX], Frase2[MAX];
    Pedir_frase (Frase1, 1);
    Pedir_frase (Frase2, 2);
    return 0;
}

void Pedir_frase(char *Frase, int i)
{
    printf("Dame frase %d (maximo 61 caracteres): ", i);
    fgets(Frase, MAX, stdin);
    Frase[strlen(Frase) - 1] = 0;
    __fpurge(stdin);
}

void Concatenar_frase(char *Frase1, char *Frase2)
{
    /*
    strcat(char *s1, char *s2);

    s1 = Es la cadena a la que se le va agrgar el contenido de la otra cadena (cadena de destino)
    s2 = La cadena que se va agregar a la tra cadena
    */
   
   strcat(Frase1," ");

}
