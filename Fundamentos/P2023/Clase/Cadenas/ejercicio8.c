/*
  @file: prg36_strtok_cadena.c
  @brief: Función strtok (string compare)
  @details: Se ejemplifica el uso de una función strcpy, cuya proceso es cortar la cadena dada por e usuario, tomando como referencia un caracter o caracteres para dividir la cadena
  @author: Iris Yulit Jasso  Cortes
  @date: 20-abril-2023
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

#define MAX 100

void Leer_Frase(char *Frase);
int Separar_Frase(char *Frase, char Guardar[MAX][MAX]);
void Imprimir(char Guardar[MAX][MAX], int Cantidad_Palabras);

int main(void)
{
    char Frase[MAX];
    char Guardar[MAX][MAX];
    int Cantidad_Palabras;

    Leer_Frase(Frase);
    Cantidad_Palabras = Separar_Frase(Frase, Guardar);
    Imprimir(Guardar, Cantidad_Palabras);

    return 0;
}

void Leer_Frase(char *Frase)
{
    printf("Dame una frase que contenga tres palabras: ");
    fgets(Frase, MAX, stdin);
    __fpurge(stdin);
    Frase[strlen(Frase) - 1] = 0;
}

int Separar_Frase(char *Frase, char Guardar[MAX][MAX])
{
    int i;
    char *Token;

    i = 0;
    Token = strtok(Frase, " ");

    while (Token != NULL)
    {
        strcpy(Guardar[i], Token);
        Token = strtok(NULL, " ");
        i++;
    }
    return i;
}

void Imprimir(char Guardar[MAX][MAX], int Cantidad_Palabras)
{
    puts(Guardar[0]);
    puts(Guardar[2]);
}
