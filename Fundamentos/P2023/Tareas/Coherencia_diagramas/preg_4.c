/*

@file: preg_4.c
@brief: Calcularemos el dia siguiente de la fecha qu el usuario introduce
@details: En este programa lograremos identificar y prácticar los if anidados
@author: Iris Yulit Jasso Cortes
@date: 16-febrero-2023

******************************
DISEÑO ARQUITECTÓNICO

Alto nivel
Dia, Mes, Anio (ENTRADAS) -> Calcular el dia siguiente(PROCESO) -> Dia_Sig, Mes_Sig, Anio_Sig (SALIDAS)

Bajo nivel

Pedir Fecha(PROCESO)  -> (SALIDAS) Dia, Mes, Anio (ENTRADAS) ->  Calcular el dia siguiente (PROCESOS) -> (SALIDAS) Dia_Sig, Mes_Sig, Anio_Sig (ENTRADAS) -> Imprimir  resultado (PROCESO)


******************************
DISEÑO DETALLADO(PSEUDOCÓDIGO)

FUNCIÓN PRINCIPAL(|) // int main (void)
INICIO

    int Dia, Mes, Anio, Dia_Sig, Mes_Sig, Anio_Sig;

    //Llamadas a las funciones
    Pedir_Fecha(| &Dia, &Mes, &Anio)
    Calcular_Fecha( Dia, Mes, Anio| &Dia_Sig, &Mes_Sig, &Anio_Sig)
    Desplegar_Fecha( Dia_Sig, Mes_Sig, Anio_Sig |)

FIN//}

 Pedir_Pot_Num (| *Dia, *Mes, *Anio)
INICIO
  printf("Dame el dia");
  scanf("%d", Dia);
  printf("Dame el Mes");
  scanf("%d", Mes);
  printf("Dame el Año");
  scanf("%d", Anio);
FIN


Función Calcular_Fecha(int Dia, int Mes, int Anio |  int *Dia_Sig, int *Mes_Sig, int *Anio_Sig)
INICIO
 if(Dia > 31)
 {
    printf("Ingresa un dia valido");
 }
 if(Mes > 12)
 {
    printf("Ingresa un Mes valido");
 }

 if(Dia == 31){
    *Dia_Sig = 1;
    if(Mes < 12)
    {
        *Mes_Sig = Mes + 1;
    }

    if(Mes == 12)
    {
        *Mes_Sig = 1;
        *Anio_Sig = Anio + 1;
    }
 }
if(Dia < 31){
    *Dia_Sig = Dia + 1;
    *Mes_Sig = Mes;
    *Anio_Sig = Anio;
}
FIN

Función Desplegar_Fecha(int Dia_Sig, int Mes_Sig, int Anio_Sig |)
INICIO//{
 printf("El dia sigiente es: %d / %d / %d", Dia_Sig, Mes_Sig, Anio_Sig);
FIN//}*/

#include<stdio.h>

void Pedir_Fecha(int *Dia, int *Mes, int *Anio);
void Calcular_Fecha(int Dia,int Mes,int Anio, int *Dia_Sig, int *Mes_Sig, int *Anio_Sig);
void Desplegar_Fecha(int Dia_Sig, int Mes_Sig, int Anio_Sig);

int main(void)
{
    int Dia, Mes, Anio, Dia_Sig, Mes_Sig, Anio_Sig;
    Pedir_Fecha(&Dia, &Mes, &Anio);
    Calcular_Fecha(Dia, Mes, Anio, &Dia_Sig, &Mes_Sig, &Anio_Sig);
    Desplegar_Fecha(Dia_Sig, Mes_Sig, Anio_Sig);
}

void Pedir_Fecha(int *Dia, int *Mes, int *Anio)
{
    printf("Dame el dia");
    scanf("%d", Dia);
    printf("Dame el Mes");
    scanf("%d", Mes);
    printf("Dame el Año");
    scanf("%d", Anio);
}

void Calcular_Fecha(int Dia, int Mes, int Anio, int *Dia_Sig, int *Mes_Sig, int *Anio_Sig)
{

    if (Dia > 31 || Dia < 0)
        printf("Ingresa un dia valido");
    if (Mes > 12 || Mes < 0)
        printf("Ingresa un mes valido");
    if (Anio < 1)
        printf("Ingresa un año valido");    

    if (Dia == 31)
    {
        *Dia_Sig = 1;
        if (Mes < 12)
        {
            *Mes_Sig = Mes + 1;
        }

        if (Mes == 12)
        {
            *Mes_Sig = 1;
            *Anio_Sig = Anio + 1;
        }
    }

    if (Dia < 31)
    {
        *Dia_Sig = Dia + 1;
        *Mes_Sig = Mes;
        *Anio_Sig = Anio;
    }
}

void Desplegar_Fecha(int Dia_Sig, int Mes_Sig, int Anio_Sig)
{
    printf("El dia sigiente es: %d / %d / %d \n", Dia_Sig, Mes_Sig, Anio_Sig);
}