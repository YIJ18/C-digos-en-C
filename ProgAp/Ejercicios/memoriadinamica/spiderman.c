#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct def_villanos
{
    char nombre_vil[100];
    char universo[50];
    struct def_villanos *sig;
} tipoVil;

typedef struct def_spiders
{
    char nombre_var[100];
    char nombre_real[100];
    char universo[50];
    tipoVil *abajo;
    struct def_spiders *sig;
} tipoSpider;

void Menu(int *op);
void InsertarSp(tipoSpider **Inicio, tipoSpider datos);
void InsertarVil(tipoVil **abajo, tipoVil datos);
void AnadirVil(tipoSpider *Inicio);
void Mostrar(tipoSpider *Inicio);
tipoSpider capturarDatos(void);
tipoVil capturarDatosVil(void);

int main(void)
{
    tipoSpider *Inicio = NULL, datos;
    int op;
    do
    {
        Menu(&op);
        if (op == 1)
        {
            datos = capturarDatos();
            InsertarSp(&Inicio, datos);
        }
        else if (op == 2)
            AnadirVil(Inicio);
        else if (op == 3)
            Mostrar(Inicio);
        else if (op == 4)
        {
            printf("Ingresa <enter> para salir");
            getchar();
        }
    } while (op != 4);

    return 0;
}

void Menu(int *op)
{
    printf("\n------------- M E N Ú -------------");
    printf("\n1. Ingresar Spider");
    printf("\n2. Ingresar Villano");
    printf("\n3. Mostrar spiders y sus villanos");
    printf("\n4. Salir\n");
    printf("---Dame op: ");
    scanf("%d", op);
    printf("\n");
}
void Mostrar(tipoSpider *Inicio)
{
    tipoSpider *temp;
    temp = Inicio;
    while (temp != NULL)
    {
        printf("\n--------------------------------------------------------------");
        printf("\nEl nombre del Spider es: %s", temp->nombre_var);
        printf("\nEl nombre real del Spider es: %s", temp->nombre_real);
        printf("\nEl nombre del universo de Spider es: %s", temp->universo);
        printf("--------------------------------------------------------------\n");
        temp = temp->sig;
    }
}

void InsertarSp(tipoSpider **Inicio, tipoSpider datos)
{
    tipoSpider *temp, *pos;
    temp = (tipoSpider *)malloc(sizeof(tipoSpider));
    *temp = datos;
    temp->sig = NULL;
    temp->abajo = NULL;

    if (*Inicio == NULL)
        *Inicio = temp;
    else
    {
        pos = *Inicio;
        while (pos->sig != NULL)
            pos = pos->sig;
        pos->sig = temp;
    }
}

tipoSpider capturarDatos(void)
{
    tipoSpider temp;
    printf("\nIngresa el nombre de la variante Spider : ");
    __fpurge(stdin);
    fgets(temp.nombre_var, 99, stdin);
    temp.nombre_var[strlen(temp.nombre_var) - 1] = 0;
    printf("\nIngresa el nombre real del Spider : ");
    __fpurge(stdin);
    fgets(temp.nombre_real, 99, stdin);
    temp.nombre_real[strlen(temp.nombre_real) - 1] = 0;
    printf("\nIngresa el nombre del universo : ");
    __fpurge(stdin);
    fgets(temp.universo, 99, stdin);
    temp.universo[strlen(temp.universo) - 1] = 0;
    return temp;
}

void InsertarVil(tipoVil **abajo, tipoVil datos)
{
    tipoVil *temp;
    temp = (tipoVil *)malloc(sizeof(tipoVil));
    *temp = datos;
    temp->sig = *abajo;
    *abajo = temp;
}

void AnadirVil(tipoSpider *Inicio)
{
    tipoVil datos;
    datos = capturarDatosVil();
    while (Inicio != NULL && strcmp(Inicio->universo, datos.universo) != 0)
        Inicio = Inicio->sig;
    if (Inicio == NULL)
        printf("Aun no hay universo registrado");
    else
        InsertarVil(&(Inicio->abajo), datos);
}

tipoVil capturarDatosVil(void)
{
    tipoVil temp;
    printf("\nIngresa el nombre de tu villano : ");
    __fpurge(stdin);
    fgets(temp.nombre_vil, 99, stdin);
    temp.nombre_vil[strlen(temp.nombre_vil) - 1] = 0;

    printf("\nIngresa el nombre del universo : ");
    __fpurge(stdin);
    fgets(temp.universo, 99, stdin);
    temp.universo[strlen(temp.universo) - 1] = 0;
    return temp;
}
