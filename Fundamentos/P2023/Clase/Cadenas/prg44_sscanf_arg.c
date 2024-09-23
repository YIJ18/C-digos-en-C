/*
  @file: prg44_sscanf_arg.c
  @brief: Determinar si este programa es palindromo o no
  @details: Esta hace la ecuación de segundo grado y válida los coeficientes utilizando la secuencia do-while
  Nota: El usuario va a introducir a travé de la linea de comandos los coeficientes.

  @author: Iris Yulit Jasso Cortes
  @date: 02-Mayo-2023
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

void Uso(void);
int Validar_coeficientes(char *argv[], int *a, int *b, int *c);

int main(int argc, char *argv[])
{
    int a, b, c;
    printf("El contenido de argv = %p", argv);
    if (argc ==  4)
    {
        if ((Validar_coeficientes(argv, &a, &b, &c))==3)
        {
            printf("Se ejecuta la solución de una ecuación de segundo grado con las respectivas válidaciones de los coeficientes");
        }

    }
    else
    {
        if (argc == 2)
        {
            if(strcmp("ayuda", argv[1])==0)
            {
                Uso();
            }
            else
            {
                printf("Opción no válida");
            }
        }
        else
        {
            printf("Opción no válida");
        }
    }
    return 0;
}

void Uso(void)
{
    printf("U S O  D E L  P O G R A M A \n\n");
    printf("Cálculo de una ecuación de segundo grado");
    printf("El usuario debe pasar a través de la linea de comandos los corficientes a, b, c. Estos deben ser enteros.\n");
    printf("El usuario introduce los siguientes comandos:\n");
    printf("<nombre_programa> <a> <b> <c>");
}

int Validar_coeficientes(char *argv[], int *a, int *b, int *c)
{
    int i = 0;
    printf("El contenido de argv = %p", argv);

    if (scanf(argv[1], "% d", a) == 1)
    {
        i++;
    }
    if (scanf(argv[2], "% d", b) == 1)
    {
        i++;
    }
    if (scanf(argv[3]," % d", c) == 1)
    {
        i++;
    }
    return i;
}