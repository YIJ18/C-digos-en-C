/*
Escriba un programa que permita calcular el cuadrado de los 100 primeros números enteros
positivos, y que a continuación escriba una tabla con dichos cuadrados. El programa debe
hacerse en dos fases: en la primera, se calcula el cuadrado de los 100 primeros números
enteros positivos. En la segunda, se imprime la tabla que incluya tanto el número como su
cuadrado.
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<math.h>

void calcular_pot(int Cuadrados[10][10]);
void desplegar_pot(int Cuadrados[10][10]);

int main (void)
{
  int Cuadrados[10][10];
  calcular_pot(Cuadrados);
  desplegar_pot(Cuadrados);  
  return 0;
}

void calcular_pot(int Cuadrados[10][10])
{
  int i, j , pot = 1;
  for ( i = 0; i < 10; i++)
    {
      for (j = 0; j < 10; j++)
	{
	  Cuadrados[i][j] = pow(pot, 2);
	  pot++; 
	}
    }
}

void desplegar_pot(int Cuadrados[10][10])
{
  int i, j, num = 1;
  for ( i = 0; i < 10; i++)
    {
      for (j = 0; j < 10; j++)
	{
	  printf("%d = %d \t", num, Cuadrados[i][j]);
	  if(i == 0)
	    printf("\t");
	  num++;
	}
      printf("\n");
    }
}
