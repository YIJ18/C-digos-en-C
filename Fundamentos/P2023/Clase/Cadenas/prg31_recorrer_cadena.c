/*

  @file: prg31_recorrer_cadena.c
  @brief: Dos formas de recorrer una cadena
  @details: Las dos formas de recorrer una cadena
  1) Utilizando la función strlen, un ciclo for y un contador
  2)Utilizando el ciclo while, un contador y validando el contenido hasta que este sea diferente de NULL

  @author: Iris Yulit Jasso Cortes
  @date: 14-Abril-2023

*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

#define MAX 61

void Pedir_frase(char *Frase);
void Recorrer_frase(char *Frase);

int main(void)
{
    char Frase[MAX];
    Pedir_frase(Frase);
    Recorrer_frase(Frase);
    return 0;
}

void Pedir_frase(char *Frase)
{
    printf("Dame frase (maximo 61 caracteres): ");
    fgets(Frase, MAX, stdin);
    Frase[strlen(Frase) - 1] = 0;
    __fpurge(stdin);
}

void Recorrer_frase(char *Frase)
{
    int i;

    /*
    Versión 1
    Recorrer el arreglo utilizando si tanaño strlen
    */
    printf("Versión 1 para recorrer el arreglo\n");
    for (i = 0; i < strlen(Frase); i++)
    {
        putchar(Frase[i]);
    }

    /*
    Versión 2
    Recorrer el arreglo al v alidar el conteido. Se detiene el ciclo cuando encuentra un carcter NULL
    */
    printf("\nVersión 2 para recorrer el arreglo\n");
    i = 0;
    while (Frase[i] != 0)
    {
        putchar(Frase[i]);
        i++;
    }
    printf("\n");
}