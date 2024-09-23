#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct def_cancion
{
    char nombre[100], autor[100];
    int duracion;
} tipoCancion;

void Menu(int *op, tipoCancion lista);
void agregar_cancion(tipoCancion *lista, int i);
void eliminar_cola(tipoCancion *lista, int *i);
void mostrar_cola(tipoCancion *lista, int i);
void tocar_min(tipoCancion *lista, int *i);
void cargar_lista();

int main(void)
{
    tipoCancion *lista;
    int elementos, op, i = 0;
    printf("\nIngresa cuantas canciones quieres ingresar: ");
    scanf("%d", &elementos);
    lista = (tipoCancion *)malloc(sizeof(tipoCancion) * elementos);
    do
    {
        Menu(&op, lista[0]);
        if (op == 1)
        {
            agregar_cancion(lista, i);
            i++;
        }
        else if (op == 2)
            eliminar_cola(lista, &i);
        else if (op == 3)
            mostrar_cola(lista, i);
        else if (op == 4)
            tocar_min(lista, &i);
        else if (op == 7)
        {
            printf("Para salir del progra presione <enter>");
            __fpurge(stdin);
            getchar();
        }
        else
            printf("No ingresaste una opción válida.\n");

    } while (op != 7);
    free(lista);
    return 0;
}

void Menu(int *op, tipoCancion lista)
{
    printf("\n---------- %s -----------\n", lista.nombre);
    printf("1. Agregar canción.\n");
    printf("2. Eliminar de la cola.\n");
    printf("3. Mostrar cola.\n");
    printf("4. Tocar un minuto de la canción.\n");
    printf("5. Guardar lista.\n");
    printf("6. Cargar lista.\n");
    printf("7. Salir.\n");
    printf("Ingresa la opción: ");
    __fpurge(stdin);
    scanf("%d", op);
    printf("\n\n");
}

void agregar_cancion(tipoCancion *lista, int i)
{
    printf("\nIngresa nombre de la canción: ");
    __fpurge(stdin);
    scanf("%[^\n]", lista[i].nombre);
    printf("Ingresa nombre del autor: ");
    __fpurge(stdin);
    scanf("%[^\n]", lista[i].autor);
    printf("Ingresa la duración: ");
    __fpurge(stdin);
    scanf("%d", &lista[i].duracion);
}

void eliminar_cola(tipoCancion *lista, int *i)
{
    int j, k;
    char eliminado[100];
    printf("Ingresa el nombre de canción que quieres eliminar: ");
    __fpurge(stdin);
    fgets(eliminado, 99, stdin);
    eliminado[strlen(eliminado) - 1] = '\0';

    for (j = 0; j < *i; j++)
    {
        if (strcmp(eliminado, lista[j].nombre) == 0)
        {
            // ultimo elemento
            if (j == *i - 1)
                *i = *i - 1;
            // cualquier otro
            else
            {
                for (k = j; k < *i; k++)
                    lista[k] = lista[k + 1];
                *i = *i - 1;
            }
        }
    }
}

void mostrar_cola(tipoCancion *lista, int i)
{
    int j;
    for (j = 0; j < i; j++)
    {
        printf("\nEl nombre del artista es: %s", lista[j].autor);
        printf("\nEl nombre de la canción es: %s", lista[j].nombre);
        printf("\nLa duración de la canción es: %d", lista[j].duracion);
        printf("\n");
    }
    printf("\n");
}

void tocar_min(tipoCancion *lista, int *i)
{
    int j, k;
    lista[0].duracion = lista[0].duracion - 1;
    if (lista[0].duracion == 0)
    {
        for (j = 0; j < *i; j++)
        {
            // ultimo elemento
            if (j == *i - 1)
                *i = *i - 1;
            // cualquier otro
            else
            {
                for (k = j; k < *i; k++)
                    lista[k] = lista[k + 1];
                *i = *i - 1;
            }
        }
    }
}
void cargar_lista(tipoCancion *lista, int *i)
{
    FILE *archivo;
    char nombrearch[50];
    long tamanio;
    int elemento;

    if (fopen(nombrearch, "rb") != NULL)
    {
        fseek(archivo, 0L, SEEK_END);
        tamanio = ftell(archivo);
        elemento = tamanio / sizeof(tipoCancion);
        fread(lista, sizeof(tipoCancion), elemento, archivo);
        fclose(archivo);
        *i = elemento;
    }
    else
        printf("No ingresaste un archivo válido. \n");
}

void guardar_lista(tipoCancion *lista, int i)
{
    char nombrearch[50];
    FILE *archivo;
    printf("Ingresa el nombre del archivo .bin: ");
    fgets(nombrearch, 49, stdin);
    nombrearch[strlen(nombrearch) - 1] = 0;
    fopen(nombrearch, "wb");
    fwrite(lista, sizeof(tipoCancion), i, archivo);
    fclose(archivo);
}