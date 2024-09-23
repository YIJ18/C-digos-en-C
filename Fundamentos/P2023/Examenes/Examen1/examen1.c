/*
  @file: examen1.c
  @brief: En este archivo calcula la cantidad que debes ahorrar para el retiro a cierta edad
  @details: Este archivo recibe dos valores enteros y se transforman en una cantidad que debes ahorrar para el retiro a cierta edad



  @author: Iris Ylit Jasso Cortes
  date: 2-Marzo-2023



**************************************************************************************
ESPECIFICACIÓN DE REQUERIMIENTOS



Título: Calculo del ahorro de la jubilación total



Descripción general:



Se desea un programa que calcule el monto mensual que te gustaria recibir cuando te retires. El programa solicita la edad a la que te quieres retirar (Edad) y la cantidad mensual que debes ahorrar (Monto)  y posteriormente, el programa despliega el resultado de la cantidad que tienes que ahorrar en pantalla.



El programa será utilizado para las personas que empiezan a trabajar y quieren asegurar un buen retiro. Es un requerimiento es que se calcule con la fórmula ahorro total= (Esperanza de Vida -  Edad de jubilación)*12*Monto deseado de la pension mensual, y que tanto el monto como la edad sean números enteros.



Comportamiento detallado:



1) El programa solicita y lee los valores de la edad (Edad) y el monto (Monto).
2) El programa calcula el monto total que debes ahorrar usando la fórmula ahorro total= (Esperanza de Vida -  Edad de jubilación)*12*Monto deseado de la pension mensua
3) El programa despliega el monto total que debes ahorrar calculada en pantalla.



                ----------------------------------

Entradas



Edad a la que se quiere retirar (Edad) y Monto que desea obtener (Monto)



Salidas



Ahorro T (Resultado)



Procesos



1) Solicitar edad a la que se quiere retirar (Edad) y monto que quiere recibir mensualmente (Monto)
2) Calcular ahorro total que debe hacer (Resultado)
3) Desplegar el ahorro total que se debe hacer (Resultado) calculado
                ----------------------------------
Alcances y limitaciones



El programa solo sirve para calcular el ahorro total, en donde sus entradas son de tipo entero(Edad) y flotante (Monto).

Si el usuario introduce Edad flotante, el programa arroja un resultado incorrecto, este programa no recibe ni Edad, ni Monto negativos, por lo que este marcara un error si los introduce de esta manera.


Diseño de pantalla

$./area_trian


    Este  programa  realiza  una  estimación  de  cuanto  debe  de  ahorrar  una  persona en su vida profesional para su retiro.

    Dame    la edad a la que te quisieras retirar: 63

    Dame el monto mensual que te gustaría recibir cuando te retires: 30000

    En total debes de ahorrar $5400000 pesos para recibir una mensualidad de $30000 pesos.

    ¡¡¡Es tiempo de ahorrar!
$
Diseño arquitectónico y detallado 

Debes de realizar 2 diagramas IPO:

Diagrama IPO de alto nivel
Monto, Edad(ENTRADAS)->Calcular el ahorro total (PROCESO) -> Monto que debes ahorrar(SALIDA)



Diagrama IPO de bajo nivel
Pedir coeficientes(PROCESO)-> (SALIDAS)Monto, Edad(ENTRADAS)->Validar Datos(PROCESO)->(SALIDAS) Monto, Edad (ENTRADAS)->Calcular el ahorro total (PROCESO) -> (SALIDA) Resultado(PROCESO) -> Imprimir resultado(PROCESO)

int main(void)
{
    int Monto, Edad, Resultado;

     Llamar a Función Pedir( &Monto,  &Edad);
     Llamar a FunciónCalcular( Monto,  Edad,  &Resultado);
     Llamar a FunciónDesplegar( Monto,  Edad,  Resultado);
     Llamar a Funciónreturn 0;
}

función Pedir(int *Monto, int *Edad)
{

}
función Validar(int Monto, int Edad)
{


}
función Calcular(int Monto, int Edad, int *Resultado)
{

}
función Desplegar(int Monto, int Edad, int Resultado)
{

}
*/

#include <stdio.h>
#include <stdio_ext.h>

void Pedir(float *Monto, int *Edad);
int Validar(float Monto, int Edad);
void Calcular(float Monto, int Edad, float *Resultado);
void Desplegar(float Monto, int Edad, float Resultado);

int main(void)
{
    float Monto, Resultado;
    int Edad;
Pedir( &Monto,  &Edad);
Calcular( Monto,  Edad,  &Resultado);
Desplegar( Monto,  Edad,  Resultado);
    return 0;
}

void Pedir(float *Monto, int *Edad)
{
    printf("Bienvenido\n");
    printf("Este  programa  realiza  una  estimación  de  cuanto  debe  de  ahorrar  una  persona en su vida profesional para su retiro.\n");

    printf("\tDame la edad a la que te quisieras retirar: ");
    scanf("%d", Edad);
    __fpurge(stdin);

    printf("\tDame el monto mensual que te gustaría recibir cuando te retires: ");
    scanf("%f", Monto);
    __fpurge(stdin);
}
int Validar(float Monto, int Edad)
{
    if (Edad <= 0)
    {
        printf("\nLa edad proporcionada es inválida.");
    }
    if (Monto <= 0)
    {
        printf("\nEl monto mensual es inválido.");
    }
    
    if(Edad <= 0 || Monto <= 0)
    {
        printf("\nTermina programa.\n");
         return 1;
    }

    if (Edad >= 75)
    {
        if(Edad > 75)
        printf("\nLa edad es mayor a la esperanza de vida. \n");
        if(Edad == 75)
        printf("\nLa edad es igual a la esperanza de vida. \n");
        return 1;
    }
    else
    {
        return 0;
    }
}
void Calcular(float Monto, int Edad, float *Resultado)
{
    *Resultado = ( 75 - Edad) * 12 * Monto;

}
void Desplegar(float Monto, int Edad, float Resultado)
{

if(Validar(Monto, Edad) == 0){
    printf("\tEn total debes de ahorrar $%.2f pesos para recibir una mensualidad de $%.2f pesos.\n", Resultado, Monto);
    printf("\t¡¡¡Es tiempo de ahorrar!!!\n");
}
}