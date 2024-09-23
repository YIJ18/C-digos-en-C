#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_complejos
{
  double operando1[100];
  double operando2[100];
  char resultado[100];
  int num, nums, num2, nums2;
  char sig, signs;
}tipocomp;


void Menu(int *op);
void Leer_archivo(tipocomp *operacion, int *i, char *signo);
void Guardar_archivo(tipocomp *operacion, int i, char *signo);
void Suma(tipocomp *operacion, int i);
void Resta(tipocomp *operacion, int i);
void Multi(tipocomp *operacion, int i);
void Div(tipocomp *operacion, int i);
void Resultados(tipocomp *operacion, int i);
void ingresar(tipocomp *operaciones,int i, char *signo);

int main(void)
{
  tipocomp operacion[100];
  char signo [100];
  int op, i;
  do
    {
      Menu(&op);
      if(op == 1)
	{
	 Leer_archivo(operacion, &i, signo);
	 if (signo[i] == '+')
	   Suma(operacion, i);
	 else if (signo[i] == '-')
	    Resta(operacion,i);
	 else if (signo[i] == 'x')
	    Multi(operacion,i);
	 else  if (signo[i] == '/')
	    Div(operacion,i);
      }
      else if (op == 2)
	Guardar_archivo(operacion, i, signo);
      else if(op == 3)
	Resultados(operacion,i);
      else if(op == 5)
	{
	  ingresar(operacion, i, signo);
	  i++;
	}
    }while(op != 4);
  
  return 0;
}

void Menu(int *op)
{
  printf("---------------------");
  printf("\n1. Leer operacion");
  printf("\n2. Guardar archivo");
  printf("\n3. Leer archivo de texto resustados\n4. Salir");
  printf("\n5. Ingresa una operacion");
  scanf("%d", op);
}


void Leer_archivo(tipocomp *operacion, int *i, char *signo)
{
  FILE *archivo;
  char nomarch[100];
  int j = 0;
  __fpurge(stdin);
  printf("\nIngresa el nombre del archivo en la que lo quieres guardar: ");
  fgets(nomarch, 99, stdin);
  nomarch[strlen(nomarch)-1]=0;
  archivo = fopen(nomarch, "rt");
  if(archivo != NULL)
    {
      while(!feof(archivo))
	{
	  fscanf(archivo, "(%d%c%d)%c(%d%c%d)\n", &operacion[j].num,&operacion[j].sig,&operacion[j].num2, &signo[j], &operacion[j].nums,&operacion[j].signs,&operacion[j].nums2);
	  j++;
	}
      fclose(archivo);
      *i=j;
    }
}
void Resultados(tipocomp *operacion, int i)
{
  FILE *archivo;
  int j = 0;
  archivo = fopen("resultados.txt", "wt");
  do{
    if (archivo != NULL)
    {
      for (j = 0; j < i; j++)
	fprintf(archivo, "%lf+%lfi\n",operacion[j].operando1[j], operacion[j].operando2[j]);
      fclose(archivo);
    }
        else
	printf("No ingreso un nombre vàlido");
   }while(archivo == NULL);
}
 
void Guardar_archivo(tipocomp *operacion, int i, char *signo)
{
  FILE *archivo;
  char nomarch[100];
  int j = 0;
 do
   {printf("\nIngresa el nombre del archivo en la que lo quieres guardar: ");
     __fpurge(stdin);
  fgets(nomarch, 99, stdin);
  __fpurge(stdin);
  nomarch[strlen(nomarch)-1]=0;
  getchar();
  archivo = fopen(nomarch, "wt");
      if(archivo != NULL)
	{
	  for (j = 0; j < i; j++)
	    fprintf(archivo, "(%d%c%d)%c(%d%c%d)\n", operacion[j].num, operacion[j].sig, operacion[j].num2,signo[j], operacion[j].nums, operacion[j].signs, operacion[j].nums2);
	  fclose(archivo);
	}
      else
	printf("No ingreso un nombre vàlido");
   }while(archivo == NULL);
}

void ingresar(tipocomp *operaciones,int i, char *signo)
{
  printf("Ingresa el elemento 1 (num+numi)");
  scanf("%d%c%di",&operaciones[i].num,&signo[i],&operaciones[i].nums);
  printf("\nIngresa el elemento 2 (num+numi)");
  scanf("%d%c%di",&operaciones[i].num2,&signo[i],&operaciones[i].nums2);
}

void Suma(tipocomp *operacion, int i)
{
  char temp, temp2[100];
  operacion[i].operando1[i] = operacion[i].num + operacion[i].num2;
  operacion[i].operando2[i] = operacion[i].nums + operacion[i].nums2;
 
}

void Resta(tipocomp *operacion, int i)
{
  operacion[i].operando1[i] = operacion[i].num - operacion[i].num2;
  operacion[i].operando2[i] = operacion[i].nums - operacion[i].nums2;
}

void Multi(tipocomp *operacion, int i)
{
  operacion[i].operando1[i] = operacion[i].num - operacion[i].num2;
  operacion[i].operando2[i] = operacion[i].nums - operacion[i].nums2;
    
}

void Div(tipocomp *operacion, int i)
{
  operacion[i].operando1[i] = operacion[i].num / operacion[i].num2;
  operacion[i].operando2[i] = operacion[i].nums / operacion[i].nums2;
}
