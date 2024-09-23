/*
Ejercicio de listas dinámicas:
Supongamos que quieres implementar un programa para almacenar y administrar una lista de tareas pendientes. Cada tarea tiene un identificador único y una descripción. Debes implementar una lista dinámica que permita agregar, eliminar y mostrar las tareas.

Crea una clase llamada "Tarea" que tenga dos atributos: "id" (identificador) y "descripcion".
Crea una clase llamada "ListaTareas" que contenga una lista dinámica para almacenar las tareas. Esta clase debe tener métodos para:
Agregar una tarea a la lista.
Eliminar una tarea de la lista según su identificador.
Mostrar todas las tareas de la lista.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct def_tarea
{
    int id;
    char descripcion[10];
} tipoTarea;

typedef struct def_ListaTareas
{
    tipoTarea tarea;
    struct def_ListaTareas *sig;
} ListaTareas;

void Menu(int *op);
void Agregar(ListaTareas **inicio, ListaTareas dato);
ListaTareas Rellenar(void);
void eliminar_tarea(ListaTareas **inicio);
void borrar(ListaTareas **inicio);
void imprimir_lista(ListaTareas *inicio);

int main(void)
{
    ListaTareas *Inicio = NULL, dato;
    int op;
    do
    {
        Menu(&op);
        if (op == 1)
        {
            dato = Rellenar();
            Agregar(&Inicio, dato);
        }
        if (op == 2)
            eliminar_tarea(&Inicio);
        if (op == 3)
            imprimir_lista(Inicio);
    } while (op != 4);
    borrar(&Inicio);
    return 0;
}
void Menu(int *op)
{
    printf("---------\n");
    printf("\n1. Ingresar tarea");
    printf("\n2. Eliminar tarea");
    printf("\n3. Mostrar tarea");
    printf("\n4. Salir");
    scanf("%d", op);
}

void Agregar(ListaTareas **inicio, ListaTareas dato)
{
    ListaTareas *temp;
    temp = (ListaTareas *)malloc(sizeof(ListaTareas));
    *temp = dato;
    temp->sig = *inicio;
    *inicio = temp;
}

ListaTareas Rellenar(void)
{
    ListaTareas temp;
    printf("Ingresa el id de tarea: ");
    scanf("%d", &temp.tarea.id);
    printf("Ingresa la descripción de la tarea: max 499 caracteres: ");
    __fpurge(stdin);
    fgets(temp.tarea.descripcion, 499, stdin);
    temp.tarea.descripcion[strlen(temp.tarea.descripcion) - 1] = '\0';
    return temp;
}

void borrar(ListaTareas **inicio)
{
    ListaTareas *temp;
    while (*inicio != NULL)
    {
        temp = *inicio;
        *inicio = (*inicio)->sig;
        free(temp);
    }
}

void eliminar_tarea(ListaTareas **inicio)
{
    ListaTareas *temp, *temp2;
    int id2;
    printf("Ingresa e id del número que quiere borrar: ");
    scanf("%d", &id2);
    temp = *inicio;
    temp2 = *inicio;
    if (*inicio == NULL)
        printf("No hay elementos en la lista");
    else
    {
        while (temp != NULL)
        {
            if (temp->tarea.id == id2)
            {
                temp2->sig = temp->sig;
                free(temp);
                return;
            }
            else
            {
                temp2 = temp;
                temp = temp->sig;
            }
        }
    }
}

void imprimir_lista(ListaTareas *inicio)
{
    ListaTareas *temp;
    temp = inicio;
    while (temp != NULL)
    {
        printf("La tarea %d es: ", temp->tarea.id);
        printf("\n%s", temp->tarea.descripcion);
        temp = temp->sig;
    }
}