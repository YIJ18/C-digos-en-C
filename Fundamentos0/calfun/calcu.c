#include <stdio.h>

/*int suma(int num1,int num2);
int rest(int num1,int num2);
int multi(int num1,int num2);
double div(int num1,int num2);
int residuo(int num1,int num2);*/


int main(void){

  int num1;
  int num2;
  char sum = '+';
  char resta= '-';
  char multiplicar='*';
  char dividir='/';
  char residual='%';
  char resultado;
  char operacion;


  printf("Ingresa el número 1:");
  scanf("%d",& num1);
  printf("Ingresa el número 2:");
  scanf("%d",& num2);
  printf("Ingresa el signo de la operación que desea hacer:");
  operacion=getchar();
  operacion=getchar();
 
 
  switch(operacion)
   {
   case '+':{
     resultado=suma(num1,num2);
     break;}
   case '-':{
     resultado=rest(num1,num2);
     break;}
   case '*':{
     resultado=multi(num1,num2);
     break;}
   case '/':{
     resultado=div(num1,num2);
     break;}
   case '%':{
     resultado=residuo(num1,num2);
     break;}
   }

  printf("El resultado es:%d", resultado);
  printf("\n");
 
    return 0;
}
