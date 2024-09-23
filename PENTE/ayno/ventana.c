#include <gtk/gtk.h>

#define ROWS 20
#define COLS 20

// Tablero
int tablero[ROWS][COLS] = {
    {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1},
    {1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2},
    // Agrega más filas según necesites
};

// Función para dibujar la ventana
void draw_board(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    int cell_width = gtk_widget_get_allocated_width(widget) / COLS;
    int cell_height = gtk_widget_get_allocated_height(widget) / ROWS;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (tablero[i][j] == 1) {
                // Dibujar una 'X'
                cairo_move_to(cr, j * cell_width, i * cell_height);
                cairo_line_to(cr, (j + 1) * cell_width, (i + 1) * cell_height);
                cairo_move_to(cr, (j + 1) * cell_width, i * cell_height);
                cairo_line_to(cr, j * cell_width, (i + 1) * cell_height);
                cairo_stroke(cr);
            } else if (tablero[i][j] == 2) {
                // Dibujar una 'Y'
                cairo_move_to(cr, j * cell_width, i * cell_height);
                cairo_line_to(cr, (j + 1) * cell_width, (i + 1) * cell_height);
                cairo_line_to(cr, j * cell_width, (i + 1) * cell_height);
                cairo_stroke(cr);
            }
        }
    }
}

// Función principal
int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *drawing_area;

    gtk_init(&argc, &argv);

    // Crear la ventana principal
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tablero");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Crear el área de dibujo
    drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    // Conectar la función de dibujo al evento 'draw'
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_board), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
