#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 12

/*-------------Funciones para el tablero trasero-------------*/
void inicializar(int tablero[MAX][MAX], int Tamano_tablero);
void disponibilidad(int casillas, int tablero[MAX][MAX], int Tamano_tablero);
void imprimir_tablero(int tablero[MAX][MAX], int Tamano_tablero);
int reversi(int tablero[MAX][MAX], int Tamano_tablero, char Caracter_1, char Caracter_2);

/*-------------Funciones para el tablero trasero-------------*/
int coordenas_guardado(int tablero[MAX][MAX], int *x, int *y, int Tamano_tablero, int coordenadas, int turno, int a, int b);
void Contar_fichas(int tablero[MAX][MAX], int Tamano_tablero, int *Ficha_t, int *Ficha_e);

/*-------------Funciones para el tablero visual-------------*/
void Imprimir_tablero(int Tamano_tablero, int Tablero[MAX][MAX], char Caracter_1, char Caracter_2);
void Celdas_disponibles(int Tamano_tablero, int Tablero_1[MAX][MAX]);
void Fichas_blanca(char Caracter_1, int j, int b);
void Fichas_negras(char Caracter_2, int j, int b);
void Imprimir_taches(int j, int b, int a, int i);

/*-------------Lectura desde terminal-------------*/
void Lectura_terminal(char Usuarios[5][20], char Contrasenas[5][20]);
void Instrucciones(char Usuarios[5][20], int i, int argc);

int main(int argc, char *argv[])
{
    /*-------------Variables para el tablero-------------*/
    int tablero[MAX][MAX], Tamano_tablero = 6, Coordenadas_t[100][5], Coordenadas_e[100][5];
    char Caracter_1 = 'E';
    char Caracter_2 = 't';

    /*-------------Variables para lectura desde terminal-------------*/
    char Usuarios[5][20];
    char Contrasenas[5][20];
    char Terminal[3][21];
    int Tamano;
    int i;

    if (argc != 1)
    {
        Lectura_terminal(Usuarios, Contrasenas);
        if (argc >= 3)
        {
            for (i = 0; i < 5; i++)
            {
                if (strcmp(Usuarios[i], argv[1]) == 0)
                {

                    if (strcmp(Contrasenas[i], argv[2]) == 0)
                    {
                    }
                    else
                    {
                        printf("Error: Opción incorrecta.\n");
                        return 0;
                    }
                }
            }
            if (argc == 4)
            {
                sscanf(argv[3], "-%d", &Tamano);
                if (Tamano == 1)
                {
                    Tamano_tablero = 6;
                }
                else if (Tamano == 2)
                {
                    Tamano_tablero = 8;
                }
                else if (Tamano == 3)
                {
                    Tamano_tablero = 10;
                }
                else if (Tamano == 4)
                {
                    Tamano_tablero = 12;
                }
                else
                {
                    printf("No ingresaste un tamaño válido");
                    return 0;
                }
            }
        }
        else
        {
            printf("Ingresa una contraseña\n");
            return 0;
        }
    }

    Instrucciones(Usuarios, i, argc);
    system("clear");
    inicializar(tablero, Tamano_tablero);
    reversi(tablero, Tamano_tablero, Caracter_1, Caracter_2);

    return 0;
}

void Instrucciones(char Usuarios[5][20], int i, int argc)
{
    int ID;
    srand(time(NULL));
    ID = 1000 + rand() % (9999 + 1 - 1000);
    printf("\n\n\n╔═══════════════════════════════════╗\n");
    printf("║   Bienvenido al juego “Reversi”   ║\n");
    printf("╚═══════════════════════════════════╝\n");
    if (argc != 1)
    {
        printf("║ ID de usuario: %d               ║\n", ID);
        printf("║ Usuario: %s                     ║\n", Usuarios[i]);
        printf("╚═══════════════════════════════════╝\n");
    }
    printf("\n\n Ingrese <enter> para continuar.\n");
    getchar();
    system("clear");
}

void Lectura_terminal(char Usuarios[5][20], char Contrasenas[5][20])
{
    /*-------------------------Usuarios------------------------------------*/
    strcpy(Usuarios[0], "Iris");
    strcpy(Usuarios[1], "Adri");
    strcpy(Usuarios[2], "YIJC");
    strcpy(Usuarios[3], "Dani");
    strcpy(Usuarios[4], "Inge");
    strcpy(Usuarios[5], "Chat");
    /*-------------------------Contraseñas-----------------------------------*/
    strcpy(Contrasenas[0], "Jasso");
    strcpy(Contrasenas[1], "Fajardo");
    strcpy(Contrasenas[2], "1504");
    strcpy(Contrasenas[3], "2920");
    strcpy(Contrasenas[4], "reversi");
    strcpy(Contrasenas[4], "1234");
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

int coordenas_guardado(int tablero[MAX][MAX], int *x, int *y, int Tamano_tablero, int coordenadas, int turno, int a, int b)
{
    int num, c;
    char Hoja[10], letra;
    char Coordenadas_t[10][100], Coordenadas_e[10][100];
    do
    {
        coordenadas = 2;
        printf("\nIngresa una coordena en (A1): ");
        *x = -1;
        *y = -1;

        scanf("%s", Hoja);
        if (strlen(Hoja) > 10)
        {
            printf("Error: debe ingresar exactamente dos caracteres seguidos.\n");
            coordenadas = 0;
        }
        else if (strcmp(Hoja, "historia") == 0)
        {
            printf("Tiros de la ficha t\n");
            for (c = 0; c < b; c++)
            {
                printf("%s\n", Coordenadas_t[c]);
            }
            printf("Tiros de la ficha e\n");
            for (c = 0; c < a; c++)
            {
                printf("%s\n", Coordenadas_e[c]);
            }
            getchar();
            return 2;
        }
        else if (strcmp(Hoja, "terminar") == 0)
        {
            return 1;
        }
        else if (sscanf(Hoja, "%c%d", &letra, &num) == 2)
        {
            // 2 es t, 1 es e
            __fpurge(stdin);
            *x = letra - 65;
            *y = num - 1;
            if (tablero[*y][*x] != 0 || *x >= Tamano_tablero || *y >= Tamano_tablero || *x == -1 || *y == -1)
            {
                printf("Error: Ingrese un coordenada válida.");
                coordenadas = 0;
            }
            else
            {
                if (turno == 2)
                {
                    sprintf(Coordenadas_t[b], "%c%d", letra, num);
                }
                else if (turno == 1)
                {
                    sprintf(Coordenadas_e[a], "%c%d", letra, num);
                    printf("sprintf, coordenada e = %s", Coordenadas_e[a]);
                    getchar();
                }
            }
        }
        else
        {
            printf("Error: No incluyo ninguna opción válida.");
        }

    } while (coordenadas != 2);
    printf("Soy el contador a, tengo el valor de %d\n", a);
    printf("Soy el contador b, tengo el valor de %d\n", b);
    return 0;
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
        for (j = 0; j < Tamano_tablero; j++)
            if (tablero[i][j] == 0)
            {
                casillas++;
            }
    }
}

int reversi(int tablero[MAX][MAX], int Tamano_tablero, char Caracter_1, char Caracter_2)
{
    int i, j, coordenadas, x, y, casillax, casillay;
    int turno = 1, conTurno = 0, casillasDisponibles = 0, ficha = 0;
    int Coordenadas_t[2][100], Coordenadas_e[2][100];
    int Ficha_t = 0, Ficha_e = 0, terminar_programa;
    char Coordenadas_guardar_t[10][100], Coordenadas_guardar_e[10][100];
    int Contador_de_coordenadas = 0;
    int a, b, c, count_t = 0, count_e = 0;
    {
        system("clear");
        Contar_fichas(tablero, Tamano_tablero, &Ficha_t, &Ficha_e);

        // 2 es t, 1 es e
        if (turno == 2)
        {
            printf("Turno: %c\n", Caracter_1);
            printf("Cuentas con < %d > fichas\n", Ficha_t);
            printf("Tu oponente cuenta con < %d >\n", Ficha_e);
            count_t++;
            turno = 1;
        }

        else
        {
            printf("Turno: %c\n", Caracter_2);
            printf("Cuentas con < %d > fichas\n", Ficha_e);
            printf("Tu oponente cuenta con < %d >\n", Ficha_t);
            count_e++;
            turno = 2;
        }

        // imprimir_tablero(tablero, Tamano_tablero);
        Imprimir_tablero(Tamano_tablero, tablero, Caracter_1, Caracter_2);
        disponibilidad(casillasDisponibles, tablero, Tamano_tablero);
        terminar_programa = coordenas_guardado(tablero, &x, &y, Tamano_tablero, coordenadas, turno, count_e, count_t);

        if (terminar_programa == 1)
        {
            return 0;
        }
        else if (terminar_programa == 2)
        {
            coordenas_guardado(tablero, &x, &y, Tamano_tablero, coordenadas, turno, count_e, count_t);
        }

        // CASO 1
        tablero[y][x] = turno;
        ficha = 0;
        casillay = i = y;
        casillax = j = x;
        while (i < Tamano_tablero - 1 && j < Tamano_tablero - 1 && i >= 0 && j >= 0)
        {
            i++;
            j++;
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

        // CASO 2
        i = y = casillay;
        j = x = casillax;
        while (i < Tamano_tablero && j < Tamano_tablero && i > 0 && j > 0)
        {
            i--;
            j--;
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
        // CASO 3
        i = y = casillay;
        j = x = casillax;
        while (i < Tamano_tablero && j < Tamano_tablero && i > 0 && j >= 0)
        {
            i--;
            j++;
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
        // CASO 4
        i = y = casillay;
        j = x = casillax;
        while (i < Tamano_tablero && j < Tamano_tablero && i >= 0 && j > 0)
        {
            i++;
            j--;
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
        // CASO 5
        i = y = casillay;
        j = x = casillax;
        while (i < Tamano_tablero && i > 0)
        {
            i--;
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
        // CASO 6
        i = y = casillay;
        j = x = casillax;
        while (i < Tamano_tablero && i >= 0)
        {
            i++;
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
                i = j = Tamano_tablero;
            }
        }
        // CASO 7
        i = y = casillay;
        j = x = casillax;
        while (j < Tamano_tablero && j >= 0)
        {
            j++;
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
        // CASO 8
        i = y = casillay;
        j = x = casillax;
        while (j < Tamano_tablero && j > 0)
        {
            j--;

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
    }
    while (casillasDisponibles != 1 || Ficha_t == 0 || Ficha_e == 0)
        ;
}

void Imprimir_tablero(int Tamano_tablero, int Tablero[MAX][MAX], char Caracter_1, char Caracter_2)
{
    int i, j, a, b, numeros = 1;
    char Letra = 'A';
    printf("\n");
    for (a = 0; a <= Tamano_tablero * 4; a++)
    {
        if (a % 4 == 0 && a != 0)
            printf("%c     ", Letra++);
        else
            printf("   ");
    }
    printf("\n");
    for (a = 0; a < Tamano_tablero * 4; a++)
    {
        printf("----");
    }
    printf("\n");
    for (i = 0; i < Tamano_tablero; i++)
    {
        if (numeros < 10)
            printf("  %d   |", numeros++);
        else if (numeros > 9)
            printf("  %d  |", numeros++);
        for (j = 0; j < 4; j++)
        {
            if (j % 4 != 0)
            {
                printf("      |");
            }
            for (a = 0; a < Tamano_tablero; a++)
            {
                for (b = 0; b < 4; b++)
                {
                    if (Tablero[i][a] == 1)
                    {
                        Fichas_blanca(Caracter_1, j, b);
                    }
                    else if (Tablero[i][a] == 2)
                    {
                        Fichas_negras(Caracter_2, j, b);
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

        for (a = 0; a < Tamano_tablero * 4; a++)
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

void Contar_fichas(int tablero[MAX][MAX], int Tamano_tablero, int *Ficha_t, int *Ficha_e)
{
    int i, j, a = 0, b = 0;
    for (i = 0; i < Tamano_tablero; i++)
    {
        for (j = 0; j < Tamano_tablero; j++)
        {
            if (tablero[i][j] == 1)
                a++;
            else if (tablero[i][j] == 2)
                b++;
        }
    }

    *Ficha_t = a;
    *Ficha_e = b;
}
