#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define filas 3
#define columnas 4

int Validar_Diagonal_Pesada(double array[filas][columnas]);
void Pedir_Matriz(double array[filas][columnas]);
void Imprimir_Matriz(double array[filas][columnas]);
void Intercambiar_Col(double array[filas][columnas], int k);
void Intercambiar_Fil(double array[filas][columnas], int k);
int Hacer_Diagonal_Pesada(double array[filas][columnas], int fila_actual);

/*********************** Equation  *******************************************************************/
void Hacer_Matrices(double array[filas][columnas], double matriz_D[filas][columnas - 1], double matriz_LU[filas][columnas - 1], double matriz_R[filas][columnas - 1]);
void Imprimir_Matriz2(double array[filas][columnas - 1]);
void Iteraciones(double array[filas][columnas], double matriz_R[filas][columnas - 1], double resultados[filas], double norma);
void ImprimirIteracionEnArchivo(FILE *archivo, int iteracion, double resultados[filas], double norma);

int main()
{

    double array[filas][columnas], matriz_LU[filas][columnas - 1], matriz_R[filas][columnas - 1], matriz_D[filas][columnas - 1];
    double resultados[3] = {0}, norma = 0;
    Pedir_Matriz(array);
    Imprimir_Matriz(array);

    if (Validar_Diagonal_Pesada(array) == 1)
        printf("Tiene Diagonal Pesado\n");
    else
    {
        if (Hacer_Diagonal_Pesada(array, 0))
        {
            printf("Tu diagonal ahora es pesada\n");
            Imprimir_Matriz(array);
        }
        else
            printf("Tu matriz nunca podra ser pesada.");
    }

    /****** Start Equation *************/
    Hacer_Matrices(array, matriz_D, matriz_LU, matriz_R);
    printf("\nEcuacuones\n");
    Imprimir_Matriz2(matriz_R);

    Iteraciones(array, matriz_R, resultados, norma);

    return 0;
}

void Pedir_Matriz(double array[filas][columnas])
{
    int j = 0;
    printf("Ingresa la matriz con el siguiente formato: \n\n");
    printf("n n n n\n");

    for (int i = 0; i < filas; i++)
    {
        scanf("%lf %lf %lf %lf", &array[i][j], &array[i][j + 1], &array[i][j + 2], &array[i][j + 3]);
        __fpurge(stdin);
    }
}

int Validar_Diagonal_Pesada(double array[filas][columnas])
{
    int i = 0, j = 0, bandera = 1;
    for (i = 0; i < filas; i++)
        for (j = 0; j < columnas - 1; j++)
            if (i != j && array[i][i] < array[i][j])
                return 0;

    return 1;
}

void Imprimir_Matriz(double array[filas][columnas])
{
    int i = 0, j = 0;
    for (int i = 0; i < filas; i++)
    {
        printf("%+lf %+lf %+lf %+lf\n", array[i][j], array[i][j + 1], array[i][j + 2], array[i][j + 3]);
        __fpurge(stdin);
    }
}

void Imprimir_Matriz2(double array[filas][columnas - 1])
{
    int i = 0, j = 0;
    printf("%+lf %+lfy %+lfz\n", array[i][j], array[i][j + 1], array[i][j + 2]);
    printf("%+lf %+lfx %+lfz\n", array[i + 1][j], array[i + 1][j + 1], array[i + 1][j + 2]);
    printf("%+lf %+lfx %+lfy\n", array[i + 2][j], array[i + 2][j + 1], array[i + 2][j + 2]);
}

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

int Hacer_Diagonal_Pesada(double array[filas][columnas], int fila_actual)
{
    printf("Entre\n");

    if (fila_actual == filas)
    {                                            // Para que no exceda el limite de intentos
        if (Validar_Diagonal_Pesada(array) == 1) // Avisa que termino
            return 1;
    }

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

void Hacer_Matrices(double array[filas][columnas], double matriz_D[filas][columnas - 1], double matriz_LU[filas][columnas - 1], double matriz_R[filas][columnas - 1])
{

    int i, j, x, y, k, l, m, z;

    /**** Diagonal ****/
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas - 1; j++)
        {
            if (i == j)
                matriz_D[i][j] = 1.0 / array[i][j]; // Invertir el valor de la diagonal
            else
                matriz_D[i][j] = 0;
        }
    }

    /**** Lower + Upper ****/
    for (x = 0; x < filas; x++)
    {
        for (y = 0; y < columnas - 1; y++)
        {
            if (x != y)
                matriz_LU[x][y] = array[x][y];
            else
                matriz_LU[x][y] = 0;
        }
    }

    /*** Mult ****/
    for (m = 0; m < filas; m++)
    {
        for (l = 0; l < columnas - 1; l++)
        {
            matriz_R[m][l] = 0;
            for (k = 0; k < columnas - 1; k++)
            {
                matriz_R[m][l] += matriz_D[m][k] * matriz_LU[k][l] * -1;
            }
        }
    }

    /*
      for(z=0; z<filas; z++){
      if(matriz_R[z][2]==0){
        matriz_R[z][2]=matriz_R[z][1];
        matriz_R[z][1]=0;
      }
      if(matriz_R[z][1]==0){
        matriz_R[z][1] = matriz_R[z][0];
        matriz_R[z][0]=0;
      }

      matriz_R[z][0] = matriz_D[z][z]*array[z][3];

    }
    */
}

void ImprimirIteracionEnArchivo(FILE *archivo, int iteracion, double resultados[filas], double norma)
{
    fprintf(archivo, "Iteracion #%d: ", iteracion);
    fprintf(archivo, "x = %lf ", resultados[0]);
    fprintf(archivo, "y = %lf ", resultados[1]);
    fprintf(archivo, "z= %lf ", resultados[2]);
    fprintf(archivo, "----> Su norma es: %lf\n", norma);
}

void Iteraciones(double array[filas][columnas], double matriz_R[filas][columnas - 1], double resultados[filas], double norma)
{

    FILE *archivo, *archivo2;
    archivo = fopen("resultados.txt", "wt");
    archivo2 = fopen("potencia.txt", "wt");
    double matriz_res[3] = {0}, matriz_total[3] = {0}, matriz_it[3] = {0}, potencia[3] = {0};
    double resultados_anteriores[3] = {0}, potencia_anterior[3] = {0};
    int z = 0, k = 1, i = 0, j = 0, l = 0, p = 0;

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    do
    {
        for (int p = 0; p < 3; p++)
        {
            resultados_anteriores[p] = resultados[p];
            potencia_anterior[p] = potencia[p];
        }

        for (z = 0; z < filas; z++)
        {
            matriz_res[z] = 0;
            printf("%lf + %lf\n", 1 / array[z][z], array[z][3]);
            matriz_res[z] = (1 / array[z][z]) * array[z][3];
        }
        for (l = 0; l < filas; l++)
        {
            potencia[l] = pow(matriz_res[l], k - 1);
            printf("Potencia: %lf\n", potencia[l]);
        }

        printf("Multiplicacion de Matrices\n");
        /**La K se multiplica por la matriz_R y le sumamos matriz_res**/

        for (i = 0; i < filas; i++)
        {
            for (j = 0; j < columnas - 1; j++)
            {
                matriz_total[i] += matriz_R[i][j] * potencia[j];
            }
        }

        for (p = 0; p < filas; p++)
        {
            resultados[p] = matriz_res[p] + matriz_total[p];
            printf("%lf\n", resultados[p]);
        }

        norma = sqrt(pow(resultados[0] - resultados_anteriores[0], 2) +
                     pow(resultados[1] - resultados_anteriores[1], 2) +
                     pow(resultados[2] - resultados_anteriores[2], 2));

        for (i = 0; i < filas; i++)
            printf("%lf", resultados[i]);

        ImprimirIteracionEnArchivo(archivo, k, resultados, norma);

        ImprimirIteracionEnArchivo(archivo2, k, potencia, norma);

        printf("Valor de la norma> %lf", norma);
        k++;
    } while (norma > 0.001);

    fclose(archivo);
    fclose(archivo2);
}

/*
1 2 3 1
5 4 2 8
4 8 5 6

3 -1 -1 1
-1 3 1 3
2 1 4 7

3 -1 1 1
3 6 2 0
3 3 7 4

3x, -1y, 1z, 1
3x, 6y, 2z, 0
3x, 3y, 7z, 4

1x, 2y, 3z, 1
5x, 4y, 2z, 8
4x, 8y, 5z, 6


3x, -1y, -1z, 1
-1x, 3y, +1z, 3
2x, 1y, 4z, 7



  for(z=0; z<filas; z++){
    printf("%lf * %lf \n",matriz_D[z][z], matriz_D[z][3] );
    matriz_R[z][z] = matriz_D[z][z]*array[z][3];
  }



  /**La K se multiplica por la matriz_R y le sumamos matriz_res**

  for( i=0; i<filas; i++){
    for( j=0; j<columnas-1; j++){
      matriz_total[i] += matriz_R[i][j] * k;
    }
  }

//Sumamos la matriz_total con la matriz_res
  for(i=0; i<filas; i++){
    printf("%lf + %lf\n", matriz_res[i], matriz_total[i]);
    matriz_it[i] = matriz_res[i] + matriz_total[i];
    matriz_it2[i] = pow(matriz_it[i], k);
  }

  for(i=0; i<filas; i++){
    printf("%lf\n", matriz_it[i]);
  }






  //Sumamos la matriz_total con la matriz_res
  for(i=0; i<filas; i++){
    printf("%lf + %lf\n", matriz_res[i], matriz_total[i]);
    matriz_it[i] = matriz_res[i] + matriz_total[i];

  }

  for(i=0; i<filas; i++){
    matriz_it[i] = pow(matriz_it[i], k);
    printf("%lf\n", matriz_it[i]);
  }

*/