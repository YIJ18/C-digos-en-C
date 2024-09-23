/*

@file: preg_2.c
@brief: Vamos a calcular la suma acumulada de los multipls de 3, desde el 3 hasta el 120
@details: Este programa explica el funcionamiento de una suma acumulativa, dentro de un for, junto con el uso de del residuo.
@author: Iris Yulit Jasso Cortes
@date: 16-febrero-2023

******************************
DISEÑO ARQUITECTÓNICO

Alto nivel

(ENTRADAS) -> Calcular la suma acumulada de la serie(PROCESO) -> suma (SALIDAS)

Bajo nivel

Calcular la suma acumulada de la serie(PROCESO)  -> (SALIDAS) Suma (ENTRADAS) -> Imprimir  resultado (PROCESO)


******************************
DISEÑO DETALLADO(PSEUDOCÓDIGO)

FUNCIÓN PRINCIPAL(|) // int main (void)
INICIO

    //Llamadas a las funciones
    Calcular_Num(|)

FIN//}




Función Calcular_Num(|)
INICIO
int par;

 for (int i=0; i != 0; i++){
    par = i % 3;
    if (par == 0){
        printf("%d, ", i);
    }
 }
FIN

*/

#include <stdio.h>

void Calcular_Num(int *Res);
void Imprimir_Suma(int Res);

int main(void)
{
    int Res;
    Calcular_Num(&Res);
    Imprimir_Suma(Res);
    return 0;
}

void Calcular_Num(int *Res)
{

    int Par, Suma, y, j = 0;

    for (int i = 1; i < 121; i++)
    {
        Par = i % 3;
        if (Par == 0)
        {
            y = i;
            Suma = j + y;
            y = j;
            j = Suma;
        }
    }
    *Res = Suma;
}

void Imprimir_Suma(int Res)
{
    printf("La suma acumulada es: %d \n", Res);
}