#include<stdio.h>
void calcular(int base, int altura, int profundidad, int* peri, int* area, int* vol);
void leer(int* dato);

int main(void){
  int base=0;
  int altura=0;
  int profundidad=0;

  int area=0;
  int perimetro=0;
  int volumen=0;
  
  printf("Ingresa la base: ");
  leer(&base);
  printf("\nIngresa la altura: ");
  leer(&altura);
  printf("\nIngresa la profundidad: ");
  leer(&profundidad);
  
  calcular(base, altura, profundidad, &perimetro, &area, &volumen);
  
  printf("\nPeri: %d ", perimetro);
  printf("\nArea: %d ", area);
  printf("\nVolumen: %d ", volumen);
  

  return 0;
}


void leer(int* dato){
  scanf("%i", dato);
}

void calcular(int base, int altura, int profu, int* peri, int* area, int* vol){
  int perimetro= (base * 2) + (altura * 2);
  *peri = perimetro;
  *area = base * altura;
  *vol = *area * profu;
  
}
