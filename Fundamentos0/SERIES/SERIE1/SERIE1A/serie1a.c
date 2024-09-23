
/*
@file: Ejercicio A
@brief:Descompone números
@details:Programa que descompone en sus componentes exponenciales un número introducido por el usuario
@author:Iris Yulit Jasso Cortes
@date: 20-Octubre-2022
*/
#include <stdio.h>
/*@Declaración de la Funcion en la que descomponemos los números y lo imprimimos*/

void des(int n);

/*@La función principal la usamos, solo para leer la entrada de usuario y llamar a la función des*/
int main(void)
{
  int n;
  printf("Ingresa el Número a descomponer: ");
  scanf("%d", &n);
  printf("Tu número descompuesto es:\n");
  des(n);
  return 0;
}
/*@Funcion en la que descomponemos los números y lo imprimimos*/
void des(int n)
{
  int y, z, d, res;
  /*contador que toma el número, para dividirlo y con el residuo imprimir el número que se multiplica por 10^z (z es el contador)*/
  for (z = 0; n != 0; z++)
  {
    res = n % 10;
    n = n / 10;
    printf("%dx10^%d\n", res, z);
  }
  /*@return: No retorna nada*/
}
