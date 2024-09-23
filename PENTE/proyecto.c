#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct def_coordenada
{
    int coordenada_fila;
    int coordenada_columna;
    struct def_coordenada *sig, *ant;
} coor;

typedef struct def_jugador
{
    char nombre[50];
    double tiempo;
    coor *juego;
    struct def_jugador *sig, *ant;
} info;

#define MAX 2

/*---FUNCIONES PARA EL TABLERO---*/
void inicializar(int tablero[MAX][MAX]);
void imprimir_tablero(int tablero[MAX][MAX]);

/*---FUNCIONES PARA EL JUEGO---*/
int encontrar_linea(int tablero[MAX][MAX]);
void leer_coordenadas(int *fila, int *columna);
int contador(int tablero[MAX][MAX], int ficha);
int pente(int tablero[MAX][MAX], int x, int y, int turno);
void posicionar(int tablero[MAX][MAX], int fila, int columna, int *turno, info *jugador1, info *jugador2);
void juego(info *jugador1, info *jugador2);

/*---REQUERIMIENTOS DEL SISTEMA---*/
int menuPrincipal(info *jugador1, info *jugador2);
void menuJuego(info *jugador1, info *jugador2);
void jugar(info *jugador1, info *jugador2);
//void deshacer(info *jugador1, info *jugador2);
//void rehacer(info *jugador1, info *jugador2);
//void recuperar(info *jugador1, info *jugador2);
void mostrarAyuda();
void mostrarAcercaDe();

/*---LISTAS---*/
void insertadoble(info **inicio, char nombre[]);
void insertadoblecoordenada(coor **inicio, int columna, int fila);
void imprimir_coordenadas(info *jugador);
void guardar(info *jugador, char *nombre_archivo);

int main(void)
{
    char nombre[50], nombre2[50];

    // Asignación de memoria para jugador1 y jugador2
    info *jugador1 = (info *)malloc(sizeof(info));
    info *jugador2 = (info *)malloc(sizeof(info));

    // Verificación de si la asignación de memoria fue exitosa
    if (jugador1 == NULL || jugador2 == NULL)
    {
        printf("Error: No se pudo asignar memoria para los jugadores.\n");
        return 1; // Terminación con error
    }

    jugador1->juego = NULL;
    jugador2->juego = NULL;
    printf("Ingresa tu nombre jugador1: ");
    gets(nombre);
    printf("Ingresa tu nombre jugador2: ");
    gets(nombre2);

    insertadoble(&jugador1, nombre);
    insertadoble(&jugador2, nombre2);

    if (menuPrincipal(jugador1, jugador2) == 1)
    {
        imprimir_coordenadas(jugador1);
        imprimir_coordenadas(jugador2);
        return 0;
    }
    else
    {
        system("clear");
        menuPrincipal(jugador1, jugador2);
    }

    // Liberar memoria asignada
    free(jugador1);
    free(jugador2);

    return 0;
}

int menuPrincipal(info *jugador1, info *jugador2)
{
    int opcion;

    do
    {
        printf("\n--- Menú ---\n");
        printf("1. Juego\n");
        printf("2. Ayuda\n");
        printf("3. Acerca de...\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            menuJuego(jugador1, jugador2);
            break;
        case 2:
            mostrarAyuda();
            break;
        case 3:
            mostrarAcercaDe();
            break;
        case 4:
            printf("Saliendo del programa...\n");
            return 1;
            break;
        default:
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
        }

    } while (opcion != 4);
    return 0;
}

void menuJuego(info *jugador1, info *jugador2)
{
    int opcion;

    do
    {
        printf("\n--- Juego ---\n");
        printf("1. Jugar\n");
        printf("2. Guardar\n");
        printf("3. Deshacer\n");
        printf("4. Rehacer\n");
        printf("5. Recuperar\n");
        printf("6. Terminar\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            jugar(jugador1, jugador2);
            break;
        case 2:
            guardar(jugador1, strcat(jugador1->nombre, ".txt"));
            guardar(jugador2, strcat(jugador2->nombre, ".txt"));
            break;
        case 3:
            //deshacer(jugador1, jugador2);
            break;
        case 4:
           // rehacer(jugador1, jugador2);
            break;
        case 5:
            //recuperar(jugador1, jugador2);
            break;
        case 6:
            printf("Terminando el juego...\n");
            break;
        default:
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
        }

    } while (opcion != 6);
}

void jugar(info *jugador1, info *jugador2)
{
    char nombre[50], nombre2[50];
    clock_t inicio, fin;
    double tiempo_transcurrido;

    inicio = clock();

    juego(jugador1, jugador2);

    fin = clock();
    tiempo_transcurrido = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
}

/*void deshacer(info *jugador1, info *jugador2)
{
    printf("Deshaciendo la última acción...\n");
    // Agregar lógica para deshacer
}

void rehacer(info *jugador1, info *jugador2)
{
    printf("Rehaciendo la última acción deshecha...\n");
    // Agregar lógica para rehacer
}

void recuperar(info *jugador1, info *jugador2)
{
    printf("Recuperando estado anterior del juego...\n");
    // Agregar lógica para recuperar estado anterior
}*/

void mostrarAyuda()
{
    printf("Bienvenido a Pente!\n");
    printf("Instrucciones:\n");
    printf("1. Pente es un juego para dos jugadores, uno con símbolos 'X' y otro con símbolos 'O'.\n");
    printf("2. El tablero tiene un tamaño de 19x19.\n");
    printf("3. El objetivo del juego es hacer una fila de cinco símbolos del jugador propio, ya sea horizontal, vertical o diagonalmente.\n");
    printf("4. Los jugadores se turnan para colocar un símbolo en una casilla vacía del tablero.\n");
    printf("5. Si un jugador logra hacer una fila de cinco símbolos, gana la partida automáticamente.\n");
    printf("6. Un 'Pente' ocurre cuando un jugador hace una fila de cinco símbolos y captura simultáneamente dos de los símbolos del oponente.\n");
    printf("7. Los jugadores pueden capturar símbolos del oponente al colocar dos de los suyos en los extremos de una fila de símbolos del oponente.\n");
    printf("8. El juego termina en empate si el tablero se llena sin que ningún jugador haga una fila de cinco símbolos.\n");
    printf("¡Disfruta jugando!\n");
}

void mostrarAcercaDe()
{
    printf("Bienvenido a Pente!\n");
    printf("Los desarrolladores:\n");
    printf("Nombre");
}

void juego(info *jugador1, info *jugador2)
{

    int tablero[MAX][MAX], coordenada_fila, coordenada_columna, turno = 1, variable = 0;
    int h = 0, k = 0;

    inicializar(tablero);
    do
    {
        leer_coordenadas(&coordenada_fila, &coordenada_columna);
        posicionar(tablero, coordenada_fila, coordenada_columna, &turno, jugador1, jugador2);
        printf("El jugador %d cuenta con %d fichas en el table\n", turno, contador(tablero, turno));

        if (contador(tablero, 0) == 0)
        {
            printf("\nNadie gano :(\nGracias por jugar <enter> para continuar");
            getchar;
            return;
        }

        pente(tablero, coordenada_columna, coordenada_fila, turno);
        variable = encontrar_linea(tablero);
        if (variable == 1){
            printf("\n\tEl jugador: %d ganó \n", turno);
            return;
        }
        imprimir_tablero(tablero);
    } while (contador(tablero, 0) != 0 || variable == 1);
}

void leer_coordenadas(int *fila, int *columna)
{
    printf("\nIngresa una coordenada en [A,1]: ");
    scanf("%d", fila);
    printf("Ingresa una coordenada en [A,1]: ");
    scanf("%d", columna);
}

void imprimir_tablero(int tablero[MAX][MAX])
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf(" %d ", tablero[i][j]);
        }
        printf("\n");
    }
}

void inicializar(int tablero[MAX][MAX])
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            tablero[i][j] = 0;
        }
    }
}

void posicionar(int tablero[MAX][MAX], int fila, int columna, int *turno, info *jugador1, info *jugador2)
{
    if (*turno == 2)
    {
        tablero[fila][columna] = 2;
        *turno = 1;
        insertadoblecoordenada(&jugador2->juego, columna, fila);
    }

    else
    {
        tablero[fila][columna] = 1;
        *turno = 2;
        insertadoblecoordenada(&jugador1->juego, columna, fila);
    }
}

int contador(int tablero[MAX][MAX], int ficha)
{
    int i, j, cont = 0;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (tablero[i][j] == ficha)
                cont++;
        }
    }

    return cont;
}

int pente(int tablero[MAX][MAX], int x, int y, int turno)
{
    int i, j, coordenadas, casillax, casillay, ficha = 0, contador;

    tablero[y][x] = turno;
    ficha = 0;

    /*----------Diagonal abajo derecha---------------*/
    contador = 0;
    casillay = i = y;
    casillax = j = x;
    while (i < MAX - 1 && j < MAX - 1 && i >= 0 && j >= 0)
    {
        i++;
        j++;
        if (tablero[i][j] == 0)
            i = j = MAX;

        if (tablero[i][j] != turno)
        {
            ficha = 1;
            contador++;
        }

        else if (ficha == 1 && tablero[i][j] == turno && contador == 2)
        {
            do
            {
                tablero[y][x] = 0;
                x++;
                y++;
            } while (tablero[y][x] != turno);
            tablero[casillay][casillax] = turno;
            i = j = MAX;
        }
    }

    /*----------Diagonal arriba izquierda---------------*/
    contador = 0;
    i = y = casillay;
    j = x = casillax;
    while (i < MAX && j < MAX && i > 0 && j > 0)
    {
        i--;
        j--;
        if (tablero[i][j] == 0)
            i = j = MAX;

        if (tablero[i][j] != turno)
        {
            ficha = 1;
            contador++;
        }

        else if (ficha == 1 && tablero[i][j] == turno && contador == 2)
        {
            do
            {
                tablero[y][x] = 0;
                x--;
                y--;
            } while (tablero[y][x] != turno);
            tablero[casillay][casillax] = turno;
            i = j = MAX;
        }
    }

    /*----------Diagonal arriba derecha---------------*/

    contador = 0;
    i = y = casillay;
    j = x = casillax;
    while (i < MAX && j < MAX && i > 0 && j >= 0)
    {
        i--;
        j++;
        if (tablero[i][j] == 0)
            i = j = MAX;

        if (tablero[i][j] != turno)
        {
            ficha = 1;
            contador++;
        }

        else if (ficha == 1 && tablero[i][j] == turno && contador == 2)
        {
            do
            {
                tablero[y][x] = 0;
                x++;
                y--;
            } while (tablero[y][x] != turno);
            tablero[casillay][casillax] = turno;
            i = j = MAX;
        }
    }

    /*----------Diagonal abajo izquierda---------------*/
    contador = 0;
    i = y = casillay;
    j = x = casillax;
    while (i < MAX && j < MAX && i >= 0 && j > 0)
    {
        i++;
        j--;
        if (tablero[i][j] == 0)
            i = j = MAX;

        if (tablero[i][j] != turno)
        {
            ficha = 1;
            contador++;
        }

        else if (ficha == 1 && tablero[i][j] == turno && contador == 2)
        {
            do
            {
                tablero[y][x] = 0;
                x--;
                y++;
            } while (tablero[y][x] != turno);
            tablero[casillay][casillax] = turno;
            i = j = MAX;
        }
    }

    /*----------Arriba---------------*/
    contador = 0;
    i = y = casillay;
    j = x = casillax;
    while (i < MAX && i > 0)
    {
        i--;
        if (tablero[i][j] == 0)
            i = MAX;

        if (tablero[i][j] != turno)
        {
            ficha = 1;
            contador++;
        }
        else if (ficha == 1 && tablero[i][j] == turno && contador == 2)
        {
            do
            {
                tablero[y][x] = 0;
                y--;
            } while (tablero[y][x] != turno);
            tablero[casillay][casillax] = turno;
            i = j = MAX;
        }
    }

    /*----------Abajo---------------*/
    contador = 0;
    i = y = casillay;
    j = x = casillax;
    while (i < MAX && i >= 0)
    {
        i++;
        if (tablero[i][j] == 0)
            i = MAX;

        if (tablero[i][j] != turno)
        {
            ficha = 1;
            contador++;
        }
        else if (ficha == 1 && tablero[i][j] == turno && contador == 2)
        {
            do
            {
                tablero[y][x] = 0;
                y++;
            } while (tablero[y][x] != turno);
            tablero[casillay][casillax] = turno;
            i = j = MAX;
        }
    }

    /*----------Derecha---------------*/
    contador = 0;
    i = y = casillay;
    j = x = casillax;
    while (j < MAX && j >= 0)
    {
        j++;
        if (tablero[i][j] == 0)
            j = MAX;

        if (tablero[i][j] != turno)
        {
            ficha = 1;
            contador++;
        }

        else if (ficha == 1 && tablero[i][j] == turno && contador == 2)
        {
            do
            {
                tablero[y][x] = 0;
                x++;
            } while (tablero[y][x] != turno);
            tablero[casillay][casillax] = turno;
            i = j = MAX;
        }
    }

    /*----------Izquierda---------------*/
    contador = 0;
    i = y = casillay;
    j = x = casillax;
    while (j < MAX && j > 0)
    {
        j--;

        if (tablero[i][j] == 0)
            j = MAX;

        if (tablero[i][j] != turno)
        {
            ficha = 1;
            contador++;
        }

        else if (ficha == 1 && tablero[i][j] == turno && contador == 2)
        {
            do
            {
                tablero[y][x] = 0;
                x--;
            } while (tablero[y][x] != turno);
            tablero[casillay][casillax] = turno;
            i = j = MAX;
        }
    }

    return 0;
}

int encontrar_linea(int tablero[MAX][MAX])
{
    int i, j;

    // Verificar horizontalmente
    for (i = 0; i < MAX; i++)
    {
        int contador = 1;
        for (j = 0; j < MAX - 1; j++)
        {
            if (tablero[i][j] != 0 && tablero[i][j] == tablero[i][j + 1])
            {
                contador++;
                if (contador == 5)
                {
                    return 1;
                }
            }
            else
            {
                contador = 1;
            }
        }
    }

    // Verificar verticalmente
    for (j = 0; j < MAX; j++)
    {
        int contador = 1;
        for (i = 0; i < MAX - 1; i++)
        {
            if (tablero[i][j] != 0 && tablero[i][j] == tablero[i + 1][j])
            {
                contador++;
                if (contador == 5)
                {
                    return 1;
                }
            }
            else
            {
                contador = 1;
            }
        }
    }

    // Verificar diagonalmente (desde la esquina superior izquierda hacia la esquina inferior derecha)
    for (i = 0; i < MAX - 4; i++)
    {
        for (j = 0; j < MAX - 4; j++)
        {
            if (tablero[i][j] != 0 &&
                tablero[i][j] == tablero[i + 1][j + 1] &&
                tablero[i][j] == tablero[i + 2][j + 2] &&
                tablero[i][j] == tablero[i + 3][j + 3] &&
                tablero[i][j] == tablero[i + 4][j + 4])
            {
                return 1;
            }
        }
    }

    // Verificar diagonalmente (desde la esquina superior derecha hacia la esquina inferior izquierda)
    for (i = 0; i < MAX - 4; i++)
    {
        for (j = MAX - 1; j >= 4; j--)
        {
            if (tablero[i][j] != 0 &&
                tablero[i][j] == tablero[i + 1][j - 1] &&
                tablero[i][j] == tablero[i + 2][j - 2] &&
                tablero[i][j] == tablero[i + 3][j - 3] &&
                tablero[i][j] == tablero[i + 4][j - 4])
            {
                return 1;
            }
        }
    }

    // Si no se encuentra ninguna línea de 5 fichas iguales
    return 0;
}

void insertadoble(info **inicio, char nombre[])
{
    info *aux;
    info *temp = (info *)malloc(sizeof(info));
    strcpy(temp->nombre, nombre);
    temp->tiempo = 0;
    temp->juego = NULL;
    temp->sig = NULL;
    temp->ant = NULL;

    if (*inicio == NULL)
    {
        *inicio = temp;
        return;
    }

    aux = *inicio;

    while (aux->sig != NULL)
    {
        aux = aux->sig;
    }

    aux->sig = temp;
    temp->ant = aux;

    printf("La zapata se inserto");
}

void insertadoblecoordenada(coor **inicio, int columna, int fila)
{
    coor *aux;
    coor *temp = (coor *)malloc(sizeof(coor));
    temp->coordenada_columna = columna;
    temp->coordenada_fila = fila;
    temp->sig = NULL;
    temp->ant = NULL;

    if (*inicio == NULL)
    {
        *inicio = temp;
        return;
    }

    aux = *inicio;

    while (aux->sig != NULL)
    {
        aux = aux->sig;
    }

    aux->sig = temp;
    temp->ant = aux;

    printf("La zapata2 se inserto");
}

void imprimir_coordenadas(info *jugador)
{
    coor *actual = jugador->juego;

    printf("Coordenadas de %s:\n", jugador->nombre);
    while (actual != NULL)
    {
        printf("Fila: %d, Columna: %d\n", actual->coordenada_fila, actual->coordenada_columna);
        actual = actual->sig;
    }
}

void guardar(info *jugador, char *nombre_archivo)
{
    coor *actual = jugador->juego;
    FILE *archivo = fopen(nombre_archivo, "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo para escribir.\n");
        return;
    }

    fprintf(archivo, "Coordenadas de %s:\n", jugador->nombre);
    while (actual != NULL)
    {
        fprintf(archivo, "Fila: %d, Columna: %d\n", actual->coordenada_fila, actual->coordenada_columna);
        actual = actual->sig;
    }

    fclose(archivo);
}
