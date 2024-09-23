/*

  @file: preg_1.c
  @brief: Para aprender a usar la libreria math.h y poder usar una de sus funciones
  @details: Este programa explica el funcionamiento de una nueva sentencia, llamada pow.
  @author: Iris Yulit Jasso Cortes
  @date: 16-febrero-2023

******************************
DISEÑO ARQUITECTÓNICO

Alto nivel

Num ,Base (ENTRADAS) -> Calcular la potencia de un número(PROCESO) -> Potencia (SALIDAS)

Bajo nivel

Pedir número y base (PROCESO)  -> (SALIDAS) Num ,Base (ENTRADAS) ->  Calcular la potencia de un número (PROCESOS) -> (SALIDAS) POtencia (ENTRADAS) -> Imprimir  resultado (PROCESO)


******************************
DISEÑO DETALLADO(PSEUDOCÓDIGO)

FUNCIÓN PRINCIPAL(|) // int main (void)
INICIO

    int Pot, Num, Res;

    //Llamadas a las funciones
    Pedir_Pot_Num (| &Pot, &Num);
    Calcular_Pot( Pot,  Num | &Res);
    Desplegar_Pot( Res |);

FIN//}

 Pedir_Pot_Num (| int *Pot, int *Num)
INICIO
  printf("Dame Potencia");
  scanf("%d",Pot);
  printf("Dame número a elevar");
  scanf("%d", Num);
FIN


Función Calcular_pot(int Num, int Pot | int *Res)
INICIO
 *Res= pow(Num, Pot);
FIN

Función Desplegar_Pot(int Res |)
INICIO//{
 printf("El resultado de la potencia calculada es: %d", Res);
FIN//}*/

#include <stdio.h>
#include <math.h>

void Pedir_Pot_Num(int *Pot, int *Num);
void Calcular_Pot(int Pot, int Num, int *Res);
void Desplegar_Pot(int Res);

int main(void)
{
  int Pot, Num, Res;
  Pedir_Pot_Num(&Pot, &Num);
  Calcular_Pot(Pot, Num, &Res);
  Desplegar_Pot(Res);
  return 0;
}

void Pedir_Pot_Num(int *Pot, int *Num)
{
  printf("Dame el número a elevar: ");
  scanf("%d", Num);
  printf("Dame la potencia: ");
  scanf("%d", Pot);
}

void Calcular_Pot(int Pot, int Num, int *Res)
{
  *Res = pow(Num, Pot);
}

void Desplegar_Pot(int Res)
{
  printf("El número calculado es: %d", Res);
}
