/*
  @file: prg29_matriz_suma_promedio
  @brief: Matriz paa calcular la suma de renglones y columnas y el promedio de columnas
  @details: El usuario puede definir el valor mínimo y máximo de datos a introducir por renglón o columna (2-10). Una vez que se guardan todos lo números, se calcula la suma tanto de los renglones y de las columnas, así como el promedio de las columnas. Estos datos se guardan en otros arreglos para después desplegar los datos.
  @author: Iris Yulit Jasso  Cortes
  @date: 13-abril-2023
*/

#include <stdio.h>
#include <stdio_ext.h>

#define MAX_REN 10
#define MAX_COL 10
#define MIN_REN 2
#define MIN_COL 2

int Pedir_tamanio (int Min, int Max);
void Pedir_numero (int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN]);
//void Pedir_numero (int Renglon, int Columna, float Matriz[10][10]);
void Calcular_renglones (int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN],float Arreglo_ren[MAX_REN]);
void Calcular_columnas (int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN],float Arreglo_col[MAX_COL][2]);
void Desplegar_matriz(int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN]);
void Desplegar_resultados(int Renglon, int Columna,float Arreglo_ren[MAX_REN],  float Arreglo_col[MAX_COL][2]);

 

int main (void)
{
  int Renglon, Columna;
  float Matriz[MAX_COL][MAX_REN], Arreglo_ren[MAX_REN], Arreglo_col[MAX_COL][2];
  //Matriz[Columna][Renglón]

 


  printf ("Ingresa el tamaño de los renglones\n");
  Renglon=Pedir_tamanio(MIN_REN,MAX_REN);
  printf ("Ingresa el tamaño de los columnas\n");
  Columna=Pedir_tamanio(MIN_COL,MAX_COL);

 

  //printf ("Renglon = %d\nColumna = %d\n", Renglon, Columna);

 

  Pedir_numero (Renglon, Columna, Matriz);
  /*Para los arreglos bidimensionales, no aplica la siguiente nomenclatura
    Pedir_numero (Renglon, Columna, &Matriz[0][0]);
   */
  Desplegar_matriz(Renglon, Columna, Matriz);

 

  Calcular_renglones (Renglon,Columna,Matriz,Arreglo_ren);
  Calcular_columnas (Renglon,Columna,Matriz,Arreglo_col);
  Desplegar_resultados(Renglon,Columna,Arreglo_ren,Arreglo_col);

 

 return 0;
}

 

int Pedir_tamanio (int Min, int Max)
{
  int Numero;

 

  do
    {
      printf ("Dame tamaño (entre 2 y 10): ");
      scanf ("%d", &Numero);
      __fpurge(stdin);
      if (Numero<Min || Numero>Max)
        printf ("Número fuera de rango. Intenta nuevamente...\n");
    }
  while(Numero<Min || Numero>Max);

 

  return Numero;
}

 

void Pedir_numero (int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN])
{
  int x,y;
  /*
    x -> columnas
    y -> renglones
   */

 

  //Los números se van a introducir por renglón

 

  for (y=0; y<Renglon; y++)
    {
      for (x=0; x<Columna; x++)
        {
          printf ("Matriz[%d][%d]: ",x,y);
          scanf ("%f", &Matriz[x][y]);
          __fpurge(stdin);
        }
    }
}

 

void Calcular_renglones (int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN],float Arreglo_ren[MAX_REN])
{
  int i, j;
  /*i -> renglones
    j -> columnas*/
  float Suma;

 

  for (i=0; i<Renglon; i++)
    {
      Suma=0;
      for (j=0; j<Columna; j++)
        {
          Suma=Suma+Matriz[j][i];
        }
      Arreglo_ren[i]=Suma;
    }
}

 

void Calcular_columnas (int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN],float Arreglo_col[MAX_COL][2])
{
  int i, j;
  /*i -> renglones
    j -> columnas*/
  float Suma;

 

  for (j=0; j<Columna; j++)
     {
      Suma=0;
      for (i=0; i<Renglon; i++)
             {
          Suma=Suma+Matriz[j][i];
        }
      Arreglo_col[j][0]=Suma;
      Arreglo_col[j][1]=Suma/Renglon;
    }

 


}

 

void Desplegar_matriz(int Renglon, int Columna, float Matriz[MAX_COL][MAX_REN])
{
 int x,y;
  /*
    x -> columnas
    y -> renglones
   */

 

  //Los números se van a desplegar por renglón

 

  for (y=0; y<Renglon; y++)
    {
      for (x=0; x<Columna; x++)
        {
          printf ("%2.2f\t",Matriz[x][y]);
        }
      printf("\n");
    }
}

 

void Desplegar_resultados(int Renglon, int Columna,float Arreglo_ren[MAX_REN],  float Arreglo_col[MAX_COL][2])
{
 int x,y;
  /*
    x -> columnas
    y -> renglones
   */

 

  //Imprimir los resultados de los renglones
 printf ("Los resultados de las sumas de los renglones son:\n");

 

 for (y=0; y<Renglon; y++)
    {
      printf ("Arreglo_ren[%d] = %f\n", y, Arreglo_ren[y]);
    }

 

 printf ("Los resultados de las sumas y promedios de las columnas son:\n");
  for (x=0; x<Columna; x++)
    {
      printf ("Arreglo_col[%d][0](suma) = %.2f\n", x, Arreglo_col[x][0]);
      printf ("Arreglo_col[%d][1](promedio) = %.2f\n\n", x, Arreglo_col[x][1]);
    }
}