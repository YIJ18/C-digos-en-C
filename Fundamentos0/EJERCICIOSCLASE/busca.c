#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define vacio 0
#define mina -1
#define banderas 4

void dif(char d, int *x, int *y);
void tablero();
void contarminas(int alto, int ancho, char Tablero[30][30]);

int main(void)
{
  tablero();
  return 0;
}

void tablero()
{
  char d, mostrar[30], Mostrar[30]; 
  int numm, sem, alto, ancho, sino, k=0;
  printf("Ingrese |f|, |m|, |d| ");
  printf("\nIngrese la dificultad: ");
  scanf("%c", &d);
//se define si quiere introducir el número de minas o no, si no introduce algo valido se vuelve a preguntar hasta que ingrese algo valido
    printf("\nIngresa 1 para SI ");
    printf("\nIngresa 2 para NO ");
do{
  printf("\n\nDesea ingresar el número de minas: ");
  scanf("%d", &sino);
  if(sino==1){
  printf("Ingrese el número de minas: ");
  scanf("%d", &numm);}
  
  else if(sino==2){
if(d=='f'){numm=11;}
if(d=='m'){numm=31;}
if(d=='d'){numm=51;}
  }
  }while(sino!=2&&sino!=1);
  printf("Ingrese la semilla: ");
  scanf("%d", &sem);

  dif(d, &alto, &ancho);

  int a = 1, toy, tox, x, y;
  char Tablero[30][30];
  int m;
  for (int i = 0; i < alto; i++)
  {
    for (int j = 0; j < ancho; j++)
    {
      Tablero[i][j] = vacio; // Llenamos de posiciones vacías el Tablero
    }
  }

  srand(sem);
  for (int i = 0; i < numm; i++)
  {

    tox = rand() % alto;
    toy = rand() % ancho;
    Tablero[tox][toy] = mina; // Lenamos el tablero de minas establecidas
  }

  // contar minas alrededor
contarminas(alto, ancho, Tablero);
  srand(sem);
  for (int i = 0; i < numm; i++)
  {

    tox = rand() % alto;
    toy = rand() % ancho;
    Tablero[tox][toy] = mina; // Lenamos el tablero de minas establecidas
  }

  for (int i = 0; i < alto; i++)
  {
    printf("\n");
    for (int j = 0; j < ancho; j++)
    {
      printf(" %d ", Tablero[i][j]); // Imprimimos el arreglo
    }
  }

  printf("\n");

  do
  {
    printf("\nIngresa la coordenada x: ");
    scanf("%d", &y);
    printf("Ingresa la coordenada y: ");
    scanf("%d", &x);
    printf("[%d, %d]", y, x);
    x--;
    y--;
    getchar();
    // Restamos 1 a cada valor, paara que se pongan en su debida coordenada
    system("clear");  
  mostrar[k]=x;
  Mostrar[k]=y;
    if (Tablero[x][y] == mina)
    {
      printf("\nLe diste a una mina");
    }
    else
    {
      int n=0;
      for (int i = 0; i < alto; i++)
      {
        printf("\n");
        for (int j = 0; j < ancho; j++)
        {
          
          if(i==  mostrar[n] && j== Mostrar[n]){  printf("  %d  ", Tablero[i][j]);}
          else{printf("%d", Tablero[i][j]);}
          n++;
        }
      }

      printf("\n\nIngresa otra coordenada");
    } 
  k++;
  } while (Tablero[x][y] != mina);
}

void dif(char d, int *x, int *y)
{
  if (d == 'd')
  {
    *x = 15;
    *y = 20;
    
  }
  else if (d == 'm')
  {
    *x = 10;
    *y = 15;
  }
  else if (d == 'f')
  {
    *x = 5;
    *y = 10;
  }
}


void contarminas(int alto, int ancho, char Tablero[30][30]){
int m;
  // contar minas alrededor
  for (int i = 0; i < alto; i++){
    for (int j = 0; j < ancho; j++){
      if (Tablero[i][j] == 0)
      {
        m = 0;
        if (i > 0 && j > 0 && Tablero[i - 1][j - 1] == mina)
        { m++; }// arriba izquierda
        if (i > 0 && Tablero[i - 1][j] == mina)
          { m++; } // arriba
        if (i > 0 && j < ancho - 1 && Tablero[i - 1][j + 1] == mina)
         { m++; } // arriba derecha
        if (j < ancho - 1 && Tablero[i][j + 1] == mina)
         { m++; }// derecha
        if (i < alto - 1 && j < ancho - 1 && Tablero[i + 1][j + 1] == mina)
         { m++; }// abajo derecha
        if (i < alto - 1 && Tablero[i + 1][j] == mina)
       { m++; }// abajo
        if (i < alto - 1 && j > 0 && Tablero[i + 1][j - 1] == mina)
         { m++; }// abajo izquierda
        if (j > 0 && Tablero[i][j - 1] == mina)
        { m++; } // izquierda
        Tablero[i][j] = m;
      }
  }}
}