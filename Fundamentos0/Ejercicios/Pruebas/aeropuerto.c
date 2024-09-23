#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#define A 8
#define B 6
#define C 4

typedef struct def_pasajero
{
    int num_pas;
    char sexo[10];
    char nombre[100];
    char vuelo[100];
    struct def_pasajero *sig;
} tipoPasajero;

typedef struct def_vuelos
{
    char num_vuelo[100];
    char destino[100];
    tipoPasajero *pas;
} tipoVuelo;

typedef struct def_dato
{
    tipoVuelo dato;
    struct def_dato *sig;
} tipodato;

void Menu(int *op);
void Ingresar(tipodato **Inicio, tipoVuelo valor);
void Ingresar_pas(tipodato **Inicio, tipoPasajero valor);
void Imprimir_vuel(tipodato *Inicio);
tipoPasajero Capturar_pas(void);
tipoVuelo Capturar_vuel(void);
void Borrar(tipodato **Inicio);

int main(void)
{
    tipodato *Inicio = NULL;
    tipoVuelo datos_vuel;
    tipoPasajero datos_pas;
    int a, b, c, op;
    do
    {
        Menu(&op);
        if (op == 1)
        {
            datos_vuel = Capturar_vuel();
            Ingresar(&Inicio, datos_vuel);
            Imprimir_vuel(Inicio);
        }
        if (op == 2)
        {
            datos_pas = Capturar_pas();
            Ingresar_pas(&Inicio, datos_pas);
        }
    } while (op != 5);
    Borrar(&Inicio);
    return 0;
}

void Menu(int *op)
{
    printf("\n1. Agregar avión");
    printf("\n2. Agrega pasajero");
    printf("\n3. Mostrar espacios de avión");
    printf("\n4. Despegar");
    printf("\n5. Salir");
    printf("\n---Dame op: ");
    scanf("%d", op);
}

tipoPasajero Capturar_pas(void)
{
    tipoPasajero temp;
    printf("Ingresa tu número de pasaporte: ");
    scanf("%d", &temp.num_pas);
    printf("Ingresa el sexo: ");
    __fpurge(stdin);
    scanf("%s", temp.sexo);
    printf("Ingresa el nombre completo: ");
    __fpurge(stdin);
    scanf("%s", temp.nombre);
    printf("Ingresa nuevo vuelo: ");
    __fpurge(stdin);
    scanf("%s", temp.vuelo);
    return temp;
}

tipoVuelo Capturar_vuel(void)
{
    tipoVuelo temp;
    printf("Ingresa tu número de vuelo: ");
    scanf("%s", temp.num_vuelo);
    __fpurge(stdin);
    printf("Ingresa el destino: ");
    scanf("%s", temp.destino);
    return temp;
}

void Ingresar(tipodato **Inicio, tipoVuelo valor)
{
    tipodato *temp;
    temp = (tipodato *)malloc(sizeof(tipodato));
    temp->dato = valor;
    temp->sig = *Inicio;
    *Inicio = temp;
}

void Imprimir_vuel(tipodato *Inicio)
{
    tipodato *temp;
    temp = Inicio;
    while (temp != NULL)
    {
        printf("\nEl vuelo %s va a %s", temp->dato.num_vuelo, temp->dato.destino);
        temp = temp->sig;
    }
}

void Borrar(tipodato **Inicio)
{
    tipodato *temp;
    while (*Inicio != NULL)
    {
        temp = *Inicio;
        *Inicio = (*Inicio)->sig;
        free(temp);
    }
}
void Ingresar_pas(tipodato **Inicio, tipoPasajero valor)
{
    tipodato *temp;
    temp = (tipodato *)malloc(sizeof(tipodato));
    temp->dato = valor;
    temp->sig = *Inicio;
    *Inicio = temp;
}