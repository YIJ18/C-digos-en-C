/*
Escriba una variante del programa anterior, en el que el programa convierta la primera letra y
la última letra de cada palabra de la frase a mayúsculas. Por ejemplo, si el usuario escribe
“Esto es una frase”, el programa debe devolver: “EstO ES UnA FrasE”.
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

void Leer(char *Frase);
void minus(char *Frase);
void mayus(char *Frase);
void desplegar(char *Frase);

int main(void)
{
    char Frase[100];
    Leer(Frase);
    minus(Frase);
    mayus(Frase);
    desplegar(Frase);
}

void Leer(char *Frase)
{
    printf("Ingresa una frase (Maximo 100 caracteres): ");
    __fpurge(stdin);
    gets(Frase);
}

void minus(char *Frase)
{
    int i, j;
    for (i = 0; i < strlen(Frase); i++)
    {
        if (Frase[i] >= 'A' && Frase[i] <= 'Z')
        {
            Frase[i] = Frase[i] + 32;
        }
    }
}

void mayus(char *Frase)
{
    int i, j;
    for (i = 0; i < strlen(Frase); i++)
    {
        if (Frase[i] == 32 && Frase[i - 1] != 32)
            if (Frase[i - 1] >= 'a' && Frase[i - 1] <= 'z')
                Frase[i - 1] = Frase[i - 1] - 32;

        if (Frase[i] == 32 && Frase[i + 1] != 32)
            if (Frase[i + 1] >= 'a' && Frase[i + 1] <= 'z')
                Frase[i + 1] = Frase[i + 1] - 32;

        if (i == 0 || i == strlen(Frase) - 1)
            Frase[i] = Frase[i] - 32;
    }
}

void desplegar(char *Frase)
{
    puts(Frase);
}