/*
  @file: prg16_prom.c
  @brief: Calcular el promedio de n cantidad de números dados por el usuario
  @details: Este programa calcula el promedio de la cantidad de números dados por el usuario. El programa pide al principio cuantos números quieres introducir y conforme da los números, se hace la suma acumulada (Este nos permite que el programa se adapte a la cantidad de números variables que nos da el usuario). Posteriormente, se despliega el programa.
  
  @author: Iris Yulit Jasso Cortes
  @date: 10-marzo-2023



DISEÑO ARQUITECTÓNICO

Diagrama IPO de alto nivel

Cantidad, número(s) (ENTRADAS) -> Calcular promedio (PROCESO) -> Promedio (SALIDA)



Diagrama Ipo de bajo nivel

Pedir cantidad de números(RPOCESO) -> (SALIDA)Cantidad(ENTRADA) -> Pedir número(PROCESO) -> (SALIDA)Numero(ENTRADA)->Sumar acumuladamente (PROCESO) -> (SALIDA)Suma(ENTRADA) -> Calular promedio (PROCESO) -> (SALIDA)Promedio(ENTRADA) -> Imprimir resultado(PROCESO)
*/

#include <stdio.h>
#include <stdio_ext.h>

void Pedir_cantidad(int *n);
void Pedir_numero(int Contador, int *Num);
void Sumar_acumulado(int Num, int *Suma);
void Calcular_promedio(int Suma, int n, float *Promedio);
void Imprimir_resultado(int n, float Promedio);

int main(void)
{
    int n, i, Num, Suma;
    float Promedio;

    i = 1;
    Suma = 0;

    Pedir_cantidad(&n);

    do
    {
        Pedir_numero(i, &Num);
        i = i + 1;
        // printf ("Numero %d: %f\n",i,Num);
        Sumar_acumulado(Num, &Suma);
    } while (i <= n);

    Calcular_promedio(Suma, n, &Promedio);
    Imprimir_resultado(n, Promedio);

    return 0;
}

void Pedir_cantidad(int *n)
{
    printf("Dame la cantidad de números a los que les quieres calcular el promedio: ");
    scanf("%d", n);
    __fpurge(stdin);
}

void Pedir_numero(int Contador, int *Num)
{
    printf("Dame número %d: ", Contador);
    scanf("%d", Num);
    __fpurge(stdin);
}

void Sumar_acumulado(int Num, int *Suma)
{
    *Suma = *Suma + Num;
    // 0=0+2;
    // Lo que guarda Suma es la dirección de memoria de la variable Suma de la función principal
    // Suma=Suma+Num; -> 1B=1B+2; -> incorrecto porque estoy sumando un valor numérico con una dirección de memoria
}

void Calcular_promedio(int Suma, int n, float *Promedio)
{
    *Promedio = (float)Suma / n;
}

void Imprimir_resultado(int n, float Promedio)
{
    printf("El promedio de los %d números es: %.2f.\n", n, Promedio);
}
