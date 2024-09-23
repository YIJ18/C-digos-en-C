/*
  @file: prg43_inv_frase.c
  @brief: Determinar si este programa es palindromo o no
  @details: Este rpograma determina si una frase dada por el palindrmo dada por el usuarioal quitar os espaciós e invertir con una función de recursión.

  @author: Iris Yulit Jasso Cortes
  @date: 02-Mayo-2023
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

#define MAX 100

void Leer_Frase(char *Frase);
void Eliminar_espacios(char *Frase, char *Frase_sin_espacios);
void Invertir_Frase(char *Frase_sin_espacios, char *Frase2, int i);

int main(void)
{
    char Frase[MAX], Frase_sin_espacios[MAX], Frase2[MAX];
    int i = 0;
    Leer_Frase(Frase);
    Eliminar_espacios(Frase, Frase_sin_espacios);
    Invertir_Frase(Frase_sin_espacios, Frase2, i);
    return 0;
}

void Leer_Frase(char *Frase)
{
    printf("Dame la frase a evaluar: ");
    fgets(Frase, MAX, stdin);
    __fpurge(stdin);
    Frase[strlen(Frase) - 1] = 0;
}

void Eliminar_espacios(char *Frase, char *Frase_sin_espacios)
{
    char *Token;

    // Primer corte de la frase
    Token = strtok(Frase, " ");
    
    while (Token != NULL)
    {
        strcat(Frase_sin_espacios, Token);
        Token = strtok(NULL, " ");
    }
    printf("Frase sin espacios: ");
    puts(Frase_sin_espacios);
}

void Invertir_Frase(char *Frase_sin_espacios, char *Frase2, int i)
{
    if (Frase_sin_espacios[i]!=0)
    {
        Invertir_Frase(Frase_sin_espacios, Frase2, i + 1);
        getchar();
        __fpurge(stdin);
        Frase2[(strlen(Frase_sin_espacios)-i)] = Frase_sin_espacios[i];
    }
}