#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

typedef struct def_dato
{
    int dato;
    struct def_dato *sig;
    struct def_dato *ant;
} tipodato;

void IngresarInicio(tipodato **Inicio, int valor);
void IngresarFin(tipodato **Inicio, int valor);
void IngresarMedio(tipodato **Inicio, int valor);
void Mostrar(tipodato *Inicio);
void Borra(tipodato **Inicio);

int main(void)
{
    tipodato *Inicio = NULL;
    int valor;
    printf("Introduce nums enteros, letra para terminar: \n");
    while (scanf("%d", &valor) == 1)
        IngresarMedio(&Inicio, valor);
    printf("Los números son: \n");
    Mostrar(Inicio);
    Borra(&Inicio);
}

void IngresarInicio(tipodato **Inicio, int valor)
{
    tipodato *temp;
    temp = (tipodato *)malloc(sizeof(tipodato));
    temp->dato = valor;
    temp->ant = NULL;
    temp->sig = *Inicio;
    if (*Inicio != NULL)
        (*Inicio)->ant = temp;
    *Inicio = temp;
}

void IngresarFin(tipodato **Inicio, int valor)
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
        temp->ant = temp2;
    }
    else
    {
        temp->ant = NULL;
        *Inicio = temp;
    }
}

void IngresarMedio(tipodato **Inicio, int valor)
{
    tipodato *dato, *temp;
    dato = (tipodato *)malloc(sizeof(tipodato));
    dato->dato = valor;
    if (NULL == *Inicio)
        IngresarInicio(Inicio, valor);
    else
    {
        temp = *Inicio;
        if ((*Inicio)->dato > dato->dato)
            IngresarInicio(Inicio, valor);
        else
        {
            while (temp->sig != NULL && valor > temp->dato)
                temp = temp->sig;

            dato->sig = temp;
            dato->ant = temp->ant;
            temp->ant = dato;

            if (dato->ant != NULL)
                dato->ant->sig = dato;
            else
                *Inicio = dato;
        }
    }
}

void Mostrar(tipodato *Inicio)
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