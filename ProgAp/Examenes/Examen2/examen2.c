#include <stdio.h>
#include <stdlib.h>

typedef struct def_funciones
{
  int valor;
  struct def_funciones *izq, *der;
}tipoFun;

void ingresar(tipoFun **raiz, int valor);
void altura(tipoFun *raiz, int *n_altura);
void izquierda(tipoFun *raiz, int *n_izq);
void derecha(tipoFun *raiz, int *n_der);
void Num_nodos(tipoFun *raiz, int *n_nodos);
void Num_hojas(tipoFun *raiz, int *n_hojas);
int mas_peque(tipoFun *raiz);
int mas_grande(tipoFun *raiz);

int main (void)
{
  tipoFun *raiz = NULL;
  int op, numero, num_hojas=0, num_nodos=0,num_altura=0, min=0, max=0;
  do
    {
      printf("\n------- M E N U---------- ");
      printf("\n1. Ingresar nuevo");
      printf("\n2. Numero de nodos");
      printf("\n3. Numero de hojas");
      printf("\n4. Altura de arbol");
      printf("\n5. Valor más pequeño");
      printf("\n6. Valor mas grande");
      printf("\n7. Salir del programa");
      printf("\n--Dame op: ");
      scanf("%d", &op);
      
      if (op == 1)
	{
	  printf("Ingresa el número: ");
	  scanf("%d", &numero);
	  ingresar(&raiz, numero);
	}
      else if(op == 2)
	{
	   Num_nodos(raiz, &num_nodos);
	   printf("\nEl numero de nodos son: %d", num_nodos);
	}
      else if (op == 3)
	{
	  Num_hojas(raiz, &num_hojas);
	  printf("\nEl numero de hojas son: %d", num_hojas);
	}
      else if(op == 4)
	{
	  altura(raiz, &num_altura);
	    printf("\nLa altura es: %d",num_altura);
	}
      else if(op == 5)
	{
	  min =  mas_peque(raiz);
	  printf("\nEl numero más pequeño del arbol es: %d", min);
	}
      else if (op == 6)
	{
	   max = mas_grande(raiz);
	   printf("\nEl numero más grande del arbol es: %d", max);
	}
     
    }while(op!=7);
  return 0;
}

void ingresar(tipoFun **raiz, int valor)
{
  tipoFun  *posicion, *nuevo;

  posicion = *raiz;
  nuevo = (tipoFun*)malloc(sizeof(tipoFun));
  nuevo->valor = valor;
  nuevo->izq = NULL;
  nuevo->der = NULL;

  while (posicion != NULL)
  {
    if (valor > posicion->valor)
    {
      if (posicion->der != NULL)
        posicion = posicion->der;
      else
      {
        posicion->der = nuevo;
        return;
      }
    }
    if (valor <= posicion->valor)
    {
      if (posicion->izq != NULL)
        posicion = posicion->izq;
      else
      {
        posicion->izq = nuevo;
        return;
      }
    }
  }
  posicion = nuevo;
  *raiz = posicion;
}

void altura(tipoFun *raiz, int *n_altura)
{
  int n_izq = 0, n_der = 0;
  if (raiz == NULL)
    *n_altura = 0;
  else
    {
      izquierda(raiz, &n_izq);
      derecha(raiz, &n_der);
      if(n_izq>n_der)
	*n_altura = n_izq;
      else
	*n_altura = n_der;
    }
}
void izquierda(tipoFun *raiz, int *n_izq)
{
   if (raiz != NULL)
     {
       izquierda(raiz->izq, n_izq);
       (*n_izq)++;
     }
}
  
void derecha(tipoFun *raiz, int *n_der)
{
     if (raiz != NULL)
     {
       izquierda(raiz->der, n_der);
       (*n_der)++;
     }
}
void Num_nodos(tipoFun *raiz, int *n_nodos)
{
  if(raiz!=NULL)
    {
      Num_nodos(raiz->izq, n_nodos);
      (*n_nodos)++;
      Num_nodos(raiz->der,n_nodos);
    }
}

void Num_hojas(tipoFun *raiz, int *n_hojas)
{
  if(raiz!= NULL)
    {
      Num_hojas(raiz->izq, n_hojas);
       if(raiz->izq==NULL && raiz->der==NULL)
	(*n_hojas)++;
      Num_hojas(raiz->der, n_hojas);
    }
}

int mas_peque(tipoFun *raiz)
{
  while (raiz != NULL && raiz->izq != NULL)
    raiz = raiz->izq;
  return raiz->valor;
}

int mas_grande(tipoFun *raiz)
{
  while(raiz != NULL && raiz->der != NULL)
    raiz= raiz->der;
  return raiz->valor;
}
