/*
@file: examen3.c
@brief:
@details: Diseña y escribe un programa que solicite al usuario el listado de materias que has llevado hasta ahora en tu carrera (mínimo de materias que llevas/llevaste en primer semestre y máximo 30 materias), los cuales se irán guardando en un arreglo de cadenas. La longitud máxima del nombre de una materia es de 30 caracteres. Posteriormente, en dos arreglos bidimensional que contienen 2 columnas debes de guardar los siguientes datos (un arreglo es de tipo char y el otro de tipo int):
1) En la columna 1 (“Longitud del nombre” se debe de guardar la longitud del nombre.

2) En la columna (“Tipo de calificación”) se debe de indicar si la calificación es numérica (valor cero) o una categoría como “Aprobado” (valor uno).

3) En la columna (“Semestre”) se debe de indicar el número del semestre en que se llevó (ej. 2).

4) En la columna (“Cantidad de vocales”) se debe de indicar cuantas vocales tiene el nombre.

@author: Iris Yulit Jasso Cortes
@date: 11-Mayo-2023

Diagrama IPO Bajo nivel
Pedir Datos (PROCESO) -> (SALIDAS)cadenas(ENTRADAS) -> Contar tamaño de nombre, vocales, consonantes de cada nombre(PROCESO)


Diagrama IPO Alto nivel
Pedir Datos (PROCESO) -> (SALIDAS)cadenas(ENTRADAS) -> Contar tamaño de nombre, vocales, consonantes de cada nombre(PROCESO)->(SALIDAS) tamaño, consonantes, vocales (ENTRADAS)->Desplegar resultados
*/

/*Función que valida la cantidad de nombres a ingresar (1 punto)

· Función que solicita y guarda los nombres en un arreglo de cadenas (1 punto)

· Función de tipo long que regresa el tamaño del nombre o función con parámetro de salida (1 punto)

· Función que valida las vocales o consonantes del inicio y fin de cada nombre (2 puntos).

· Función que cuenta la cantidad de vocales de cada nombre (1 punto).

· Desplegar resultados correctamente con base
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

int numero_materias();
void Pedir_nombres(int n, char Listado[30][30], int longitud_calif[2][30], int semestre_voc[2][30]);
void LeeCad(char *Cadena, int Longitud);
void Imprimir_nombres(int n, char Listado[30][30]);
void validar_nombres(int semestre_voc[2][30], int i);
int tamano_nombre(char materia[30][30], int n);
void cantidad_vocales(char materia[30][30], int n, int semestre_voc[2][30]);
void decir_semestres(int n, int semestre_voc[2][30]);
void tipo_calif(int longitud_calif[2][30]);
void desplegar_resultados();

int main(void)
{
    int longitud_calif[2][30], semestre_voc[2][30];
    char materia[30][30];
    int numero, semestre;
    int i, longitud, tamanio;
    numero = numero_materias();
    Pedir_nombres(numero, materia, longitud_calif, semestre_voc);
    decir_semestres(numero, semestre_voc);
    cantidad_vocales(materia, numero, semestre_voc);
    Imprimir_nombres(numero, materia);
    return 0;
}

void cantidad_vocales(char materia[30][30], int n, int semestre_voc[2][30])
{
    int i, j;
    int Contador_vocal;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < strlen(materia[i]); j++)
        {
            if (materia[i][j] == 'a' || materia[i][j] == 'A' || materia[i][j] == 'e' || materia[i][j] == 'E' || materia[i][j] == 'i' || materia[i][j] == 'I' || materia[i][j] == 'o' || materia[i][j] == 'O' || materia[i][j] == 'u' || materia[i][j] == 'U')
            {
                Contador_vocal++;
            }
        }
        semestre_voc[1][i] = Contador_vocal;
    }
}

/*Función para el número de materias a ingresar*/
int numero_materias()
{
    int numero;
    do
    {
        printf("Ingresa el número de materias: ");
        scanf("%d", &numero);
        if (numero < 6 || numero > 30)
        {
            printf("No ingresaste una cantidad válida de materias, el rango esta entre (6 y 30)\n");
            printf("Intentalo nuevamente\n");
        }
    } while (numero < 6 || numero > 30);

    return numero;
}

//-----------------------------------------------------------------------------
/*Se definen las funciones parar solicitar y guardar los números a ordenar*/

void Pedir_nombres(int n, char Listado[30][30], int longitud_calif[2][30], int semestre_voc[2][30])
{
    int i; // Este contador va a hacer referencia a los renglones de mi arreglo bidimensional y va a recorrer hasta n-1 (cantidad de nombres que me va a dar el usuario)

    printf("La cantidad de nombres a guardar es: %d\n", n);

    for (i = 0; i < n; i++)
    {
        printf("Dame el nombre %d: ", i + 1);
        __fpurge(stdin);
        LeeCad(Listado[i], 30);
        __fpurge(stdin);
        longitud_calif[0][i] = tamano_nombre(Listado, i);
        __fpurge(stdin);
    }
}
void decir_semestres(int n, int semestre_voc[2][30])
{
    int semestre, i, j = 1;
    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Dime en que semestre la estas tomando la  materia %d", j);
            scanf("%d", &semestre);
            __fpurge(stdin);
        } while (semestre < 0);

        semestre_voc[0][i] = semestre;
        getchar();
        j++;
    }
}
void LeeCad(char *Cadena, int Longitud)
{
    fgets(Cadena, Longitud, stdin);
    Cadena[strlen(Cadena) - 1] = 0;
    __fpurge(stdin);
}

//----------------------------------------------------------------------------

void Imprimir_nombres(int n, char Listado[30][30])
{
    int i;

    printf("Los nombres ordenados son:\n");
    for (i = 0; i < n; i++)
        puts(Listado[i]);
}
/*-----------------------------------------------*/
int tamano_nombre(char Listado[30][30], int n)
{
    return strlen(Listado[n]);
}
