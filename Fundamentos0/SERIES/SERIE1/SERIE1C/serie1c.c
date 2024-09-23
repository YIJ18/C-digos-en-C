/*
@file: Ejercicio c
@brief:Hace un triaungulo
@details:Realizar un programa que imprima en pantalla un triángulo escaleno de base n, n siendo un número entero dado por el usuario. El programa debe validar la entrada.
@author:Iris Yulit Jasso Cortes 
@date: 20-Octubre-2022   
*/
#include <stdio.h>


/*@Declaración de la Funcion en la que hacemos un cuadrado*/
int ko(int n, int z);

/*@Declaración de la variable principal*/
int main(void) {
/*@Parámetros: inicialuzados en 0 para poder ir añadiendo esñacio por espacio*/
  int n, x, z;
  z=0;
  printf(" Programa que imprime un triangulo escaleno\n");
  printf("Introduce la base de el triangulo: ");
  scanf("%d", &n);
  for(x=0;x<n;x++){
    z++;
    ko(n, z);
    printf("\n");
  }
/*@Retorna un 0, para indicar wie goda la función salio bien*/
  return 0;
}

/*Parametro: Funcion declarada, junto a las variables de otra función dentro, ñara poderlas usar dentro de está, imprime lls asteriscos*/
int ko(int n, int z){
int y;
for(y=0;y<z;y++){
  printf("*");
  }
/*@Retorna, no retorna nada*/
}
