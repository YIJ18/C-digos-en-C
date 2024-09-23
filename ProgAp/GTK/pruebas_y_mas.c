void guarda(GtkWidget *button, gpointer data)
{
    tipoescuela *escuela, *alumno;
    GtkWidget *dialogo;
    FILE *archivo;
    char *nombre;
    gint res;

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
        g_free(nombre);

        archivo = fopen(nombre, "wt");

        if (archivo != NULL)
        {
            escuela = (tipoescuela *)data;
            alumno = escuela->sig;

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

            fclose(archivo);
        }
        else
            g_print("No se pudo abrir el archivo\n");
    }

    gtk_widget_destroy(dialogo);
}

void lee(GtkWidget *button, gpointer data)
{
    GtkWidget *dialogo, *otro;
    FILE *archivo;
    char *nombre, nombre_arch[200];
    gint res;

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
        g_free(nombre);

        archivo = fopen(nombre, "rt");

        if (archivo != NULL)
        {
            tipoescuela *escuela = (tipoescuela *)data;
            tipoescuela *ultimoAlumno = escuela;

            while (!feof(archivo))
            {
                tipoescuela *nuevoAlumno = (tipoescuela *)malloc(sizeof(tipoescuela));
                nuevoAlumno->sig = NULL;

                fscanf(archivo, "Nombre: %s %s %s\n", nuevoAlumno->alumnos.nombre.nombre, nuevoAlumno->alumnos.nombre.ap_Pat, nuevoAlumno->alumnos.nombre.ap_Mat);
                fscanf(archivo, "Teléfono: %d\n", &nuevoAlumno->alumnos.telefono);
                fscanf(archivo, "Sexo: %s\n", nuevoAlumno->alumnos.sexo);
                fscanf(archivo, "Fecha de Cumpleaños: %d/%d/%d\n", &nuevoAlumno->alumnos.cumple.dia, &nuevoAlumno->alumnos.cumple.mes, &nuevoAlumno->alumnos.cumple.anio);
                fscanf(archivo, "Edad: %d\n", &nuevoAlumno->alumnos.edad);
                fscanf(archivo, "Número de Cuenta: %s\n", nuevoAlumno->alumnos.numCuenta);
                fscanf(archivo, "Estatus: %s\n", nuevoAlumno->alumnos.estatus);
                fscanf(archivo, "Gcad: %s\n", nuevoAlumno->alumnos.gcad);

                ultimoAlumno->sig = nuevoAlumno;
                ultimoAlumno = nuevoAlumno;
            }

            fclose(archivo); // Cierra el archivo
        }
        else
        {
            // No se pudo abrir el archivo, maneja el error en consecuencia
            g_print("No se pudo abrir el archivo\n");
        }
    }

    gtk_widget_destroy(dialogo);
}
