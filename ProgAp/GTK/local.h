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
} principal;