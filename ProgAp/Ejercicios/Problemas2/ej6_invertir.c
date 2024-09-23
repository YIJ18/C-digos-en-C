/*
Escriba un programa que pueda invertir el orden de las palabras de una frase. El programa
debe solicitar la frase que será procesada. Por ejemplo, si el usuario introduce “esto es una
frase”, el programa debe devolver “frase una es esto”
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

void Ingresa(char *Frase);
void Inviertes(char *Frase, char *Frase2);
void Desplegar(char *Frase2);

int main(void)
{
    char Frase[200], Frase2[200];
    Ingresa(Frase);
    Inviertes(Frase, Frase2);
    Desplegar(Frase2);
    return 0;
}

void Ingresa(char *Frase)
{
    printf("Ingresa una frase (Maximo 200 caracteres): ");
    __fpurge(stdin);
    gets(Frase);
}

void Inviertes(char *Frase, char *Frase2)
{
    int i, j = 0, k = 0, tamano = 0;
    char temp;
    for (i = strlen(Frase) - 1; i >= 0; i--)
    {
        Frase2[k] = Frase[i];
        k++;
    }
    Frase2[k] = '\0';
    for (i = 0; i < strlen(Frase); i++)
    {
        if (Frase2[i] == 32)
        {
            tamano = i - 1;
            while (j < tamano)
            {
                temp = Frase2[j];
                Frase2[j] = Frase2[tamano];
                Frase2[tamano] = temp;
                j++;
                tamano--;
            }
            j = i + 1;
        }
    }
    tamano = strlen(Frase) - 1;
    while (j < tamano)
    {
        temp = Frase2[j];
        Frase2[j] = Frase2[tamano];
        Frase2[tamano] = temp;
        j++;
        tamano--;
    }

    puts(Frase);
}

void Desplegar(char *Frase2)
{
    printf("La oración invertida es: ");
    puts(Frase2);
}