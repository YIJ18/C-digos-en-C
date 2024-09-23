#include <stdio.h>
#include <string.h>
#define tamano 5
typedef struct
{
    char nombre[20];
    int edad;
    double estat;
    double peso;
} persona;

void leer(persona arrLec[]);
void imprimir(persona arrImp[]);

int main(void)
{

    persona listaClase[tamano];
    persona profesor;
    profesor.edad = 28;
    profesor.estat = 1.79;
    profesor.peso = 67.0;
    strcpy(profesor.nombre, "Iker");

    printf("%s", profesor.nombre);
    printf("%d", profesor.edad);
    printf("%lf", profesor.estat);
    printf("%lf", profesor.peso);

    leer(listaClase);
    imprimir(listaClase);
    return 0;
}

void leer(persona arrLec[])
{
    int i;
    for (i = 0; i < tamano; i++)
    {
        scanf("%[^\n]", arrLec[i].nombre);
        getchar();
        scanf("%lf", &arrLec[i].peso);
        scanf("%lf", &arrLec[i].estat);
        scanf("%d", &arrLec[i].edad);
    }
}

void imprimir(persona arrImp[])
{
    int i;
    for (i = 0; i < tamano; i++)
    {
        printf("%s", arrImp[i].nombre);
        printf("%lf", arrImp[i].peso);
        printf("%lf", arrImp[i].estat);
        printf("%d", arrImp[i].edad);
    }
}