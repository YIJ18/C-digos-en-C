#include<stdio.h>

int  main(void)
{
  /*Programa que calcula el radio, area, volumen y perimetro de un circulo; declaro las primeras variables y constante*/
  const float pi = 3.1416;
  float D, r, a, p, v;
  
  /*se pide el dato que necesitamos*/
  printf("Introduce el Diametro del Circulo: ");
  scanf("%f", &D);
  
  /* se hacen las operaciones que pedimos y se guardan en su variable*/
  r = D/2;
  a = r*r*pi;
  p = 2*pi*r;
  v = 4/3*pi*r*r*r;


  /*se escriben los resultados de las variables*/
  
  printf("Tu radio es: %f\n", r);
  
   
  printf("Tu área es: %f\n", a );

   
  printf("Tu perimetro es: %f\n", p);

  
  printf("Tu volumen es: %f\n", v);

  return 0;
  
}

