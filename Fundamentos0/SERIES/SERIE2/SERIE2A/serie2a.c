#include <stdio.h>

/*Este programa compara dos cadenas*/

int cadena(char arr1[], char arr2[]);

int main(void) {
  char arr1[100];
  char arr2[100];

  printf("Ingresa la primera frase: ");
  scanf("%[^\n]",arr1);

  printf("Ingresa la segunda frase: ");
  getchar();
  scanf("%[^\n]",arr2);
  
  if(cadena (arr1, arr2)==0){
    printf("Las cadenas son diferentes");
  }
  if(cadena (arr1, arr2)==1){
    printf("Las cadenas son iguales");
  }

  
  return 0;
}

/*Está función compara dos arreglos para evaluar si, estos dos son inguales.
*@param arr1: arreglo tipo caracter; primera cadena para comparar.
*@param arr2: arreglo tipo caracter; segunda cadena para comparar.
*@return regresa un '0', si son diferentes.
*@return regresa un '1', si son iguales.
*/

int cadena(char arr1[], char arr2[]){
  int i, x, contador=0,y;
  x=0;
  y=0;

  while (arr1[x]!='\0' || arr2[y]!='\0')
    {
      x++;
      y++;
    }
  
  for(i=0; i<100; i++){
    if(arr1[i]=='\0'||arr2[i]=='\0')
    {
      i=100;
    }
    if(arr1[i]==arr2[i]){
      contador++;
      }
    
    }

  if(contador != x)
  {
   return 0;
  }
  if (contador == x && contador == y)
  {
    return 1;
  }

}
