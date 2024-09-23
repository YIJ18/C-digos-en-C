#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct def_alumno
{
  char nombre[200];
  double cal1;
  double cal2;
  double cal3;
  double promedio;
} tipoAlumno;

void menu(int *op);
void datos(int i, tipoAlumno *alumnos);
void imprimir(int i, tipoAlumno *alumno);
void imprimir_prom(int i, tipoAlumno *alumnos);
void leer_archivo(tipoAlumno *alumnos, int *i);
void guardar_archivo(tipoAlumno *alumnos, int i);
void busca_nombre(tipoAlumno *alumnos, char *nombreB);
void guardar_bin(tipoAlumno *alumnos, int i);
void leer_bin(tipoAlumno *alumnos, int *i);

int main(void)
{
  tipoAlumno alumnos[10];
  int op, i = 0;
  char nombreB[200];
  do
  {
    menu(&op);
    if (op == 1)
    {
      datos(i, alumnos);
      system("clear");
      i++;
    }
    else if (op == 2)
      imprimir(i, alumnos);
    else if (op == 3)
      imprimir_prom(i, alumnos);
    else if (op == 4)
      leer_archivo(alumnos, &i);
    else if (op == 5)
      guardar_archivo(alumnos, i);
    else if (op == 6)
      guardar_bin(alumnos, i);
    else if (op == 7)
      busca_nombre(alumnos, nombreB);
    else if (op == 8)
      leer_bin(alumnos, &i);
    else if (op == 9)
    {
      printf("Presione < enter > para salir.");
      __fpurge(stdin);
      getchar();
    }
    else
      printf("No ingresaste una opción válida.\n");
  } while (op != 9 && op < 10 && op > 0);

  return 0;
}

void menu(int *op)
{
  printf("\n---------------Menú----------------\n");
  printf("1. Ingresar datos alumnos.\n");
  printf("2. Mostrar alumnos.\n");
  printf("3. Sacar promedios.\n");
  printf("4. Leer de un archivo de texto.\n");
  printf("5. Guardar de un archivo de texto.\n");
  printf("6. Guardar archivos en archivo binario.\n");
  printf("7. Busca en nombre en el archivo.\n");
  printf("8. Leer en binario.\n");
  printf("9. Salir.\n");
  printf("Ingresa la opción del menú: ");
  scanf("%d", op);
  printf("\n");
}

void datos(int i, tipoAlumno *alumnos)
{
  __fpurge(stdin);
  printf("Ingresa el nombre: ");
  gets(alumnos[i].nombre);
  printf("\nIngresa calificación 1: ");
  scanf("%lf", &(alumnos[i].cal1));
  printf("\nIngresa la calficación 2: ");
  scanf("%lf", &(alumnos[i].cal2));
  printf("\nIngresa la calficación 3: ");
  scanf("%lf", &(alumnos[i].cal3));

  alumnos[i].promedio = (alumnos[i].cal1 + alumnos[i].cal2 + alumnos[i].cal3) / 3;
}

void imprimir_prom(int i, tipoAlumno *alumnos)
{
  int j;
  for (j = 0; j < i; j++)
    printf("El promedio del estudiante %s es : %.2lf\n", alumnos[j].nombre, alumnos[j].promedio);
}

void imprimir(int i, tipoAlumno *alumnos)
{
  int j;

  for (j = 0; j < i; j++)
  {
    printf("Nombre del alumno: %s\n", alumnos[j].nombre);
    printf("Calificación 1: %.2lf\n", alumnos[j].cal1);
    printf("Calificación 2: %.2lf\n", alumnos[j].cal2);
    printf("Calificación 3: %.2lf\n\n", alumnos[j].cal3);
  }
}

void leer_archivo(tipoAlumno *alumnos, int *i)
{
  char nombrearch[100];
  int j = 0;
  FILE *archivo;
  __fpurge(stdin);
  printf("Dame el nombre del archivo: ");
  gets(nombrearch);
  archivo = fopen(nombrearch, "rt");
  if (archivo != NULL)
  {
    while (!feof(archivo))
    {
      fgets(alumnos[j].nombre, 199, archivo);
      alumnos[j].nombre[strlen(alumnos[j].nombre) - 1] = '\0';
      fscanf(archivo, "%lf, %lf, %lf, %lf\n", &(alumnos[j].cal1), &(alumnos[j].cal2), &(alumnos[j].cal3), &(alumnos[j].promedio));
      j++;
    }
    fclose(archivo);
    *i = j;
  }
}

void guardar_archivo(tipoAlumno *alumnos, int i)
{
  char nombrearch[100];
  int j;
  FILE *archivo;
  __fpurge(stdin);
  printf("Dame el nombre del archivo: ");
  gets(nombrearch);
  archivo = fopen(nombrearch, "wt");
  for (j = 0; j < i; j++)
    fprintf(archivo, "%s\n%lf, %lf, %lf, %lf\n", alumnos[j].nombre, alumnos[j].cal1, alumnos[j].cal2, alumnos[j].cal3, alumnos[j].promedio);
  fclose(archivo);
}

void busca_nombre(tipoAlumno *alumnos, char *nombreB)
{
  char nombre[200];
  FILE *archivo;
  long tamanio;
  int elemento, i = 0, encontrados = 0;
  __fpurge(stdin);
  printf("Ingresa el nombre de alumno que quiere encontrar: ");
  gets(nombreB);
  archivo = fopen("datos.bin", "rb");

  fseek(archivo, 0L, SEEK_END);
  tamanio = ftell(archivo);
  elemento = tamanio / sizeof(tipoAlumno);
  fseek(archivo, 0L, SEEK_SET);

  while (i < elemento && encontrados == 0)
  {
    fread(nombre, sizeof(char), 200, archivo);
    if (strcmp(nombre, nombreB) == 0)
    {
      fseek(archivo, -sizeof(nombre), SEEK_CUR);
      fread(alumnos, sizeof(tipoAlumno), 1, archivo);
      printf("%s", alumnos[0].nombre);
      encontrados = 1;
    }
    else
    {
      i++;
      fseek(archivo, (sizeof(float)) * 4, SEEK_CUR);
    }
    if (i < elemento)
    {
      i++;
      fseek(archivo, -200L, SEEK_CUR);
    }
    else
      printf("Dato no encontrado\n");
  }
  fclose(archivo);
}

void guardar_bin(tipoAlumno *alumnos, int i)
{
  FILE *archivo;
  __fpurge(stdin);
  archivo = fopen("datos.bin", "wb");
  fwrite(alumnos, sizeof(tipoAlumno), i, archivo);
  fclose(archivo);
}

void leer_bin(tipoAlumno *alumnos, int *i)
{
  long tamanio;
  int elemento;
  FILE *archivo;
  archivo = fopen("datos.bin", "rb");
  fseek(archivo, 0L, SEEK_END);
  tamanio = ftell(archivo);
  elemento = tamanio / sizeof(tipoAlumno);
  fseek(archivo, 0L, SEEK_SET);

  __fpurge(stdin);
  fread(alumnos, sizeof(tipoAlumno), elemento, archivo);
  fclose(archivo);
  *i = elemento;
}
