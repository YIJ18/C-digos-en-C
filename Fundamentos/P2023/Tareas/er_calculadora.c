/*
  @file: er_calculadora.c
  @brief:  Este programa realiza una calculadora, realiza las operaciones de suma, resta, multiplicación y división de dos números.
  @details: Este programa tiene 3 entradas: un caracter y dos enteros, la operación la cual quiere realizar y los dos números con los cuales relizara la operación. Aqui vamos a realizar una transformación, de las dos variables enteras, sale solo una.

  @author: Iris Ylit Jasso Cortes
  date: 12-02-2023



**************************************************************************************
ESPECIFICACIÓN DE REQUERIMIENTOS



Título: Calculadora Básica



Descripción general:


Se desea un programa que calcule las operaciones de suma, resta, multiplicación y división de dos números. El programa solicita la operación a realizar (Op), solicita un número flotante (Num1) y un segundo número flotante (Num2) y posteriormente, el programa despliega el resultado de la operación realizada en la pantalla.



El programa será utilizado para un negocio local, para lograr optimizar el proceso de cobro y devolución de cambio. Es un requerimiento que el cáracter de entrada sea un simbolo (+, -, *, / ): para la suma (Num1+Num2), resta (Num1-Num2), multiplicación (Num1*Num2) o división (Num1/Num2).



Comportamiento detallado:



1) El programa solicita y lee el valor de la operación a realizar (Op).
1) El programa solicita y lee los valores de el número 1 (Num1) y el número 2 (Num2).
2) El programa calculala operación que el usuario desea realizar, ya sea suma (Num1+Num2), resta(Num1-Num2), multiplicación(Num1*Num2) o división(Num1/Num2).
3) El programa despliega el resultado de operación asignada en pantalla.



                ----------------------------------


Entradas



Operación(Op), Número 1 (Num1), Número 2 (Num2).



Salidas



Resultado de operación asignada (Res1)



Procesos



1) Solicitar operación (Op), número 1 (Num1) y número 2 (Num2)
2) Calcular la operación (Res1)
3) Desplegar el resultado (Res) calculado
                ----------------------------------
Alcances y limitaciones


El programa solo realiza una operación donde su entrada solo puede ser un cáracter (+, -, *, /), solo sirve para calcular suma, resta, multiplicación y división, en donde sus entradas permiten números decimales.




El programa hace un tipo de validación. Si el usuario introduce una operación diferente a +, -, *, / el programa te deplegara un error.



Diseño de pantalla



$./area_trian



   Bienvenido. Este programa realiza la operación de suma, resta, multiplicación o división.



   Dame la operación que desea realizar: +
   Dame tu primer número: 2.3
   Dame tu segundo número: 2.3



   El área resultante es: 4.6



   Adiós. Vuelve pronto...
$
**************************************************************************************
DISEÑO ARQUITECTÓNICO

Alto nivel

Op, Num1, Num2 (ENTRADAS) -> Calcular lo que diga Op (PROCESO) -> Res1 (SALIDAS)

Bajo nivel

Pedir Op, Num1, Num2 (PROCESO)  -> (SALIDAS) Num1, Num2, Op (ENTRADAS) -> calcular Op (PROCESOS) -> (SALIDAS) Res (ENTRADAS) -> Imprimir  resultado (PROCESO)


*/

#include <stdio.h>
void Instrucciones();
void Pedir_Datos(char *Op, int *Num1, int *Num2);
void Calcular_Operacion(char Op, int Num1, int Num2, double *Res);
void Desplegar_Resultado(double Res);

int main(void)
{
  char Op;
  int Num1, Num2;
  double Res;
  Instrucciones();
  Pedir_Datos(&Op, &Num1, &Num2);
  Calcular_Operacion(Op, Num1, Num2, &Res);
  Desplegar_Resultado(Res);
  return 0;
}

void Instrucciones()
{
  printf("\nLa calculadora resuelve:"); 
  printf("\n\t\t1. Suma (+)");
  printf("\n\t\t2. Resta (-)");
  printf("\n\t\t3. Multiplicación (*)");
  printf("\n\t\t4. División (/)\n\n");
}

void Pedir_Datos(char *Op, int *Num1, int *Num2)
{
  printf("Ingresa la operación que desea realizar: ");
  scanf("%c", Op);
  printf("Ingresa el primer número: ");
  scanf("%d", Num1);
  printf("Ingresa el segundo número: ");
  scanf("%d", Num2);
}

void Calcular_Operacion(char Op, int Num1, int Num2, double *Res)
{
  double N1, N2;
  if (Op == '+' || Op == '1')
    *Res = Num1 + Num2;
  if (Op == '-' || Op == '2')
    *Res = Num1 - Num2;
  if (Op == '*' || Op == '3')
    *Res = Num1 * Num2;
  if (Op == '/' || Op == '4')
  {
    N1 = Num1;
    N2 = Num2;
    *Res = N2 / N1;
  }
}
void Desplegar_Resultado(double Res)
{
  printf("El resultado de la operación realizada es: %.2lf\n", Res);
}