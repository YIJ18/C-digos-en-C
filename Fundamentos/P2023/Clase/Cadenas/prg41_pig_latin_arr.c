
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

#define MAX 100
#define MAX_PAL 50

void Pedir_frase(char *Frase);
void Convierte_pig_latin(char *Frase, char *Frase_convertida);
int Separar_Frase(char *Frase, char Guardar[MAX_PAL][MAX]);
void Imprimir_conversion(char Frase_convertida[MAX_PAL][MAX], int Cantidad_Palabras);

int main(void)
{
    char Frase[MAX], Frase_convertida[MAX_PAL][MAX], Guardar[MAX_PAL][MAX], Palabra[MAX], Palabra_Conv[MAX];
    int Cantidad_Palabras, i;

    Pedir_frase(Frase);
    Cantidad_Palabras = Separar_Frase(Frase, Guardar);
    for (i = 0; i < Cantidad_Palabras; i++)
    {
        Convierte_pig_latin(Guardar[i], Palabra_Conv);
        strcpy(Frase_convertida[i], Palabra_Conv);
    }
    Imprimir_conversion(Frase_convertida, Cantidad_Palabras);

    return 0;
}

void Pedir_frase(char *Frase)
{
    printf("Dame frase: ");
    fgets(Frase, MAX, stdin);
    Frase[strlen(Frase) - 1] = 0;
    __fpurge(stdin);
}

int Separar_Frase(char *Frase, char Guardar[MAX_PAL][MAX])
{
    int i;
    char *Token;

    i = 0;

    // Primer corte de la frase
    Token = strtok(Frase, " ");

    while (Token != NULL)
    {
        strcpy(Guardar[i], Token);
        printf("Palabra: %d\n", i + 1);
        puts(Token);
        Token = strtok(NULL, " ");
        i++;
    }
    return i;
}

void Convierte_pig_latin(char *Frase, char *Frase_convertida)
{
    char Base[MAX], Comodin[MAX];
    int Bandera, Indice, i, j;
    /*
      Bandera -> Dentro va a indicar si ya encontró el cambio de consonante a vocal
      Indice -> la variable donde se guarda el índice donde encuentra la primera vocal
      j -> hace referencia a los índices de mi arreglo Base
      i -> contador que recorre los índices de mi cadena Frase
     */

    if (Frase[0] == 'A' || Frase[0] == 'E' || Frase[0] == 'I' || Frase[0] == 'O' || Frase[0] == 'U' || Frase[0] == 'a' || Frase[0] == 'e' || Frase[0] == 'i' || Frase[0] == 'o' || Frase[0] == 'u') // Vocales
    {
        strcpy(Frase_convertida, Frase);
        strcat(Frase_convertida, "yay");
    }
    else // Consonantes
    {
        Bandera = 0;
        for (i = 0; i < strlen(Frase); i++)
        {
            if (!(Frase[i] == 'A' || Frase[i] == 'E' || Frase[i] == 'I' || Frase[i] == 'O' || Frase[i] == 'U' || Frase[i] == 'a' || Frase[i] == 'e' || Frase[i] == 'i' || Frase[i] == 'o' || Frase[i] == 'u'))
            {
                if (Bandera == 0)
                {
                   // printf("En el if de la consonante y bandera = 0\n");
                    Comodin[i] = Frase[i];
                }
            }
            else
            {
                if (Bandera == 0)
                {
                    Bandera = 1;
                    Indice = i;
                    Comodin[Indice] = 0;
                //    printf("Else cuando se encuentra el cambio\n");
                }
            }
        }

        for (i = Indice; i < strlen(Frase); i++)
        {
            Base[i - Indice] = Frase[i];
            //printf("valor de %d (2 for)\n", i);
        }

        Base[strlen(Frase) - Indice] = 0; // Para convertir el arreglo en cadena

        strcat(Base, Comodin);
        strcat(Base, "ay");
        strcpy(Frase_convertida, Base);
    }
}

void Imprimir_conversion(char Frase_convertida[MAX_PAL][MAX], int Cantidad_Palabras)
{
    int i;
    printf("La frase convertida es de pig latin es: \n");

    for (i = 0; i < Cantidad_Palabras; i++)
    {
        puts(Frase_convertida[i]);
    }
}