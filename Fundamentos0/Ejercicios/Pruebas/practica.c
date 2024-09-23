/**
 *@file alumnos.c
 *@brief El programa es una base de datos que permite registrar datos de un alumno desde terminal, archivo de texto o binario, asi como guardar esta informacion para n perderla
 *@details:
 *@author Daniela Mendez Ramirez
 *@author Iris Yulit Jasso Cortes
 *@date 09/02/23
 **/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct def_fecha
{
    int dia, mes, anio;
} tipofecha;
typedef struct def_direccion
{
    char calle[100], num_ext[100], num_int[100], col[100], ciudad[100], pais[100];
    int cp;
} tipodireccion;

typedef struct def_alumno
{
    char nombre[100], ap_Pat[100], ap_Mat[100], correo[100], cuenta[10];
    int telefono;
    double prom;
    tipofecha fecha;
    tipodireccion direccion;
    struct def_alumno *sig;
} tipoalumno;

void Nombre();
void Menu(int *op);
tipoalumno CapturarDatos(void);
void InsertarInicio(tipoalumno **inicio, tipoalumno dato);
void InsertarFin(tipoalumno **inicio, tipoalumno dato);
void InsertarOrden(tipoalumno **inicio, tipoalumno dato);
void Mostrar(tipoalumno *inicio);
void Borrar(tipoalumno **inicio);
void guardar_bin(tipoalumno *inicio);
void cargar_bin(tipoalumno **inicio);
void borrar_alumno(tipoalumno **inicio);
void Menu_GuardarArchivo(int *tipo_de_guardado);
void Menu_LeerdeArchivo(int *tipo_de_guardado);
int BuscarDato(tipoalumno *inicio, tipoalumno dato);
void GuardarEnArchivoDeTexto(tipoalumno *inicio);
void LeerdeArchivoDeTexto(tipoalumno **inicio);

int main(void)
{
    tipoalumno *inicio = NULL, dato;
    int opcion, cont = 0, tipo_de_guardado, tipo_de_lectura;
    Nombre();
    do
    {

        Menu(&opcion);
        system("clear");
        switch (opcion)
        {
        case 1:
            dato = CapturarDatos();
            InsertarOrden(&inicio, dato);
            break;
        case 2:
            printf("     Información de los Alumnos:\n");
            printf("--------------------------------------");
            Mostrar(inicio);
            break;
        case 3:
            borrar_alumno(&inicio);
            break;
        case 4:
            Menu_GuardarArchivo(&tipo_de_guardado);
            if (tipo_de_guardado == 1)
            { // Texto
                GuardarEnArchivoDeTexto(inicio);
            }
            else if (tipo_de_guardado == 2)
            { // Binario
                guardar_bin(inicio);
            }
            else if (tipo_de_guardado == 3)
            { // Ambos
                GuardarEnArchivoDeTexto(inicio);
                guardar_bin(inicio);
            }
            else
            {
                printf("Invalido \n");
            }
            break;
        case 5:
            Menu_LeerdeArchivo(&tipo_de_lectura);
            if (tipo_de_lectura == 1)
            { // Texto
                LeerdeArchivoDeTexto(&inicio);
            }
            else if (tipo_de_lectura == 2)
            { // Binario
                cargar_bin(&inicio);
            }
            else if (tipo_de_lectura == 3)
            { // Ambos
                GuardarEnArchivoDeTexto(inicio);
                cargar_bin(&inicio);
            }
            else
            {
                printf("Invalido \n");
            }

            break;
        default:
            break;
        }

    } while (opcion != 6);
    Borrar(&inicio);
}
void Nombre()
{
    printf("\nLas creadoras del programa son: Iris Yulit Jasso Cortes, Daniela Mendez Ramirez.\n");
    printf("\nPresione <ENTER> para continuar.\n");
    getchar();
    system("clear");
}

void Menu(int *op)
{
    int var;
    printf("\n------------- M E N U -------------");
    printf("\n1. Agregar alumno.");
    printf("\n2. Mostrar alumnos.");
    printf("\n3. Borrar alumno.");
    printf("\n4. Guardar alumnos en archivo.");
    printf("\n5. Cargar alumnos del archivo.");
    printf("\n6. Salir.");
    do
    {
        printf("\n---Dame op: ");

        while (scanf("%d", &var) != 1)
        {
            printf("Entrada invalida. Intente nuevamente: ");
            __fpurge(stdin);
        }
        if (var < 1 || var > 6)
        {
            printf("Entrada invalida. Intente nuevamente: ");
            __fpurge(stdin);
        }
        *op = var;
    } while (var < 1 || var > 6);
    printf("\n");
}

tipoalumno CapturarDatos(void)
{
    tipoalumno temp;
    printf("Ingresa el nombre del alumno: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.nombre);

    printf("Ingresa Apellido Paterno: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.ap_Pat);

    printf("Ingresa Apellido Materno: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.ap_Mat);

    printf("Correo: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.correo);

    printf("Cuenta: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.cuenta);

    printf("Telefono: ");
    while (scanf("%d", &temp.telefono) != 1)
    {
        __fpurge(stdin);
        printf("Entrada invalida. Intente nuevamente: ");
    }

    printf("Prom: ");
    while (scanf("%lf", &temp.prom) != 1)
    {
        __fpurge(stdin);
        printf("Entrada invalida. Intente nuevamente: ");
    }

    printf("Fecha de nacimiento con el sig. formato dd/mm/aaaa: ");
    while (scanf("%d/%d/%d", &temp.fecha.dia, &temp.fecha.mes, &temp.fecha.anio) != 3)
    {
        __fpurge(stdin);
        printf("Entrada invalida. Intente nuevamente: ");
    }

    printf("Direccion. ");

    printf("\nCalle: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.direccion.calle);

    printf("Numero exterior: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.direccion.num_ext);

    printf("Numero interior: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.direccion.num_int);

    printf("Colonia: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.direccion.col);

    printf("Ciudad: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.direccion.ciudad);

    printf("Pais: ");
    __fpurge(stdin);
    scanf("%[^\n]", temp.direccion.pais);

    printf("Codigo Postal: ");
    while (scanf("%d", &temp.direccion.cp) != 1)
    {
        __fpurge(stdin);
        printf("Entrada invalida. Intente nuevamente: ");
    }
    return temp;
}

void Borrar(tipoalumno **inicio)
{
    tipoalumno *temp;
    while (*inicio != NULL)
    {
        temp = *inicio;
        *inicio = (*inicio)->sig;
        free(temp);
    }
}

void Mostrar(tipoalumno *inicio)
{
    int op;
    tipoalumno *temp;
    temp = inicio;
    if (inicio != NULL)
    {
        do
        {
            printf("_________________________________________\n\n");
            printf("      Menu visualizacion de alumnos    \n");
            printf("_________________________________________\n");
            printf("  1. Solo sus nombres: \n");
            printf("  2. Datos Escenciales (Nombre, Num. Cuenta, Promedio) \n");
            printf("  3. Todos sus datos: \n");
            printf("  .__: ");
            scanf("%d", &op);
        } while (op != 1 && op != 2 && op != 3);
        printf("\nDireccion op> %d\n", op);

        if (op == 1)
            while (temp != NULL)
            {
                printf("\nNombre: %s %s %s", temp->ap_Pat, temp->ap_Mat, temp->nombre);
                temp = temp->sig;
            }

        if (op == 2)
            while (temp != NULL)
            {
                printf("\nNombre: %s %s %s", temp->ap_Pat, temp->ap_Mat, temp->nombre);
                printf("\nCuenta: %s", temp->cuenta);
                printf("\nPromedio: %lf\n", temp->prom);
                temp = temp->sig;
            }

        if (op == 3)
        {
            while (temp != NULL)
            {
                printf("\nNombre: %s %s %s", temp->ap_Pat, temp->ap_Mat, temp->nombre);
                printf("\nCuenta: %s", temp->cuenta);
                printf("\nTelefono: %d", temp->telefono);
                printf("\nCorreo Electronico: %s", temp->correo);
                printf("\n   Calle: %s", temp->direccion.calle);
                printf("\n   Num ext: %s", temp->direccion.num_ext);
                printf("\n   Num int: %s", temp->direccion.num_int);
                printf("\n   Colonia: %s", temp->direccion.col);
                printf("\n   Ciudad: %s", temp->direccion.ciudad);
                printf("\n   Pais: %s", temp->direccion.pais);
                printf("\n   Codigo Postal: %d", temp->direccion.cp);
                printf("\nFecha de nacimiento: %d/%d/%d", temp->fecha.dia, temp->fecha.mes, temp->fecha.anio);
                printf("\nCuenta: %s", temp->cuenta);
                printf("\nPromedio: %lf\n", temp->prom);
                temp = temp->sig;
            }
        }
    }
    else
        printf("La lista esta vacia. \n");
}

void guardar_bin(tipoalumno *inicio)
{
    tipoalumno *temp;
    FILE *archivo;
    char nameArch[100];
    printf("Nombre del archivo Binario: ");
    __fpurge(stdin);
    scanf("%[^\n]", nameArch);
    archivo = fopen(nameArch, "wb");

    temp = inicio;
    if (archivo != NULL)
    {
        while (temp != NULL)
        {
            fwrite(temp, sizeof(tipoalumno), 1, archivo);
            temp = temp->sig;
        }
        fclose(archivo);
    }
    else
        printf("No se pudo abrir el archivo.\n");
}

void cargar_bin(tipoalumno **inicio)
{
    tipoalumno dato;
    int elementos, i;
    char nameArch[100];
    FILE *archivo;
    printf("Nombre del archivo Binario: ");
    __fpurge(stdin);
    scanf("%[^\n]", nameArch);
    archivo = fopen(nameArch, "rb");
    if (archivo != NULL)
    {
        fseek(archivo, 0L, SEEK_END);
        elementos = ftell(archivo) / sizeof(tipoalumno);
        fseek(archivo, 0L, SEEK_SET);

        // leer e insertar en orden
        for (i = 0; i < elementos; i++)
        {
            fread(&dato, sizeof(tipoalumno), 1, archivo);
            InsertarOrden(inicio, dato);
        }
        fclose(archivo);
    }
    else
        printf("No se pudo abrir el archivo.\n");
}

void borrar_alumno(tipoalumno **inicio)
{
    tipoalumno *temp, *temp2;
    char numero_cuenta[100];
    int encontrado = 0;
    temp = *inicio;
    temp2 = *inicio;

    printf("Ingresa el numero de cuenta del alumno que deseas eliminar: ");
    __fpurge(stdin);
    scanf("%[^\n]", numero_cuenta);

    if (*inicio == NULL)
    {
        printf("No se ha registrado ningun alumno en el sistema hasta el momento.\n");
    }
    else if (strcmp(numero_cuenta, temp->cuenta) == 0)
    {
        *inicio = temp->sig;
        free(temp);
        encontrado = 1;
    }
    else
    {
        while (temp != NULL && encontrado == 0)
        {
            if (strcmp(numero_cuenta, temp->cuenta) == 0)
            {
                temp2->sig = temp->sig;
                free(temp);
                encontrado = 1;
            }
            else
            {
                temp2 = temp;
                temp = temp->sig;
            }
        }

        if (encontrado == 0)
        {
            printf("No se encontro el numero de cuenta del alumno.\n");
        }
    }
}

void InsertarOrden(tipoalumno **inicio, tipoalumno dato)
{
    tipoalumno *nodo, *ant, *pos;

    nodo = (tipoalumno *)malloc(sizeof(tipoalumno));

    // Validar memoria
    if (nodo == NULL)
    {
        printf("No se encontr▒ memoria \n");
        return;
    }

    // Pasamos los datos a la estructura
    *nodo = dato;

    // Si la lista esta vacia
    if (*inicio == NULL)
    {
        *inicio = nodo;
        nodo->sig = NULL;
    }
    // Inserta Fin o Medio
    else
    {
        // Eliminar si el dato esta duplicado
        if (BuscarDato(*inicio, dato) == 1)
        {
            printf("Este numero de cuenta ya esta registrado  %s.\n por lo que se eliminara.\n", nodo->cuenta);
            free(nodo);
            return;
        }

        // Otro apuntador para recorrer
        pos = *inicio;
        ant = NULL;

        while ((pos != NULL) && (strcmp(pos->ap_Pat, dato.ap_Pat) < 0))
        {
            ant = pos;
            pos = pos->sig;
        }

        if (ant == NULL)
        {
            // Insertar al principio
            nodo->sig = *inicio;
            *inicio = nodo;
        }
        else
        {
            // Insertar medio
            nodo->sig = pos;
            ant->sig = nodo;
        }
    }
}

int BuscarDato(tipoalumno *inicio, tipoalumno dato)
{
    tipoalumno *temp;
    temp = inicio;

    // Recorremos la lista
    while (temp != NULL)
    {
        // Comparamos el numero de cuenta
        if (strcmp(temp->cuenta, dato.cuenta) == 0)
        {
            return 1;
        }
        temp = temp->sig;
    }

    return 0;
}

void LeerdeArchivoDeTexto(tipoalumno **inicio)
{
    FILE *archivo;
    tipoalumno temp;
    char nameArch[100];
    printf("Nombre del archivo de Texto: ");
    __fpurge(stdin);
    scanf("%[^\n]", nameArch);
    archivo = fopen(nameArch, "rt");

    if (archivo != NULL)
    {
        // Comprobamos que el archivo tenga datos
        fseek(archivo, 0, SEEK_END); // posicionamos al final del archivo
        if (ftell(archivo) == 0)
        {
            printf("El archivo esta vacio\n");
            fclose(archivo);
            return;
        }
        fseek(archivo, 0, SEEK_SET); // posicionamos al final del archivo
        while (fscanf(archivo, "%[^\n]%*c", temp.ap_Pat) == 1)
        {
            // fscanf(archivo, "%[^\n]%*c", temp.ap_Pat);
            fscanf(archivo, "%[^\n]%*c", temp.ap_Mat);
            fscanf(archivo, "%[^\n]%*c", temp.nombre);
            fscanf(archivo, "%[^\n]%*c", temp.correo);
            fscanf(archivo, "%[^\n]%*c", temp.cuenta);
            fscanf(archivo, "%d%*c", &temp.telefono);
            fscanf(archivo, "%lf%*c", &temp.prom);
            fscanf(archivo, "%d/%d/%d%*c", &temp.fecha.dia, &temp.fecha.mes, &temp.fecha.anio);
            fscanf(archivo, "%[^\n]%*c", temp.direccion.calle);
            fscanf(archivo, "%[^\n]%*c", temp.direccion.num_ext);
            fscanf(archivo, "%[^\n]%*c", temp.direccion.num_int);
            fscanf(archivo, "%[^\n]%*c", temp.direccion.col);
            fscanf(archivo, "%[^\n]%*c", temp.direccion.ciudad);
            fscanf(archivo, "%[^\n]%*c", temp.direccion.pais);
            fscanf(archivo, "%d%*c", &temp.direccion.cp);

            temp.sig = NULL;
            InsertarOrden(inicio, temp);
        }
        fclose(archivo);
        // printf("\n\nApellido Paterno: %s\n", temp.ap_Pat);
    }
}
void GuardarEnArchivoDeTexto(tipoalumno *inicio)
{
    FILE *archivo;
    tipoalumno *temp;
    char nameArch[100];
    printf("Nombre del archivo de Texto: ");
    __fpurge(stdin);
    scanf("%[^\n]", nameArch);
    archivo = fopen(nameArch, "wt");

    temp = inicio;

    while (temp != NULL)
    {

        fprintf(archivo, "%s\n", temp->ap_Pat);
        fprintf(archivo, "%s\n", temp->ap_Mat);
        fprintf(archivo, "%s\n", temp->nombre);
        fprintf(archivo, "%s\n", temp->correo);
        fprintf(archivo, "%s\n", temp->cuenta);
        fprintf(archivo, "%d\n", temp->telefono);
        fprintf(archivo, "%lf\n", temp->prom);
        fprintf(archivo, "%d/%d/%d\n", temp->fecha.dia, temp->fecha.mes, temp->fecha.anio);
        fprintf(archivo, "%s\n", temp->direccion.calle);
        fprintf(archivo, "%s\n", temp->direccion.num_ext);
        fprintf(archivo, "%s\n", temp->direccion.num_int);
        fprintf(archivo, "%s\n", temp->direccion.col);
        fprintf(archivo, "%s\n", temp->direccion.ciudad);
        fprintf(archivo, "%s\n", temp->direccion.pais);
        fprintf(archivo, "%d\n\n", temp->direccion.cp);

        temp = temp->sig;
    }
    fclose(archivo);
}
void Menu_GuardarArchivo(int *tipo_de_guardado)
{
    int var;
    printf("\n------------- M E N U -------------\n");
    printf("  De que manera deseas guardar tu archivo: \n");
    printf("  1. Archivo de Texto.\n");
    printf("  2. Archivo Binario.\n");
    printf("  3. Ambos.\n");
    do
    {
        printf("\n---Dame op: ");

        while (scanf("%d", &var) != 1)
        {
            printf("Entrada invalida. Intente nuevamente: ");
            __fpurge(stdin);
        }
        if (var < 1 || var > 3)
        {
            printf("Entrada invalida. Intente nuevamente: ");
            __fpurge(stdin);
        }
        *tipo_de_guardado = var;
    } while (var < 1 || var > 3);
    printf("\n");
}
void Menu_LeerdeArchivo(int *tipo_de_guardado)
{
    int var;
    printf("\n------------- M E N U -------------\n");
    printf("  De que manera deseas leer tu archivo: \n");
    printf("  1. Archivo de Texto.\n");
    printf("  2. Archivo Binario.\n");
    printf("  3. Ambos.\n");
    do
    {
        printf("\n---Dame op: ");

        while (scanf("%d", &var) != 1)
        {
            printf("Entrada invalida. Intente nuevamente: ");
            __fpurge(stdin);
        }
        if (var < 1 || var > 3)
        {
            printf("Entrada invalida. Intente nuevamente: ");
            __fpurge(stdin);
        }
        *tipo_de_guardado = var;
    } while (var < 1 || var > 3);
    printf("\n");
}
