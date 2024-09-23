/*

@file: examen2.c / ejecutable examen2
@brief: REducción de resistencias en paralelo
@details: El programa debe de solicitar al usuario la cantidad de resistencias en paralelo que tiene conectadas (n). Si  el  usuario  introduce  una  cantidad  negativa,  el  programa  debe  de  desplegar  un  mensaje  de  error  y  terminar.

@author: Iris Yulit Jasso Cortes
@date: 30-Marzo-2023

Diagrama IPO alto nivel
Valor de resistencia (Res), Cantidad de resistencias (Cant) (ENTRADA) -> Calculo de resistencia (PROCESO)-> Suma (SALIDA)

Diagrama IPO bajo nivel
Pedir Cantidad de resistencias (PROCESO) -> (SALIDA) Cantidad(Cant)(ENTRADA) -> Pedir resistencia (PROCESO) -> (SALIDA) Valor de resistencia (Res)(ENTRADA) -> Validar caracter(PROCESO) -> Calculo de resistencia (PROCESO)-> Suma (SALIDA)
Función main(void)
{
    int Cant, Res, Suma = 0, i = 1, Resultado;
    float Suma_ac;

        Solicitar_Cant(&Cant);

        Solicitar_Res(i, &Res);


            Calcular(i, Res, &Suma_ac);

    Resultado = Calcular(i, Res, &Suma_ac);

    return 0;
}

Función Solicitar_Cant(int *Cant)
{

}

Función Solicitar_Res(int i, int *Res)
{

}

Función Calcular(int i, int Res, float *Suma_ac)
{

    return Suma;
}

Función Desplegar(int Res)
{
}
*/

#include <stdio.h>
#include <stdio_ext.h>

void Solicitar_Cant(int *Cant);
void Solicitar_Res(int i, int *Res);
float Calcular(int Res, float *Suma_ac);
void Desplegar(float Resultado);

int main(void)
{
    int Cant, Res, Suma = 0, i = 1;
    float Suma_ac = 0, Resultado = 0;
    printf("Este  programa  calcula  la  resistencia  equivalente  (Re)  de  un  circuito  de  n  resistencias conectadas en paralelo. \n");
    do
    {
        Solicitar_Cant(&Cant);
    } while (Cant <= 0);
    printf("Dame, en ohms, los valores de las resistencias: \n");
    do
    {
        Solicitar_Res(i, &Res);
        if (Res <= 0)
        {
            printf("No me puedes dar resistencias negativas o cero. Intenta otra vez.");
            i--;
        }
        else
            Calcular(Res, &Suma_ac);
        i++;
    } while (Cant >= i || Res <= 0);

    Resultado = Calcular(Res,& Suma_ac)/1;
    Desplegar(Resultado);
    return 0;
}

void Solicitar_Cant(int *Cant)
{
    printf("Dime cuántas resistencias conectadas en paralelo tienes: ");
    scanf("%d", Cant);
    __fpurge(stdin);
}

void Solicitar_Res(int i, int *Res)
{
    printf("\nR%d = ", i);
    scanf("%d", Res);
    __fpurge(stdin);
}

float Calcular (int Res, float *Suma_ac)
{
 
    return *Suma_ac =  *Suma_ac+ 1/(float)Res ;
}

void Desplegar(float Resultado)
{
    printf("La Re de tu circuito es de %f ohms.\n", Resultado);
}