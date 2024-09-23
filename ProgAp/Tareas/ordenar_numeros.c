#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

typedef struct def_dato
{
    int dato;
    struct def_dato *sig;
} tipodato;

void InsertaInicio(tipodato **Inicio, int valor);
void Insertafin(tipodato **Inicio, int valor);
void Medio(tipodato **Inicio, int valor);
void Imprime(tipodato *Inicio);
void Borra(tipodato **Inicio);

int main(void)
{
    tipodato *primero = NULL;
    int numero;
    printf("Introduce nums enteros, letra para terminar: \n");
    while (scanf("%d", &numero) == 1)
        Medio(&primero, numero);
    printf("Los nùmeros introducidos son: \n");
    Imprime(primero);
    Borra(&primero);
    return 0;
}

void InsertaInicio(tipodato **Inicio, int valor)
{
    tipodato *temp;
    temp = (tipodato *)malloc(sizeof(tipodato));
    temp->dato = valor;
    temp->sig = *Inicio;
    *Inicio = temp;
}

void Insertafin(tipodato **Inicio, int valor)
{
    tipodato *temp, *temp2;
    temp = (tipodato *)malloc(sizeof(tipodato));
    temp->dato = valor;
    temp->sig = NULL;
    if (*Inicio != NULL)
    {
        temp2 = *Inicio;
        while (temp2->sig != NULL)
            temp2 = temp2->sig;
        temp2->sig = temp;
    }
    else
        *Inicio = temp;
}

void Imprime(tipodato *Inicio)
{
    tipodato *temp;
    temp = Inicio;
    while (temp != NULL)
    {
        printf("%d\n", temp->dato);
        temp = temp->sig;
    }
}

void Borra(tipodato **Inicio)
{
    tipodato *temp;
    while (*Inicio != NULL)
    {
        temp = *Inicio;
        *Inicio = (*Inicio)->sig;
        free(temp);
    }
}

void Medio(tipodato **Inicio, int valor)
{
    tipodato *temp, *pos, *ant;
    if (*Inicio == NULL || valor < (*Inicio)->dato)
        InsertaInicio(Inicio, valor);
    else
    {
        pos = *Inicio;
        while (pos != NULL && pos->dato < valor)
            pos = pos->sig;
        if (pos == NULL)
            Insertafin(Inicio, valor);
        else
        {
            temp = (tipodato *)malloc(sizeof(tipodato));
            temp->dato = valor;
            temp->sig = pos;
            ant = *Inicio;
            while (ant->sig != pos)
                ant = ant->sig;
            ant->sig = temp;
        }
    }
}
