#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nodo
{
  int num;
  struct nodo *izq, *der;
};

void inserta(struct nodo **raiz, int i);
void borra(struct nodo *p);
void imprime(struct nodo *p);

int main()
{
  int i;
  struct nodo *raiz;
  raiz = NULL;
  printf("Numeros:   ");
  while (scanf("%d", &i) == 1)
    inserta(&raiz, i);
  printf("Numeros impresos: \n");
  imprime(raiz);
  borra(raiz);
}

void imprime(struct nodo *p)
{
  if (p != NULL)
  {
    imprime(p->izq);
    printf("%d ", p->num);
    imprime(p->der);
  }
}

void borra(struct nodo *p)
{
  if (p != NULL)
  {
    borra(p->izq);
    borra(p->der);
    free(p);
  }
}

void inserta(struct nodo **raiz, int i)
{
  struct nodo *posicion, *nuevo;

  posicion = *raiz;
  if ((nuevo = (struct nodo *)malloc(sizeof(struct nodo))) == NULL)
  {
    printf("No hay memoria\n");
    exit(1);
  }

  nuevo->num = i;
  nuevo->izq = NULL;
  nuevo->der = NULL;

  while (posicion != NULL)
  {
    if (i > posicion->num)
    {
      if (posicion->der != NULL)
        posicion = posicion->der;
      else
      {
        posicion->der = nuevo;
        return;
      }
    }
    if (i <= posicion->num)
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
