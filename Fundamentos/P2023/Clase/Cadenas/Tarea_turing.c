/*
  @file: Tarea_turing.c
  @brief: La misión es descifrar lo que viene codificado en la siguiente matriz.
  @details: Para descifrar el mensaje.
    1) La matriz tiene un tamaño de 5 columnas x 20 renglones.

    2) Para los renglones que son pares, debes de restar 3 unidades.

    3) Para los renglones que son impares, debes de sumar 2 unidades

  @author: Iris Yulit Jasso  Cortes
  @date: 20-abril-2023
*/

#include <stdio.h>

void Imprimir(char Datos[20][5]);
void Descifrar(char Datos[20][5], char Descifrado[20][5]);

int main(void)
{
    char Descifrado[20][5];
    char Datos[20][5] = {{"Krod1"}, {"Cqrc]"}, {"hvbxq"}, {"chcpa"}, {"lflrb"}, {"bc]am"}, {"glilf"}, {"_agml"}, {"-----"}, {"Qg]jm"}, {"judvb"}, {"pcqmj"}, {"yhubh"}, {"j]pmk"}, {"shfde"}, {"cx_q*"}, {"vlhqw"}, {"crc]m"}, {"ujxoo"}, {"mqm,,"}};

    printf("\n\n----- Mensaje a descifrar -----\n\n");
    Imprimir(Datos);
    Descifrar(Datos, Descifrado);
    printf("----- Mensaje descifrado -----\n\n");
    Imprimir(Descifrado);
    return 0;
}

void Imprimir(char Datos[20][5])
{
    int i, j;
    // Impresión arreglo
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", Datos[i][j]);
        }
    }
    printf("\n\n");
}

void Descifrar(char Datos[20][5], char Descifrado[20][5])
{
    int i, j;
    // se resta 3 a los renglones pares y se le suma tres a los impares
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i % 2 == 0)
                Descifrado[i][j] = Datos[i][j] - 3;
            if (i % 2 != 0)
                Descifrado[i][j] = Datos[i][j] + 2;
        }
    }
}