/*
@file:ProyectoFinal.c
@brief: Este es el código para jugar reversi
@authors: Andrés Macías, Emilio Rojo, Sebastian Said
@date: 12-mayo-2023

 */

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <stdlib.h>

#define MAX_REN 12
#define MAX_COL 12
#define MIN_COL 6
#define MIN_COL 6
#define MAX_TAB 150 // 4 * 12 = 48
#define MAX_FICHA 5

void Pedir_n(int n, int Minimo, int Maximo);
void CrearTablero(int n, char TablaReal[MAX_REN][MAX_COL]);
void TableroGrande(int n, char Tablero[MAX_TAB][MAX_TAB]);
void Tablero_inicio(int n, char TablaReal[MAX_REN][MAX_COL]);

void Contrasenas(char contrasenias[10][20], char usuarios[10][20]);

void CrearFichas(char FichaBlanca[MAX_FICHA][MAX_FICHA], char FichaNegra[MAX_FICHA][MAX_FICHA]);
void Pedir_Tiro1(int n, char Tiro1[6], int CantFichBlanc, int CantFichNeg, char Tiro2[6], char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB], char Bandera[1], char Coordenadas_1[2][100], char Coordenadas_2[2][100]);
void Cambiar_Tabla1(int n, char Tiro1[6], char Bandera[1], char TablaReal[MAX_REN][MAX_COL], int CantFichBlanc, int CantFichNeg, char Tiro2[6], char Tablero[MAX_TAB][MAX_TAB]);
void Cambiar_Tablero1(int n, char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB]);
void Pedir_Tiro2(int n, char Tiro2[6], int CantFichNeg, int CantFichBlanc, char Tiro1[6], char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB], char Bandera[1], char Coordenadas_1[2][100], char Coordenadas_2[2][100]);
void Cambiar_Tabla2(int n, char Tiro2[6], char Bandera[1], char TablaReal[MAX_REN][MAX_COL], int CantFichBlanc, int CantFichNeg, char Tiro1[6], char Tablero[MAX_TAB][MAX_TAB]);
void Cambiar_Tablero2(int n, char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB]);
void ContarFichas(int n, char TablaReal[MAX_REN][MAX_COL], int *CantFichBlanc, int *CantFichNeg);
void Desplegar_matriz(int n, char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB], char Tiro1[6], char Tiro2[6], int CantFichBlanc, int CantFichNeg);
void Instrucciones(void);
// A Partir de aqui de incluyen las funciones para la lectura desde la terminal/

int main(int argc, char *argv[])
{
    int n, CantFichBlanc, i, CantFichNeg;
    char Bandera[1], TablaReal[MAX_REN][MAX_COL], Tablero[MAX_TAB][MAX_TAB], Tiro1[6], Tiro2[6];
    char valor;
    char *usuario = argv[1];
    char *contrasena = argv[2];
    char Coordenadas_1[2][100], Coordenadas_2[2][100];
    char usuarios[10][20] = {{"ac23amg"}, {"ac23erq"}, {"mc22mag"}, {"lcpf22nva"}, {"lm22kng"}, {"andres"}, {"marco"}, {"\
alejandro"},{"emmanuel"},{"jaime"}};
    char contrasenas[10][20] = {{"verde"}, {"blanco"}, {"azul"}, {"rojo"}, {"amarillo"}, {"naranja"}, {"negro"}, {"morado\
"},  {"gris"},   {"rosa"}};
    int w = 0;
    if (argc == 1)
        Instrucciones();
    if (argc == 2)
    {
        printf("\nDatos incorrectos\n");
    }
    while (w < 10)
    {
        if ((strcmp(argv[1], usuarios[w]) == 0) && (strcmp(argv[2], contrasenas[w]) == 0))
        {
            //      system("clear");
            printf("\nUsuario y contraseña correcta\n¡Bienvenido al juego usuario: %s!\n\n", argv[1]);

            sscanf(argv[4], "-1 %c", &valor);
            sscanf(argv[3], "%d", &n);
            Pedir_n(n, MIN_COL, MAX_COL);

            // n = Pedir_n(MIN_COL, MAX_COL);
            CrearTablero(n, TablaReal);
            TableroGrande(n, Tablero);

            Pedir_Tiro1(n, Tiro1, CantFichBlanc, CantFichNeg, Tiro2, TablaReal, Tablero, Bandera);
            Cambiar_Tabla1(n, Tiro1, Bandera, TablaReal, CantFichBlanc, CantFichNeg, Tiro2, Tablero);
            Cambiar_Tablero1(n, TablaReal, Tablero);
            Desplegar_matriz(n, TablaReal, Tablero, Tiro1, Tiro2, CantFichBlanc, CantFichNeg);

            Cambiar_Tabla2(n, Tiro2, Bandera, TablaReal, CantFichBlanc, CantFichNeg, Tiro1, Tablero);
            Cambiar_Tablero2(n, TablaReal, Tablero);

            ContarFichas(n, TablaReal, &CantFichBlanc, &CantFichNeg);

            Desplegar_matriz(n, TablaReal, Tablero, Tiro1, Tiro2, CantFichBlanc, CantFichNeg);
        }
        else
            w++;
    }

    if (w == 10)
        printf("\nUsuario o contraseña incorrecto.\nVuelve a intentarlo\n\n");
    return 0;
}

void Instrucciones(void)
{
    printf("\n Las instrucciones son las siguientes: Jugaras uno contra uno, podrás moverte en diagonal, ascendente \
y descendentemente; convertirás las fichas de tu opnenete en tus fichas \n");
}

void Pedir_n(int n, int Minimo, int Maximo)
{
    /*   int n;

    printf("Dame un valor entre %d y %d: ", Minimo, Maximo);
    scanf("%d", &n);
    __fpurge(stdin);*/
    if (n > Maximo || n < Minimo)
    {
        printf("El número está fuera de rango. Intenta nuevamente...\n");
        //    Pedir_n(Minimo, Maximo);
    }
    return;
}

void CrearTablero(int n, char TablaReal[MAX_REN][MAX_COL])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {

            if (((i % 2 == 1) && (j % 2 == 1)) || ((i % 2 == 0) && (j % 2 == 0)))
                TablaReal[i][j] = 120; // x en codigo ASCII
            else
                TablaReal[i][j] = 32; // ESPACIO en codigo ASCII
        }
    }
}

void TableroGrande(int n, char Tablero[MAX_TAB][MAX_TAB])
{
    int i, j, k, l, var;
    char a;

    for (i = 0; i < n * 4; i++)
    {
        for (j = 0; j < n * 4; j++)
        {
            if ((i % 8 < 4 && j % 8 < 4) || (i % 8 >= 4 && j % 8 >= 4))
                a = '-';
            else
                a = ' ';
            for (k = i; k < i + 4; k++)
            {

                for (l = j; l < j + 4; l++)
                {
                    Tablero[l][k] = a;
                }
            }
        }
    }
    for (k = n * 2; k < n * 2 + 4; k++)
    {
        for (l = n * 2; l < n * 2 + 4; l++)
        {
            if ((l % 4 == 0 && k % 4 == 0) || (l % 4 == 3 && k % 4 == 3) || (l % 4 == 3 && k % 4 == 0) || (l % 4 == 0 && k % 4 == 3))
                Tablero[k][l] = '-';
            if ((l % 4 == 1 && k % 4 == 0) || (l % 4 == 2 && k % 4 == 0) || (l % 4 == 1 && k % 4 == 3) || (l % 4 == 2 && k % 4 == 3) |\
| (l % 4 == 0 && k % 4 == 1) ||
                (l % 4 == 0 && k % 4 == 2) || (l % 4 == 3 && k % 4 == 1) || (l % 4 == 3 && k % 4 == 2))
                Tablero[k][l] = 'E';
            else
                Tablero[k][l] = ' ';
        }
    }

    for (k = n * 2 - 4; k < n * 2; k++)
    {
        for (l = n * 2 - 4; l < n * 2; l++)
        {
            if ((l % 4 == 0 && k % 4 == 0) || (l % 4 == 3 && k % 4 == 3) || (l % 4 == 3 && k % 4 == 0) || (l % 4 == 0 && k % 4 == 3))
                Tablero[k][l] = '-';
            if ((l % 4 == 1 && k % 4 == 0) || (l % 4 == 2 && k % 4 == 0) || (l % 4 == 1 && k % 4 == 3) || (l % 4 == 2 && k % 4 == 3) |\
| (l % 4 == 0 && k % 4 == 1) ||
                (l % 4 == 0 && k % 4 == 2) || (l % 4 == 3 && k % 4 == 1) || (l % 4 == 3 && k % 4 == 2))
                Tablero[k][l] = 'E';
            else
                Tablero[k][l] = ' ';
        }
    }
    for (k = (n * 2); k < n * 2 + 4; k++)
    {

        for (l = n * 2; l < n * 2 + 4; l++)
        {
            if ((l % 4 == 0 && k % 4 == 0) || (l % 4 == 3 && k % 4 == 3) || (l % 4 == 3 && k % 4 == 0) || (l % 4 == 0 && k % 4 == 3))
                Tablero[k][l] = '-';
            else
                Tablero[k][l] = 't';
        }
    }
}

void Pedir_Tiro1(int n, char Tiro1[6], int CantFichBlanc, int CantFichNeg, char Tiro2[6], char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB], char Bandera[1], char Coordenadas_1[2][100], char Coordenadas_2[2][100])
{
    char letra[1], numero[2];

    printf(" TIRO 1: \n\n");

    printf("Dame la letra de la coordenada:\n");
    fgets(letra, 6, stdin);
    __fpurge(stdin);

    Tiro1[0] = letra[0];

    printf("Dame el numero de la coordenada:\n");
    fgets(numero, 6, stdin);
    __fpurge(stdin);
    if (strcmp(Tiro1, "historia"))
    {
        //despliego coordenadas
    }
    Tiro1[1] = numero[0];

    if (CantFichBlanc < pow(n, 2) / 2)
    {
        Cambiar_Tabla1(n, Tiro1, Bandera, TablaReal, CantFichBlanc, CantFichNeg, Tiro2, Tablero);
        Cambiar_Tablero1(n, TablaReal, Tablero);
        printf(" Hay %d fichas blancas \n", CantFichBlanc);
        Desplegar_matriz(n, TablaReal, Tablero, Tiro1, Tiro2, CantFichBlanc, CantFichNeg);
        Pedir_Tiro2(n, Tiro2, CantFichNeg, CantFichBlanc, Tiro1, TablaReal, Tablero, Bandera);
    }
}

void Cambiar_Tabla1(int n, char Tiro1[6], char Bandera[1], char TablaReal[MAX_REN][MAX_COL], int CantFichBlanc, int CantFichNeg, char Tiro2[6], char Tablero[MAX_TAB][MAX_TAB])
{
    int i, j, k, l;

    if (Tiro1[0] == 'A' || Tiro1[0] == 'B' || Tiro1[0] == 'C' || Tiro1[0] == 'D' || Tiro1[0] == 'E' || Tiro1[0] == '\
F' || Tiro1[0] == 'G' ||
        Tiro1[0] == 'H' || Tiro1[0] == 'I' || Tiro1[0] == 'J' || Tiro1[0] == 'K' || Tiro1[0] == 'L')
    {
        if (strlen(Tiro1) <= n)
        {
            k = Tiro1[0] - 65; // Letra. Le restamos el valor de A en ascii para que tome solo el valor de la letra: A=0\
, B=1, etc.
            l = Tiro1[1] - 49; // numero

            TablaReal[k][l] = 'A';
        }
        else
        {
            printf("ERROR! TIRO FUERA DE RANGO, INTENTE DE NUEVO\n");
            Pedir_Tiro1(n, Tiro1, CantFichBlanc, CantFichNeg, Tiro2, TablaReal, Tablero, Bandera);
            Cambiar_Tabla1(n, Tiro1, Bandera, TablaReal, CantFichBlanc, CantFichNeg, Tiro2, Tablero);
        }
    }
    else
    {
        printf("ERROR! TIRO FUERA DE RANGO, INTENTE DE NUEVO\n");
        Pedir_Tiro1(n, Tiro1, CantFichBlanc, CantFichNeg, Tiro2, TablaReal, Tablero, Bandera);
        Cambiar_Tabla1(n, Tiro1, Bandera, TablaReal, CantFichBlanc, CantFichNeg, Tiro2, Tablero);
    }
}

void Cambiar_Tablero1(int n, char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB])
{
    int i, j, k, l;
    char a, b, c, d;

    for (i = 0; i < n * 4; i++)
    {
        for (j = 0; j < n * 4; j++)
        {
            if (TablaReal[i][j] == 'A' || TablaReal[i][j] == 'B') // Si sale A sabemos que es un espacio Negro
            {
                for (k = i * 4; k < i * 4 + 4; k++)
                {
                    // printf ("\netro al 3er for\n");
                    //  TENEMOS AQUI LA FICHA BLANCA

                    for (l = j * 4; l < j * 4 + 4; l++)
                    {
                        if ((l % 4 == 0 && k % 4 == 0) || (l % 4 == 3 && k % 4 == 3) || (l % 4 == 3 && k % 4 == 0) || (l % 4 =\
= 0 && k % 4 == 3))
                            Tablero[k][l] = '-';
                        if ((l % 4 == 1 && k % 4 == 0) || (l % 4 == 2 && k % 4 == 0) || (l % 4 == 1 && k % 4 == 3) || (l % 4 =\
= 2 && k % 4 == 3) || (l % 4 == 0 && k % 4 == 1) ||
                            (l % 4 == 0 && k % 4 == 2) || (l % 4 == 3 && k % 4 == 1) || (l % 4 == 3 && k % 4 == 2))
                            Tablero[k][l] = 'E';
                        else
                            Tablero[k][l] = ' ';
                    }
                }
            }
        }
    }
}

void Pedir_Tiro2(int n, char Tiro2[6], int CantFichNeg, int CantFichBlanc, char Tiro1[6], char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB], char Bandera[1], char Coordenadas_1[2][100], char Coordenadas_2[2][100])
{
    char letra1[1], numero1[2];

    printf("TIRO 2: \n\n");

    printf("Dame la letra de la coordenada:\n");
    fgets(letra1, 6, stdin);
    __fpurge(stdin);

    Tiro2[0] = letra1[0];

    printf("Dame el numero de la coordenada:\n");
    fgets(numero1, 6, stdin);
    __fpurge(stdin);

    Tiro2[1] = numero1[0];

    if (CantFichNeg < pow(n, 2) / 2)
    {
        Cambiar_Tabla2(n, Tiro2, Bandera, TablaReal, CantFichBlanc, CantFichNeg, Tiro1, Tablero);
        Cambiar_Tablero2(n, TablaReal, Tablero);
        Desplegar_matriz(n, TablaReal, Tablero, Tiro1, Tiro2, CantFichBlanc, CantFichNeg);
        printf(" Hay %d fichas negras \n", CantFichNeg);
        Pedir_Tiro1(n, Tiro1, CantFichBlanc, CantFichNeg, Tiro2, TablaReal, Tablero, Bandera);
    }
}

void Cambiar_Tabla2(int n, char Tiro2[6], char Bandera[1], char TablaReal[MAX_REN][MAX_COL], int CantFichBlanc, int CantFichNeg, char Tiro1[6], char Tablero[MAX_TAB][MAX_TAB])
{
    int i, j, k, l;

    if (Tiro2[0] == 'A' || Tiro2[0] == 'B' || Tiro2[0] == 'C' || Tiro2[0] == 'D' || Tiro2[0] == 'E' || Tiro2[0] == 'F' || Tiro2[0] == 'G' || Tiro2[0] == 'H' || Tiro2[0] == 'I' || Tiro2[0] == 'J' || Tiro2[0] == 'K' || Tiro2[0] == 'L')
    {
        if (strlen(Tiro2) < n)
        {
            k = Tiro2[0] - 65; // Le restamos el valor de A en ascii para que tome solo el valor de la letra: A=0, B=1\
, etc.
            l = Tiro2[1] - 49;

            if (TablaReal[k][l] == 'x')
                Bandera[0] = 'D';
            if (TablaReal[k][l] == ' ')
                Bandera[0] = 'C';

            TablaReal[k][l] = Bandera[0];
        }
        else
        {
            printf("ERROR! TIRO FUERA DE RANGO, INTENTE DE NUEVO\n");
            Pedir_Tiro2(n, Tiro2, CantFichNeg, CantFichBlanc, Tiro1, TablaReal, Tablero, Bandera);
            Cambiar_Tabla2(n, Tiro2, Bandera, TablaReal, CantFichBlanc, CantFichNeg, Tiro1, Tablero);
        }
    }
    else
    {
        printf("ERROR! TIRO FUERA DE RANGO, INTENTE DE NUEVO\n");
        Pedir_Tiro2(n, Tiro2, CantFichNeg, CantFichBlanc, Tiro1, TablaReal, Tablero, Bandera);
        Cambiar_Tabla2(n, Tiro2, Bandera, TablaReal, CantFichBlanc, CantFichNeg, Tiro1, Tablero);
    }
}

void Cambiar_Tablero2(int n, char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB])
{
    int i, j, k, l;
    char a, b, c, d;

    for (i = 0; i < n * 4; i++)
    {
        for (j = 0; j < n * 4; j++)
        {
            if (TablaReal[i][j] == 'C' || TablaReal[i][j] == 'D') // Si sale A sabemos que es un espacio Negro
            {
                for (k = i * 4; k < i * 4 + 4; k++)
                {

                    // TENEMOS AQUI LA FICHA NEGRA

                    for (l = j * 4; l < j * 4 + 4; l++)
                    {
                        if ((l % 4 == 0 && k % 4 == 0) || (l % 4 == 3 && k % 4 == 3) || (l % 4 == 3 && k % 4 == 0) || (l % 4 =\
= 0 && k % 4 == 3))
                            Tablero[k][l] = '-';
                        else
                            Tablero[k][l] = 't';
                    }
                }
            }
        }
    }
}

void ContarFichas(int n, char TablaReal[MAX_REN][MAX_COL], int *CantFichBlanc, int *CantFichNeg)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (TablaReal[i][j] == 'A' || TablaReal[i][j] == 'B')
                CantFichBlanc += 1;
            if (TablaReal[i][j] == 'C' || TablaReal[i][j] == 'D')
                CantFichNeg += 1;
        }
    }
}

void Desplegar_matriz(int n, char TablaReal[MAX_REN][MAX_COL], char Tablero[MAX_TAB][MAX_TAB], char Tiro1[6], char Tiro2[6], int CantFichBlanc, int CantFichNeg)
{
    int x, y;
    /*
      x -> Columnas
      y -> Renglones
     */

    // Los numeros se van a desplegar por renglon

    //   printf("%c", Tiro1[0]);
    //   printf("%c\n", Tiro1[1]);
    printf("Hay un total de %d Fichas blancas. \n", CantFichBlanc);
    printf("Hay un total de %d Fichas negras. \n", CantFichNeg);

    for (y = 0; y < n; y++)
    {
        for (x = 0; x < n; x++)
        {
            printf("%c\t", TablaReal[x][y]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    for (y = 0; y < (n * 4); y++)
    {
        for (x = 0; x < (n * 4); x++)
        {
            printf("%c\t", Tablero[x][y]);
        }
        printf("\n");
    }
    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 5; x++)
        {
            // printf("%c", FichaBlanca[x][y]);
        }
        // printf("\n");
    }

    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            // printf("%c\t", FichaNegra[x][y]);
        }
        // printf("\n");
    }
}