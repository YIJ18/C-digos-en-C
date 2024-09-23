/*
 @file: ordenar_nombres.c
 @brief: Ordenar n cantidad de nombres dados al utilizar cadenas
 @details: Este programa ordena n cantidad de nombres dados por el usuario. Utiliza las funciones para manipular cadenas y las guarda en un arreglo de cadenas.
 @authors: Adriana Lorena Fajardo Martos
 @date: 25-abril-2023
 */

 

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

 

#define MAX_REN 50 //La cantidad máxima de nombres que tendrá la tabla
#define MAX_COL 31 //La longitud máxima del nombre
#define MIN_NOM 5 //La cantidad mínima de nombres que nos tiene que dar el usuario

 

int Pedir_n (int Minimo, int Maximo);
void Pedir_nombres (int n, char Listado[MAX_REN][MAX_COL]);
void Ordenar_nombres (int n, char Listado[MAX_REN][MAX_COL]);
void Imprimir_nombres (int n, char Listado[MAX_REN][MAX_COL]);

 


int main (void)
{
  char Listado[MAX_REN][MAX_COL];
  int n;

 

  printf ("Dime cuantos nombres vas a ordenar.\n");
  n= Pedir_n (MIN_NOM, MAX_REN); //n=Pedir_n(5, 50);

 

  Pedir_nombres (n, Listado);
  Ordenar_nombres (n, Listado);
  Imprimir_nombres (n, Listado);

 

  return 0;
}

 

int Pedir_n (int Minimo, int Maximo)
{
  int n;

 

  do
    {
      printf ("Dame un valor entre %d y %d: ",Minimo, Maximo);
      scanf ("%d", &n);
      __fpurge(stdin);
      if (n>Maximo || n<Minimo)
        printf ("El número está fuera de rango. Intenta nuevamente...\n");
    }
  while(n>Maximo || n<Minimo);

 

  return n;
}

 

//-----------------------------------------------------------------------------
/*Se definen las funciones parar solicitar y guardar los números a ordenar*/

 

void LeeCad (char *Cadena, int Longitud);

 

void Pedir_nombres (int n, char Listado[MAX_REN][MAX_COL])
{
  int i; //Este contador va a hacer referencia a los renglones de mi arreglo bidimensional y va a recorrer hasta n-1 (cantidad de nombres que me va a dar el usuario)


  printf ("La cantidad de nombres a guardar es: %d\n", n);

  for (i=0; i<n; i++)
    {
      printf ("Dame el nombre %d: ", i+1);
      LeeCad(Listado[i], MAX_COL);
    }
}

 

void LeeCad (char *Cadena, int Longitud)
{
  fgets (Cadena, Longitud, stdin);
  Cadena[strlen(Cadena)-1]=0;
  __fpurge(stdin);
}

 

//----------------------------------------------------------------------------

 

void Ordenar_nombres (int n, char Listado[MAX_REN][MAX_COL])
{
  int i, j;
  char Hoja[MAX_COL];

 

  for (i=0; i<=n-2; i++)
    {
      for (j=i+1; j<=n-1; j++)
        {
          if (strcmp(Listado[i], Listado[j])>0)
            {
              strcpy(Hoja, Listado[i]);
              strcpy(Listado[i], Listado[j]);
              strcpy (Listado[j], Hoja);
            }
        }

 

    }
}

 

void Imprimir_nombres (int n, char Listado[MAX_REN][MAX_COL])
{
  int i;

 

  printf ("Los nombres ordenados son:\n");
  for (i=0; i<n; i++)
    puts(Listado[i]);
}