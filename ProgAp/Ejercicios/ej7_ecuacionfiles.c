#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>

void calcula(float a, float b, float c, float *x1, float *x2);

int main (void)
{
  char nombrearch[50];
  float a, b, c, r1, r2;
  FILE *archivo;
  printf("Dame el nombre del archivo: ");
  gets(nombrearch);
  archivo = fopen (nombrearch, "rt");
  if (archivo != NULL)
    {
      while (!feof(archivo))
	{
	  fscanf(archivo, "%f, %f, %f\n", &a, &b ,&c);
	  calcula (a, b, c, &r1, &r2);
	  printf("x1 = %.2f, x2 = %.2f\n", r1, r2);
	}
      fclose(archivo);
    }
  return 0;
}

void calcula(float a, float b, float c, float *x1, float *x2)
{
  *x1 = -b+(sqrt((b*b-(4*a*c))))/(2*a);
  *x2 = -b-(sqrt((b*b-(4*a*c))))/(2*a);
}
