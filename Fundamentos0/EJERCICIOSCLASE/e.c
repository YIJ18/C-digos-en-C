#include<stdio.h>

int eu(float n);
float suma(float n);
int expo(float n);

int main(void){
  float n;
  printf("Ingresa el número de decimales: ");
  scanf("%f", &n);
  expo(n);
  return 0;
}

int eu(float n){
  int x;
  float y, z, w;
  for(x=1;x<=n;x++){
  }

return 0;
}

float suma(float n){
  float y, fac;
  y=1+(1/n);
  return y;
}

int expo(float n){
  int con;
  float no;
  no=suma(n);
  for(con=1; con<n; con++){
    no=suma(n)*no;
  }
  printf("%f", no);
  return 0;
}
