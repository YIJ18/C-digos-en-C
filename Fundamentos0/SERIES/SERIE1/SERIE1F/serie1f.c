/*
@file: Ejercicio F
@brief: Tablero de ajedrez
@details:Programa que imprime un tablero de ajedrez dependiendo la medida que introduce el usuario
@author:Iris Yulit Jasso Cortes
@date: 20-Octubre-2022
*/
#include <stdio.h>

/*@Parametros: ram1= imprime la linea de asteriscos;   ram2= imprime el número de guiones;  conca: Repite concatena ram1 y ram2, repitiendolo el numero de veces que introduce el usuario*/
void ram1(int n);
void ram2(int n);
void conca(int a, int n);

/*@Parametro main: Esta funcion lee el valor que el usuario introduce */
int main(void)
{
  int n, a;
  a = 4;

  printf("Ingresa un número: ");
  scanf("%d", &n);
  printf("\n");
  /*@Parametro que llama a la función conca*/
  conca(a, n);
}

/*Parametro vacío en el que mientras mi contador sea menor a númeron **/
void ram1(int n)
{

  int no;

  for (int no = 0; no < n; no++)
  {
    printf("*");
  }
  /*@Return: La función no retorna nada, pues es una función vacía*/
}

/*@parametro vacío ram2,que mientras mi contador sea menor a númeron imprime -*/
void ram2(int n)
{

  int no;

  for (int no = 0; no < n; no++)
  {
    printf("-");
  }
  /*@Return: La función no retorna nada, pues es una función vacía*/
}

/*@Parametro vacío conca, que llama a ram1 y ram2 repitiendolos hasta que sea menor a mi contador*/
void conca(int a, int n)
{

  int x;
  int no;
  int co;
  /*Mientras que mi x sea menor a 0, se hace lo que esta dentro, que son lineas con * y -*/
  for (int x = 0; x < a; x++)
  {
    for (int no = 0; no < n; no++)
    {
      /*Mientras que contador sea igual a 4, de llama a las funciones ram1, ram2*/
      for (int co = 0; co < a; co++)
      {
        ram1(n);
        ram2(n);
      }
      printf("\n");
    }
    for (int no = 0; no < n; no++)
    {
      /*Mientras que contador sea igual a 4, de llama a las funciones ram1, ram2*/
      for (int co = 0; co < a; co++)
      {
        ram2(n);
        ram1(n);
      }
      printf("\n");
    }
  }
  /*@Return: La función no retorna nada, pues es una función vacía*/
}
