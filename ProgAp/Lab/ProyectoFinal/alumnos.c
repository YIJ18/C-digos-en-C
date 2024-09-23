/**
 * @file alumnos.c
 *
 * @brief Este programa permite
 *
 * @author Daniela Mendez Ramirez
 * @author Iris Yulit Jasso Cortes
 * @author Ariadna
 * @date 22/06/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos las estructuras para la estructura alumnos

typedef struct def_name
{
  char nombre[100], ap_Pat[100], ap_Mat[100];
} tiponombre;

typedef struct def_fecha
{
  int dia, mes, anio;
} tipofecha;

typedef struct def_direccion
{
  char calle[100], ciudad[100];
  int cp;
} tipodireccion;

typedef struct def_alumnos
{
  tiponombre nombre;
  int telefono;
  char sexo[100];
  tipofecha cumple;
  int edad; // Se calcula, no se pregunta
  char numCuenta[100];
  char estatus[100];
} tipoalumnos;

// Estructura para Historial Academico
typedef struct def_HistAcad
{
  int clave;
  char nombreMat[100];
  double cal;
  struct def_HistAcad *sig2;
} tipoacademico;

// Estructura Principal
typedef struct def_escuela
{
  tipoalumnos alumnos;
  tipoacademico *academico;

  struct def_escuela *sig;
} tipoescuela;

/******************** Inicio ****************************/
int main()
{

  tipoescuela *inicio = NULL;
  tipoescuela *alumno;
  tipoacademico *academico;
}
/********************   fin   ***************************/

// Pedir Datos