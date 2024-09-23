/*
Ejercicio de árboles:
Supongamos que quieres implementar un programa para representar una estructura jerárquica de empleados en una empresa. Cada empleado tiene un nombre y puede tener subordinados (otros empleados). Debes implementar un árbol para representar esta estructura.

Crea una clase llamada "Empleado" que tenga dos atributos: "nombre" y "subordinados" (una lista dinámica de empleados).
Crea una clase llamada "ArbolEmpleados" que contenga un árbol para almacenar la estructura jerárquica. Esta clase debe tener métodos para:
Agregar un empleado al árbol como subordinado de otro empleado.
Buscar un empleado en el árbol por su nombre y mostrar su jerarquía completa.
Mostrar todos los empleados de un nivel específico en la jerarquía.
Espero que estos ejercicios te resulten útiles para practicar con listas dinámicas y árboles. Si necesitas más detalles o ayuda con la implementación, estaré encantado de ayudarte.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>

typedef struct def_random
{
    int valor;
    struct def_random *izq, *der;
} tipoDato;

void Insertar(tipoDato **raiz, int valor);
void Imprimir(tipoDato *p);

int main(void)
{
    tipoDato *raiz = NULL;
    int num, i, valor;
    printf("Ingresa la cantidad de datos: ");
    scanf("%d", &num);
    srand(time(NULL));
    for (i = 0; i < num; i++)
    {
        valor = rand() % 100;
        printf("%d\n", valor);
        Insertar(&raiz, valor);
    }
    Imprimir(raiz);

    return 0;
}

void Imprimir(tipoDato *p)
{
    if (p != NULL)
    {
        Imprimir(p->izq);
        printf("%d ", p->valor);
        Imprimir(p->der);
    }
}

void Insertar(tipoDato **raiz, int valor)
{
    tipoDato *pos, *temp;
    temp = (tipoDato *)malloc(sizeof(tipoDato));
    pos = *raiz;
    temp->valor = valor;
    temp->der = NULL;
    temp->izq = NULL;
    while (pos != NULL)
    {
        if (valor > pos->valor)
        {
            if (pos->der != NULL)
                pos = pos->der;
            else
            {
                pos->der = temp;
                return;
            }
        }
        else
        {
            if (pos->izq != NULL)
                pos = pos->izq;
            else
            {
                pos->izq = temp;
                return;
            }
        }
    }
    *raiz = temp;
}
