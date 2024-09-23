#include <stdio.h>
/*Se declara la función que usaremos más adelante*/
int linea(int lado);

/*Es la función principal*/
int main(void) {
  int lado, y, z;
  y=0;
  /*Se pide que el usuario introduzca el tamaño del cuadrado y lo guarda en la variable lado*/
  printf("Introduce el tamaño del cuadrado: ");
  scanf("%d",&lado);
  
/* z lo usamos para llamar a una función, y lo usamos como ocntador hasta que sea menor a lado y se imprime un espacio*/
  while (y<lado){
  z= linea(lado);
  y=y+1;
  printf("\n");
  }
  

  return 0;
}

int linea (int lado ){
  int x;
  x=0;
    /*Con esta función lo  que hacemos es crear una fila de asteriscos según el número ingresado*/
  while(lado>x){
  printf("*");
  x=x+1;
  }
  
  return 0;
}
