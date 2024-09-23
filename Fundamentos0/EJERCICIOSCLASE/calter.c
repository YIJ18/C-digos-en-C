#include <stdio.h>
#include <math.h>

double pot(int n1, int n2);
double raiz(int n1, int n2, char op);

int main(int argc, char*argv[]) {


float r;
 int n1, n2;
  char multiplicacion ='*';
  char division ='/';
  char suma ='+';
  char resta ='-';
  char residuo ='%';
  char op;
  double re, x, y;
 
  if(argc==4){
    sscanf(argv[1],"%i",&n1);
    sscanf(argv[2],"%c",&op);
    sscanf(argv[3],"%i",&n2);

      if(op=='*'){
  r= n1*n2;
    printf("El resultado es: %.2f", r);
  }
  else if(op=='/'){
  x=(double)n1;
  y=(double)n2;
  re= x/y;
    printf("El resultado es: %.2lf", re);
  }
  else if(op=='+'){
  r= n1+n2;
    printf("El resultado es: %.2f", r);
  }
  else if(op=='-'){
  r= n1-n2;
    printf("El resultado es: %.2f", r);
  }
  else if(op=='%'){
  r= n1%n2;
    printf("El resultado es: %.2f", r);
  }
  else if(op=='^'){
    pot(n1, n2);
   }
  else if(op=='R' || op=='r'){
    raiz(n1, n2, op);
   }

  else{ 
    printf("Error");
  }
    }


  return 0;
}

double pot(int n1, int n2){
double r;
r= pow(n1, n2);
printf("El resultado es: %lf", r);
return 0;}

double raiz(int n1, int n2, char op){
double r;
if(op=='R'){
r= sqrt(n1);
printf("El resultado es: %lf", r);
}
return 0;}



