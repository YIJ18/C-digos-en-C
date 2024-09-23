#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

typedef struct def_calculadora
{
    int num;
    struct def_calculadora *izq, *der;
} tipoCalc;

void insertar(tipoCalc **raiz, int num);
void mostrar(tipoCalc *raiz);
void borra(tipoCalc *raiz);
tipoCalc *Buscar(tipoCalc *raiz, int variable);
void borrar_elemento();

int main(void)
{
    tipoCalc *raiz = NULL;
    int opcion, num, buscar;

    do
    {
        printf("\n--- Calculadora ---\n");
        printf("1. Insertar elemento\n");
        printf("2. Mostrar elementos\n");
        printf("3. Buscar elemento\n");
        printf("4. Borrar elementos\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese el número a insertar: ");
            scanf("%d", &num);
            insertar(&raiz, num);
            printf("Número insertado exitosamente.\n");
            break;
        case 2:
            printf("Elementos en el árbol: ");
            mostrar(raiz);
            printf("\n");
            break;
        case 3:
            printf("Ingrese el número a buscar: ");
            scanf("%d", &buscar);
            if (Buscar(raiz, buscar) != NULL)
                printf("El número se encuentra en el árbol.\n");
            else
                printf("El número no se encuentra en el árbol.\n");
            break;
        case 4:
            borra(raiz);
            raiz = NULL;
            printf("Árbol borrado exitosamente.\n");
            break;
        case 5:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
            break;
        }
    } while (opcion != 5);

    return 0;
}

void insertar(tipoCalc **raiz, int num)
{
    tipoCalc *nuevo, *pos;

    pos = *raiz;

    nuevo = (tipoCalc *)malloc(sizeof(tipoCalc));

    nuevo->num = num;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    while (pos != NULL)
    {
        if (num > pos->num) // se va moviendo hacia la derecha
        {
            if (pos->der != NULL)
                pos = pos->der;
            else
            {
                pos->der = nuevo;
                return;
            }
        }
        if (num <= pos->num) // se va moviendo hacia la izquierda
        {
            if (pos->izq != NULL)
                pos = pos->izq;
            else
            {
                pos->izq = nuevo;
                return;
            }
        }
    }
    pos = nuevo;
    *raiz = pos;
}

void borra(tipoCalc *raiz)
{
    while (raiz != NULL)
    {
        borra(raiz->izq);
        borra(raiz->der);
        free(raiz);
    }
}

void mostrar(tipoCalc *raiz)
{
    if (raiz != NULL)
    {
        mostrar(raiz->izq);
        printf("%d ", raiz->num);
        mostrar(raiz->der);
    }
}

tipoCalc *Buscar(tipoCalc *raiz, int variable)
{
    if (!raiz)
        return 0;
    else if (variable == raiz->num)
        return raiz;
    else if (variable < raiz->num)
        Buscar(raiz->izq, variable);
    else
        Buscar(raiz->der, variable);
}
