#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct def_directorio
{
    char nombre[100];
    struct def_directorio *der;
    struct def_directorio *izq;
} tipoDir;

int menu(void);
void insertar(tipoDir **raiz, char *nomb);
void Imprimir(tipoDir *raiz);
tipoDir *Buscar(tipoDir *raiz, char *buscar);
void borrar(tipoDir *raiz);
void BorrarNodo(tipoDir **raiz, char *nombre);
tipoDir *encontrar_min(tipoDir *raiz);
void leer_bin(tipoDir **raiz);
void guardar_bin2(tipoDir *raiz, FILE *archivo);
void leer_txt(tipoDir **raiz);
void guaradar_txt(tipoDir *raiz);
void guardar_txt2(tipoDir *raiz, FILE *archivo);
void guardar_bin(tipoDir *raiz);

int main(void)
{
    tipoDir *raiz = NULL;
    int op;
    char nomb[100], nombre_buscado[100];
    do
    {
        op = menu();
        if (op == 1)
        {
            __fpurge(stdin);
            printf("\nIngresa el directorio: ");
            fgets(nomb, 99, stdin);
            nomb[strlen(nomb) - 1] = 0;
            insertar(&raiz, nomb);
        }
        else if (op == 2)
        {
            printf("\nLos elementos del arbol: ");
            Imprimir(raiz);
        }
        else if (op == 3)
        {
            printf("\nIngresa en nombre del directorio a buscar: ");
            __fpurge(stdin);
            fgets(nombre_buscado, 99, stdin);
            nombre_buscado[strlen(nomb) - 1] = 0;

            if (Buscar(raiz, nombre_buscado) != NULL)
                printf("El elemento fue encontrado");
            else
                printf("El elemento no fue encontrado");
        }
        else if (op == 4)
        {
            printf("\nIngresa en nombre del directorio a borrar: ");
            __fpurge(stdin);
            fgets(nombre_buscado, 99, stdin);
            nombre_buscado[strlen(nomb) - 1] = 0;
            BorrarNodo(&raiz, nombre_buscado);
        }
        else if (op == 5)
        {
            guardar_bin(raiz);
            printf("El árbol se ha guardado en binario.\n");
        }
        else if (op == 6)
        {
            leer_bin(&raiz);
            printf("El árbol se ha cargado desde el archivo binario.\n");
        }
    } while (op != 7);

    borrar(raiz);
    return 0;
}

void borrar(tipoDir *raiz)
{
    if (raiz != NULL)
    {
        borrar(raiz->izq);
        borrar(raiz->der);
        free(raiz);
    }
}

int menu(void)
{
    int opcion;
    printf("\n--- Directorio ---\n");
    printf("1. Insertar elemento\n");
    printf("2. Mostrar elementos\n");
    printf("3. Buscar elemento\n");
    printf("4. Borrar elementos\n");
    printf("5. Guardar en binario\n");
    printf("6. Cargar desde binario\n");
    printf("7. Salir\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);
    return opcion;
}

void insertar(tipoDir **raiz, char *nomb)
{
    tipoDir *pos, *nuevo;
    pos = *raiz;
    nuevo = (tipoDir *)malloc(sizeof(tipoDir));
    strcpy(nuevo->nombre, nomb);
    nuevo->izq = NULL;
    nuevo->der = NULL;

    while (pos != NULL)
    {
        if (strcmp(pos->nombre, nomb) > 0)
        {
            if (pos->der != NULL)
                pos = pos->der;
            else
            {
                pos->der = nuevo;
                return;
            }
        }
        if (strcmp(pos->nombre, nomb) <= 0)
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
    *raiz = nuevo;
}

void Imprimir(tipoDir *raiz)
{
    if (raiz != NULL)
    {
        Imprimir(raiz->izq);
        printf("%s ", raiz->nombre);
        Imprimir(raiz->der);
    }
}

tipoDir *Buscar(tipoDir *raiz, char *buscar)
{
    if (!raiz)
        return 0;
    else if (strcmp(buscar, raiz->nombre) == 0)
        return raiz;
    else if (strcmp(buscar, raiz->nombre) < 0)
        Buscar(raiz->der, buscar);
    else
        Buscar(raiz->izq, buscar);
}

void BorrarNodo(tipoDir **raiz, char *nombre)
{
    if (*raiz == NULL)
    {
        return; // Si el árbol está vacío, no hay nada que borrar
    }

    tipoDir *nodo = *raiz; // Almacenar el puntero al nodo raíz del árbol
    tipoDir *padre = NULL; // Inicializar el puntero al padre como NULL
    tipoDir *minimo;
    // Buscar el nodo a borrar y su padre
    while (nodo != NULL && strcmp(nombre, nodo->nombre) != 0)
    {
        padre = nodo; // Actualizar el puntero al padre actual
        if (strcmp(nombre, nodo->nombre) < 0)
        {
            nodo = nodo->der; // Avanzar hacia el hijo derecho
        }
        else
        {
            nodo = nodo->izq; // Avanzar hacia el hijo izquierdo
        }
    }

    // Si el nodo no se encontró, terminar la función
    if (nodo == NULL)
    {
        return;
    }

    // Caso 1: El nodo a borrar es una hoja (no tiene hijos)
    if (nodo->izq == NULL && nodo->der == NULL)
    {
        if (padre != NULL)
        {
            // Actualizar el puntero del padre para eliminar la referencia al nodo
            if (strcmp(nombre, padre->nombre) < 0)
            {
                padre->der = NULL;
            }
            else
            {
                padre->izq = NULL;
            }
        }
        else
        {
            *raiz = NULL; // El nodo a borrar es la raíz del árbol
        }
        free(nodo); // Liberar la memoria del nodo
    }
    // Caso 2: El nodo a borrar tiene un hijo (derecho o izquierdo)
    else if (nodo->izq == NULL)
    {
        if (padre != NULL)
        {
            if (strcmp(nombre, padre->nombre) < 0)
            {
                padre->der = nodo->der; // Conectar el hijo derecho al padre
            }
            else
            {
                padre->izq = nodo->der; // Conectar el hijo derecho al padre
            }
        }
        else
        {
            *raiz = nodo->der; // El nodo a borrar es la raíz del árbol
        }
        free(nodo); // Liberar la memoria del nodo
    }
    else if (nodo->der == NULL)
    {
        if (padre != NULL)
        {
            if (strcmp(nombre, padre->nombre) < 0)
            {
                padre->der = nodo->izq; // Conectar el hijo izquierdo al padre
            }
            else
            {
                padre->izq = nodo->izq; // Conectar el hijo izquierdo al padre
            }
        }
        else
        {
            *raiz = nodo->izq; // El nodo a borrar es la raíz del árbol
        }
        free(nodo); // Liberar la memoria del nodo
    }
    // Caso 3: El nodo a borrar tiene dos hijos
    else
    {
        // Encontrar el nodo mínimo en el subárbol derecho
        minimo = encontrar_min(nodo->der);

        // Copiar el nombre del nodo mínimo al nodo a borrar
        strcpy(nodo->nombre, minimo->nombre);

        // Borrar el nodo mínimo recursivamente
        BorrarNodo(&nodo->der, minimo->nombre);
    }
}

tipoDir *encontrar_min(tipoDir *raiz)
{
    while (raiz != NULL && raiz->izq != NULL)
        raiz = raiz->izq;
    return raiz;
}

void leer_bin(tipoDir **raiz)
{
    int elementos, i;
    char nomb[100];
    FILE *archivo;
    archivo = fopen("archivo.bin", "rb");
    if (archivo != NULL)
    {
        fseek(archivo, 0L, SEEK_END);
        elementos = ftell(archivo) / 100;
        fseek(archivo, 0L, SEEK_SET);
        for (i = 0; i < elementos; i++)
        {
            fread(nomb, 100, 1, archivo);
            insertar(raiz, nomb);
        }
        fclose(archivo);
    }
}

void leer_txt(tipoDir **raiz)
{
    FILE *archivo;
    char nomb[100];
    archivo = fopen("archivo.txt", "rt");
    if (archivo != NULL)
    {
        while (!feof(archivo))
        {
            fgets(nomb, 99, archivo);
            nomb[strlen(nomb) - 1] = '\0';
            insertar(raiz, nomb);
        }
        fclose(archivo);
    }
}

void guaradar_txt(tipoDir *raiz)
{
    FILE *archivo;
    archivo = fopen("archivo.txt", "wt");
    if (archivo != NULL)
    {
        guardar_txt2(raiz, archivo);
        fclose(archivo);
    }
}

void guardar_txt2(tipoDir *raiz, FILE *archivo)
{
    if (raiz != NULL)
    {
        guardar_txt2(raiz->izq, archivo);
        fprintf(archivo, "%s", raiz->nombre);
        guardar_txt2(raiz->der, archivo);
    }
}

void guardar_bin(tipoDir *raiz)
{
    FILE *archivo;
    archivo = fopen("archivo.bin", "wb");
    guardar_bin2(raiz, archivo);
    fclose(archivo);
}
void guardar_bin2(tipoDir *raiz, FILE *archivo)
{
    if (raiz != NULL)
    {
        guardar_bin2(raiz->izq, archivo);
        fwrite(raiz->nombre, 100, 1, archivo);
        guardar_bin2(raiz->der, archivo);
    }
}