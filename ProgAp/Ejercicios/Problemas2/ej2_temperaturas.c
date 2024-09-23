/*
Se tienen N temperaturas almacenadas en un arreglo. Se desea calcular la media de dichas
temperaturas, y también conocer la cantidad de temperaturas que son mayores o iguales a la
media. Al comienzo, el programa debe solicitar al usuario la cantidad de temperaturas
existentes. Esta cantidad deberá ser un valor  entre 5 y 100, y el programa debe validarlo.
Posteriormente, el programa hará la lectura de las temperaturas, y por último, desplegará los
valores deseados.
 */

#include <stdio.h>
#include <stdio_ext.h>

void solicitar(int *n, int *temps);
double calcular_media (int *temps, int num);
void desplegar (int *temps, double media, int num);

int main (void)
{
  int temps[100], num;
  double media;
  solicitar(&num,temps);
  media = calcular_media (temps, num);
  desplegar (temps, media, num);
  return 0;
}

void solicitar(int *n, int *temps)
{
  int i;
  printf("Ingrese el número de temperaturas: ");
  scanf("%d", n);
  
  for(i = 0; i < *n; i++)
    {
      printf("Ingrese temperatura: ");
      scanf("%d", &temps[i]);
    }
}

double calcular_media (int *temps, int num)
{
  int i;
  double suma = 0;
  for (i = 0; i < num; i++)
    {
      suma = suma + temps[i];
    }
  return suma / num;
}


void desplegar (int *temps, double media, int num)
{
  int i, men = 0;
  printf("\n\nLa media de las temperaturas proporcionadas es: %lf\n", media);

  for (i = 0; i < num; i++)
    {
      if (temps[i] > media)
	{
	  if (men == 0)
	    printf("\nLos datos mayores a la media son: ");
	  printf ("%d, ", temps[i]);
	  men++;
	}
    }
  men = 0;
   for (i = 0; i < num; i++)
    {
      if (temps[i] < media)
	{
	  if (men == 0)
	    printf("\nLos datos menores a la media son: ");
	  printf ("%d, ", temps[i]);
	  men++;
	}
    }
   men = 0;
  for (i = 0; i < num; i++)
    {
      if (temps[i] == media)
	{
	  if (men == 0)
	    printf("\nLos datos iguales a la media son: ");
	  printf ("%d, ", temps[i]);
	  men++;
	}
    }
}
