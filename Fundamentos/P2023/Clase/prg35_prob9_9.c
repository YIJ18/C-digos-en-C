#include <stdio.h>
#include <stdio_ext.h>
void Pedir_num(int *Num);
void Sumar(int Num, int *Suma_ac);
void  Numeros_pos_neg (int Num, int *Positivos, int *Negativos);
float Calcular_media (int Sum_ac, int Cant);
void Imprimir_resultados(int Cant_pares, int Suma_impares, float Medi_impares, int Positivos, int Negativos);
int main (void)
{
    int Numero, Cant_totales = 0, Cant_pares = 0, Cant_impares = 0, Suma_pares = 0, Suma_impares = 0, Cant_positivos = 0, Cant_negativos = 0;
    float Media_Impares;
    do
    {
      Pedir_numeros(&Numero);
      Cant_totales++;
      if ((Numero % 2) == 0)
      {
        Sumar(Numero, &Suma_pares);
      }
      else 
      {
        Sumar(Numero, &Suma_impares);
      }
      if (Numero >= 0)
        Cant_positivos++;
      else
        Cant_negativos++;

    } while (Cant_totales <= 10);
    
    return 0;
}

void Pedir_num(int *Num)
{
    printf("Dame número: " );
    scanf("%d", Num );
    __fpurge(stdin);
}

void Sumar(int Num, int *Suma_ac)
{
    *Suma_ac = *Suma_ac + Num;
}

void  Numeros_pos_neg (int Num, int *Positivos, int *Negativos)
{

}

float Calcular_media (int Sum_ac, int Cant)
{

}

void Imprimir_resultados(int Cant_pares, int Suma_impares, float Medi_impares, int Positivos, int Negativos)
{

}