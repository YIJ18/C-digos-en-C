#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

struct nodo
{
  char nombre[100];
  struct nodo *izq, *der;
};

void inserta(struct nodo **raiz, char *nomb);
void borra(struct nodo *p);
void imprime(struct nodo *p);
void guardar(struct nodo *raiz);
void guarda_2(struct nodo *p, FILE *archivo);
void leer(struct nodo **raiz);

int main()
{
  int i, a = 0;
  char nomb[100];
  struct nodo *raiz;
  raiz = NULL;
  printf("Cadenas:   ");
  /* while (a < 5)
  {
    __fpurge(stdin);
    scanf("%[^\n]", nomb);
    inserta(&raiz, nomb);
    a++;
    }*/
  leer(&raiz);
  printf("Numeros impresos: \n");
  // guardar(raiz);
  imprime(raiz);
  borra(raiz);
}

void imprime(struct nodo *p)
{
  if (p != NULL)
  {
    imprime(p->izq);
    puts(p->nombre);
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

void inserta(struct nodo **raiz, char *nomb)
{
  struct nodo *posicion, *nuevo;

  posicion = *raiz;
  if ((nuevo = (struct nodo *)malloc(sizeof(struct nodo))) == NULL)
  {
    printf("No hay memoria\n");
    exit(1);
  }
  strcpy(nuevo->nombre, nomb);
  // = nomb;
  nuevo->izq = NULL;
  nuevo->der = NULL;

  while (posicion != NULL)
  {
    if (strcmp(nuevo->nombre, posicion->nombre) > 0)
    {
      //  if(i>posicion->nomb){
      if (posicion->der != NULL)
        posicion = posicion->der;
      else
      {
        posicion->der = nuevo;
        return;
      }
    }
    if (strcmp(nuevo->nombre, posicion->nombre) <= 0)
    {
      // if(i<=posicion->num){
      if (posicion->izq != NULL)
      {
        posicion = posicion->izq;
      }
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

void guardar(struct nodo *raiz)
{
  FILE *archivo;
  archivo = fopen("archivo.txt", "wt");
  guarda_2(raiz, archivo);
  fclose(archivo);
}
void guarda_2(struct nodo *p, FILE *archivo)
{
  struct nodo *temp;
  temp = p;
  if (temp != NULL)
  {
    guarda_2(temp->izq, archivo);
    fprintf(archivo, "%s\n", temp->nombre);
    guarda_2(temp->der, archivo);
  }
}

void leer(struct nodo **raiz)
{
  FILE *archivo;
  char nombre[100];
  archivo = fopen("archivo.txt", "rt");
  if (archivo != NULL)
  {
    while (fgets(nombre, 99, archivo) != NULL)
    {
      nombre[strlen(nombre) - 1] = 0;
      inserta(raiz, nombre);
    }
  }
  fclose(archivo);
}
