/*
@file: practica3.c
@brief: Esta practica conta de un juego llamado reversi
@details:

@author: Iris Yulit Jasso Cortes
@date: 18-Abril-2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#define MAX 12
#define MIN 6
void inicializar_tablero ();
void reversi();
int main (void)
{
    reversi();
    return 0;
}

void reversi()
{
    int i, j, turno = 1, tablero[MAX][MAX], coordenadas, x, y, casillax, casillay, conTurno = 0, ficha, casillasDisponibles = 0;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            tablero[i][j] = 0;

    tablero[MAX / 2][MAX / 2] = 1;
    tablero[MAX / 2][MAX / 2 - 1] = 2;
    tablero[MAX / 2 - 1][MAX / 2 - 1] = 1;
    tablero[MAX / 2 - 1][MAX / 2] = 2;

    do
    {
        // Define turnos
        system("clear");
        if (turno == 2)
            turno = 1;
        else
            turno = 2;

        printf("Turno: %d\n", turno);

        for (i = 0; i < MAX; i++)
            printf(" %d", i);
        printf("\n");
        for (i = 0; i < MAX; i++)
            printf(" -");

        printf("\n");
        casillasDisponibles = 0;

        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
                if (tablero[i][j] == 0)
                {
                    casillasDisponibles++;
                    printf(" *");
                }
                else
                    printf(" %d", tablero[i][j]);
            printf(" | %d ", i);
            printf("\n");
        }
        // ingresa coordenadas
        do
        {
            printf("\nIngresa una coordena en (x,y): ");
            __fpurge(stdin);
            x = y = -1;
            coordenadas = scanf("%d,%d", &x, &y);
            printf("<<%d>>", coordenadas);
            if (tablero[y][x] != 0 || x >= MAX || y >= MAX || x == -1 || y == -1)
                coordenadas = 0;
            printf("<<%d>>", coordenadas);
        } while (coordenadas != 2);

        tablero[y][x] = turno;
        ficha = 0;
        casillay = i = y;
        casillax = j = x;

        // Primer caso
        while (i < MAX - 1 && j < MAX - 1 && i >= 0 && j >= 0)
        {
            i++;
            j++;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = j = MAX;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    x++;
                    y++;
                } while (tablero[y][x] != turno);
                i = j = MAX;
            }
        }
        // Segundo caso
        i = y = casillay;
        j = x = casillax;
        while (i < MAX && j < MAX && i > 0 && j > 0)
        {
            i--;
            j--;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = j = MAX;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    x--;
                    y--;
                } while (tablero[y][x] != turno);
                i = j = MAX;
            }
        }
        // Tercer caso
        i = y = casillay;
        j = x = casillax;
        while (i < MAX && j < MAX && i > 0 && j >= 0)
        {
            i--;
            j++;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = j = MAX;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    x++;
                    y--;
                } while (tablero[y][x] != turno);
                i = j = MAX;
            }
        }
        // Cuarto caso
        i = y = casillay;
        j = x = casillax;
        while (i < MAX && j < MAX && i >= 0 && j > 0)
        {
            i++;
            j--;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = j = MAX;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    x--;
                    y++;
                } while (tablero[y][x] != turno);
                i = j = MAX;
            }
        }
        // Quinto caso
        i = y = casillay;
        j = x = casillax;
        while (i < MAX && i > 0)
        {
            i--;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = MAX;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    y--;
                } while (tablero[y][x] != turno);
                i = j = MAX;
            }
        }
        // Sexto caso
        i = y = casillay;
        j = x = casillax;
        while (i < MAX && i >= 0)
        {
            i++;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = MAX;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    y++;
                } while (tablero[y][x] != turno);
                i = j = MAX;
            }
        }
        // Septimo caso
        i = y = casillay;
        j = x = casillax;
        while (j < MAX && j >= 0)
        {
            j++;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                j = MAX;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    x++;
                } while (tablero[y][x] != turno);
                i = j = MAX;
            }
        }
        // Octavo caso
        i = y = casillay;
        j = x = casillax;
        while (j < MAX && j > 0)
        {
            j--;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                j = MAX;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    x--;
                } while (tablero[y][x] != turno);
                i = j = MAX;
            }
        }
        getchar();
    } while (casillasDisponibles != 1);
}
