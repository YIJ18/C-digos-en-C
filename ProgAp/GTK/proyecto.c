#include <gtk-2.0/gtk/gtk.h>
#include <stdio.h>

typedef struct
{
  GtkWidget *ventana;
  GtkWidget *cajaHorizontal[7];
  GtkWidget *cajaVertical[12];
  GtkWidget *etiqueta[12];
  GtkWidget *imagen;
  GtkWidget *boton[2];
  GtkWidget *campo[12];
  GtkWidget *menu, *menu1, *root_menu, *menu_bar, *op1, *op2, *op3, *rb1, *rb2, *rb3;
} principal;

typedef struct
{
  GtkWidget *new_ventana;
  GtkWidget *table;
  GtkWidget *label[5];
  GtkWidget *name[5];
  GtkWidget *boton;
  ;
} materias_principal;

typedef struct def_checks
{
  GtkWidget *cb1, *cb2, *cb3, *cb4;
} tipochecks;

typedef struct def_param
{
  GtkWidget *entry;
  int op1;
  char operacion;
  GtkWidget *texto;
  char tipogrados[20];
  GtkWidget *ventana;
  tipochecks checks;
} tipo_param;

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
  char nameArchAlumnos[300];
} tipoalumnos;

// Estructura para Historial Academico
typedef struct def_HistAcad
{
  int clave;
  char nombreMat[100];
  double cal;
  materias_principal tabla_mat;
  struct def_HistAcad *abajo;
} tipoacademico;

// Estructura Principal
typedef struct def_escuela
{
  tipoalumnos alumnos;
  tipoacademico *materias;
  principal diseno;
  struct def_escuela *sig;
} tipoescuela;

void Acercade(GtkWidget *button, gpointer data);
void StopTheApp(GtkWidget *window, gpointer data);
void on_close(GtkDialog *dialog, gint response_id, gpointer user_data);
void Cambiaopcion1(GtkToggleButton *button, gpointer data);
void LeerdeArchivo(GtkWidget *button, gpointer data);
void GuardarEnArchivo(GtkWidget *button, gpointer data);
void ClearEntry(GtkButton *button, gpointer data);
void LeeCampoMal(GtkWidget *widget, gpointer data);
void LeeTodosLosCampos(GtkWidget *button, gpointer data);
void LeeCampo(GtkButton *button, gpointer data);
void InsertaAlumno(tipoescuela **inicio, tipoescuela alumno);
void Imprime(tipoescuela *inicio);

// funciones de las materias
void abrir_nueva_ventana(GtkWidget *widget, gpointer data);
void LeeCampoMaterias(GtkButton *button, gpointer data);
void buscar_nombre(GtkButton *button, gpointer data);
void InsertaMaterias(tipoacademico **inicio, tipoacademico academico);

int main(gint argc, gchar *argv[])
{
    tipoescuela parametro;

    int x, y, z, k, l;
    // Inicializar el ambiente
    gtk_init(&argc, &argv);

    // crear widgets
    tipoescuela *presentacion = malloc(sizeof(tipoescuela));
    // principal *presentacion = malloc(sizeof(principal));

    if (presentacion == NULL)
    {
        printf("No se encontro memoria");
    }

    presentacion->diseno.ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width(GTK_CONTAINER(presentacion->diseno.ventana), 10);

    for (x = 0; x < 7; x++)
    {
        presentacion->diseno.cajaHorizontal[x] = gtk_hbox_new(TRUE, 5);
    }

    for (y = 0; y < 12; y++)
    {
        presentacion->diseno.cajaVertical[y] = gtk_vbox_new(TRUE, 5);
    }
    presentacion->diseno.cajaVertical[1] = gtk_vbox_new(FALSE, 5);

    for (z = 0; z < 12; z++)
    {
        presentacion->diseno.campo[z] = gtk_entry_new();
    }

    presentacion->diseno.boton[0] = gtk_button_new_with_label("Enviar");
    presentacion->diseno.boton[1] = gtk_button_new_with_label("Borrar");

    presentacion->diseno.etiqueta[0] = gtk_label_new("Nombre");
    presentacion->diseno.etiqueta[1] = gtk_label_new("Apellido paterno");
    presentacion->diseno.etiqueta[2] = gtk_label_new("Apellido materno");
    presentacion->diseno.etiqueta[3] = gtk_label_new("Telefono");
    presentacion->diseno.etiqueta[4] = gtk_label_new("Numero de cuenta");
    presentacion->diseno.etiqueta[5] = gtk_label_new("Sexo");
    presentacion->diseno.etiqueta[6] = gtk_label_new("Estatus");
    presentacion->diseno.etiqueta[7] = gtk_label_new("Cumple"); // Cumple
    presentacion->diseno.etiqueta[8] = gtk_label_new("Datos de alumno");

    presentacion->diseno.imagen = gtk_image_new_from_file("disenio.jpg");

    // fijar atributos
    gtk_window_set_title(GTK_WINDOW(presentacion->diseno.ventana), "Proyecto final");

    /*************** MENU *****************************/
    presentacion->diseno.menu_bar = gtk_menu_bar_new();

    // SubMenu1
    presentacion->diseno.menu1 = gtk_menu_new();
    presentacion->diseno.op1 = gtk_menu_item_new_with_label("Leer de Archivo");
    presentacion->diseno.op2 = gtk_menu_item_new_with_label("Guardar en archivo");
    // Los metemos en la opcion menu1
    gtk_menu_append(GTK_MENU(presentacion->diseno.menu1), presentacion->diseno.op1);
    gtk_menu_append(GTK_MENU(presentacion->diseno.menu1), presentacion->diseno.op2);

    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.op1), "activate", GTK_SIGNAL_FUNC(LeerdeArchivo), &parametro);
    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.op2), "activate", GTK_SIGNAL_FUNC(GuardarEnArchivo), &parametro);

    presentacion->diseno.menu = gtk_menu_new();
    presentacion->diseno.op1 = gtk_menu_item_new_with_label("Ingresar Alumnos");
    presentacion->diseno.op2 = gtk_menu_item_new_with_label("Modificar Alumnos");
    presentacion->diseno.op3 = gtk_menu_item_new_with_label("Salir");
    /******* Conectar con las funciones *******/
    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.op3), "activate", GTK_SIGNAL_FUNC(StopTheApp), NULL);

    gtk_menu_append(GTK_MENU(presentacion->diseno.menu), presentacion->diseno.op1);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(presentacion->diseno.op1), presentacion->diseno.menu1);

    gtk_menu_append(GTK_MENU(presentacion->diseno.menu), presentacion->diseno.op2);
    gtk_menu_append(GTK_MENU(presentacion->diseno.menu), presentacion->diseno.op3);

    presentacion->diseno.root_menu = gtk_menu_item_new_with_label("Alumnos");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(presentacion->diseno.root_menu), presentacion->diseno.menu);
    gtk_menu_bar_append(GTK_MENU_BAR(presentacion->diseno.menu_bar), presentacion->diseno.root_menu);
    // Submenu2
    presentacion->diseno.menu = gtk_menu_new();
    presentacion->diseno.op1 = gtk_menu_item_new_with_label("Ingresar Materias");
    presentacion->diseno.op2 = gtk_menu_item_new_with_label("Modificar Materias");

    gtk_menu_append(GTK_MENU(presentacion->diseno.menu), presentacion->diseno.op1);
    gtk_menu_append(GTK_MENU(presentacion->diseno.menu), presentacion->diseno.op2);
    /*************** Aqui van las funciones **********/
    presentacion->diseno.root_menu = gtk_menu_item_new_with_label("Materias");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(presentacion->diseno.root_menu), presentacion->diseno.menu);
    gtk_menu_bar_append(GTK_MENU_BAR(presentacion->diseno.menu_bar), presentacion->diseno.root_menu);
    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.op1), "activate", GTK_SIGNAL_FUNC(abrir_nueva_ventana), NULL);

    // Submenu 3
    presentacion->diseno.root_menu = gtk_menu_item_new_with_label("Acerca De Nosotras");
    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.root_menu), "activate", GTK_SIGNAL_FUNC(Acercade), NULL);
    gtk_menu_bar_append(GTK_MENU_BAR(presentacion->diseno.menu_bar), presentacion->diseno.root_menu);

    gtk_box_pack_start(GTK_BOX(presentacion->diseno.cajaVertical[1]), presentacion->diseno.menu_bar, FALSE, FALSE, 0); // Menu

    // llamadas a funciones

    // definir jerarquia

    /*************** SECCION PEDIR DATOS*****************************/

    // se agrega titulo a la caja horizontal[1]
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[1]), presentacion->diseno.etiqueta[8]); // Titulo

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[2]), presentacion->diseno.etiqueta[0]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[2]), presentacion->diseno.campo[0]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[1]), presentacion->diseno.cajaVertical[2]); // Nombre

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[3]), presentacion->diseno.etiqueta[1]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[3]), presentacion->diseno.campo[1]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[1]), presentacion->diseno.cajaVertical[3]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[4]), presentacion->diseno.etiqueta[2]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[4]), presentacion->diseno.campo[2]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[1]), presentacion->diseno.cajaVertical[4]);

    // Guardamos las 3 preguntas en la caja vertical
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[1]), presentacion->diseno.cajaHorizontal[1]);

    // Horizontal 2
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[5]), presentacion->diseno.etiqueta[3]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[5]), presentacion->diseno.campo[3]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[2]), presentacion->diseno.cajaVertical[5]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[6]), presentacion->diseno.etiqueta[4]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[6]), presentacion->diseno.campo[4]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[2]), presentacion->diseno.cajaVertical[6]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[1]), presentacion->diseno.cajaHorizontal[2]);

    // horizontal 3
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[7]), presentacion->diseno.etiqueta[5]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[7]), presentacion->diseno.campo[5]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[3]), presentacion->diseno.cajaVertical[7]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[8]), presentacion->diseno.etiqueta[6]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[8]), presentacion->diseno.campo[6]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[3]), presentacion->diseno.cajaVertical[8]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[9]), presentacion->diseno.etiqueta[7]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[9]), presentacion->diseno.campo[7]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[3]), presentacion->diseno.cajaVertical[9]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[1]), presentacion->diseno.cajaHorizontal[3]);

    /*
    // Botones redonditos
    presentacion->diseno.rb1 = gtk_radio_button_new_with_label(NULL, "Femenino");
    gtk_box_pack_start(GTK_BOX(presentacion->diseno.cajaVertical[10]), presentacion->diseno.rb1, FALSE, FALSE, 0);
    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.rb1), "toggled", GTK_SIGNAL_FUNC(Cambiaopcion1), &parametro);

    presentacion->diseno.rb2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(presentacion->diseno.rb1)), "Masculino");
    gtk_box_pack_start(GTK_BOX(presentacion->diseno.cajaVertical[10]), presentacion->diseno.rb2, FALSE, FALSE, 0);
    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.rb2), "toggled", GTK_SIGNAL_FUNC(Cambiaopcion1), &parametro);

    presentacion->diseno.rb3 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(presentacion->diseno.rb1)), "Otro");
    gtk_box_pack_start(GTK_BOX(presentacion->diseno.cajaVertical[10]), presentacion->diseno.rb3, FALSE, FALSE, 0);
    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.rb3), "toggled", GTK_SIGNAL_FUNC(Cambiaopcion1), &parametro);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[4]), presentacion->diseno.cajaVertical[10]);
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[1]), presentacion->diseno.cajaHorizontal[4]);

    */

    // botones
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[4]), presentacion->diseno.boton[0]); // Enviar
    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.boton[0]), "clicked", GTK_SIGNAL_FUNC(LeeCampo), presentacion);
    // gtk_signal_connect(GTK_OBJECT(presentacion->diseno.boton[0]), "clicked", GTK_SIGNAL_FUNC(LeeCampo), presentacion->diseno.campo[0]);

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaHorizontal[4]), presentacion->diseno.boton[1]); // Borrar
    for (k = 0; k < 12; k++)
    {
        gtk_signal_connect(GTK_OBJECT(presentacion->diseno.boton[1]), "clicked", GTK_SIGNAL_FUNC(ClearEntry), presentacion->diseno.campo[k]);
    }

    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[1]), presentacion->diseno.cajaHorizontal[4]);

    /************** ORDENAMOS *************************************/
    gtk_signal_connect(GTK_OBJECT(presentacion->diseno.ventana), "destroy", GTK_SIGNAL_FUNC(StopTheApp), NULL);

    // iIMAGEN se agrega la imagen a la caja horizontal[2]
    gtk_box_pack_start_defaults(GTK_BOX(presentacion->diseno.cajaVertical[0]), presentacion->diseno.imagen);
    gtk_container_add(GTK_CONTAINER(presentacion->diseno.cajaHorizontal[0]), presentacion->diseno.cajaVertical[0]);

    gtk_container_add(GTK_CONTAINER(presentacion->diseno.cajaHorizontal[0]), presentacion->diseno.cajaVertical[1]);
    gtk_container_add(GTK_CONTAINER(presentacion->diseno.ventana), presentacion->diseno.cajaHorizontal[0]);

    // mostrar widgets
    gtk_widget_show_all(presentacion->diseno.ventana);

    gtk_main();
    return 0;
}
void StopTheApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}

void Acercade(GtkWidget *button, gpointer data)
{
    GtkWidget *about_dialog;
    const gchar *authors[] = {"Daniela Mendez Ramirez", NULL};
    const gchar *documenters[] = {"Ariadna", NULL};

    about_dialog = gtk_about_dialog_new();

    /* We fill in the information for the about dialog */
    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about_dialog), "Acerca de este codigo");
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(about_dialog), "Copyright \xc2\xa9 2012 GNOME Documentation Team");
    gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(about_dialog), authors);
    gtk_about_dialog_set_documenters(GTK_ABOUT_DIALOG(about_dialog), documenters);
    gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(about_dialog), "GNOME Developer Website");
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(about_dialog), "http://developer.gnome.org");

    g_signal_connect(GTK_DIALOG(about_dialog), "response",
                     G_CALLBACK(on_close), NULL);

    gtk_widget_show(about_dialog);
}

void on_close(GtkDialog *dialog, gint response_id, gpointer user_data)
{
    /* This will cause the dialog to be destroyed */
    gtk_widget_destroy(GTK_WIDGET(dialog));
}

void Cambiaopcion1(GtkToggleButton *button, gpointer data)
{
    tipoescuela *datos = (tipoescuela *)data;

    if (gtk_toggle_button_get_active(button))
    {
        strcpy(datos->alumnos.sexo, gtk_button_get_label(GTK_BUTTON(button)));
        g_print("boton seleccionado %s \n", datos->alumnos.sexo);
    }
}

void LeerdeArchivo(GtkWidget *button, gpointer data)
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
                // fscanf(archivo, "Gcad: %s\n", nuevoAlumno.alumnos.gcad);

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

void GuardarEnArchivo(GtkWidget *button, gpointer data)
{
    tipoescuela *escuela, *alumno;
    GtkWidget *dialogo;
    FILE *archivo;
    char *nombre;
    escuela = (tipoescuela *)data;

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
                // fprintf(archivo, "Gcad: %s\n", alumno->alumnos.gcad);

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

void ClearEntry(GtkButton *button, gpointer data)
{
    GtkEntry *entry = GTK_ENTRY(data);
    gtk_entry_set_text(entry, "");
}

void InsertaAlumno(tipoescuela **inicio, tipoescuela alumno)
{
    tipoescuela *temp;
    temp = (tipoescuela *)malloc(sizeof(tipoescuela));

    *temp = alumno;
    temp->sig = *inicio;
    *inicio = temp;
}

void Imprime(tipoescuela *inicio)
{
    tipoescuela *temp;
    temp = inicio;
    while (temp != NULL)
    {
        printf("%s\n", temp->alumnos.nombre.nombre);
        printf("Materias: \n");
        // Imprime_Villano(temp->villano);
        temp = temp->sig;
    }
}

void LeeCampo(GtkButton *button, gpointer data)
{
    tipoescuela *datos = (tipoescuela *)data;
    tipoescuela *inicio = NULL;
    const gchar *telefono_texto;
    const gchar *fecha_texto;
    int dia, mes, anio, telefono;

    strcpy(datos->alumnos.nombre.nombre, gtk_entry_get_text(GTK_ENTRY(datos->diseno.campo[0]))); // name
    strcpy(datos->alumnos.nombre.ap_Pat, gtk_entry_get_text(GTK_ENTRY(datos->diseno.campo[1]))); // Ap_Pat
    strcpy(datos->alumnos.nombre.ap_Mat, gtk_entry_get_text(GTK_ENTRY(datos->diseno.campo[2]))); // Ap_Mat
    telefono_texto = gtk_entry_get_text(GTK_ENTRY(datos->diseno.campo[3]));
    telefono = atoi(telefono_texto);
    datos->alumnos.telefono = telefono;
    strcpy(datos->alumnos.numCuenta, gtk_entry_get_text(GTK_ENTRY(datos->diseno.campo[4]))); // numCuenta
    strcpy(datos->alumnos.sexo, gtk_entry_get_text(GTK_ENTRY(datos->diseno.campo[5])));      // sexo
    strcpy(datos->alumnos.estatus, gtk_entry_get_text(GTK_ENTRY(datos->diseno.campo[6])));   // estatus
    fecha_texto = gtk_entry_get_text(GTK_ENTRY(datos->diseno.campo[7]));
    if (sscanf(fecha_texto, "%d/%d/%d", &dia, &mes, &anio) == 3)
    {
        datos->alumnos.cumple.dia = dia;
        datos->alumnos.cumple.mes = mes;
        datos->alumnos.cumple.anio = anio;
    }
    else
    {
        g_print("Fecha ingresada incorrectamente\n");
    }

    g_print("Nombre: %s \n", datos->alumnos.nombre.nombre);
    g_print("Ap_Pat: %s \n", datos->alumnos.nombre.ap_Pat);
    g_print("Ap_Mat: %s \n", datos->alumnos.nombre.ap_Mat);
    g_print("telefono: %d \n", datos->alumnos.telefono);
    g_print("Num_Cuenta: %s \n", datos->alumnos.numCuenta);
    g_print("Sexo: %s \n", datos->alumnos.sexo);
    g_print("Estatus: %s \n", datos->alumnos.estatus);
    g_print("Fecha: %d/%d/%d\n\n\n\n", datos->alumnos.cumple.dia, datos->alumnos.cumple.mes, datos->alumnos.cumple.anio);

    InsertaAlumno(&inicio, *datos);
    Imprime(inicio);
}

void abrir_nueva_ventana(GtkWidget *widget, gpointer data)
{
    tipoacademico *datos = (tipoacademico *)malloc(sizeof(tipoacademico));
    GdkColor color;

    // Crear la nueva ventana
    datos->tabla_mat.new_ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(datos->tabla_mat.new_ventana), "Ventana de Materias");
    gtk_window_set_default_size(GTK_WINDOW(datos->tabla_mat.new_ventana), 200, 200);

    // Cambiar el color de fondo de la ventana
    gdk_color_parse("#ECE0F8", &color);
    gtk_widget_modify_bg(datos->tabla_mat.new_ventana, GTK_STATE_NORMAL, &color);

    // Crear una tabla para organizar los widgets
    datos->tabla_mat.table = gtk_table_new(3, 2, TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(datos->tabla_mat.table), 20);

    // Crear etiquetas y campo de entrada
    datos->tabla_mat.label[0] = gtk_label_new("Ingresa la información de la materia");
    datos->tabla_mat.label[1] = gtk_label_new("Nombre: ");
    datos->tabla_mat.name[0] = gtk_entry_new();
    datos->tabla_mat.label[2] = gtk_label_new("Clave : ");
    datos->tabla_mat.name[1] = gtk_entry_new();
    datos->tabla_mat.label[3] = gtk_label_new("Calificacion : ");
    datos->tabla_mat.name[2] = gtk_entry_new();

    // Crear botones
    datos->tabla_mat.boton = gtk_button_new_with_label("Enviar");
    g_signal_connect(datos->tabla_mat.boton, "clicked", G_CALLBACK(LeeCampoMaterias), datos);

    // g_signal_connect(boton, "clicked", G_CALLBACK(LeeCampoMaterias), name2);
    // g_signal_connect(boton, "clicked", G_CALLBACK(LeeCampoMaterias), name3);
    gtk_table_attach(GTK_TABLE(datos->tabla_mat.table), datos->tabla_mat.boton, 0, 1, 4, 5, GTK_FILL, GTK_FILL, 0, 0);

    datos->tabla_mat.boton = gtk_button_new_with_label("Borrar");
    g_signal_connect(datos->tabla_mat.boton, "clicked", G_CALLBACK(ClearEntry), datos->tabla_mat.name[0]);
    g_signal_connect(datos->tabla_mat.boton, "clicked", G_CALLBACK(ClearEntry), datos->tabla_mat.name[1]);
    g_signal_connect(datos->tabla_mat.boton, "clicked", G_CALLBACK(ClearEntry), datos->tabla_mat.name[2]);
    gtk_table_attach(GTK_TABLE(datos->tabla_mat.table), datos->tabla_mat.boton, 1, 2, 4, 5, GTK_FILL, GTK_FILL, 0, 0);

    // Adjuntar las etiquetas y el campo de entrada a la tabla
    gtk_table_attach(GTK_TABLE(datos->tabla_mat.table), datos->tabla_mat.label[0], 0, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
    gtk_table_attach(GTK_TABLE(datos->tabla_mat.table), datos->tabla_mat.label[1], 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
    gtk_table_attach(GTK_TABLE(datos->tabla_mat.table), datos->tabla_mat.name[0], 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
    gtk_table_attach(GTK_TABLE(datos->tabla_mat.table), datos->tabla_mat.label[2], 0, 1, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
    gtk_table_attach(GTK_TABLE(datos->tabla_mat.table), datos->tabla_mat.name[1], 1, 2, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
    gtk_table_attach(GTK_TABLE(datos->tabla_mat.table), datos->tabla_mat.label[3], 0, 1, 3, 4, GTK_FILL, GTK_FILL, 0, 0);
    gtk_table_attach(GTK_TABLE(datos->tabla_mat.table), datos->tabla_mat.name[2], 1, 2, 3, 4, GTK_FILL, GTK_FILL, 0, 0);

    // Agregar la tabla a la nueva ventana
    gtk_container_add(GTK_CONTAINER(datos->tabla_mat.new_ventana), datos->tabla_mat.table);

    // Mostrar todos los widgets
    gtk_widget_show_all(datos->tabla_mat.new_ventana);
}

void LeeCampoMaterias(GtkButton *button, gpointer data)
{
    tipoacademico *datos = (tipoacademico *)data;
    const gchar *clave_txt, *calif_txt;
    int clave;
    double calif;
    /*
        Guia de como hacerlo :(
        strcpy(datos->alumnos.nombre.nombre, gtk_entry_get_text(GTK_ENTRY(datos->diseno.campo[0])));
        g_print("Nombre: %s \n", datos->alumnos.nombre.nombre);
    */
    strcpy(datos->nombreMat, gtk_entry_get_text(GTK_ENTRY(datos->tabla_mat.name[0])));

    clave_txt = gtk_entry_get_text(GTK_ENTRY(datos->tabla_mat.name[1]));
    clave = atoi(clave_txt);
    datos->clave = clave;

    calif_txt = gtk_entry_get_text(GTK_ENTRY(datos->tabla_mat.name[2]));
    calif = atoi(calif_txt);
    datos->cal = calif;
    g_print("Nombre de la Materia: %s \n", datos->nombreMat);
    g_print("Clave de la Materia: %d \n", datos->clave);
    g_print("Calificacio de la Materia: %lf \n", datos->cal);
}

void InsertaMaterias(tipoacademico **inicio, tipoacademico academico)
{
    tipoacademico *temp;

    temp = (tipoacademico *)malloc(sizeof(tipoacademico));
    *temp = academico;
    temp->abajo = *inicio;
    *inicio = temp;
}
