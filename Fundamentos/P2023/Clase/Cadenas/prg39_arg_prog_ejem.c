/*
  @file: prg39_arg_prog_ejemplo.c
  @brief: Argumentos de programas
  @details: Este programa hace una breve ejemplificación de los argumentos de programa
  @authors: Adriana Lorena Fajardo Martos
  @date: 27-abril-2023
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

int main(int argc, char *argv[])
{
    int i;

    printf("Los argumentos de programa recibidos por la función principal son:\n\n");

    printf("El valor de argc es: %d\n", argc);

    for (i = 0; i < argc; i++)
    {
        printf("argv[%d] -> %p\n", i, argv[i]);
        printf("El valor del renglón es: ");
        puts(argv[i]);
    }

    if (argc == 4)
    {
        if (strcmp(argv[3], "Ibero") == 0)
            printf("El cuarto argumento es Ibero.\n");
        else
            printf("El cuarto argumento no es Ibero.\n");
    }
    else
        printf("La cantidad de argumentos dados son: %d\n", argc);

    return 0;
}