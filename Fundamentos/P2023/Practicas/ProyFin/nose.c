#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 6

void reversi();
void Poner_tache();

int main(void)
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
        Poner_tache(turno, tablero);
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
                printf(" %d", tablero[i][j]);
            printf(" | %d ", i);
            printf("\n");
        }

        do
        {
            printf("\nIngresa una coordena en (x,y): ");
            __fpurge(stdin);
            x = y = -1;
            coordenadas = scanf("%d,%d", &x, &y);
            printf("<<%d>>", coordenadas);
            if (tablero[y][x] != 3)
                coordenadas = 0;
            printf("<<%d>>", coordenadas);
        } while (coordenadas != 2);
        tablero[y][x] = turno;

        ficha = 0;
        casillay = i = y;
        casillax = j = x;
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

void Poner_tache(int turno, int tablero[MAX][MAX])
{
    int i, j, coordenadas, x, y, casillax, casillay, conTurno = 0, ficha = 0, casillasDisponibles = 0;
    for (x = 0; x < MAX; x++)
    {
        for (y = 0; y < MAX; y++)
        {
            if (tablero[y][x] == 3)
            {
                tablero[y][x] = 0;
            }
        }
    }

    for (x = 0; x < MAX; x++)
    {
        for (y = 0; y < MAX; y++)
        {
            /*----------Izquierda---------------*/
            if (tablero[y][x] == turno)
            {
                ficha = 0;
                i = y;
                j = x;
                while (j < MAX && j > 0)
                {
                    j--;
                    if (tablero[i][j] == 0)
                        j = MAX;
                    else if (tablero[i][j] != turno && tablero[i][j] != 3)
                        ficha = 1;
                    if (tablero[i][j - 1] == 0 && ficha == 1)
                    {
                        tablero[i][j - 1] = 3;
                        i = j = MAX;
                    }
                }
                /*----------Derecha---------------*/
                ficha = 0;
                i = y;
                j = x;
                while (j < MAX && j > 0)
                {
                    j++;
                    if (tablero[i][j] == 0)
                        j = MAX;
                    else if (tablero[i][j] != turno && tablero[i][j] != 3)
                        ficha = 1;
                    if (tablero[i][j + 1] == 0 && ficha == 1)
                    {
                        tablero[i][j + 1] = 3;
                        i = j = MAX;
                    }
                }
                /*----------Abajo---------------*/
                ficha = 0;
                i = y;
                j = x;
                while (i < MAX && i > 0)
                {
                    i++;
                    if (tablero[i][j] == 0)
                        i = MAX;
                    else if (tablero[i][j] != turno && tablero[i][j] != 3)
                        ficha = 1;
                    if (tablero[i + 1][j] == 0 && ficha == 1)
                    {
                        tablero[i + 1][j] = 3;
                        i = j = MAX;
                    }
                }
                /*----------Arriba---------------*/
                ficha = 0;
                i = y;
                j = x;
                while (i < MAX && i > 0)
                {
                    i--;
                    if (tablero[i][j] == 0)
                        i = MAX;
                    else if (tablero[i][j] != turno && tablero[i][j] != 3)
                        ficha = 1;
                    if (tablero[i - 1][j] == 0 && ficha == 1)
                    {
                        tablero[i - 1][j] = 3;
                        i = j = MAX;
                    }
                }
                /*----------Diagonal arriba izquierda---------------*/
                ficha = 0;
                i = y;
                j = x;
                while (i < MAX && i > 0 && j < MAX && j > 0)
                {
                    i--;
                    j--;
                    if (tablero[i][j] == 0)
                    {
                        i = MAX;
                        j = MAX;
                    }

                    else if (tablero[i][j] != turno && tablero[i][j] != 3)
                        ficha = 1;
                    if (tablero[i - 1][j - 1] == 0 && ficha == 1)
                    {
                        tablero[i - 1][j - 1] = 3;
                        i = j = MAX;
                    }
                }
            }
        }
    }
}
