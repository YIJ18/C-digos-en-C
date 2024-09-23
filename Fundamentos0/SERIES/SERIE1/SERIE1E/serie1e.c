/*
@FILE: EJERCICIO E
@BRIEF:  MULTIPLOS
@DETAILS: PROGRAMA QUE IMPRIME UNA SERIE DE NÚMEROS QUE SUMADOS DEN UN NÚMERO
@AUTHOR: IRIS YULIT JASSO CORTES
@DATE: 20-OCTUBRE-2020
*/

#include <stdio.h>

/*
@PARAMENTROS QUE PIDEN LA ARIABLE INICIAL
*/
int fo3(int a); int fo4(int a); int fo5(int a); int fo6(int a); int fo7(int a); int fo8(int a); int fo9(int a); int fo10(int a);

//@FUNCIÓN  PRINCIPAL
int main(void) {
  int a;
  printf("Ingresa el número a evaluar: ");
  scanf(" %d", &a);
  fo3(a);
  fo4(a);
  fo5(a);
  fo6(a);
  fo7(a);
  fo8(a);
  fo9(a);
  fo10(a);

  return 0;
}
//FUNVIONES QUE CALCULAN LA SERIE DEL 3 EN ADELANTE, YA QUE SON 3 TERMINOS O MÁS, LOS QUE SE SUMAN
int fo3(int a){
int n, con, y, z, w, ot;
int r;
z=3;

r=a%z;
if(r==0){
  for(con=0;con<z;con++){
  n=a-con;
  y=n/z;
  }
  for(w=0;w<z;w++){
  ot=y+w;
  printf("%d", ot);
  printf("+");
  }
}
  printf("\n");

return 0;
}

int fo4(int a){
int n, con, y, z, w, ot;
int r;
z=4;
n=a-6;
y=n/z;
r=n%z;
if(r==0){
  for(w=0;w<z;w++){
  ot=y+w;
  printf("%d", ot);
  printf("+");
  }
}
  printf("\n");

return 0;
}

int fo5(int a){
int n, con, y, z, w, ot;
int r;
z=5;
n=a-10;
y=n/z;
r=n%z;
if(r==0){
  for(w=0;w<z;w++){
  ot=y+w;
  printf("%d", ot);
  printf("+");
  }
}
  printf("\n");

return 0;
}

int fo6(int a){
int n, con, y, z, w, ot;
int r;
z=6;
n=a-15;
y=n/z;
r=n%z;
if(r==0){
  for(w=0;w<z;w++){
  ot=y+w;
  printf("%d", ot);
  printf("+");
  }
}
  printf("\n");

return 0;
}

int fo7(int a){
int n, con, y, z, w, ot;
int r;
z=7;
n=a-21;
y=n/z;
r=n%z;
if(r==0){
  for(w=0;w<z;w++){
  ot=y+w;
  printf("%d", ot);
  printf("+");
  }
}
  printf("\n");

return 0;
}

int fo8(int a){
int n, con, y, z, w, ot;
int r;
z=8;
n=a-28;
y=n/z;
r=n%z;
if(r==0){
  for(w=0;w<z;w++){
  ot=y+w;
  printf("%d", ot);
  printf("+");
  }
}
  printf("\n");

return 0;
}

int fo9(int a){
int n, con, y, z, w, ot;
int r;
z=9;
n=a-36;
y=n/z;
r=n%z;
if(r==0){
  for(w=0;w<z;w++){
  ot=y+w;
  printf("%d", ot);
  printf("+");
  }
}
  printf("\n");

return 0;
}

int fo10(int a){
int n, con, y, z, w, ot;
int r;
z=9;
n=a-45;
y=n/z;
r=n%z;
if(r==0){
  for(w=0;w<z;w++){
  ot=y+w;
  printf("%d", ot);
  printf("+");
  }
}
  printf("\n");

return 0;
}
