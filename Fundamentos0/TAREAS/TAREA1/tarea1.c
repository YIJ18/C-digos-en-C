#include <stdio.h>

int main(void) {
/*Se definen las primeras variables que vamos a utilizar para todo el programa, tanto en entero como en caracter para la tabla ascii*/
  int R, RE, n1, n2;
/*Para despues convertir un entero a caracter*/
  char ca, co;
/*El programa nos dice para que funciona y nos piden las primeras variables*/
  printf("Este programa te dice el número mayor, si son multiplos y si alguno de ellos representa un carácter arábigo\n ");
  printf("\nIngresa un número: ");
  scanf("%d",&n1);
  printf("\nIngresa un número: ");
  scanf("%d",&n2);
  /*Compara el número 1 y 2 para ver cual es el número mayor y lo imprime en nuestro prgrama*/
  if(n1>n2)
  {
    printf("\nEl número mayor es: %d\n",n1);
    
  }
  else if(n2>n1)
  {
    printf("\nEl número mayor es: %d\n",n2);
    
  }
    else if(n2==n1)
  {
    printf("\nEl número mayor es: %d\n",n2);
    
  }
  /*Usamos R y RE, para guardar el resultado del residuo en nuestras variables para poder saber si son multiplos o no; en los siguientes if nos dice que si su residuo es 0 nos muestre en pantalla las divisiones enteras y que es multiplo de que; si no es asi nos muestra un mensaje de que no son multiplos*/
R=n1%n2;
RE=n2%n1;
  if(R==0 && RE==0 )
  {
    printf("\n\n%d  es múltiplo de %d; la división entera es: %d/%d \n",  n1, n2, n2, n1);
    }
  
 else  if(R==0 )
  {
    printf("\n\n%d no es múltiplo de %d; la división entera es: %d/%d \n",  n1, n2, n2, n1);
     printf("\n%d es múltiplo de %d; la división entera es: %d/%d \n",n2, n1, n1, n2);
    }
  
 else if(RE==0 )
  {
    printf("\n%d es múltiplo de %d; la división entera es: %d/%d \n",  n1, n2, n2, n1);
     printf("\n%d no es múltiplo de %d; la división entera es: %d/%d \n",n2, n1, n1, n2);
    }

  if(R!=0 && RE!=0)
  {
    printf("\nNo son múltiplos\n");
    }

  /*Convertimos nuestros numeros a caracteres de texto, para asi poder ver si el número que introduce el usuario pertenece a algun caracter del código ascii*/

ca=n1;
co=n2;
  
  if(ca>=97 && ca<=122||ca>=48 && ca<=57 ||ca>=65 && ca<=90)
  {
    printf("\nEn código ASCII, el carcter %d es: %c\n", n1, ca);
  }

    else{
     
      printf("\nEl número %d no pertenece a ningún carcter en código ASCII\n", n1);
        }
  
  if(co>=97 && co<=122||co>=48 && co<=57 ||co>=65 && co<=90)
  {
    printf("\nEn código ASCII, el carcter %d es: %c\n", n2, co);
  }

    else{
      printf("\nEl número %d no pertenece a ningún carcter en código ASCII\n",n2);
        }
  
  return 0;
}
