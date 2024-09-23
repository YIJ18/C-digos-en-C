/*
Para determinar la concavidad de una función se deben determinar los máximos y/o mínimos de la función;
para esto, usando la primera derivada, hay que encontrar el punto (o los puntos) de la abscisa en el que la
pendiente es cero. Con este valor de abscisa hay que encontrar la segunda derivada de la función y si es posi;vo,
la concavidad es hacia arriba; en caso contrario la concavidad es hacia abajo.
Mediante un programa en C, obtenga la primera derivada de la función en un intervalo dado y recorra los valores
de la pendiente hasta encontrar el valor de cero; se recomienda u;lizar método central, aunque puede usar el
método de su preferencia. Conserve el valor o valores de x en los que la pendiente es cero (raíces) y calcule la
segunda derivada, determinando si el resultado es posi;vo o nega;vo. En caso de que en el intervalo existan
dos o más valores de pendiente cero, calcular para cada uno de ellos la concavidad. Documente los resultados
que obtenga.
La función por analizar, en el intervalo de -4 a 4, es:
�(�) = �! − 3�" − 9� + 5
También puede obtener el valor de la o las raíces usando el método de Newton-Raphson. Emplee el método de
su preferencia
 */
#include <stdio.h>
#include <math.h>

#define h 0.01
#define inicio -4.0
#define fin 4.0


double F(double x);
double n_derivada_central(double x, int n);
double Newton(float xn);

int main(void)
{
  double concavidad, max, min, i, derivada1, derivada2;
  double x = 0, y = 1, c = (x + y) / 2;
  
  printf("Ejercicio 1\n");

  
  for(i = inicio; i <= fin; i+=0.5)
    {
      derivada1 = n_derivada_central(i, 1);
      printf("La derivada en el punto %.2lf, es : %.5lf\n", i, derivada1);

      derivada2 = n_derivada_central(i, 2);
      if(derivada2 > 0)
	{
	   printf("La concavidad de la funcion es hacia arriba: %lf\n", derivada2); 
	}
      else
	{
	  if(derivada2 < 0)
	    {
	      printf("La concavidad de la funcion es hacia abajo: %lf\n", derivada2);
	    }
	  else
	    {
	      printf("La concavidad de la funcion es un putno de inflexiòn o un punto silla: %lf\n",derivada2 );
	    }
	}
      printf("\n");


 

      printf("---------------------------\n");

      if (F(x) * F(y) >= 0)
        printf("El producto de f(a) y f(b) no cumple la condición f(a) * f(b) < 0. \nNo se garantiza la existencia de una raíz en el intervalo [%f,%f].\n", x, y);
      else if ( n_derivada_central(x, 1) == 0 || n_derivada_central(y, 1) == 0)
        printf("La derivada en al menos uno de los extremos del intervalo es cero. No se garantiza la existencia del punto de cruce.\n");
      else if (F(c) / n_derivada_central(c, 1) > y - x)
        printf("La tangente de f(x) no cruza en algún punto del intervalo [a,b].\n");
      else
	{
	  y = Newton(x);
	  while (x != y)
	    {
	      x = y;
	      y = Newton(x);
	    }
	  if(y == 0)
	    {
	      printf("La raiz de Newton es: %lf\n", y);

	    }
	}
      printf("---------------------------\n");
      printf("\n");
    }

  
  
  
  return 0;
}

double F(double x)
{
  return (pow(x,3) - (3 * pow(x, 2)) - (9 * x) + 5);
}


/**
 * Calcula la n-ésima derivada adelante de F(x) en el punto x
 *
 * @param x Punto en el que se calcula la derivada
 * @param n Orden de la derivada
 * @return El valor de la n-ésima derivada adelante
 */
double n_derivada_central(double x, int n)
{
    if (n == 0)
        return F(x);
    else
        return (n_derivada_central(x + h, n - 1) - n_derivada_central(x - h, n - 1)) / (2 * h);
}



/**
 * Aplica el método de Newton para encontrar una raíz de la función F.
 *
 * @param xn Valor inicial para el método de Newton.
 * @return La aproximación de la raíz de F.
 */
double Newton(float xn)
{
  double fxn = F(xn), df =  n_derivada_central(xn,1);
    return (xn - (fxn / df));
}
