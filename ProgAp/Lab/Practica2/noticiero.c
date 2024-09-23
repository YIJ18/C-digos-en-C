/*
  @file: noticiero.c
  @brief: Le da puntos a las palabras más repetidos
  @details:
  - Al momento de ejecutarlo, desde la línea de comandos se introduzca el nombre del archivo de texto donde se encuentran las noticias.(ej. ./noticias datos.txt)
  - El programa lea el archivo y genere un árbol binario de palabras donde se guarde en cada nodo la palabra y el número de veces que aparece en el archivo.
  - Después recorra el árbol e imprima las palabras en el monitor, en orden alfabético, indicando el número de veces que aparece y el tamaño de la fuente correspondiente, de acuerdo a la tabla anterior.
  @author: Iris Yulit Jasso Cortes, Ariadna Berenice Predraza Rodriguez, Daniela Mendez Ramirez.
  @date: 15-Junio-2023
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

struct nodo
{
    char nombre[100];
    int apar;
    struct nodo *izq, *der;
};

void inserta(struct nodo **raiz, char *nomb);
void borra(struct nodo *p);
void imprime(struct nodo *p);
void leer(struct nodo **raiz, char *nombreArch);
void imprimirPalabras(struct nodo *raiz);

int fuente(int num);

int main(int argc, char *argv[])
{
    struct nodo *raiz = NULL;
    char nombreArch[100];
    char nombre[100];
    int cant, i, op;

    if (argc == 2)
    {
        sscanf(argv[1], "%[^\n]", nombreArch);
        leer(&raiz, nombreArch);
        printf("\nN O T I C I E R O: \n");
        imprimirPalabras(raiz);
        borra(raiz);
    }
    else
    {
        printf("Ingresaste un numero invalido de argumentos. \n\n");
    }
}

void borra(struct nodo *p)
{
    if (p != NULL)
    {
        borra(p->izq);
        borra(p->der);
        free(p);
    }
}

void inserta(struct nodo **raiz, char *nomb)
{
    int i;
    struct nodo *posicion, *nuevo;

    posicion = *raiz;
    if ((nuevo = (struct nodo *)malloc(sizeof(struct nodo))) == NULL)
    {
        printf("No hay memoria\n");
        exit(1);
    }

    strcpy(nuevo->nombre, nomb);
    nuevo->apar = 1;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    while (posicion != NULL)
    {
        if (strcmp(nuevo->nombre, posicion->nombre) > 0)
        {
            if (posicion->der != NULL)
                posicion = posicion->der;
            else
            {
                posicion->der = nuevo;
                return;
            }
        }
        else if (strcmp(nuevo->nombre, posicion->nombre) < 0)
        {
            if (posicion->izq != NULL)
                posicion = posicion->izq;
            else
            {
                posicion->izq = nuevo;
                return;
            }
        }
        else
        {
            posicion->apar++;
            free(nuevo);
            return;
        }
    }
    posicion = nuevo;
    *raiz = posicion;
}

void leer(struct nodo **raiz, char *nombreArch)
{
    FILE *archivo;
    char nombre[100];
    int bandera = 1;

    archivo = fopen(nombreArch, "rt");
    if (archivo != NULL)
    {
        while (fscanf(archivo, "%s ", nombre) == 1)
            inserta(raiz, nombre);
        fclose(archivo);
    }
}

void imprimirPalabras(struct nodo *raiz)
{
    if (raiz != NULL)
    {
        imprimirPalabras(raiz->izq);
        printf("----------------------------------------------------------\n");
        printf("Palabra: %s\n", raiz->nombre);
        printf("Apariciones: %d\n", raiz->apar);
        printf(" Fuente: %d\n", fuente(raiz->apar));
        printf("----------------------------------------------------------\n");
        imprimirPalabras(raiz->der);
    }
    printf("\n");
}

int fuente(int num)
{
    if (num <= 5 && num > 0)
        return 8;
    else if (num <= 10 && num > 5)
        return 10;
    else if (num <= 15 && num > 10)
        return 14;
    else if (num <= 20 && num > 15)
        return 18;
    else if (num > 20)
        return 24;
}
