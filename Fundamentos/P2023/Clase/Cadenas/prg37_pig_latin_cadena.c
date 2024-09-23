
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

#define MAX 100
void Pedir_frase(char *Frase);
void Convierte_pig_latin(char *Frase, char *Frase_convertida);
void Imprimir_conversion(char *Frase_convertida);

int main(void)
{
    char Frase[MAX], Frase_convertida[MAX];

    Pedir_frase(Frase);
    Convierte_pig_latin(Frase, Frase_convertida);
    Imprimir_conversion(Frase_convertida);

    return 0;
}

void Pedir_frase(char *Frase)
{
    printf("Dame frase: ");
    fgets(Frase, MAX, stdin);
    Frase[strlen(Frase) - 1] = 0;
    __fpurge(stdin);
}

void Convierte_pig_latin(char *Frase, char *Frase_convertida)
{
    char Base[MAX], Comodin[MAX];
    int Bandera, Indice, i, j;
    /*
      Bandera -> Dentro va a indicar si ya encontró el cambio de consonante a voca                    l
      Indice -> la variable donde se guarda el índice donde encuentra la primera v                    ocal
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
                    printf("En el if de la consonante y bandera = 0\n");
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
                    printf("Else cuando se encuentra el cambio\n");
                }
            }
        }

        for (i = Indice; i < strlen(Frase); i++)
        {
            Base[i - Indice] = Frase[i];
            printf("valor de %d (2 for)\n", i);
        }

        Base[strlen(Frase) - Indice] = 0; // Para convertir el arreglo en cadena

        strcat(Base, Comodin);
        strcat(Base, "ay");
        strcpy(Frase_convertida, Base);
    }
}

void Imprimir_conversion(char *Frase_convertida)
{
    printf("La frase convertida es: ");
    puts(Frase_convertida);
}