#include <stdio.h>

int main(void) {
  //Se declaran las variables que usaremos en cada while-for
  int x,y,z;
  //Se declara x=0, para que no tome ot valor
  x=0;
  //mientras x sea menor a 10 se imprimira 
  while(x<10){
    x=x+1;
    printf("%d\n",x);
  }
  //se declara for, definimos que es y, mientras y sea menor o igual a 10, se le suma uno a y
for(y=1;y<=10;y++){
   printf("%d\n",y);
}
//se define z, se declara que hace, mientras z sea igual o menor a 10
  z=1;
do{
  printf("%d\n",z);
  z++;
}
  while(z<=10);
  return 0;
}
