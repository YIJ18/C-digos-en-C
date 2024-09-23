/**
 * @file alumnos.c
 *
 * @brief Este programa permite
 *
 * @author Daniela Mendez Ramirez
 * @author Iris Yulit Jasso Cortes
 * @author Ariadna Pedraza
 * @date 22/06/2023
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definimos las estructuras para la estructura alumnos

typedef struct def_name
{
    char nombre[100], ap_Pat[100], ap_Mat[100];
} tiponombre;

typedef struct def_fecha
{
    int dia, mes, anio;
} tipofecha;

typedef struct def_direccion
{
    char calle[100], ciudad[100];
    int cp;
} tipodireccion;

typedef struct def_alumnos
{
    tiponombre nombre;
    int telefono;
    char sexo[100];
    tipofecha cumple;
    int edad; // Se calcula, no se pregunta
    char numCuenta[100];
    char estatus[100];
    char gcad[100]; // concatenador
} tipoalumnos;

// Estructura para Historial Academico
typedef struct def_HistAcad
{
    int clave;
    char nombreMat[100];
    double cal;
    struct def_HistAcad *abajo;
} tipoacademico;

// Estructura Principal
typedef struct def_escuela
{
    tipoalumnos alumnos;
    tipoacademico *academico;

    struct def_escuela *sig;
} tipoescuela;

void Menu();
void PedirDatos(tipoescuela *alumno, tipoescuela *inicio);
int VerificarNombre(tipoescuela *inicio, const char *nombre, const char *ap_Pat, const char *ap_Mat);
void InsertaAlumno(tipoescuela **inicio, tipoescuela alumno);
void InsertaMaterias(tipoacademico **inicio, tipoacademico academico);
void Borrar(tipoescuela **inicio);
void Imprime(tipoescuela *inicio);
void PedirMaterias(tipoacademico *academico, tipoescuela *inicio);
void Imprime_Materias(tipoacademico *inicio);
void guardar_bin(tipoescuela *inicio);
void LeerdeArchivoDeTexto(tipoescuela **inicio);
void guardar_bin_historia(tipoacademico *abajo);
void guardar_bin_alumnos(tipoescuela *inicio);

int calcularEdad(tipofecha nacimiento);
// void InsertaDatosSpiderman(tipospiderman *spiderman);

/******************** Inicio ****************************/
int main()
{
    int op;
    tipoescuela *inicio = NULL;
    tipoescuela *alumno;      // Estructura de datos alumno
    tipoacademico *academico; // Estructura de datos materia

    do
    {
        Menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            // Pide datos e insertalos
            PedirDatos(alumno, inicio);
            InsertaAlumno(&inicio, *alumno);
            break;

        case 2:
            // Materias
            PedirMaterias(academico, inicio);
            break;
        case 3:
            // Cargar
            guardar_bin_alumnos(inicio);
            break;

        case 4:
            // Leer
            PedirMaterias(academico, inicio);
            break;

        case 6:
            Imprime(inicio);

            break;
        }

    } while (op != 7);
}
/********************   fin   ***************************/
void Menu()
{
    printf(" Menu \n");
    printf("1. Insertar Alumno \n");
    printf("2. Insertar Materias  \n");
    printf("3. Cargar de Archivo  \n");
    printf("4. Guardar Archivo  \n");
    printf("5. Eliminar Alumno \n");
    printf("6. Imprimir Lista\n");
    printf("7. Salir\n");
}

// Pedir Datos
void PedirDatos(tipoescuela *alumno, tipoescuela *inicio)
{
    printf("Ingresa el nombre: ");
    __fpurge(stdin);
    scanf("%[^\n]", alumno->alumnos.nombre.nombre);

    printf("Ingresa el Apellido Paterno: ");
    __fpurge(stdin);
    scanf("%[^\n]", alumno->alumnos.nombre.ap_Pat);

    printf("Ingresa el Apellido Materno: ");
    __fpurge(stdin);
    scanf("%[^\n]", alumno->alumnos.nombre.ap_Mat);

    printf("Ingresa el telefono: ");
    __fpurge(stdin);
    scanf("%d", &alumno->alumnos.telefono);

    printf("Sexo: ");
    __fpurge(stdin);
    scanf("%[^\n]", alumno->alumnos.sexo);

    printf("Fecha de nacimiento: ");
    __fpurge(stdin);
    scanf("%d/%d/%d", &alumno->alumnos.cumple.dia, &alumno->alumnos.cumple.mes, &alumno->alumnos.cumple.anio);
    // se agrega a la estructura la edad calculada despues de mandarle la fecha que ingreso el usuario
    alumno->alumnos.edad = calcularEdad(alumno->alumnos.cumple);

    printf("Num. Cuenta: ");
    __fpurge(stdin);
    scanf("%[^\n]", alumno->alumnos.numCuenta);

    printf("Estatus: ");
    __fpurge(stdin);
    scanf("%[^\n]", alumno->alumnos.estatus);

    alumno->academico = NULL;
}

int VerificarNombre(tipoescuela *inicio, const char *nombre, const char *ap_Pat, const char *ap_Mat)
{
    tipoescuela *temp = inicio;
    while (temp != NULL)
    {
        if (strcmp(temp->alumnos.nombre.nombre, nombre) == 0 &&
            strcmp(temp->alumnos.nombre.ap_Pat, ap_Pat) == 0 &&
            strcmp(temp->alumnos.nombre.ap_Mat, ap_Mat) == 0)
        {
            return 1;
        }
        temp = temp->sig;
    }
    return 0;
}

void InsertaAlumno(tipoescuela **inicio, tipoescuela alumno)
{
    tipoescuela *temp;
    temp = (tipoescuela *)malloc(sizeof(tipoescuela));

    *temp = alumno;
    temp->sig = *inicio;
    *inicio = temp;
}

void InsertaMaterias(tipoacademico **inicio, tipoacademico academico)
{
    tipoacademico *temp;

    temp = (tipoacademico *)malloc(sizeof(tipoacademico));
    *temp = academico;
    temp->abajo = *inicio;
    *inicio = temp;
}

void PedirMaterias(tipoacademico *academico, tipoescuela *inicio)
{

    tipoescuela *temp;
    tipoescuela *temp2;
    char name[100], last_NamePat[100], Last_NameMat[100];
    char newcadena[350], estructcad[100]; // gcad[100]; dentro de la estructura
    char telStr[20], tel2Str[20];
    int tel;

    temp = inicio;

    printf("Cual es tu nombre(sin apellidos): ");
    scanf(" %[^\n]", name);

    printf("Cual es tu Apellido Paterno: ");
    scanf(" %[^\n]", last_NamePat);

    printf("Cual es tu Apellido Materno: ");
    scanf(" %[^\n]", Last_NameMat);

    printf("Cual es tu numero de telefono: ");
    scanf(" %d", &tel);

    sprintf(telStr, "%d", tel);
    sprintf(tel2Str, "%d", temp->alumnos.telefono);

    strcpy(newcadena, name);
    strcat(newcadena, last_NamePat);
    strcat(newcadena, Last_NameMat);
    strcat(newcadena, telStr);

    strcpy(temp->alumnos.gcad, temp->alumnos.nombre.nombre);
    strcat(temp->alumnos.gcad, temp->alumnos.nombre.ap_Pat);
    strcat(temp->alumnos.gcad, temp->alumnos.nombre.ap_Mat);
    strcat(temp->alumnos.gcad, tel2Str);

    while (temp != NULL && strcmp(temp->alumnos.gcad, newcadena) != 0)
        temp = temp->sig;

    if (temp != NULL)
    {
        academico = (tipoacademico *)malloc(sizeof(tipoacademico));

        printf("Ingresa Clave de la Materia: ");
        scanf(" %d", &academico->clave);

        printf("Ingresa Nombre de la Materia: ");
        scanf(" %[^\n]", academico->nombreMat);

        printf("Calificacion: ");
        scanf(" %lf", &academico->cal);

        InsertaMaterias(&(temp->academico), *academico);
        printf("Quieres guardar en archivo? "); // Aqui va boton
        // guardar_bin_historia(&(temp->academico));
    }
    else
    {
        printf("Alumno no encontrado\n\n");
    }
}

void Borrar(tipoescuela **inicio)
{
    tipoescuela *temp;

    while (*inicio != NULL)
    {
        temp = *inicio;
        *inicio = (*inicio)->sig;
        free(temp);
    }
}

void Imprime(tipoescuela *inicio)
{
    tipoescuela *temp;
    temp = inicio;
    while (temp != NULL)
    {
        printf("%s\n", temp->alumnos.nombre.nombre);
        printf("Materias: \n");
        Imprime_Materias(temp->academico);
        temp = temp->sig;
    }
}

void Imprime_Materias(tipoacademico *inicio)
{
    tipoacademico *temp;
    temp = inicio;
    while (temp != NULL)
    {
        printf("  %d\n", temp->clave);
        printf("  %s\n", temp->nombreMat);
        printf("  %.2lf\n", temp->cal);
        temp = temp->abajo;
    }
}

// materias
void guardar_bin_historia(tipoacademico *abajo)
{
    tipoacademico *temp;
    FILE *archivo;
    char nameArch[100];
    printf("Nombre del archivo Binario: ");
    __fpurge(stdin);
    scanf("%[^\n]", nameArch);
    archivo = fopen(nameArch, "wb");

    temp = abajo;
    if (archivo != NULL)
    {
        fwrite(temp, sizeof(tipoacademico), 1, archivo);
        fclose(archivo);
    }
    else
        printf("No se pudo abrir el archivo.\n");
}

// alumnos
void guardar_bin_alumnos(tipoescuela *inicio)
{
    tipoescuela *temp;
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
            fwrite(temp, sizeof(tipoalumnos), 1, archivo);
            temp = temp->sig;
        }
        fclose(archivo);
    }
    else
        printf("No se pudo abrir el archivo.\n");
}

int calcularEdad(tipofecha nacimiento)
{
    int dia_nac, mes_nac, anio_nac, dia_actual, mes_actual, anio_actual, edad;
    time_t tiempo;
    dia_nac = nacimiento.dia;
    mes_nac = nacimiento.dia;
    anio_nac = nacimiento.dia;
    // Obtenemos la fecha actual
    time(&tiempo);
    struct tm *fecha_actual = localtime(&tiempo);
    dia_actual = fecha_actual->tm_mday;
    mes_actual = fecha_actual->tm_mon + 1;
    anio_actual = fecha_actual->tm_year + 1900;

    // Calculamos la edad
    edad = anio_actual - anio_nac;

    // Verificamos si todavía no ha cumplido años en el año actual
    if (mes_actual < mes_nac || (mes_actual == mes_nac && dia_actual < dia_nac))
        edad--;

    return edad;
}