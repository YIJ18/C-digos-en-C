#include<stdio.h>

/*Se definen las funciones que nos encontraremos más adelante*/
int primo(int n);
int leer (int n);
int error (int n);

int main(){
   int n;
   int c, w;
/*A n le dmos el valor de la función que llamamos, en este caso llamamos a a la función leer, por tanto sera el número que introduce el usuario*/
   n=leer(n);
  /*Con este for lo que hacemos es un contador, dentro de esta hacemos un if, que sive para decirnos que si la función primo es igual a 1, esta imprime el número */
      for(c=0;c<=n;c++){       
            if(primo(c)==1){
              printf("%d, ",c);
              }
        }
  /*Llama a la función error*/
  error(n);
    
   return 0;
}


/*Esta función es la que calcúla si es un número primo o no*/
int primo(int n){
   int i;
   int condicion;  
  /*Si n es diferente de 0 o uno lo que hace esta función, es crear un contador, el cual inicia en 2 y el número ingresado se va dividiendo entre el contador, lo que despúes hace es que cuenta cuantas veces se hace la operación, hasta que su residuo sea 0*/
    if(n!=1 && n!=0){
         for(i=2;i<=n;i++)       
          if(n%i==0)
            if(n==i) condicion=1;                
               else{ 
                condicion=0;
                return 0;}
      }
      else condicion=0;
   return condicion;
  }


/*Esta función lo que hace es que cuando el usuario ingrese un número negativo o 0, se termine el programa */
int error (int n){
    if(n<=0){
 printf("Ingresa un número valido xd");
  }
 
  return 0;
}
/*Esta función lo que hace es que le pide al usuario introducir hasta que número quire que le diga los números primos*/
int leer (int n){
printf("Por favor ingrese el numero: ");
  scanf("%i",&n);
  return n;
}
