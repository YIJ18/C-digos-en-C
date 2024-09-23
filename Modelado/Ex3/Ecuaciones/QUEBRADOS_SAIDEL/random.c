/*
  @file: quebrados.c
  @brief: Hace la suma, resta, multiplicación y división de fracciones.
  @details: Definiremos los numeradores y denominadores dentro de la estructura.
  1. El programa hará la suma, resta, multiplicación y división de fracciones.
  2. La fracción se reducirá hasta su mínima expresión.
  3. El resultado será impreso.

  @author: Iris Yulit Jasso Cortes
  @date: 15-agosto-2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct def_quebrados
{
    int denominador, numerador;
    struct def_quebrados *sig;
} tipoQuebrados;

void rellenar_no_dinamico(tipoQuebrados quebrados[100]);
void rellenar_dinamico(tipoQuebrados **inicio);
void Borra(tipoQuebrados **inicio);

int main(void)
{
    tipoQuebrados quebrados[100], *inicio = NULL;
    double tiempo_total;
    clock_t segundo_inicial, segundo_final;

    time(&tiempo);
    segundo_inicial = clock();
    rellenar_dinamico(&inicio);
    segundo_final = clock();
    tiempo_total = ((double)(fin_clock - inicio_clock) * 1000.0) / CLOCKS_PER_SEC;
    printf("Me tarde %f ms en el  dinamico\n", tiempo_total);

    /* time(&tiempo);
     segundo_inicial = tiempo % 60;
     rellenar_no_dinamico(quebrados);

     time(&tiempo);
     segundo_final = tiempo % 60;
     printf("Me tarde %d ms en el no dinamico\n", segundo_final - segundo_inicial);
 */
    Borra(&inicio);
    return 0;
}

void rellenar_dinamico(tipoQuebrados **inicio)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < 1000000; i++)
    {
        tipoQuebrados *temp = (tipoQuebrados *)malloc(sizeof(tipoQuebrados) * 100);
        temp->numerador = rand() % 100;
        temp->denominador = rand() % 100;
        temp->sig = *inicio;
        *inicio = temp;
    }
}

void rellenar_no_dinamico(tipoQuebrados quebrados[100])
{
    int i;
    srand(time(NULL));
    for (i = 0; i < 100; i++)
    {
        quebrados[i].numerador = rand() % 100;
        quebrados[i].denominador = rand() % 100;
    }
}

void Borra(tipoQuebrados **inicio)
{
    tipoQuebrados *temp;
    while (*inicio != NULL)
    {
        temp = *inicio;
        *inicio = (*inicio)->sig;
        free(temp);
    }
}
