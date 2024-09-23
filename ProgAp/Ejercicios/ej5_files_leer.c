#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

void leecoeficientes(float coeficientes[5][3]);
void guarda (float coeficientes[5][3]);

int main (void)
{
  float datos[5][3];
  leecoeficientes(datos);
  guarda (datos);
  return 0;
}

void leecoeficientes(float coeficientes[5][3])
{
  int i;

  for (i = 0; i < 5; i++)
    {
      printf("Dame los coeficientes de la ecuaciòn %d separados por comas: ", i+1);
      scanf("%f, %f, %f", &coeficientes[i][0],  &coeficientes[i][1], &coeficientes[i][2]);
    }
  
}

void guarda (float coeficientes[5][3])
{
  FILE *archivo;
  char nombre_archivo[50];
  int i;

  
  printf("Dame el nombre del archivo: ");
  __fpurge(stdin);
  gets(nombre_archivo);
  archivo = fopen (nombre_archivo, "wt");
  for ( i = 0; i < 5; i ++)
  fprintf(archivo, "%f, %f, %f\n", coeficientes[i][0],  coeficientes[i][1], coeficientes[i][2] );

  fclose(archivo);
}
