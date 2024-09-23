#include <stdio.h>

void Suma(int *suma, int x, int y);
void Resta(int *resta, int x, int y);
void Multi(int *multiplicacion, int x, int y);
void Div(double *division, int x, int y);

int main (void)
{
  int x, y, suma, resta, multiplicacion;
  char operacion;
  double division;

  printf("\n\nIngresa la operacion a realizar: ");
  scanf("%c", &operacion);

  printf("\nIngresa el numero 1: ");
  scanf("%d", &x);

  printf("\nIngresa el numero 2: ");
  scanf("%d", &y);
  
  if (operacion == '+')
    {
      Suma(&suma, x, y);
      printf("El resultado de  la operacon + es : %d\n\n", suma);
    }
  else
    {
         if (operacion == '-')
	   {
	     Resta(&resta, x, y);
	     printf("El resultado de  la operacon - es : %d\n\n", resta);
	   }
	 else
	   {
	      if (operacion == '*')
		{
		  Multi(&multiplicacion, x, y);
		  printf("El resultado de  la operacon * es : %d\n\n", multiplicacion);
		}
	      else
		{
		  if (operacion == '/')
		    {
		      Div(&division,  x,  y);
		      printf("El resultado de  la operacon / es : %lf\n\n", division);
		    }
		  else
		    printf("Ingresa una operacion valida.\n");
		}
	   }
    }
    
}

void Suma(int *suma, int x, int y)
{
  int a;
    a = x + y;
    *suma = a;
}

void Resta(int *resta, int x, int y)
{
  int a;
    a = x - y;
    *resta = a;
}

void Multi(int *multiplicacion, int x, int y)
{
  int a;
    a = x * y;
    *multiplicacion = a;
}


void Div(double *division, int x, int y)
{
  int a;
    a =  x / y;
    *division = a;
}
