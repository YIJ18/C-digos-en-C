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

#define COL_MAX 50
#define REN_MAX 25

void Leer_Frase(char *Frase);
int Separar_Frase(char *Frase, char Guardar[REN_MAX][COL_MAX]);
void Imprimir(char Guardar[REN_MAX][COL_MAX], int Cantidad_Palabras);

int main(void)
{
    char Frase[COL_MAX];
    char Guardar[REN_MAX][COL_MAX];
    int Cantidad_Palabras;

    Leer_Frase(Frase);
    Cantidad_Palabras = Separar_Frase(Frase, Guardar);
    Imprimir(Guardar, Cantidad_Palabras);

    return 0;
}

void Leer_Frase(char *Frase)
{
    printf("Dame una frase que contenga tres palabras: ");
    fgets(Frase, COL_MAX, stdin);
    __fpurge(stdin);
    Frase[strlen(Frase) - 1] = 0;
}

int Separar_Frase(char *Frase, char Guardar[REN_MAX][COL_MAX])
{
    int i;
    char *Token;

    i = 0;

    // Primer corte de la frase
    Token = strtok(Frase, " ");

    while (Token != NULL)
    {
        strcpy(Guardar[i], Token);
        printf("Palabra: %d\n", i+1);
        Token = strtok(NULL, " ");
        i++;
    }
    return i;
}

void Imprimir(char Guardar[REN_MAX][COL_MAX], int Cantidad_Palabras)
{
    if (Cantidad_Palabras == 3)
    {
        fputs(Guardar[0], stdout);
        printf(" ");
        puts(Guardar[2]);
    }
    else
        printf("La frase contiene más o menos palabras de las indicadas. Adios.\n");
}
