/*Escriba un algoritmo que permita convertir una frase introducida en mayúsculas y minúsculas
a una frase de sólo mayúsculas y a una frase de sólo minúsculas. Por ejemplo, si el usuario
escribe: “EstO eS uNA Frase”, el programa debe devolver: “ESTO ES UNA FRASE” y “esto es una
frase”.*/

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
    desplegar(Frase);
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
        if (Frase[i] >= 'a' && Frase[i] <= 'z')
        {
            Frase[i] = Frase[i] - 32;
        }
    }
}

void desplegar(char *Frase)
{
    puts(Frase);
}