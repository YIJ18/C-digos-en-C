/*
Escriba un programa que solicite una frase de tres palabras. El programa debe ser capaz de
quitar la palabra de en medio, sin importar si entre cada palabra existen uno o más espacios.
Por ejemplo, si el usuario introduce:
”Esto me gusta”,
el programa debe responder:
”Esto gusta”
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

void Leer(char *Frase);
void Responder(char *Frase);

int main(void)
{
    char Frase[100];
    Leer(Frase);
    Responder(Frase);
    return 0;
}

void Leer(char *Frase)
{
    printf("Ingresa una frase (Maximo 100 caracteres): ");
    __fpurge(stdin);
    gets(Frase);
}

void Responder(char *Frase)
{
    int espacios = 0, i, j;

    for (i = 0; i < strlen(Frase); i++)
    {
        if (Frase[i] == 32 && Frase[i - 1] != 32)
            espacios++;
        if (espacios != 1)
            printf("%c", Frase[i]);
    }
    printf("\n");
}