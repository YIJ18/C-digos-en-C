#include <gtk-2.0/gtk/gtk.h>
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

// Declaración de la función lee()
void lee(GtkWidget *button, gpointer data);
void guarda(GtkWidget *button, gpointer data);

int main(int argc, char *argv[])
{
    // Inicializar GTK
    gtk_init(&argc, &argv);

    // Crear una ventana
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Archivos");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Crear los botones
    GtkWidget *buttonGuardar = gtk_button_new_with_label("Guardar archivo");
    GtkWidget *buttonLeer = gtk_button_new_with_label("Leer archivo");

    // Conectar los botones a las funciones correspondientes
    g_signal_connect(buttonGuardar, "clicked", G_CALLBACK(guarda), NULL);
    g_signal_connect(buttonLeer, "clicked", G_CALLBACK(lee), NULL);

    // Crear una caja vertical para organizar los botones
    GtkWidget *box = gtk_vbox_new(TRUE, 5);
    gtk_box_pack_start(GTK_BOX(box), buttonGuardar, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), buttonLeer, TRUE, TRUE, 0);

    // Agregar la caja a la ventana
    gtk_container_add(GTK_CONTAINER(window), box);

    // Mostrar todos los widgets
    gtk_widget_show(buttonGuardar);
    gtk_widget_show(buttonLeer);
    gtk_widget_show(box);
    gtk_widget_show(window);

    // Ejecutar el bucle principal de GTK
    gtk_main();

    return 0;
}

// Implementación de la función lee()
void lee(GtkWidget *button, gpointer data)
{
    tipoescuela *escuela, nuevoAlumno;
    GtkWidget *dialogo;
    FILE *archivo;
    char *nombre;

    g_print("leer");

    dialogo = gtk_file_chooser_dialog_new("Abrir Archivo",
                                          NULL,
                                          GTK_FILE_CHOOSER_ACTION_OPEN,
                                          GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                          GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                          NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialogo)) == GTK_RESPONSE_ACCEPT)
    {
        nombre = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogo));
        g_print(nombre);

        archivo = fopen(nombre, "rt");

        if (archivo != NULL)
        {
            escuela = (tipoescuela *)data;

            while (!feof(archivo))
            {
                fscanf(archivo, "Nombre: %s %s %s\n", nuevoAlumno.alumnos.nombre.nombre, nuevoAlumno.alumnos.nombre.ap_Pat, nuevoAlumno.alumnos.nombre.ap_Mat);
                fscanf(archivo, "Teléfono: %d\n", &nuevoAlumno.alumnos.telefono);
                fscanf(archivo, "Sexo: %s\n", nuevoAlumno.alumnos.sexo);
                fscanf(archivo, "Fecha de Cumpleaños: %d/%d/%d\n", &nuevoAlumno.alumnos.cumple.dia, &nuevoAlumno.alumnos.cumple.mes, &nuevoAlumno.alumnos.cumple.anio);
                fscanf(archivo, "Edad: %d\n", &nuevoAlumno.alumnos.edad);
                fscanf(archivo, "Número de Cuenta: %s\n", nuevoAlumno.alumnos.numCuenta);
                fscanf(archivo, "Estatus: %s\n", nuevoAlumno.alumnos.estatus);
                fscanf(archivo, "Gcad: %s\n", nuevoAlumno.alumnos.gcad);

                //  InsertaAlumno(&inicio, alumno);
            }
            g_free(nombre);
            fclose(archivo);
        }
        else
            g_print("No se pudo abrir el archivo\n");
    }

    gtk_widget_destroy(dialogo);
}
void guarda(GtkWidget *button, gpointer data)
{
    tipoescuela *escuela, *alumno;
    GtkWidget *dialogo;
    FILE *archivo;
    char *nombre;

    g_print("guardar");

    dialogo = gtk_file_chooser_dialog_new("Guardar Archivo",
                                          NULL,
                                          GTK_FILE_CHOOSER_ACTION_SAVE,
                                          GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                          GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
                                          NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialogo)) == GTK_RESPONSE_ACCEPT)
    {
        nombre = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogo));
        g_print(nombre);

        archivo = fopen(nombre, "wt");

        if (archivo != NULL)
        {
            escuela = (tipoescuela *)data;
            alumno = escuela;

            while (alumno != NULL)
            {
                fprintf(archivo, "Nombre: %s %s %s\n", alumno->alumnos.nombre.nombre, alumno->alumnos.nombre.ap_Pat, alumno->alumnos.nombre.ap_Mat);
                fprintf(archivo, "Teléfono: %d\n", alumno->alumnos.telefono);
                fprintf(archivo, "Sexo: %s\n", alumno->alumnos.sexo);
                fprintf(archivo, "Fecha de Cumpleaños: %d/%d/%d\n", alumno->alumnos.cumple.dia, alumno->alumnos.cumple.mes, alumno->alumnos.cumple.anio);
                fprintf(archivo, "Edad: %d\n", alumno->alumnos.edad);
                fprintf(archivo, "Número de Cuenta: %s\n", alumno->alumnos.numCuenta);
                fprintf(archivo, "Estatus: %s\n", alumno->alumnos.estatus);
                fprintf(archivo, "Gcad: %s\n", alumno->alumnos.gcad);

                alumno = alumno->sig;
            }
            g_free(nombre);
            fclose(archivo);
        }
        else
            g_print("No se pudo abrir el archivo\n");
    }

    gtk_widget_destroy(dialogo);
}