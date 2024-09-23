#include <stdio.h>
void minus(char arr1[]);
int cadena(char arr1[]);
void espacio(char arr1[], char arr2[]);

int main(void)
{
  char arr1[100];

  printf("Ingresa la frase: ");
  scanf("%[^\n]", arr1);

  if (cadena(arr1) == 0)
  {
    printf("La frase ingresada no es un palíndromo");
  }
  if (cadena(arr1) == 1)
  {
    printf("La frase ingresada es un palíndromo");
  }

  return 0;
}

/* Está función compara el arreglo al derecho y al reves.
*@param arr1: arreglo tipo caracter; arr1 cadena para comparar.
*@return regresa un '0', si son diferentes.
*@return regresa un '1', si son iguales.
*/
int cadena(char arr1[])
{
  char arr2[100];
  int i, contador = 0, x = 0, y = 0, z = 0, temp=0;
  minus(arr1);
  espacio(arr1, arr2);

  while (arr2[x] != '\0')
  {
    x++;
    z++;
    temp++;
  }
  for (i = 0; i <temp; i++)
  {
    z--;


    if (arr2[i] == arr2[z])
    {
      contador++;
    }
  }
  if (contador != x)
  {
    return 0;
  }
  if (contador == x)
  {
    return 1;
  }
}
/* Está función quita todos los espacios de arr1 y pega la cadena sin espacios en arr2
*@param arr1: arreglo tipo caracter; arr1 cadena para quitar espacios.
*@param arr2: arreglo tipo caracter; arr2 cadena para pegar la cadena sin espacios.
*@return no retorna nada
*/
void espacio(char arr1[], char arr2[])
{
  int i = 0, j = 0;
  while (arr1[i] != '\0')
  {
    if (arr1[i] != ' ')
    {
      arr2[j] = arr1[i];
      j++;
    }
    i++;
  }
}
/* Está función convierte el arreglo en minusculas.
*@param arr1: arreglo tipo caracter; arr1 cadena para convertir.
*@return no retorna nada
*/
void minus(char arr1[])
{
  int y;
  for (y = 0; y < arr1[y]; y++)
  {
    if (arr1[y] <= 'Z' && arr1[y] >= 'A')
    {
      arr1[y] = arr1[y] + 32;
    }
  }
}
