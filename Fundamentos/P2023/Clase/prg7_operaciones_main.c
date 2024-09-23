/*
@file: prg7_operaciones_main.c
@Brief: Programa que calcula la resta, suma, multiplicación y división.
@details: Este programa solicita dos números de tipo enetero y dos números flotantes, calcula los 5 tipos de operaciones aritmeticas.

@author: Iris Yulit Jasso Cortes
@date: 3 de febrero 2023
*/

#include <stdio.h>
#include <stdio_ext.h>

int main(void)
{
    int Num_ent1, Num_ent2, Suma_ent, Resta_ent, Multi_ent, Div_ent, Res_ent;
    float Num_fl1, Num_fl2, Suma_fl, Resta_fl, Multi_fl, Div_fl, Res_fl;

    printf("\n");
    // los números enteros
    printf("Dame primer número entero: ");
    scanf("%d", &Num_ent1);
    __fpurge(stdin);

    printf("Dame segundo número entero: ");
    scanf("%d", &Num_ent2);
    __fpurge(stdin);
    printf("\n");

    Suma_ent = Num_ent1 + Num_ent2;
    Resta_ent = Num_ent1 - Num_ent2;
    Multi_ent = Num_ent1 * Num_ent2;
    Div_ent = Num_ent1 / Num_ent2;
    Res_ent = Num_ent1 % Num_ent2;

    // Nota: Recordar que el signo igual es un operador de asignación y se lee como "La  variable toma el valor de ... una operación aritmetica , el contenido de otra variable, el número de la raiz, etc"
    printf("Los valores resultantes de las operaciones de los números flotantes son : \n\n");
    printf("\tSuma = %d + %d = %d\n", Num_ent1, Num_ent2, Suma_ent);
    printf("\tResta = %d - %d = %d\n", Num_ent1, Num_ent2, Resta_ent);
    printf("\tMultiplicación = %d * %d = %d\n", Num_ent1, Num_ent2, Multi_ent);
    printf("\tDivisión = %d + %d = %d\n", Num_ent1, Num_ent2, Div_ent);
    printf("\tResiduo = %d + %d = %d\n", Num_ent1, Num_ent2, Res_ent);

    // los números flotantes
    printf("\n\n");
    printf("Dame primer número flotante: ");
    scanf("%f", &Num_fl1);
    __fpurge(stdin);

    printf("Dame segundo número flotante: ");
    scanf("%f", &Num_fl2);
    __fpurge(stdin);
    printf("\n");

    Suma_fl = Num_fl1 + Num_fl2;
    Resta_fl = Num_fl1 - Num_fl2;
    Multi_fl = Num_fl1 * Num_fl2;
    Div_fl = Num_fl1 / Num_fl2;
    /*Res_ent = Num_fl1 % Num_fl2;
    -----invalid operands to binary % (have ‘float’ and ‘float’)-----
    Esta operación es invalida puesto que el residuo de números flotantes es invalido*/

    // Nota: Recordar que el signo igual es un operador de asignación y se lee como "La  variable toma el valor de ... una operación aritmetica , el contenido de otra variable, el número de la raiz, etc"
    printf("Los valores resultantes de las operaciones de los números enteros son : \n\n");
    printf("\tSuma = %.2f + %.2f = %.2f\n", Num_fl1, Num_fl2, Suma_fl);
    printf("\tResta = %.2f - %.2f = %.2f\n", Num_fl1, Num_fl2, Resta_fl);
    printf("\tMultiplicación = %.2f * %.2f = %.2f\n", Num_fl1, Num_fl2, Multi_fl);
    printf("\tDivisión = %.2f / %.2f = %.2f\n", Num_fl1, Num_fl2, Div_fl);
    /*printf("Residuo = %d + %d = %d\n", Num_ent1, Num_ent2, Res_ent);
    esta impresión no la hicimos, puesto que la operación es invalida, al imprimir este valor nos arrojaria basura, puesto que no lo definimos en ningun lugar*/

    return 0;
}