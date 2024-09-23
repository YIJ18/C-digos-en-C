#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define MAX 6

void inicializar(int tablero[MAX][MAX], int Tamano_tablero);
void disponibilidad(int casillas, int tablero[MAX][MAX], int Tamano_tablero);
void imprimir_tablero(int tablero[MAX][MAX], int Tamano_tablero);
void reversi(int tablero[MAX][MAX], int Tamano_tablero, char Caracter_1, char Caracter_2);
void coordenas_guardado(int tablero[MAX][MAX], int *x, int *y, int Tamano_tablero, int coordenadas);

void Imprimir_tablero(int Tamano_tablero, int Tablero[MAX][MAX], char Caracter_1, char Caracter_2);
void Celdas_disponibles(int Tamano_tablero, int Tablero_1[MAX][MAX]);
void Fichas_blanca(char Caracter_1, int j, int b);
void Fichas_negras(char Caracter_2, int j, int b);
void Imprimir_taches(int j, int b, int a, int i);

int main(int argc, char *argv[])
{
    int tablero[MAX][MAX], Tamano_tablero = 6;
    char Caracter_1 = 'E';
    char Caracter_2 = 't';
    inicializar(tablero, Tamano_tablero);
    reversi(tablero, Tamano_tablero, Caracter_1, Caracter_2);
    return 0;
}

void inicializar(int tablero[MAX][MAX], int Tamano_tablero)
{
    int i, j;
    for (i = 0; i < Tamano_tablero; i++)
        for (j = 0; j < Tamano_tablero; j++)
            tablero[i][j] = 0;

    tablero[Tamano_tablero / 2][Tamano_tablero / 2] = 1;
    tablero[Tamano_tablero / 2][Tamano_tablero / 2 - 1] = 2;
    tablero[Tamano_tablero / 2 - 1][Tamano_tablero / 2 - 1] = 1;
    tablero[Tamano_tablero / 2 - 1][Tamano_tablero / 2] = 2;
}

void coordenas_guardado(int tablero[MAX][MAX], int *x, int *y, int Tamano_tablero, int coordenadas)
{
    do
    {
        printf("\nIngresa una coordena en (x,y): ");
        __fpurge(stdin);
        *x = -1;
        *y = -1;
        coordenadas = scanf("%d,%d", x, y);
        printf("<<%d>>", coordenadas);
        if (tablero[*y][*x] != 0 || *x >= Tamano_tablero || *y >= Tamano_tablero || *x == -1 || *y == -1)
            coordenadas = 0;
        printf("<<%d>>", coordenadas);
    } while (coordenadas != 2);
}

void imprimir_tablero(int tablero[MAX][MAX], int Tamano_tablero)
{
    int i, j;
    for (i = 0; i < Tamano_tablero; i++)
    {
        for (j = 0; j < Tamano_tablero; j++)
        {
            printf(" %d ", tablero[i][j]);
        }
        printf("\n");
    }
}

void disponibilidad(int casillas, int tablero[MAX][MAX], int Tamano_tablero)
{
    int i, j;
    casillas = 0;
    for (i = 0; i < Tamano_tablero; i++)
    {
        for (j = 0; j < MAX; j++)
            if (tablero[i][j] == 0)
            {
                casillas++;
            }
    }
}

void reversi(int tablero[MAX][MAX], int Tamano_tablero, char Caracter_1, char Caracter_2)
{
    int i, j, turno = 1, coordenadas, x, y, casillax, casillay, conTurno = 0, ficha, casillasDisponibles = 0;

    do
    {
        system("clear");
        if (turno == 2)
            turno = 1;
        else
            turno = 2;

        printf("Turno: %d\n", turno);
        imprimir_tablero(tablero, Tamano_tablero);
        Imprimir_tablero(Tamano_tablero, tablero, Caracter_1, Caracter_2);
        disponibilidad(casillasDisponibles, tablero, Tamano_tablero);
        coordenas_guardado(tablero, &x, &y, Tamano_tablero, coordenadas);

        tablero[y][x] = turno;
        ficha = 0;
        casillay = i;
        casillay = y;
        casillax = j;
        casillax = x;

        while (i < Tamano_tablero - 1 && j < Tamano_tablero - 1 && i >= 0 && j >= 0)
        {
            i++;
            j++;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = j = Tamano_tablero;
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
                i = j = Tamano_tablero;
            }
        }

        i = casillay;
        y = casillay;
        j = casillax;
        x = casillax;
        while (i < Tamano_tablero && j < Tamano_tablero && i > 0 && j > 0)
        {
            i--;
            j--;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = j = Tamano_tablero;
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
                i = j = Tamano_tablero;
            }
        }
        i = casillay;
        y = casillay;
        j = casillax;
        x = casillax;
        while (i < Tamano_tablero && j < Tamano_tablero && i > 0 && j >= 0)
        {
            i--;
            j++;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = j = Tamano_tablero;
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
                i = j = Tamano_tablero;
            }
        }
        i = casillay;
        y = casillay;
        j = casillax;
        x = casillax;
        while (i < Tamano_tablero && j < Tamano_tablero && i >= 0 && j > 0)
        {
            i++;
            j--;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = j = Tamano_tablero;
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
                i = j = Tamano_tablero;
            }
        }
        i = casillay;
        y = casillay;
        j = casillax;
        x = casillax;
        while (i < Tamano_tablero && i > 0)
        {
            i--;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = Tamano_tablero;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    y--;
                } while (tablero[y][x] != turno);
                i = j = Tamano_tablero;
            }
        }
        i = casillay;
        y = casillay;
        j = casillax;
        x = casillax;
        while (i < Tamano_tablero && i >= 0)
        {
            i++;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                i = Tamano_tablero;
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
        i = casillay;
        y = casillay;
        j = casillax;
        x = casillax;
        while (j < Tamano_tablero && j >= 0)
        {
            j++;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                j = Tamano_tablero;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    x++;
                } while (tablero[y][x] != turno);
                i = j = Tamano_tablero;
            }
        }
        i = casillay;
        y = casillay;
        j = casillax;
        x = casillax;
        while (j < Tamano_tablero && j > 0)
        {
            j--;
            printf("\n<<%d<<%d", i, j);
            if (tablero[i][j] == 0)
                j = Tamano_tablero;
            if (tablero[i][j] != turno)
                ficha = 1;
            else if (ficha == 1 && tablero[i][j] == turno)
            {
                do
                {
                    tablero[y][x] = turno;
                    x--;
                } while (tablero[y][x] != turno);
                i = j = Tamano_tablero;
            }
        }
        getchar();
    } while (casillasDisponibles != 1);
}

/*-------------Funciones para el tablero-------------*/
void Imprimir_tablero(int Tamano_tablero, int Tablero[MAX][MAX], char Caracter_1, char Caracter_2)
{
    int i, j, a, b, numeros = 0;

    for (i = 0; i < Tamano_tablero; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (a = 0; a < Tamano_tablero; a++)
            {
                for (b = 0; b < 4; b++)
                {
                    if (Tablero[i][a] == 1)
                    {
                        Fichas_blanca(Caracter_1, j, b);
                    }
                    else if ( Tablero[i][a] == 2)
                    {
                        Fichas_negras(Caracter_2, j, b);
                    }
                    else if ( Tablero[i][a] == 3)
                    {
                      // Imprimir_taches(int j, int b, int a, int i);
                    }
                    else if ((a + i) % 2 == 0)
                    {
                        printf(" - ");
                    }
                    else
                    {
                        printf("   ");
                    }
                }
                printf(" | ");
            }
            printf("\n");
        }

        for (a = 0; a <= Tamano_tablero * 4; a++)
        {
            printf("----");
        }
        printf("\n");
    }
}

void Fichas_blanca(char Caracter_1, int j, int b)
{
    if (j == 1 || j == 2 || b == 1 || b == 2)
        printf(" %c ", Caracter_1);
    else
        printf("   ");
}

void Fichas_negras(char Caracter_2, int j, int b)
{
    if (j == 0 || j == 3 || b == 0 || b == 3)
    {
        if (j == 0 && b == 0 || j == 0 && b == 3 || j == 3 && b == 0 || j == 3 && b == 3)
            printf("   ");
        else
            printf(" %c ", Caracter_2);
    }
    else
        printf("   ");
}

void Imprimir_taches(int j, int b, int a, int i)
{
    if (j == 0 || b == 0 || j == 3 || b == 3)
    {
        if ((a + i) % 2 == 0 && a != 0)
        {
            printf(" - ");
        }
        else
        {
            printf("   ");
        }
    }
    else
    {
        printf(" x ");
    }
}
