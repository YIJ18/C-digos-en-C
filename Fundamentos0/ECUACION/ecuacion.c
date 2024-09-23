#include <stdio.h>
#include <math.h>

void dec(int n1, char op, int n2, int n3);
double pot(int n1, int n2);

/*double raiz(int n1, int n2, char op);
double ecuacion(int n1, int n2, int n3, double *ap1, double *ap2);*/

/*   double potb = 0, determinante = 0;
if (op == 'e' || op == 'E')
 {
   printf(
       "Ingresa el tercer número: ");
   scanf("%d", &n3);
   if (ecuacion(n1, n2, n3, &potb, &determinante) == 1)
   {
     printf("%.2lf", potb);
     printf("\n%.2lf\n", determinante);
   }
   else
   {
     printf("No hay soluciones reales");
   }
 }
 */

int main(int argc, char *argv[])
{

  FILE *archivo = fopen("calculadora.txt", "r");
  FILE *salida = fopen("resultados.txt", "w");

  float r;
  int n1, n2, n3;
  char op;
  double re, x, y;

  if (argc = 2)
  {
    sscanf(argv[1], "%d", &n1);
    sscanf(argv[2], "%c", &op);
    sscanf(argv[3], "%d", &n2);
    while (fscanf(archivo; "%d %c %d", ))
    {
      /* code */
    }
  }
  return 0;
}

void dec(int n1, char op, int n2, int n3)
{
  double r, re, x, y;
  if (op == '*')
  {
    r = n1 * n2;
    printf("El resultado es: %.2f", r);
  }
  else if (op == '/')
  {
    x = (double)n1;
    y = (double)n2;
    re = x / y;
    printf("El resultado es: %.2lf", re);
  }
  else if (op == '+')
  {
    r = n1 + n2;
    printf("El resultado es: %.2f", r);
  }
  else if (op == '-')
  {
    r = n1 - n2;
    printf("El resultado es: %.2f", r);
  }
  else if (op == '%')
  {
    r = n1 % n2;
    printf("El resultado es: %.2f", r);
  }
  else if (op == '^')
  {
    pot(n1, n2);
  }
  else if (op == 'R' || op == 'r')
  {
    raiz(n1, n2, op);
  }
}

double pot(int n1, int n2)
{
  double r;
  r = pow(n1, n2);
  printf("El resultado es: %lf", r);
  return 0;
}

/*double raiz(int n1, int n2, char op)
{
  double r;
  if (op == 'R')
  {
    r = sqrt(n1);
    printf("El resultado es: %lf", r);
  }
  return 0;
}

int ecuacion(int n1, int n2, int n3, double *ap1, double *ap2)
{
  double dentro, b2, r, r1, r2;
  b2 = pow(n2, 2);
  dentro = b2 - (4 * n1 * n3);
  if (dentro >= 0)
  {
    // tiene 2 soluciones
    r = ((n2 * -1) - sqrt(dentro)) / 2 * n1;
    *ap1 = r;
    r1 = ((-1 * n2) + sqrt(dentro)) / 2 * n1;
    *ap2 = r1;
    return 1;
  }

  if (dentro < 0)
  {
    // no hay solución
    return 0;
  }
}
*/