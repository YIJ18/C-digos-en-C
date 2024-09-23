/* calcula.c
   Este ejercicio muestra el uso de contenedores, botones y
   espacios de entrada con sus funciones de callback y seniales

   generando una calculadora sencilla

*/

#include <gtk-2.0/gtk/gtk.h>
#include <string.h>

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

GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
GtkWidget *AddButton2(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, tipo_param *EntryBox);
void ButtonClicked(GtkWidget *button, gpointer data);
void StopTheApp(GtkWidget *window, gpointer data);
void ButtonClicked2(GtkWidget *button, gpointer data);
void ButtonClicked3(GtkWidget *button, gpointer data);
void Cambiaopcion1(GtkToggleButton *button, gpointer data);
void lee(GtkWidget *button, gpointer data);
void guarda(GtkWidget *button, gpointer data);
void limpia(GtkWidget *button, gpointer data);
void Acercade(GtkWidget *button, gpointer data);
void on_close(GtkDialog *dialog, gint response_id, gpointer user_data);
void CierraVentana(GtkWidget *button, gpointer data);

gint main(gint argc, gchar *argv[])
{

    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box1, *box2, *box3, *box4, *box5;
    GtkWidget *verticalbox, *vertical2, *vertical3;
    GtkWidget *entrybox;
    GtkWidget *label;
    GtkWidget *texto;
    GtkWidget *menu, *menu1, *root_menu, *menu_bar, *op1, *op2, *op3, *rb1, *rb2;
    char buf[128];
    int i;
    GdkColor color;

    tipo_param parametro;

    parametro.ventana = NULL;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 320, 200);
    gtk_window_move(GTK_WINDOW(window), 200, 400);
    gtk_container_border_width(GTK_CONTAINER(window), 0);

    parametro.texto = gtk_text_view_new();

    verticalbox = gtk_vbox_new(TRUE, 5);
    vertical2 = gtk_vbox_new(FALSE, 5);
    vertical3 = gtk_vbox_new(FALSE, 0);

    entrybox = gtk_entry_new();
    gtk_entry_set_editable(GTK_ENTRY(entrybox), FALSE);
    gtk_entry_set_alignment(GTK_ENTRY(entrybox), 1);
    gtk_entry_set_max_length(GTK_ENTRY(entrybox), 10);

    parametro.entry = entrybox;

    // menu
    menu_bar = gtk_menu_bar_new();

    // subsub1
    menu1 = gtk_menu_new();
    op1 = gtk_menu_item_new_with_label("Subop1");
    op2 = gtk_menu_item_new_with_label("Subop2");
    op3 = gtk_menu_item_new_with_label("Subop3");
    gtk_menu_append(GTK_MENU(menu1), op1);
    gtk_menu_append(GTK_MENU(menu1), op2);
    gtk_menu_append(GTK_MENU(menu1), op3);

    menu = gtk_menu_new();
    op1 = gtk_menu_item_new_with_label("op1");
    op2 = gtk_menu_item_new_with_label("op2");
    op3 = gtk_menu_item_new_with_label("Salir");

    gtk_signal_connect(GTK_OBJECT(op3), "activate", GTK_SIGNAL_FUNC(StopTheApp), NULL);

    gtk_menu_append(GTK_MENU(menu), op1);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(op1), menu1);

    gtk_menu_append(GTK_MENU(menu), op2);
    gtk_menu_append(GTK_MENU(menu), op3);

    root_menu = gtk_menu_item_new_with_label("Calculadora");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(root_menu), menu);

    gtk_menu_bar_append(GTK_MENU_BAR(menu_bar), root_menu);

    // sub2
    menu = gtk_menu_new();
    op1 = gtk_menu_item_new_with_label("Leer");
    op2 = gtk_menu_item_new_with_label("Guardar");
    op3 = gtk_menu_item_new_with_label("Nuevo");

    gtk_menu_append(GTK_MENU(menu), op1);
    gtk_menu_append(GTK_MENU(menu), op2);
    gtk_menu_append(GTK_MENU(menu), op3);

    gtk_signal_connect(GTK_OBJECT(op1), "activate", GTK_SIGNAL_FUNC(lee), NULL);
    gtk_signal_connect(GTK_OBJECT(op2), "activate", GTK_SIGNAL_FUNC(guarda), NULL);
    gtk_signal_connect(GTK_OBJECT(op3), "activate", GTK_SIGNAL_FUNC(limpia), &parametro);

    root_menu = gtk_menu_item_new_with_label("Juego");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(root_menu), menu);

    gtk_menu_bar_append(GTK_MENU_BAR(menu_bar), root_menu);

    // sub3
    root_menu = gtk_menu_item_new_with_label("Salir");
    gtk_signal_connect(GTK_OBJECT(root_menu), "activate", GTK_SIGNAL_FUNC(StopTheApp), NULL);
    gtk_menu_bar_append(GTK_MENU_BAR(menu_bar), root_menu);

    // sub4
    root_menu = gtk_menu_item_new_with_label("Acerca_de");
    gtk_signal_connect(GTK_OBJECT(root_menu), "activate", GTK_SIGNAL_FUNC(Acercade), NULL);
    gtk_menu_bar_append(GTK_MENU_BAR(menu_bar), root_menu);

    // fin del menu

    box1 = gtk_hbox_new(TRUE, 5);
    box2 = gtk_hbox_new(TRUE, 5);
    box3 = gtk_hbox_new(TRUE, 5);
    box4 = gtk_hbox_new(TRUE, 5);

    box5 = gtk_hbox_new(TRUE, 5); // gral

    button = AddButton(box1, "1", ButtonClicked, entrybox);
    button = AddButton(box1, "2", ButtonClicked, entrybox);
    button = AddButton(box1, "3", ButtonClicked, entrybox);
    button = AddButton(box1, "CL", ButtonClicked, entrybox);

    // label = gtk_label_new(" ");
    // gtk_box_pack_start(GTK_BOX(box1),label,FALSE,TRUE,0);

    button = AddButton(box2, "4", ButtonClicked, entrybox);
    button = AddButton(box2, "5", ButtonClicked, entrybox);
    button = AddButton(box2, "6", ButtonClicked, entrybox);
    button = AddButton2(box2, "+", ButtonClicked3, &parametro);

    button = AddButton(box3, "7", ButtonClicked, entrybox);
    button = AddButton(box3, "8", ButtonClicked, entrybox);
    button = AddButton(box3, "9", ButtonClicked, entrybox);
    button = AddButton2(box3, "-", ButtonClicked3, &parametro);

    button = AddButton(box4, "0", ButtonClicked, entrybox);
    button = AddButton2(box4, "*", ButtonClicked3, &parametro);
    button = AddButton2(box4, "/", ButtonClicked3, &parametro);
    button = AddButton2(box4, "=", ButtonClicked2, &parametro);

    gtk_box_pack_start(GTK_BOX(verticalbox), entrybox, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(verticalbox), box1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(verticalbox), box2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(verticalbox), box3, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(verticalbox), box4, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(box5), verticalbox, TRUE, TRUE, 5);

    // radio buttons
    rb1 = gtk_radio_button_new_with_label(NULL, "Grados   ");
    gtk_box_pack_start(GTK_BOX(vertical3), rb1, FALSE, FALSE, 0);
    gtk_signal_connect(GTK_OBJECT(rb1), "toggled", GTK_SIGNAL_FUNC(Cambiaopcion1), &parametro);

    rb2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(rb1)), "Radianes   ");
    gtk_box_pack_start(GTK_BOX(vertical3), rb2, FALSE, FALSE, 0);
    gtk_signal_connect(GTK_OBJECT(rb2), "toggled", GTK_SIGNAL_FUNC(Cambiaopcion1), &parametro);

    rb2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(rb1)), "Gradianes   ");
    gtk_box_pack_start(GTK_BOX(vertical3), rb2, FALSE, FALSE, 0);
    gtk_signal_connect(GTK_OBJECT(rb2), "toggled", GTK_SIGNAL_FUNC(Cambiaopcion1), &parametro);

    gtk_box_pack_start(GTK_BOX(vertical3), parametro.texto, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box5), vertical3, TRUE, TRUE, 5);
    // fin radio buttons

    gtk_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(StopTheApp), NULL);

    gtk_box_pack_start(GTK_BOX(vertical2), menu_bar, FALSE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vertical2), box5, TRUE, TRUE, 5);

    gtk_container_add(GTK_CONTAINER(window), vertical2);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
    GtkWidget *button;
    button = gtk_button_new_with_label(buttonText);
    gtk_box_pack_start(GTK_BOX(theBox), button, FALSE, TRUE, 0);
    // gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,FALSE,0);
    gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(CallBackFunction), EntryBox);
    gtk_widget_show(button);
    return button;
}

GtkWidget *AddButton2(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, tipo_param *EntryBox)
{
    GtkWidget *button;
    button = gtk_button_new_with_label(buttonText);
    gtk_box_pack_start(GTK_BOX(theBox), button, FALSE, TRUE, 0);
    // gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,FALSE,0);
    gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(CallBackFunction), EntryBox);
    gtk_widget_show(button);
    return button;
}

void Cambiaopcion1(GtkToggleButton *button, gpointer data)
{
    tipo_param *datos = (tipo_param *)data;

    if (gtk_toggle_button_get_active(button))
    {
        strcpy(datos->tipogrados, gtk_button_get_label(GTK_BUTTON(button)));
        g_print("boton seleccionado %s \n", datos->tipogrados);
    }
}

void ButtonClicked(GtkWidget *button, gpointer data)
{
    const gchar *text, *text2;
    char texto2[22];

    text = gtk_button_get_label(GTK_BUTTON(button));
    if (strcmp(text, "CL") != 0)
    {
        text2 = gtk_entry_get_text(GTK_ENTRY(data));
        strcpy(texto2, text2);
        strcat(texto2, text);
    }
    else
        texto2[0] = '\0';
    gtk_entry_set_text(GTK_ENTRY(data), texto2);

    // gtk_widget_set_sensitive(button,FALSE);
}

void ButtonClicked3(GtkWidget *button, gpointer data)
{
    tipo_param *dato = (tipo_param *)data;

    const gchar *text, *text2;
    char texto2[11];

    text = gtk_button_get_label(GTK_BUTTON(button));
    dato->operacion = text[0];
    text2 = gtk_entry_get_text(GTK_ENTRY(dato->entry));

    strcpy(texto2, text2);

    sscanf(text2, "%d", &(dato->op1));

    strcpy(texto2, "");
    gtk_entry_set_text(GTK_ENTRY(dato->entry), texto2);
}

void ButtonClicked2(GtkWidget *button, gpointer data)
{
    tipo_param *datos = (tipo_param *)data;
    const gchar *text, *text2;
    char texto2[100];
    int op2;
    int res;
    char operacion, resultado[30];
    GtkTextBuffer *Buff;
    GtkTextIter inicio, fin, pos;

    text = gtk_entry_get_text(GTK_ENTRY(datos->entry));

    sscanf(text, "%d", &op2);
    switch (datos->operacion)
    {
    case '+':
        res = datos->op1 + op2;
        break;
    case '-':
        res = datos->op1 - op2;
        break;
    case '*':
        res = datos->op1 * op2;
        break;
    case '/':
        res = datos->op1 / op2;
        break;
    }
    sprintf(resultado, "%d", res);
    gtk_entry_set_text(GTK_ENTRY(datos->entry), resultado);

    sprintf(resultado, "%d%c%d=%d\n", datos->op1, datos->operacion, op2, res);

    Buff = gtk_text_view_get_buffer(GTK_TEXT_VIEW(datos->texto));

    gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(Buff), resultado, strlen(resultado));

    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(Buff), &inicio, &fin);
    text2 = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(Buff), &inicio, &fin, FALSE);

    strcpy(texto2, text2);
    g_print(texto2);

    printf("otra\n");

    gtk_text_view_get_line_at_y(GTK_TEXT_VIEW(datos->texto), &pos, 2, NULL);
    text2 = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(Buff), &pos, &fin, FALSE);
    strcpy(texto2, text2);

    g_print(texto2);
}

void StopTheApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
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
        //   strcat(nombre,gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialogo)));
        //   leerarchivo(nombre_arch,&(datos->inicioalumnos));
    }

    gtk_widget_destroy(dialogo);
}

void guarda(GtkWidget *button, gpointer data)
{

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
    }

    gtk_widget_destroy(dialogo);
}

void limpia(GtkWidget *button, gpointer data)
{
    tipo_param *datos = (tipo_param *)data;

    GtkWidget *vb;
    GtkWidget *boton;

    g_print("limpiar");

    if (datos->ventana == NULL)
    {
        datos->ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_signal_connect(GTK_OBJECT(datos->ventana), "destroy", GTK_SIGNAL_FUNC(CierraVentana), datos);

        vb = gtk_vbox_new(TRUE, 0);

        boton = gtk_button_new_with_label("Limpiar");
        gtk_signal_connect(GTK_OBJECT(boton), "clicked", GTK_SIGNAL_FUNC(CierraVentana), datos);
        gtk_box_pack_start(GTK_BOX(vb), boton, TRUE, TRUE, 0);

        datos->checks.cb1 = gtk_check_button_new_with_label("check 1");
        gtk_box_pack_start(GTK_BOX(vb), datos->checks.cb1, TRUE, TRUE, 0);
        datos->checks.cb2 = gtk_check_button_new_with_label("check 2");
        gtk_box_pack_start(GTK_BOX(vb), datos->checks.cb2, TRUE, TRUE, 0);
        datos->checks.cb3 = gtk_check_button_new_with_label("check 3");
        gtk_box_pack_start(GTK_BOX(vb), datos->checks.cb3, TRUE, TRUE, 0);
        datos->checks.cb4 = gtk_check_button_new_with_label("check 4");
        gtk_box_pack_start(GTK_BOX(vb), datos->checks.cb4, TRUE, TRUE, 0);

        gtk_container_add(GTK_CONTAINER(datos->ventana), vb);
        gtk_widget_show_all(datos->ventana);
    }
}

void Acercade(GtkWidget *button, gpointer data)
{
    GtkWidget *about_dialog;
    const gchar *authors[] = {"Yo mismo", "otro mas", "y el ultimo", NULL};
    const gchar *documenters[] = {"El que documenta", NULL};

    about_dialog = gtk_about_dialog_new();

    /* We fill in the information for the about dialog */
    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about_dialog), "Ejemplo de AboutDialog");
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

void CierraVentana(GtkWidget *button, gpointer data)
{
    tipo_param *datos = (tipo_param *)data;
    /* This will cause the dialog to be destroyed */
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(datos->checks.cb1)))
    {
        gtk_widget_destroy(GTK_WIDGET(datos->ventana));
        datos->ventana = NULL;
    }
}