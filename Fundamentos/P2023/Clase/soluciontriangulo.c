#include <stdio.h>
#include <stdio_ext.h>

 

void Pedir_datos (int *base, int *altura);
void Calcular_base (int base, int altura, int *area);
void Imprimir_area (int area);

 

int main (void)
{
  int base, altura, area;

 

  Pedir_datos (&base, &altura);
  Calcular_base (base, altura, &area);
  Imprimir_area (area);

 

  return 0;
}

 

void Pedir_datos (int *base, int *altura)
{
  printf ("Bienvenido. Este programa calcula el área de un triángulo rectángulo.\n");
  printf ("Dame base: ");
  scanf ("%d", base);
  __fpurge(stdin);
  printf ("Dame altura: ");
  scanf ("%d", altura);
  __fpurge(stdin);
}

 


void Calcular_base (int base, int altura, int *area)
{
  *area=(base*altura)/2;
}

 

void Imprimir_area (int area)
{
  printf ("El área resultante es: %d\n", area);
  printf("Adiós. Vuelve pronto...\n");
}