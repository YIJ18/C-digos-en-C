/*
  @file: prg10_calif_num.c
  @brief: Calcular el equivalente de una calificación númerica a letra
  @details: En este programa se hace ñla demostración de los IF-THEM anidados para calcular el equivalentende de una califciacion númer

  @author: Iris Yulit Jasso Cortes
  @date: 17-febrero-2023

Diagrama IPO de alto nivel
  Calis (ENTRADAS) -> Validar equivalencia (PROCESO)

Diagrama IPO de bajo nivel
    Pedir Calificación (PROCESO) -> (ENTRADA) Validar (SALIDA)
*/

#include <stdio.h>

void Pedir_Calificacion(int *Calif);
void Validar_Calificacion(int Calif);

int main(void)
{
    int Calificacion;
    Pedir_Calificacion(&Calificacion);
    Validar_Calificacion(Calificacion);
    return 0;
}

void Pedir_Calificacion(int *Calif)
{
    printf("Dame cálificación númerica (0 y 100)");
    scanf("%d", Calif);
}

void Validar_Calificacion(int Calif)
{
    if (Calif<101)
    {
        if (Calif>=0)
        {
            if(Calif>92)
             printf("La calificación en letra es A.\n");
            else
            {
                if(Calif>79)
                    printf("La calificación en letra es B.\n");

                    if(Calif<80){
                        if(Calif>69)
                        printf("La calificación en letra es C.\n");
                        else
                        printf("La calificación en letra es D.\n");
                    }
            }
        }
        else
            printf("La calificación dada sale del rango. Adios\n");
}
    
    else 
        printf("La calificación dada sale del rango. Adios\n");
}