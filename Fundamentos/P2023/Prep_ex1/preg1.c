/*
  @file: preg_1.c
  @brief: Potencia de un programa de un número entero
  @details: Este programa calcula la potencia de una base y de un exponente dado pór el usuario
  @author: Iris Yulit Jasso Cortes
  @date: 28-febrero-2023

**************************************************************************************
ESPECIFICACIÓN DE REQUERIMIENTOS

Descripción general:

Este programa calcula la potencia de la base y exponenre dados por el usuario. El programa solicita la base como el exponente.

Este programa esta diseñado para que lo utilizen las maestras de 2do grado de primaria. Se utiliza la funcion pow para calcular dicha potencia. Ambos números tienen que ser tipo double (son enteros grandes).
En caso de que la base o el exponente son negativos, el programa despliega un mensaje de error y termina su ejecución.

Entradas

Base y exponente

Salida

La potencia calculada

Procesos
1)Pedir base y exponente
2) Calcular potencia
3) Desplegar potencia

Limitaciones  y Alcances
Este programa calcula la potencia de dos números enteros. Si el usuario intrduce la base y/o exponente negativos, el programa imprime un mesaje de error y termina el programa.

Diseño de pantalla

Diagrama IPO de alto nivel

Pedir datos(PROCESO) -> (SALIDAS) Base, exponente (ENTRADAS) -> Calcular potencia(PROCESO) -> (SALIDAS)Potencia(ENTRADAS -> Impeimir resultado(PROCESO)

DISEÑO DETALLADO

int main(void)
{
  double Base, Exponente, Potencia;
  Pedir_Datos(&Base, &Exponente);
  Calcular_potencia( Base,  Exponente,  &Potencia);
  Imprimir_resultado( Potencia);
}

Función Pedir_Datos(double *Base, double *Exponente)
{

}
Función Calcular_potencia(double Base, double Exponente, double *Potencia)
{

}
Función Imprimir_resultado(double Potencia)
{

}
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <math.h>

void Pedir_Datos(double *Base, double *Exponente);
void Calcular_potencia(double Base, double Exponente, double *Potencia);
void Imprimir_resultado(double Potencia);

int main(void)
{
  double Base, Exponente, Potencia;
  Pedir_Datos(&Base, &Exponente);
  if(Base>0 && Exponente>0)
  {
  Calcular_potencia(Base, Exponente, &Potencia);
  Imprimir_resultado(Potencia);
  }

  if(Base<=0)
    printf("La base es cero o negativo\n");
  if(Exponente<0)
    printf("La base es negativo\n");


  return 0;
}

void Pedir_Datos(double *Base, double *Exponente)
{
  printf("Dame base: ");
  scanf("%lf", Base);
  __fpurge(stdin);

  printf("\nDame exponente: ");
  scanf("%lf", Exponente);
  __fpurge(stdin);
}

void Calcular_potencia(double Base, double Exponente, double *Potencia)
{
  *Potencia = pow(Base, Exponente);
}

void Imprimir_resultado(double Potencia)
{
  printf("El resulado de la potencia es %.2lf", Potencia);
}