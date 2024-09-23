#include <stdio.h>

void Solicitar_temp (int temperaturas [7][4], int i, int j);
void Rellenar_temp (int temperaturas [7][4], int *mayor, int *menor);
void Mayor_Menor (int temp, int *may, int *men);
void Promedio_temp (int temperaturas[7][4], double promedios[7]);
void Desplegar_temp (int temperaturas[7][4], double promedios[7], int mayor, int menor);

int main (void)
{
  int temperaturas[7][4];
  double promedios[7];
  int mayor, menor;
  Rellenar_temp (temperaturas, &mayor, &menor);
  Promedio_temp (temperaturas, promedios);
  Desplegar_temp (temperaturas, promedios, mayor, menor); 
}

void Solicitar_temp (int temperaturas[7][4], int i, int j)
{
  printf("Ingrese la temperatura %d del dia %d: ", j+1, i+1);
  scanf("%d", &temperaturas[i][j]);
}

void Rellenar_temp (int temperaturas[7][4], int *mayor, int *menor)
{
  int i, j, may, men, temp;
  printf("\n\n");
  for (i = 0 ; i < 7; i++)
    {
      for(j = 0; j < 4; j++)
	{
	  Solicitar_temp(temperaturas, i, j);
	  temp = temperaturas[i][j];
	  if (i == 0 && j == 0)
	    {
	      may = temp;
	      men = temp;
	    }
	  Mayor_Menor (temp, &may, &men);
	}
      printf("\n");
    }
  *mayor = may;
  *menor = men;
}

void Mayor_Menor (int temp, int *may, int *men)
{
  int i, j;
  
  if (*may < temp)
    *may = temp;
  else if (*may > temp)
     *may = *may;
	      
   if (*men> temp)
     *men = temp;
   else if (*men < temp)
     *men = *men;
}

void Promedio_temp (int temperaturas[7][4], double promedios[7])
{
  int i, j, suma;
  for (i = 0; i < 7; i++)
    {
      suma = 0;
      for(j = 0; j < 4; j++)
	{
	  suma = suma + temperaturas[i][j];
	}
      promedios[i] = suma / 4;
    }
}

void Desplegar_temp (int temperaturas[7][4], double promedios[7], int mayor, int menor)
{
  int i, j;

  for (i = 0; i < 7; i++)
    {
      for (j = 0; j < 4; j++)
	{
	  printf("%d\t", temperaturas[i][j]);
	}
      printf("\n");
    }

  printf("\n1. La temperatura mayor de la semana fue %d\n", mayor);
  printf("2. La temperatura menor de la semana fue %d\n\n", menor);
  for (i = 0; i < 7; i++)
    printf("La temperatura promedio del dia %d, fue de : %.2lf\n", i+1, promedios[i]);
}
