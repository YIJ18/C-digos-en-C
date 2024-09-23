/*
@file: practica1.c
@brief: Serie de diferentes ejercicios
@details: Este programa resuelve diferentes ejercicios
@author: Iris Yulit Jasso Cortes
@date: 15-Marzo-2023
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

// Inicio
void Nombre(void);

// Menú
void Instrucciones_y_menu(void);
void Pedir_opcion(int *Opcion);

// Primer programa : Suma acumulada
void Problema_1(void);
int Suma_acumulada_1(void);
void Desplegar_1(int Suma);

// Segundo programa : Número menor, número mayor
void Problema_2(void);
void Solicitar_2(int *Cant);
void Ingresar_2(int *Num, int i);
void Menor_2(int Num, int i, int *Menor);
void Mayor_2(int Num, int i, int *Mayor);
void Desplegar_2(int Menor, int Mayor);

// Tercer programa : Determina si un número n es primo o no
void Problema_3(void);
void Solicitar_3(int *Num);
void Primo_3(int Numero, int *cont);
void Desplegar_3(int Numero, int cont);

// Cuarto programa : Calcula la superficie de un triángulo
void Problema_4(void);
void Solicitar_4(float *Base, float *Altura);
int Calcular_4(float Base, float Altura);
void Desplegar_4(float Superficie);

// Quinto Programa :  Libras a kilogramos y gramos
void Problema_5(void);
void Solicitar_5(float *Libras);
void Calcular_5(float Libras, float *Kg, float *gramos);
void Desplegar_5(float Kg, float gramos);

// Sexto Programa : Suma de los números pares e impares comprendidos entre el número 521 y 1125
void Problema_6(void);
void Suma_acumulada_6(int Cant, int *Suma);
void Desplegar_6(int Par, int Impar);

// Séptimo Programa : Indica el número impar más chico y el número par más grande
void Problema_7(void);
void Solicitar_7(int *Cant);
void Ingresar_7(int *Num);
void Mayor_7(int Num, int i, int *Mayor);
void Menor_7(int Num, int j,  int *Menor);
void Desplegar_7(int Menor, int Mayor, int i, int j);

// Octavo Programa : Suma de 7 números introducidos por el teclado.
void Problema_8(void);
void Solicitar_8(int i, int *Num);
int Validar_8(int Num);
void Suma_acumulada_8(int Num, int *Suma);
void Desplegar_8(int Suma);

// Noveno Programa : Media impares, cantidad pares, suma pares, cantidad impares.
void Problema_9(void);
void Solicitar_9(int i, int *Num);
void Suma_acumulada_9(int Num, int *Suma);
void Media_9(int Suma_Impar, int j, float *Media);
void Contabilizar(int Num, int *Positivos, int *Negativos);
void Desplegar_9(float Media, int k, int Suma_Par, int j, int Positivos, int Negativos);

// Décimo Programa : Muestra dos días después.
void Problema_10(void);
void Solicitar_10(int *Dia, int *Mes, int *Anio);
void Meses_31(int Dia, int Mes, int Anio, int *Dia_sig, int *Mes_sig, int *Anio_sig);
void Meses_30(int Dia, int Mes, int Anio, int *Dia_sig, int *Mes_sig, int *Anio_sig);
void Calcular_10(int Dia, int Mes, int Anio, int *Dia_sig, int *Mes_sig, int *Anio_sig);
int Desplegar_10(int Dia_sig, int Mes_sig, int Anio_sig);

// Undécimo : Potencia de x número a n potencia.
void Problema_11(void);
void Solicitar_11(int *Exp, int *Num);
int Validar_11(int Exp, int Num);
int Potencia_11(int Num, int Exp);
void Desplegar_11(int Pot);

// Duodécimo : Imprimir triángulos rectángulos.
void Problema_12(void);
void Triangulo_12(void);
void Triangulo_12_1(void);

// Décimo tercero : Adivina el número Aleatorio.
void Problema_13(void);
void Solicitar_13(int i, int *Num);
void Aleatorio_13(int *Aleatorio);

// Décimo cuarto : Imprime un rectángulo.
void Problema_14(void);
void Solicitar_14(int *Base, int *Altura, char *Caracter);
void Cuadrado_14(int Base, int Altura, char Caracter);

// Décimo quinto : Imprime un triángulo.
void Problema_15(void);
void Solicitar_15(int *Base);
void Contador_15(int Base, int i);
void Desplegar_15(int Base);

int main(void)
{

    // Menu
    int Opcion;
    Nombre();
    do
    {
        Instrucciones_y_menu();
        Pedir_opcion(&Opcion);
        if (Opcion == 1)
        {
            system("clear");
            Problema_1();
        }
        else
        {
            if (Opcion == 2)
            {
                system("clear");
                Problema_2();
            }
            else
            {
                if (Opcion == 3)
                {
                    system("clear");
                    Problema_3();
                }
                else
                {
                    if (Opcion == 4)
                    {
                        system("clear");
                        Problema_4();
                    }
                    else
                    {
                        if (Opcion == 5)
                        {
                            system("clear");
                            Problema_5();
                        }
                        else
                        {
                            if (Opcion == 6)
                            {
                                system("clear");
                                Problema_6();
                            }
                            else
                            {
                                if (Opcion == 7)
                                {
                                    system("clear");
                                    Problema_7();
                                }
                                else
                                {
                                    if (Opcion == 8)
                                    {
                                        system("clear");
                                        Problema_8();
                                    }
                                    else
                                    {
                                        if (Opcion == 9)
                                        {
                                            system("clear");
                                            Problema_9();
                                        }
                                        else
                                        {
                                            if (Opcion == 10)
                                            {
                                                system("clear");
                                                Problema_10();
                                            }
                                            else
                                            {
                                                if (Opcion == 11)
                                                {
                                                    system("clear");
                                                    Problema_11();
                                                }
                                                else
                                                {
                                                    if (Opcion == 12)
                                                    {
                                                        system("clear");
                                                        Problema_12();
                                                    }
                                                    else
                                                    {
                                                        if (Opcion == 13)
                                                        {
                                                            system("clear");
                                                            Problema_13();
                                                        }
                                                        else
                                                        {
                                                            if (Opcion == 14)
                                                            {
                                                                system("clear");
                                                                Problema_14();
                                                            }
                                                            else
                                                            {
                                                                if (Opcion == 15)
                                                                {
                                                                    system("clear");
                                                                    Problema_15();
                                                                }
                                                                else
                                                                {
                                                                    if (Opcion == 16)
                                                                    {
                                                                        system("clear");
                                                                        printf("Termina el programa. Adiós...\n");
                                                                    }
                                                                    else
                                                                    {
                                                                        system("clear");
                                                                        printf("Opción invalida. Intenta nuevamnete...\n");
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("\n\nPresiona <ENTER> para continuar...\n\n");
        getchar();
        __fpurge(stdin);
        system("clear");

    } while (Opcion != 16);

    return 0;
}

// Inicio

void Nombre(void)
{
    printf("\nB I E N V E N I D O ");
    printf("\n\nCreador : Iris Yulit Jasso Cortes");
    printf("\n\nPresiona <ENTER> para continuar...\n\n");
    getchar();
    system("clear");
    printf("\n\nEste programa contiene una serie de ejercicios que es capaz de ejecutar y resolver. Para ejecutar las diversas soluciones de  los problemas es necesario introducir el número del programa, seguido de un <enter>, después el programa seleccionado solicitará los datos necesarios para ejecutarse.  Existen programas que no requieren entradas, estos desplegaran directamente los resultados.\n\n");
    printf("\n\nPresiona <ENTER> para continuar...\n\n");
    getchar();
    system("clear");
}

// Menu

void Instrucciones_y_menu(void)
{
    printf(" ---------------------------- M E N Ú ----------------------------\n\n ");
    printf("Las opciones del menú son las siguientes: \n");
    printf(" 1) Imprime la suma acumulada de 5,6,8,11,15,...,195. \n");
    printf(" 2) Determinar número mayor y menor de n números.\n");
    printf(" 3) Determina si un número n es primo o no.\n");
    printf(" 4) Calcula la superficie de un triángulo.\n");
    printf(" 5) Convierte el peso en libras a kilogramos y gramos.\n");
    printf(" 6) Suma de los números pares e impares de 521 a 1125.\n");
    printf(" 7) Indica el número menor impar y el número mayor par.\n");
    printf(" 8) Suma de 7 números introducidos por el teclado.\n");
    printf(" 9) Media impares, cantidad pares, suma pares, cantidad impares.\n");
    printf("10) Muestra dos días después.\n");
    printf("11) Potencia de x número a n potencia.\n");
    printf("12) Imprimir triángulos rectángulos. \n");
    printf("13) Adivina el número Aleatorio.\n");
    printf("14) Imprime un rectángulo.\n");
    printf("15) Imprime un triángulo.\n");
    printf("16) Salir del programa.\n\n");
}

void Pedir_opcion(int *Opcion)
{
    printf("---Dame Opción: ");
    scanf("%d", Opcion);
    __fpurge(stdin);
}

// Primer programa : Suma acumulada

void Problema_1(void)
{
    int Suma;
    printf("\n1) Suma acumulada\n\n");
    Suma = Suma_acumulada_1();
    Desplegar_1(Suma);
}

int Suma_acumulada_1(void)
{
    int i, suma, num, b;
    suma = 0;
    num = 5;
    b = 0;
    printf("\n");
    for (i = 0; i < 20; i++)
    {
        num = num + i;
        b = num;
        suma = b + suma;
        b = suma;
    }
    return suma;
}

void Desplegar_1(int Suma)
{
    int i, suma = 5, j = 0;
    for (i = 0; suma < 195; i++)
    {
        suma = suma + j;
        j++;

        printf("%d ", suma);
        if (suma < 195)
            printf("+ ");
    }
    printf("\nLa suma acumulada es : %d ", Suma);
}

// Segundo programa : Número menor, número mayor

void Problema_2(void)
{
    int Cant, Num, Menor, Mayor;
    int i = 1;
    printf("\n2) Determinar número mayor y menor de n números.\n\n");
    do
    {
        Solicitar_2(&Cant);
        if (Cant < 1)
            printf("Ingresa un número válido.\n");
    } while (Cant < 1);

    do
    {
        Ingresar_2(&Num, i);
        Menor_2(Num, i, &Menor);
        Mayor_2(Num, i, &Mayor);
        i++;
    } while (i <= Cant);
    Desplegar_2(Menor, Mayor);
}

void Solicitar_2(int *Cant)
{
    printf("Ingresa la cantidad de números a comparar: ");
    scanf("%d", Cant);
    __fpurge(stdin);
    printf("\n");
}

void Ingresar_2(int *Num, int i)
{
    printf("Ingresa el número %d: ", i);
    scanf("%d", Num);
    __fpurge(stdin);
}

void Menor_2(int Num, int i, int *Menor)
{
    if (i == 1)
        *Menor = Num;
    else
    {
        if (Num < *Menor)
            *Menor = Num;
        else
        {
            if (Num > *Menor)
                *Menor = *Menor;
        }
    }
}

void Mayor_2(int Num, int i, int *Mayor)
{
    if (i == 1)
        *Mayor = Num;
    else
    {
        if (Num > *Mayor)
            *Mayor = Num;
        else
        {
            if (Num < *Mayor)
                *Mayor = *Mayor;
        }
    }
}

void Desplegar_2(int Menor, int Mayor)
{
    if (Mayor == Menor)
        printf("\nEl número mayor y menor son iguales, es %d", Mayor);
    else
    {
        printf("\n\nEl número menor es: %d", Menor);
        printf("\nEl número mayor es: %d\n\n", Mayor);
    }
}

// Tercer programa : Determina si un número n es primo o no

void Problema_3(void)
{
    int Numero, cont;
    printf("\n3) Determina si un número n es primo o no.\n\n");
    do
    {
        Solicitar_3(&Numero);
        if (Numero < 1)
            printf("Ingresa un número positivo.\n");
    } while (Numero < 1);

    Primo_3(Numero, &cont);
    Desplegar_3(Numero, cont);
}

void Solicitar_3(int *Num)
{
    printf("Ingresa el número a evaluar: ");
    scanf("%d", Num);
    __fpurge(stdin);
}

void Primo_3(int Numero, int *cont)
{
    int i, temp, conta = 0;
    temp = 0;
    for (i = 1; i <= Numero; i++)
    {
        temp = Numero % i;
        if (temp == 0)
            conta++;
    }
    *cont = conta;
}

void Desplegar_3(int Numero, int cont)
{
    if (cont == 2)
        printf("\nEl número %d es un número primo, pues es divisible solo por %d números\n", Numero, cont);

    else
        printf("\nEl número %d no es un número primo, pues es divisible por %d números\n", Numero, cont);
}

// Cuarto programa : Calcula la superficie de un triángulo

void Problema_4(void)
{
    float Base, Altura, Superficie;
    printf("\n4) Calcula la superficie de un triángulo.\n\n");
    do
    {
        Solicitar_4(&Base, &Altura);
        if (Base < 0 || Altura < 0)
        {
            printf("\nSe debe intoducir un número positivo.\n");
            printf("INTENTALO DE NUEVO <ENTER> PARA CONTINUAR\n");
            getchar();
            system("clear");
        }
    } while (Base < 0 || Altura < 0);
    Superficie = Calcular_4(Base, Altura);
    Desplegar_4(Superficie);
}

void Solicitar_4(float *Base, float *Altura)
{
    printf("\nIngresa la base: ");
    scanf("%f", Base);
    __fpurge(stdin);

    printf("\nIngresa la altura: ");
    scanf("%f", Altura);
    __fpurge(stdin);
}

int Calcular_4(float Base, float Altura)
{
    int Superficie;
    Superficie = (Base * Altura) / 2;
    return Superficie;
}

void Desplegar_4(float Superficie)
{
    printf("\nLa superficie de tu triángulo es: %.2f", Superficie);
}

// Quinto Programa :  Libras a kilogramos y gramos

void Problema_5(void)
{
    float Libras, Kg, gramos;
    printf("\n5) Convierte el peso en libras a kilogramos y gramos.\n\n");
    do
    {
        Solicitar_5(&Libras);
        if (Libras < 0.1)
            printf("Ingresa un peso válido");

    } while (Libras < 0.1);

    Calcular_5(Libras, &Kg, &gramos);
    Desplegar_5(Kg, gramos);
}

void Solicitar_5(float *Libras)
{
    printf("\nIngresa tu peso en Libras: ");
    scanf("%f", Libras);
    __fpurge(stdin);
}

void Calcular_5(float Libras, float *Kg, float *gramos)
{
    // Nota: una libra equivale a 0.453592 kilogramos | 1lb = 0.453592 kilogramos
    *Kg = 0.453592 * Libras;
    *gramos = *Kg * 1000;
}

void Desplegar_5(float Kg, float gramos)
{
    printf("\nTu peso en kilogramos es: %.4f Kg", Kg);
    printf("\nTu peso en gramos es: %.4f g", gramos);
}

// Sexto Programa : Suma de los números pares e impares comprendidos entre el número 521 y 1125

void Problema_6(void)
{
    int Par = 0;
    int Impar = 0;
    int Cant = 0;
    int Valida = 0;
    int i;

    printf("6) Suma de los números pares e impares de 521 a 1125.\n\n");
    for (i = 521; i <= 1125; i++)
    {
        Cant = i;
        Valida = Cant % 2;
        if (Valida == 0)
        {
            // Par
            Suma_acumulada_6(Cant, &Par);
        }
        else
        {
            Suma_acumulada_6(Cant, &Impar);
        }
    }
    Desplegar_6(Par, Impar);
}

void Suma_acumulada_6(int Cant, int *Suma)
{
    *Suma = Cant + *Suma;
}

void Desplegar_6(int Par, int Impar)
{
    printf("La suma acumulada de números pares es: %d\n", Par);
    printf("La suma acumulada de números impares es: %d\n\n", Impar);
}

// Séptimo Programa : Indica el número impar más chico y el número par más grande
void Problema_7(void)
{
    int Num, Menor, Mayor;
    int i = 0, j = 0;
    printf("\n7) Indica el número menor impar y el número mayor par (se detiene con -124).\n\n");

    do
    {
        Ingresar_7(&Num);
        if (Num <= 0 && Num != -124)
            printf("Ingresa un número positivo o diferente de cero.\n");
        else
        {
            if (Num == -124)
            {
                printf("\nIngresó el último dígito.\n");
            }
            else if (Num % 2 == 0)
            {
                i++;
                Mayor_7(Num, i, &Mayor);
            }
            else 
            {
                j++;
                Menor_7(Num, j, &Menor);

            }
        }

    } while (Num < -124 || Num > -124);

    Desplegar_7(Menor, Mayor, i, j);
}

void Ingresar_7(int *Num)
{
    printf("Ingresa el número: ");
    scanf("%d", Num);
    __fpurge(stdin);
}

void Menor_7(int Num, int j, int *Menor)
{
    //Impar
    if (j == 1)
        *Menor = Num;
    else
    {
        if (Num < *Menor)
            *Menor = Num;
        else
        {
            if (Num > *Menor)
                *Menor = *Menor;
        }
    }
}

void Mayor_7(int Num, int i, int *Mayor)
{
    //Par
    if (i == 1)
        *Mayor = Num;
    else
    {
        if (Num > *Mayor)
            *Mayor = Num;
        else
        {
            if (Num < *Mayor)
                *Mayor = *Mayor;
        }
    }
}

void Desplegar_7(int Menor, int Mayor, int i, int j)
{
    if (Mayor == Menor)
        printf("\nEl número mayor y menor son iguales, es %d", Mayor);
    else
    {
        if (i == 0)
        {
            printf("\n\nEl número impar menor es: %d\n", Menor);
            printf("No ingresó ningun número par\n\n");
        }
        else if(j == 0)
        {
            printf("\nNo ingresó ningun número impar\n\n");
            printf("El número par mayor es: %d\n\n", Mayor);
        }
        else
        {
            printf("\n\nEl número impar menor es: %d", Menor);
            printf("\nEl número par mayor es: %d\n\n", Mayor);
        }
    }
}


// Octavo Programa : Suma de 7 números introducidos por el teclado.

void Problema_8(void)
{
    int i = 1;
    int Num, Suma = 0;
    printf("\n8) Suma de 7 números introducidos por el teclado.\n\n");
    do
    {
        Solicitar_8(i, &Num);
        if (Validar_8(Num) == 0)
            Suma_acumulada_8(Num, &Suma);
        if (Validar_8(Num) == 1)
        {
            printf("Ingrese un número positivo.\n");
            i--;
        }
        i++;
    } while (i <= 7);
    Desplegar_8(Suma);
}

void Solicitar_8(int i, int *Num)
{
    printf("Ingresa el número %d: ", i);
    scanf("%d", Num);
    __fpurge(stdin);
}

int Validar_8(int Num)
{
    if (Num >= 0)
    {
        return 0;
    }
    if (Num < 0)
    {
        return 1;
    }
}

void Suma_acumulada_8(int Num, int *Suma)
{
    *Suma = Num + *Suma;
}

void Desplegar_8(int Suma)
{
    printf("La suma acumulada es : %d", Suma);
}

// Noveno Programa : Media impares, cantidad pares, suma pares, cantidad impares.

void Problema_9(void)
{
    int Num, Res;
    int Suma_Impar = 0;
    int Positivos = 0;
    int Negativos = 0;
    int Suma_Par = 0;
    float Media = 0;
    int i = 1;
    int j = 0;
    int k = 0;
    printf("9) Media impares, cantidad pares, suma pares, cantidad impares.\n\n");
    do
    {
        Solicitar_9(i, &Num);
        Contabilizar(Num, &Positivos, &Negativos);
        Res = Num % 2;
        if (Res != 0)
        {
            Suma_acumulada_9(Num, &Suma_Impar);
            j++;
        }
        if (Res == 0)
        {
            Suma_acumulada_9(Num, &Suma_Par);
            k++;
        }
        i++;
    } while (i <= 10);
    Media_9(Suma_Impar, j, &Media);
    Desplegar_9(Media, k, Suma_Par, j, Positivos, Negativos);
}

void Solicitar_9(int i, int *Num)
{
    printf("Ingresa el número %d: ", i);
    scanf("%d", Num);
    __fpurge(stdin);
}

void Media_9(int Suma_Impar, int j, float *Media)
{
    float flotante = j;
    *Media = Suma_Impar / flotante;
}

void Suma_acumulada_9(int Num, int *Suma)
{
    *Suma = Num + *Suma;
}

void Contabilizar(int Num, int *Positivos, int *Negativos)
{
    if (Num > 0)
        *Positivos = *Positivos + 1;
    if (Num < 0)
        *Negativos = *Negativos + 1;
}

void Desplegar_9(float Media, int k, int Suma_Par, int j, int Positivos, int Negativos)
{
    printf("\nLa media aritméticade los números impares: %.2f", Media);
    printf("\nLa suma de los números pares %d\n", Suma_Par);

    if (k != 0)
        printf("\nExisten %d números pares.", k);
    if (j != 0)
        printf("\nExisten %d números impares.", j);
    if (k == 0)
        printf("\nNo ingreso números pares.");
    if (j == 0)
        printf("\nNo ingreso números impares.");

    printf("\n\nSon %d números positivos.", Positivos);
    printf("\nSon %d números negativos.\n\n", Negativos);
}

// Décimo Programa : Muestra dos días después.

void Problema_10(void)
{
    int Dia, Mes, Anio;
    int Dia_sig = 0, Mes_sig = 0, Anio_sig = 0;
    printf("\n10) Muestra dos días después.\n\n");
    do
    {
        Solicitar_10(&Dia, &Mes, &Anio);
        Calcular_10(Dia, Mes, Anio, &Dia_sig, &Mes_sig, &Anio_sig);

    } while (Desplegar_10(Dia_sig, Mes_sig, Anio_sig) == 1);
}

void Solicitar_10(int *Dia, int *Mes, int *Anio)
{
    printf("\nIngresa el día: ");
    scanf("%d", Dia);
    __fpurge(stdin);

    printf("Ingresa el mes: ");
    scanf("%d", Mes);
    __fpurge(stdin);

    printf("Ingresa el año: ");
    scanf("%d", Anio);
    __fpurge(stdin);

    printf("\n");
}

void Calcular_10(int Dia, int Mes, int Anio, int *Dia_sig, int *Mes_sig, int *Anio_sig)
{
    int Febrero;
    int Dia_sig_p, Mes_sig_p, Anio_sig_p;
    if (Anio >= 0)
    {
        if (Mes == 1)
        {
            if (Dia <= 31 && Dia > 0)
            {
                Meses_31(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                *Dia_sig = Dia_sig_p;
                *Mes_sig = Mes_sig_p;
                *Anio_sig = Anio_sig_p;
            }
            else
            {
                printf("Ingrese un día válido.\n");
            }
        }
        else
        {
            if (Mes == 2)
            {
                Febrero = Anio % 4;
                if (Dia <= 29 && Dia > 0)
                {
                    if (Febrero == 0 && Dia <= 29 && Dia > 0)
                    {
                        // Año Bisiesto - 29 días
                        if (Dia == 29 || Dia == 28)
                        {
                            *Mes_sig = Mes + 1;
                            if (Dia == 29)
                                *Dia_sig = 2;
                            if (Dia == 28)
                                *Dia_sig = 1;
                        }

                        else
                        {
                            *Mes_sig = Mes;
                            *Dia_sig = Dia + 2;
                        }
                    }
                    else if (Febrero != 0 && Dia <= 28 && Dia > 0)
                    {
                        // 28 días Febrero
                        if (Dia == 27 || Dia == 28)
                        {
                            *Mes_sig = Mes + 1;
                            if (Dia == 28)
                                *Dia_sig = 2;
                            if (Dia == 27)
                                *Dia_sig = 1;
                        }

                        else
                        {
                            *Mes_sig = Mes;
                            *Dia_sig = Dia + 2;
                        }
                    }
                    if (Febrero != 0 && Dia == 29)
                    {
                        printf("Ingrese un día válido.\n");
                        *Dia_sig = 0;
                    }
                    *Anio_sig = Anio;
                }

                else
                {
                    printf("Ingrese un día válido.\n");
                }
            }
            else
            {
                if (Mes == 3)
                {
                    if (Dia <= 31 && Dia > 0)
                    {
                        Meses_31(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                        *Dia_sig = Dia_sig_p;
                        *Mes_sig = Mes_sig_p;
                        *Anio_sig = Anio_sig_p;
                    }
                    else
                    {
                        printf("Ingrese un día válido.\n");
                    }
                }
                else
                {
                    if (Mes == 4)
                    {
                        if (Dia <= 30 && Dia > 0)
                        {
                            Meses_30(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                            *Dia_sig = Dia_sig_p;
                            *Mes_sig = Mes_sig_p;
                            *Anio_sig = Anio_sig_p;
                        }
                        else
                        {
                            printf("Ingrese un día válido.\n");
                        }
                    }
                    else
                    {
                        if (Mes == 5)
                        {
                            if (Dia <= 31 && Dia > 0)
                            {
                                Meses_31(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                                *Dia_sig = Dia_sig_p;
                                *Mes_sig = Mes_sig_p;
                                *Anio_sig = Anio_sig_p;
                            }
                            else
                            {
                                printf("Ingrese un día válido.\n");
                            }
                        }
                        else
                        {
                            if (Mes == 6)
                            {
                                if (Dia <= 30 && Dia > 0)
                                {
                                    Meses_30(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                                    *Dia_sig = Dia_sig_p;
                                    *Mes_sig = Mes_sig_p;
                                    *Anio_sig = Anio_sig_p;
                                }
                                else
                                {
                                    printf("Ingrese un día válido.\n");
                                }
                            }
                            else
                            {
                                if (Mes == 7)
                                {
                                    if (Dia <= 31 && Dia > 0)
                                    {
                                        Meses_31(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                                        *Dia_sig = Dia_sig_p;
                                        *Mes_sig = Mes_sig_p;
                                        *Anio_sig = Anio_sig_p;
                                    }
                                    else
                                    {
                                        printf("Ingrese un día válido.\n");
                                    }
                                }
                                else
                                {
                                    if (Mes == 8)
                                    {
                                        if (Dia <= 31 && Dia > 0)
                                        {
                                            Meses_31(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                                            *Dia_sig = Dia_sig_p;
                                            *Mes_sig = Mes_sig_p;
                                            *Anio_sig = Anio_sig_p;
                                        }
                                        else
                                        {
                                            printf("Ingrese un día válido.\n");
                                        }
                                    }
                                    else
                                    {
                                        if (Mes == 9)
                                        {
                                            if (Dia <= 30 && Dia > 0)
                                            {
                                                Meses_30(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                                                *Dia_sig = Dia_sig_p;
                                                *Mes_sig = Mes_sig_p;
                                                *Anio_sig = Anio_sig_p;
                                            }
                                            else
                                            {
                                                printf("Ingrese un día válido.\n");
                                            }
                                        }
                                        else
                                        {
                                            if (Mes == 10)
                                            {
                                                if (Dia <= 31 && Dia > 0)
                                                {
                                                    Meses_31(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                                                    *Dia_sig = Dia_sig_p;
                                                    *Mes_sig = Mes_sig_p;
                                                    *Anio_sig = Anio_sig_p;
                                                }
                                                else
                                                {
                                                    printf("Ingrese un día válido.\n");
                                                }
                                            }
                                            else
                                            {
                                                if (Mes == 11)
                                                {
                                                    if (Dia <= 30 && Dia > 0)
                                                    {
                                                        Meses_30(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                                                        *Dia_sig = Dia_sig_p;
                                                        *Mes_sig = Mes_sig_p;
                                                        *Anio_sig = Anio_sig_p;
                                                    }
                                                    else
                                                    {
                                                        printf("Ingrese un día válido.\n");
                                                    }
                                                }
                                                else
                                                {
                                                    if (Mes == 12)
                                                    {
                                                        if (Dia <= 31 && Dia > 0)
                                                        {
                                                            Meses_31(Dia, Mes, Anio, &Dia_sig_p, &Mes_sig_p, &Anio_sig_p);
                                                            *Dia_sig = Dia_sig_p;

                                                            if (Dia == 31 || Dia == 30)
                                                            {
                                                                *Mes_sig = 1;
                                                                *Anio_sig = Anio_sig_p + 1;
                                                            }

                                                            else
                                                            {
                                                                *Mes_sig = Mes_sig_p;
                                                                *Anio_sig = Anio_sig_p;
                                                            }
                                                        }
                                                        else
                                                        {
                                                            printf("Ingrese un día válido.\n");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        printf("El mes ingresado es inválido.\n");
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Meses_31(int Dia, int Mes, int Anio, int *Dia_sig_p, int *Mes_sig_p, int *Anio_sig_p)
{
    if (Dia == 31 || Dia == 30)
    {
        *Mes_sig_p = Mes + 1;
        if (Dia == 31)
            *Dia_sig_p = 2;
        if (Dia == 30)
            *Dia_sig_p = 1;
    }
    else
    {
        *Mes_sig_p = Mes;
        *Dia_sig_p = Dia + 2;
    }
    *Anio_sig_p = Anio;
}

void Meses_30(int Dia, int Mes, int Anio, int *Dia_sig_p, int *Mes_sig_p, int *Anio_sig_p)
{
    if (Dia == 30 || Dia == 29)
    {
        *Mes_sig_p = Mes + 1;
        if (Dia == 30)
            *Dia_sig_p = 2;
        if (Dia == 29)
            *Dia_sig_p = 1;
    }
    else
    {
        *Mes_sig_p = Mes;
        *Dia_sig_p = Dia + 2;
    }
    *Anio_sig_p = Anio;
}

int Desplegar_10(int Dia_sig, int Mes_sig, int Anio_sig)
{
    if (Dia_sig == 0 || Mes_sig == 0 || Anio_sig == 0)
    {
        printf("Ingrese una fecha válida\n");
        return 1;
    }

    else
    {
        if (Dia_sig > 0 && Dia_sig < 10 || Mes_sig > 0 && Mes_sig < 10)
        {
            if (Dia_sig > 0 && Dia_sig < 10 && Mes_sig > 0 && Mes_sig < 10)
                printf("\nLa fecha después de dos días es: 0%d / 0%d / %d\n\n", Dia_sig, Mes_sig, Anio_sig);

            else
            {
                if (Dia_sig > 0 && Dia_sig < 10)
                    printf("\nLa fecha despúes de dos días es: 0%d / %d / %d\n\n", Dia_sig, Mes_sig, Anio_sig);

                else if (Mes_sig > 0 && Mes_sig < 10)
                    printf("\nLa fecha despúes de dos días es: %d / 0%d / %d\n\n", Dia_sig, Mes_sig, Anio_sig);
            }
        }
        else
            printf("\nLa fecha despúes de dos días es: %d / %d / %d\n\n", Dia_sig, Mes_sig, Anio_sig);
        return 0;
    }
}

// Undécimo : Potencia de x número a n potencia.

void Problema_11(void)
{
    int Exp, Num, Pot;
    printf("\n11) Potencia de x número a n potencia.\n\n");
    do
    {
        Solicitar_11(&Exp, &Num);
    } while (Validar_11(Exp, Num) == 1);
    Pot = Potencia_11(Num, Exp);
    Desplegar_11(Pot);
}

void Solicitar_11(int *Exp, int *Num)
{
    printf("\nIngresa la base de la potencia: ");
    scanf("%d", Num);
    __fpurge(stdin);

    printf("Ingresa el exponente de la potencia: ");
    scanf("%d", Exp);
    __fpurge(stdin);

    printf("\n");
}

int Validar_11(int Exp, int Num)
{
    if (Num >= 0 && Exp >= 0)
        return 0;

    else
    {
        if (Num < 0)
            printf("Ingresa una ----base---- positiva.\n");

        if (Exp < 0)
            printf("Ingrese un --exponente-- positivo.\n");

        printf("Vuelva a ingresar los datos.\n");

        return 1;
    }
}

int Potencia_11(int Num, int Exp)
{
    int i = 0;
    int Pot = 1;
    if (Exp == 0)
        Pot = 1;
    else
    {
        while (i < Exp)
        {
            Pot = Pot * Num;
            i++;
        }
    }

    return Pot;
}

void Desplegar_11(int Pot)
{
    printf("El resultado de la potencia es : %d", Pot);
}

// Duodécimo : Imprimir triángulos rectángulos.

void Problema_12(void)
{
    printf("\n12) Imprimir triángulos rectángulos. \n\n");
    Triangulo_12_1();
    Triangulo_12();
}

void Triangulo_12(void)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void Triangulo_12_1(void)
{
    int i, j;

    printf("\n");

    for (i = 10; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

// Décimo tercero : Adivina el número Aleatorio.

void Problema_13(void)
{
    int Num, Aleatorio;
    int i = 1;
    Aleatorio_13(&Aleatorio);
    printf("\n13) Adivina el número Aleatorio entre 7 y 21.\n\n");
    do
    {
        Solicitar_13(i, &Num);

        if (Num == Aleatorio)
            printf(" ------- ✧◝(⁰▿⁰)◜✧˖° G A N A S T E ✧◝(⁰▿⁰)◜✧˖° -------\n");
        else if (i < 5)
            printf("\t ¡ N o ! Inténtalo de nuevo ... \n\n");
        else
        {
            printf(" ------- (╥﹏╥) P E R D I S T E (╥﹏╥) -------\n");
            printf("\n\nEl número era : %d\n", Aleatorio);
        }
        i++;
    } while (i <= 5 && Num != Aleatorio);
}

void Solicitar_13(int i, int *Num)
{
    printf("Intento #%d = ", i);
    scanf("%d", Num);
    __fpurge(stdin);

    printf("\n");
}

void Aleatorio_13(int *Aleatorio)
{
    srand(time(NULL));
    *Aleatorio = 7 + rand() % 21;
}

// Décimo cuarto : Imprime un rectángulo.

void Problema_14(void)
{
    int Base, Altura;
    char Caracter;
    printf("\n14) Imprime un rectángulo.\n\n");
    do
    {
        Solicitar_14(&Base, &Altura, &Caracter);

        if (Base < 0 || Altura < 0)
            printf("Ingresa un número válido.\n");
    } while (Base < 0 || Altura < 0);

    Cuadrado_14(Base, Altura, Caracter);
}

void Solicitar_14(int *Base, int *Altura, char *Caracter)
{
    printf("\nBase : ");
    scanf("%d", Base);
    __fpurge(stdin);

    printf("Altura : ");
    scanf("%d", Altura);
    __fpurge(stdin);

    printf("Carácter : ");
    scanf("%c", Caracter);
    __fpurge(stdin);

    printf("\n");
}

void Cuadrado_14(int Base, int Altura, char Caracter)
{
    int i, j;
    for (i = 0; i < Altura; i++)
    {
        for (j = 0; j < Base; j++)
        {
            printf("%c ", Caracter);
        }
        printf("\n");
    }
}

// Décimo quinto : Imprime un triángulo.

void Problema_15(void)
{
    int Base;
    printf("\n15) Imprime un triángulo.\n\n");
    do
    {
        Solicitar_15(&Base);
        if (Base > 10 || Base < 0)
            printf("Ingresa un número válido\n");
    } while (Base > 10 || Base < 0);

    Desplegar_15(Base);
}

void Solicitar_15(int *Base)
{
    printf("\nDame cantidad de letras a desplegar: ");
    scanf("%d", Base);
    __fpurge(stdin);
}

void Contador_15(int Base, int i)
{
    int con1;
    char letra = 'x';

    for (con1 = 0; con1 < i; con1++)
    {
        printf("%c. ", letra);

        if (con1 < 3 || con1 > 2)
            letra++;

        if (con1 == 2)
            letra = letra - 26;
    }
}

void Desplegar_15(int Base)
{
    int i;
    for (i = 0; i <= Base; i++)
    {
        Contador_15(Base, i);
        printf("\n");
    }
}