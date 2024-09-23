/*
  @file: prg16_prom.c
  @brief: Calcular el promedio de n cantidad de números dados por el usuario
  @details: Este programa calcula el promedio de la cantidad de números dados por el usuario. El programa pide al principio cuantos números quieres introducir y conforme da los números, se hace la suma acumulada (Este nos permite que el programa se adapte a la cantidad de números variables que nos da el usuario). Posteriormente, se despliega el programa.

  @author: Iris Yulit Jasso Cortes
  @date: 24-marzo-2023



DISEÑO ARQUITECTÓNICO

Diagrama IPO de alto nivel

Número (ENTRADAS) -> Calcular número de digitos (PROCESO) -> Cantidad digitos (SALIDA)



Diagrama Ipo de bajo nivel

Pedir número (PROCESO) -> (SALIDA)Número(ENTRADA) -> Calcular número de digitos(PROCESO) -> (SALIDA)CAntidad (ENTRADA) -> Imprimir resultado(PROCESO)
*/

#include <stdio.h>
#include <stdio_ext.h>

void Pedir_Num(int *Num);
int Calcular(int Num);
void Desplegar(int Num);

int main(void)
{
  int Num, Cant;
  Pedir_Num(&Num);
  Desplegar(Calcular(Num));
  return 0;
}

void Pedir_Num(int *Num)
{
  printf("Ingresa el número: ");
  scanf("%d", Num);
}

int Calcular(int Num)
{
  int i = 0, residuo, Div;
  int temp = Num;
  do
  {
    Div = temp / 10;
    temp = Div;
    i++;
  } while (Div != 0);

  return i;
}

void Desplegar(int Cant)
{
  printf("La cantida de números es : %d\n", Cant);
}
