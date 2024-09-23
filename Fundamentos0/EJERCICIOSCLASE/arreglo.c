#include <stdio.h>
void entrada(int arreglo[]);
void salida( int arreglo[]);
int main(void){
  int arreglo[10];
  int i;

entrada(arreglo);

salida(arreglo);
    
  return 0;
}

void entrada(int arreglo[]){
  int i;
    for(i=0; i<10; i++)
    {
        printf("Escoge un número: \n");
      scanf("%d", &arreglo[i]);}

}
void salida(int arreglo[]){
    int i;
    for(i=0; i<10; i++)
    {
        printf("\n");
      printf("-%d.\n", arreglo[i]);}

}
