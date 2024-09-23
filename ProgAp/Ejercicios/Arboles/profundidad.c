#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct def_inventario
{
    // comida
    int jamon;
    int leche;
    int queso;
    int cereal;
    int tostadas;
    // electronicos
    int tv;
    int tabletas;
    int telefono;
    int opamps;
    // hogar limp
    int papel;
    int jabon;
    int fabuloso;
    int escoba;
} tipoinv;

typedef struct def_arbol
{
    char nombre[100];
    int codigo;
    float precio;
    tipoinv iventario;
    struct def_arbol *izq, *der;
} tipoArbol;

int main(char argc, char **argv)
{
    char nombreArch[100];
    sscanf(argv[1], "%s", nombreArch);
}