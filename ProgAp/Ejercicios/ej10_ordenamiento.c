#include <stdio.h>

void Ingresar(int *numeros, int cont);
void Ordenar(int *numeros, int i);
void Imprimir(int *numeros, int cont);

int main (void)
{
  int numeros[15], cont = 0;
  for (cont = 0; cont < 15; cont++)
    {
      Ingresar(numeros, cont);
      Ordenar(numeros, cont);
      Imprimir(numeros, cont);
    }
  return 0;
}

void Ingresar(int *numeros, int cont)
{
  printf("\nIngresa un nùmero: ");
  scanf("%d",&numeros[cont]);
}

void Ordenar(int *numeros, int i)
{
  int j, temp;
    for (j = 0; j < i + 1; j++)
    {
        if (i == 0 || j == 0)
            numeros[j] = numeros[j];
        else
        {
            if (numeros[i] < numeros[j - 1])
            {
                temp = numeros[i];
                numeros[i] = numeros[j - 1];
                numeros[j - 1] = temp;
            }
        }
    }
}

void Imprimir(int *numeros, int cont)
{  int i;
  for (i = 0; i < 15; i++)
    {
      if (i <= cont)
	printf("%d,",numeros[i]);
      else
	printf("x, ");
    }
  printf("\n");
}
