#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define filas 3
#define columnas 4

/*-------------FUNCIONES DE LECTURA E IMPRESION--------------*/
int LeerSistema(double sistema[filas][columnas]);
void Imprimir_Matriz(double array[filas][columnas]);
void Imprimir_Resultados(double x, double y, double z, double norma, int k);

/*---------------FUNCIONES DE DIAGONAL PESADA-----------------*/
int Validar_Diagonal_Pesada(double array[filas][columnas]);
void Intercambiar_Col(double array[filas][columnas], int k);
void Intercambiar_Fil(double array[filas][columnas], int k);
int Hacer_Diagonal_Pesada(double array[filas][columnas], int fila_actual);
int Validar_Diagonal_Pesada2(double array[filas][columnas]);

/*--------FUNCIONES DE EJECUCION METODO GAUSS-JACOBI---------*/
void Matriz_Necesaria(double array[filas][columnas], char Resultado[3][100]);
void Calcular_Jacobi(char Ec_Iteracion[3][100]);

/*--------------- FUNCIONES RADIO ESPECTRAL -----------------*/
void Espectro_radial(double array[filas][columnas]);
double encontrarMayor(double array[]);

/*--------FUNCIONES DE ARCHIVOS---------*/
void Guardar_Archivo(double x, double y, double z, double norma, int k);

int main()
{
    double array[filas][columnas];
    char Ec_Iteracion[3][100];
    int i;

    printf("\n\n");

    if (LeerSistema(array) == 0)
    {
        system("clear");
        printf("--------------- MATRIZ ---------------\n");
        Imprimir_Matriz(array);

        if (/*Validar_Diagonal_Pesada2(array) == 1 &&*/ Validar_Diagonal_Pesada(array) == 1)
        {
            printf("\n-->La matriz tiene una Diagonal Pesada.\n");
            Matriz_Necesaria(array, Ec_Iteracion);
            Espectro_radial(array);
            printf("\nTus ecuaciones iterativas son:\n");
            printf("-------------------------------\n");
            for (i = 0; i < 3; i++)
                printf("%s\n", Ec_Iteracion[i]);
            Calcular_Jacobi(Ec_Iteracion);
        }
        else
        {
            if (Hacer_Diagonal_Pesada(array, 0))
            {
                printf("\nSe ha convertido la diagonal en pesada.\n");
                Imprimir_Matriz(array);
                Espectro_radial(array);
                Matriz_Necesaria(array, Ec_Iteracion);

                printf("\nTus ecuaciones iterativas son:\n");
                printf("-------------------------------------------------------\n");

                for (i = 0; i < 3; i++)
                    printf("%s\n", Ec_Iteracion[i]);

                Calcular_Jacobi(Ec_Iteracion);
            }
            else
            {
              //  if (Validar_Diagonal_Pesada2(array) == 0)
                //    printf("\nNo cumples con la condicion Necesaria, es decir, la suma de los absolutos de los elementos a su alrededor es mayor.\n");
                if (Validar_Diagonal_Pesada(array) == 0)
                    printf("\nNo cumple la Suficiente, es decir, el elemento de la diagonal principal no es mayor que los elementos cercanos\n");
                else
                    printf("Tienes infinidad de soluciones\n");
            }
        }
    }

    return 0;
}

/**
 * Lee el sistema de ecuaciones desde la entrada estándar y lo almacena en una matriz.
 *
 * @param sistema La matriz donde se almacenarán las ecuaciones.
 * @return 0 si la lectura se realizó con éxito, 1 si hubo un error de formato.
 */
int LeerSistema(double sistema[filas][columnas])
{
    printf("Ingresa el sistema de ecuaciones (formato a, b, c, d):\n");

    for (int i = 0; i < 3; i++)
        if (scanf("%lf %lf %lf %lf", &sistema[i][0], &sistema[i][1], &sistema[i][2], &sistema[i][3]) != 4)
        {
            printf("Error al leer la ecuación %d. Asegúrate de que esté en el formato correcto.\n", i + 1);
            return 1;
        }
    return 0;
}

/**
 * Calcula la matriz necesaria para el método de Jacobi y la almacena en un arreglo de cadenas.
 *
 * @param array La matriz original.
 * @param Resultado El arreglo de cadenas donde se almacenarán las ecuaciones iterativas.
 * @return void
 */
void Matriz_Necesaria(double array[filas][columnas], char Resultado[3][100])
{
    int i, j, k;
    double matriz_D[3][3], matriz_U_L[3][3], matriz_b[3], primera_suma[3], tercera_suma[3][3];

    // Inicializar matriz_D y matriz_U_L
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j == i)
            {
                matriz_D[i][j] = 1 / array[i][j];
                matriz_U_L[i][j] = 0;
            }
            else
            {
                matriz_D[i][j] = 0;
                matriz_U_L[i][j] = array[i][j];
            }
        }

        matriz_b[i] = array[i][3];
    }

    /* ------- FÓRMULA: D^-1 * b - D^-1(L+U) * x^k ------- */

    // D^-1 * b
    for (i = 0; i < 3; i++)
    {
        primera_suma[i] = 0;
        for (j = 0; j < 3; j++)
            primera_suma[i] += matriz_D[i][j] * matriz_b[j];
    }

    // - D^-1(L+U) * x^k
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            tercera_suma[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                tercera_suma[i][j] += (-1 * matriz_D[i][k] * matriz_U_L[k][j]);
            }
        }
    }

    sprintf(Resultado[0], "%lf %+lf%c %+lf%c", primera_suma[0], tercera_suma[0][1], 'y', tercera_suma[0][2], 'z');
    sprintf(Resultado[1], "%lf %+lf%c %+f%c", primera_suma[1], tercera_suma[1][0], 'x', tercera_suma[1][2], 'z');
    sprintf(Resultado[2], "%lf %+lf%c %+lf%c", primera_suma[2], tercera_suma[2][0], 'x', tercera_suma[2][1], 'y');
}

/**
 * Realiza el cálculo del método de Jacobi y guarda los resultados en un archivo.
 *
 * @param Ec_Iteracion El arreglo de cadenas con las ecuaciones iterativas.
 * @return void
 */
void Calcular_Jacobi(char Ec_Iteracion[3][100])
{
    double x = 0, y = 0, z = 0;
    double num_x, num_y, num_z, term_ind;
    double temp_x, temp_y, temp_z;
    int k = 0;
    double norma = 1;
    while (norma >= 0.001)
    {
        temp_x = x;
        temp_y = y;
        temp_z = z;

        sscanf(Ec_Iteracion[0], "%lf %lfy %lfz", &term_ind, &num_y, &num_z);
        x = term_ind + (num_y * temp_y) + (num_z * temp_z);

        sscanf(Ec_Iteracion[1], "%lf %lfx %lfz", &term_ind, &num_x, &num_z);
        y = term_ind + (num_x * temp_x) + (num_z * temp_z);

        sscanf(Ec_Iteracion[2], "%lf %lfx %lfy", &term_ind, &num_x, &num_y);
        z = term_ind + (num_x * temp_x) + (num_y * temp_y);

        if (k != 0)
            norma = sqrt(pow(x - temp_x, 2) + pow(y - temp_y, 2) + pow(z - temp_z, 2));
        Imprimir_Resultados(x, y, z, norma, k);
        Guardar_Archivo(x, y, z, norma, k);
        k++;
    }
}

/**
 * Guarda los resultados de las iteraciones en un archivo de texto.
 *
 * @param x Valor de x en la iteración.
 * @param y Valor de y en la iteración.
 * @param z Valor de z en la iteración.
 * @param norma Norma en la iteración.
 * @param k Número de iteración.
 * @return 0.
 */
void Guardar_Archivo(double x, double y, double z, double norma, int k)
{
    FILE *archivo;

    archivo = fopen("datos.txt", "at");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "Iteracion #%d:x = %lf y = %lf z = %lf ----> Su norma es: %lf\n", k, x, y, z, norma);

    fclose(archivo);
}

/**
 * Valida si la matriz tiene una diagonal pesada.
 *
 * @param array La matriz a validar.
 * @return 1 si la matriz tiene una diagonal pesada, 0 en caso contrario.
 * @return void
 */
/*** Necesaria ***/
int Validar_Diagonal_Pesada(double array[filas][columnas])
{
    double suma_alrededor;
    int i = 0, j = 0, bandera = 1;
    for (i = 0; i < filas; i++)
        for (j = 0; j < columnas - 1; j++)
            if (i != j && array[i][i] < array[i][j])
                return 0;

    return 1;
}

/*** Suficiente ***/
/*int Validar_Diagonal_Pesada2(double array[filas][columnas])
{
    double suma_alrededor = 0;
    int i = 0, j = 0, bandera = 1;
    for (i = 0; i < filas; i++)
    {
        suma_alrededor = 0;
        for (j = 0; j < columnas - 1; j++)
        {
            if (i != j)
                suma_alrededor += fabs(array[i][j]);
        }
        if (suma_alrededor >= array[i][i])
            return 0;
    }

    return 1;
}*/

/**
 * Imprime una matriz en la salida estándar.
 *
 * @param array La matriz a imprimir.
 * @return void
 */
void Imprimir_Matriz(double array[filas][columnas])
{
    int i = 0, j = 0;
    for (int i = 0; i < filas; i++)
    {
        printf("%lf %lf %lf %lf\n", array[i][j], array[i][j + 1], array[i][j + 2], array[i][j + 3]);
    }
}

/**
 * Intercambia dos columnas de una matriz.
 *
 * @param array La matriz en la que se realizará la operación.
 * @param k Índice de la columna a intercambiar.
 * @return void.
 */
void Intercambiar_Col(double array[filas][columnas], int k)
{
    double temp = 0;
    int i = 0;

    for (i = 0; i < filas; i++)
    {
        temp = array[i][0];
        array[i][0] = array[i][k];
        array[i][k] = temp;
    }
}

/**
 * Intercambia dos filas de una matriz.
 *
 * @param array La matriz en la que se realizará la operación.
 * @param k Índice de la fila a intercambiar.
 * @return void.
 */
void Intercambiar_Fil(double array[filas][columnas], int k)
{
    double temp = 0;
    int i = 0;

    for (i = 0; i < columnas; i++)
    {
        temp = array[0][i];
        array[0][i] = array[k][i];
        array[k][i] = temp;
    }
}

/**
 * Convierte la matriz en una matriz con diagonal pesada.
 *
 * @param array La matriz a modificar.
 * @param fila_actual Índice de fila actual en el proceso.
 * @return 1 si se logró hacer la diagonal pesada, 0 si no se logro.
 */
int Hacer_Diagonal_Pesada(double array[filas][columnas], int fila_actual)
{
    // printf("Entre\n");

    /*if (fila_actual == filas)
    {                                                                                    // Para que no exceda el limite de intentos
        if (Validar_Diagonal_Pesada2(array) == 1 && Validar_Diagonal_Pesada(array) == 1) // Avisa que termino
            return 1;
    }*/

    for (int i = fila_actual; i < filas; i++)
    { // El contador de filas inicia cada vez mas alto
        Intercambiar_Fil(array, i);

        for (int j = 0; j < columnas - 1; j++)
        { // Columnas -1 para que no interfiera con la de resultados
            Intercambiar_Col(array, j);
            if (Hacer_Diagonal_Pesada(array, fila_actual + 1) == 1) // Detiene la busqueda dentro del ciclo recursivo
                return 1;
            Intercambiar_Col(array, j); // Se regresa el movimiento para ver si con otro es posible
        }
        Intercambiar_Fil(array, i); // Ahora se cambia la fila, para probarla con otros movimientos de columnas
    }

    return 0; // Si no se consiguio, se envia el 0
}

/**
 * Imprime los resultados de una iteración del método de Jacobi.
 *
 * @param x Valor de x en la iteración.
 * @param y Valor de y en la iteración.
 * @param z Valor de z en la iteración.
 * @param norma Norma en la iteración.
 * @param k Número de iteración.
 * @return void
 */
void Imprimir_Resultados(double x, double y, double z, double norma, int k)
{
    printf("\nResultados de la Iteración #%d\n", k);
    printf("----------------------------\n");
    printf("x = %.2lf\n", x);
    printf("y = %.2lf\n", y);
    printf("z = %.2lf\n", z);
    printf("Norma = %lf\n", norma);
}

/**
 * Calcula el radio espectral de la matriz.
 *
 * @param array La matriz para la que se calculará el radio espectral.
 * @return void
 */
void Espectro_radial(double array[filas][columnas])
{
    int i, j, k;
    double num_mayor_fil[3], num_mayor_col[3], matriz_D_R[3][3], matriz_R[3][3], matriz_D[3][3];

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (j == i)
            {
                matriz_D[i][j] = 1 / array[i][j];
                matriz_R[i][j] = 0;
            }
            else
            {
                matriz_D[i][j] = 0;
                matriz_R[i][j] = array[i][j];
            }
        }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            matriz_D_R[i][j] = 0;
            for (k = 0; k < 3; k++)
                matriz_D_R[i][j] += matriz_R[i][k] * matriz_D[k][j];
        }

    for (i = 0; i < 3; i++)
    {
        num_mayor_fil[i] = 0;
        for (j = 0; j < 3; j++)
        {
            num_mayor_fil[i] += fabs(matriz_D_R[i][j]); // filas
            num_mayor_col[i] += fabs(matriz_D_R[j][i]); // columnas
        }
    }

    if (encontrarMayor(num_mayor_fil) <= encontrarMayor(num_mayor_col))
        printf("El radio espectral es de: %lf", encontrarMayor(num_mayor_col));
    else
        printf("El radio espectral es de: %lf", encontrarMayor(num_mayor_fil));
}

/**
 * Encuentra el mayor valor en un arreglo de números.
 *
 * @param array El arreglo de números.
 * @return El mayor
 */
double encontrarMayor(double array[])
{
    double mayor;
    int i;
    mayor = array[0];
    for (i = 1; i < 3; i++)
        if (array[i] > mayor)
            mayor = array[i];

    return mayor;
}
