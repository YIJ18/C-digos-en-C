#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio_ext.h>

void Lee(float datos[5][3]);
void Calcula(float datos[5][3]);

int main (void)
{
  float coef[5][3];
  Lee(coef);
  Calcula(coef);
  return 0;
}

void Lee(float datos[5][3])
{
  FILE *archivo;
  int i;
  char nombre_archivo[50];
  gets(nombre_archivo);
  archivo = fopen(nombre_archivo, "rt");

  if(archivo != NULL)
    {
      for(i = 0; i < 5; i++)
	fscanf(archivo,"%f, %f, %f\n", &datos[i][0],  &datos[i][1],  &datos[i][2]);
      fclose(archivo);
    }
  else
    printf("No existe el archivo\n");
}

void Calcula(float datos[5][3])
{
  int i;
  float x1, x2;
  for (i = 0; i < 5; i++)
    {
      x1 =(-datos[i][1]+(sqrt(datos[i][1]*datos[i][1]-4*datos[i][0]*datos[i][2])))/(2*datos[i][0]);
      x2 =(-datos[i][1]-(sqrt(datos[i][1]*datos[i][1]-4*datos[i][0]*datos[i][2])))/(2*datos[i][0]);
      printf("Ecuaciòn: %d: x1 = %f, x2 = %f\n", i+1, x1, x2);
    }
    
  
}
