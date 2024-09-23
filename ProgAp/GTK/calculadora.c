#include <gtk-2.0/gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

void StopTheApp(GtkWidget *window, gpointer data);
GtkWidget *AddButton(GtkWidget *theBox, gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
void ButtonClicked(GtkButton *button, gpointer data);
gchar *calcular(gchar *current_text);

int main(gint argc, gchar *argv[])
{
  GtkWidget *window;
  GtkWidget *entrybox;
  GtkWidget *verticalbox;
  // GtkWidget *numbersbox;
  GtkWidget *box;
  GtkWidget *box_nivel_2;
  GtkWidget *box_nivel_3;
  GtkWidget *box_nivel_4;
  GtkWidget *button1;
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  // POner titulo a la ventana
  gtk_window_set_title(GTK_WINDOW(window), "Calculadora");
  // Para cerrar la ventana
  gtk_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(StopTheApp), NULL);
  // SE le pone el borde
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  // no sè que hace
  verticalbox = gtk_vbox_new(TRUE, 5);

  // crea una entrada
  entrybox = gtk_entry_new();
  // Caja nueva horizontal
  box = gtk_hbox_new(TRUE, 5);
  box_nivel_2 = gtk_hbox_new(TRUE, 5);
  box_nivel_3 = gtk_hbox_new(TRUE, 5);
  box_nivel_4 = gtk_hbox_new(TRUE, 5);
  // caja 1
  button1 = AddButton(box, "9", ButtonClicked, entrybox);
  button1 = AddButton(box, "8", ButtonClicked, entrybox);
  button1 = AddButton(box, "7", ButtonClicked, entrybox);
  button1 = AddButton(box, " ", ButtonClicked, entrybox);
  // caja 2
  button1 = AddButton(box_nivel_2, "6", ButtonClicked, entrybox);
  button1 = AddButton(box_nivel_2, "5", ButtonClicked, entrybox);
  button1 = AddButton(box_nivel_2, "4", ButtonClicked, entrybox);
  button1 = AddButton(box_nivel_2, "x", ButtonClicked, entrybox);
  // caja 3
  button1 = AddButton(box_nivel_3, "3", ButtonClicked, entrybox);
  button1 = AddButton(box_nivel_3, "2", ButtonClicked, entrybox);
  button1 = AddButton(box_nivel_3, "1", ButtonClicked, entrybox);
  button1 = AddButton(box_nivel_3, "/", ButtonClicked, entrybox);
  // caja 4
  button1 = AddButton(box_nivel_4, "0", ButtonClicked, entrybox);
  button1 = AddButton(box_nivel_4, "-", ButtonClicked, entrybox);
  button1 = AddButton(box_nivel_4, "+", ButtonClicked, entrybox);
  button1 = AddButton(box_nivel_4, "=", ButtonClicked, entrybox);

  gtk_box_pack_start(GTK_BOX(verticalbox), entrybox, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(verticalbox), box, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(verticalbox), box_nivel_2, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(verticalbox), box_nivel_3, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(verticalbox), box_nivel_4, TRUE, TRUE, 5);

  //  empacamiento correcto
  gtk_container_add(GTK_CONTAINER(window), verticalbox);

  // Cambiar el color de fondo de la ventana
  GdkColor color;
  gdk_color_parse("#ECE0F8", &color); // Cambia el código de color aquí (#RRGGBB)
  gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &color);

  gtk_widget_show_all(window);

  gtk_main();
  return 0;
}

GtkWidget *AddButton(GtkWidget *theBox, gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
  GtkWidget *button;
  button = gtk_button_new_with_label(buttonText);
  gtk_box_pack_start(GTK_BOX(theBox), button, FALSE, TRUE, 0);
  gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(CallBackFunction), EntryBox);
  gtk_widget_show(button);
  return button;
}

void StopTheApp(GtkWidget *window, gpointer data)
{
  gtk_main_quit();
}

void ButtonClicked(GtkButton *button, gpointer data)
{
  // Para robarte el texto de tu boton
  gchar *label, *current_text;
  GtkEntry *entry;
  gchar *new_text, result[50];

  // Robate el titulo de tu boton
  label = gtk_button_get_label(button);
  entry = GTK_ENTRY(data); // ES UN CAST
  // Pre concatenadora, y se roba el texto de mi cajita
  current_text = gtk_entry_get_text(entry);
  // Si el botón "=" es presionado, calcular el resultado
  if (strcmp(label, "=") == 0)
  {
    strcpy(result, calcular(current_text));

    gtk_entry_set_text(entry, result);
  }
  else
  {
    // agrega más texto/ lo que hace va a concatenar la cadena que acabo de crear con mi boton
    new_text = g_strconcat(current_text, label, NULL);
    // impresion en la caja
    gtk_entry_set_text(entry, new_text);
  }
}

gchar *calcular(gchar *current_text)
{
  gchar signo;
  int numero1, numero2;
  double result;
  sscanf(current_text, "%d%c%d", &numero1, &signo, &numero2);
  if (signo == '+')
    result = numero1 + numero2;
  if (signo == '-')
    result = numero1 - numero2;
  if (signo == 'x')
    result = numero1 * numero2;
  if (signo == '/')
    result = numero2 / numero2;
  return g_strdup_printf("%lf", result);
}
