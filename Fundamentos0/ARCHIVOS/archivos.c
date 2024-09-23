#include <stdio.h>
#include <string.h>

void contarcaracteres(char texto[], int *numconespacios, int *numsinespacios);
void espacio(char texto[], char arr2[]);

int main(void)
{
    char texto[1000];
    int numcon, numsin;
    printf("Ingresa la cedna: ");
    scanf("%[^\n]", texto);
    contarcaracteres(texto, &numcon, &numsin);
    printf("%d, %d", numcon, numsin);
    return 0;
}

void contarcaracteres(char texto[], int *numconespacios, int *numsinespacios)
{
    char arr2[1000];
    *numconespacios = strlen(texto);
    espacio(texto, arr2);
    *numsinespacios = strlen(arr2);
}

void espacio(char texto[], char arr2[])
{
    int i = 0, j = 0;
    while (texto[i] != '\0')
    {
        if (texto[i] != ' ')
        {
            arr2[j] = texto[i];
            j++;
        }
        i++;
    }
}