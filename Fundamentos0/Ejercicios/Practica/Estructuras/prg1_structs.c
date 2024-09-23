#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

//Ingrese estructura aqui

typedef struct artistas
{
  char nombre[100];
  char album [100];
  char cancionfav[100];
  int anio;
  float duracion;
  
} tipoartistas;

//Declaración y definición 
void Solicitar (int contador, char array[]);

int main (void)
{
  int contador;
  
  return 0;
}

void Solicitar (int contador, char array[])
{
  printf("Ingresa el nombre del cantante");
  __fpurge(stdin);
  gets(array[contador].nombre);
}

