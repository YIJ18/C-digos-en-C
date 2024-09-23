#include "header.h"


void mover(GtkWidget * boton, gpointer info);
int ceroPar(int a[4][4]);
int inversiones(int a[4][4]);
int checaResolvible(int a[4][4]);
int modificarArray(int actual[4][4], coordenada * coordenadas, coordenada *coordenadasO, int dato);
void imprimirMatriz(int matriz[4][4]);
void barajarArreglo(int arreglo[], int n);
void generarMatriz(int matriz[4][4], int matrizInicial[4][4]);
int verificar(matrizDeJuego *juego);
void crearTabla(matrizDeJuego * juego);
void G_mover(coordenada coordenadasA,coordenada coordenadasO, juegoYMenus * juego, int numero, GtkWidget * boton);
void ventanaSiguiente(GtkButton *button, gpointer data);
void funcionSalir(GtkWidget *widget, gpointer info);
gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer info);
void crearTablero(gpointer datos);
void reiniciarJuego(GtkWidget *widget, gpointer info);
gboolean actualizarReloj(gpointer datos);
void pausar_cronometro(GtkWidget *boton, gpointer datos);
void reanudar_cronometro(GtkWidget *boton, gpointer datos);
void guardarDatos(GtkButton *button, gpointer info);
void iniciar_cronometro(GtkWidget *boton, gpointer datos);
void reiniciar_cronometro(GtkWidget *boton, gpointer datos);
void cargarTablero(gpointer datos, juegoBase juegoCargado);
void insertarElemento(GtkButton *button, gpointer info);
void funcionPopOut(GtkButton *button, gpointer data);

/*
 *@brief actualiza el reloj cada segundo
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param datos, variable tipo apuntador
 *@return vacio
*/
gboolean actualizarReloj(gpointer datos) {
    tiempo *cronometro = (tiempo *) datos;
    
    cronometro->segundos += 1;
    
    if (cronometro->segundos == 60) {
        cronometro->segundos = 0;
        cronometro->minutos += 1;
    }
    
    if (cronometro->minutos == 60) {
        cronometro->minutos = 0;
        cronometro->horas += 1;
    }
    
    sprintf(cronometro->display, "%02d:%02d:%02d", cronometro->horas, cronometro->minutos, cronometro->segundos);
    
    // Actualiza el texto del label.
    gtk_label_set_text(GTK_LABEL(cronometro->etiqueta), cronometro->display);

    // Devuelve TRUE para que el temporizador se siga ejecutando.
    return TRUE;
}

//es como actualizarReloj pero respeta el tiempo que habia
gboolean respetar(gpointer datos){
    tiempo *cronometro = (tiempo *) datos;
    
    cronometro->segundos += 1;
    
    if (cronometro->segundos == 60) {
        cronometro->segundos = 0;
        cronometro->minutos += 1;
    }
    
    if (cronometro->minutos == 60) {
        cronometro->minutos = 0;
        cronometro->horas += 1;
    }
    
    sprintf(cronometro->display, "%02d:%02d:%02d", cronometro->horas, cronometro->minutos, cronometro->segundos);
    
    // Actualiza el texto del label.
    gtk_label_set_text(GTK_LABEL(cronometro->etiqueta), cronometro->display);

    // Devuelve TRUE para que el temporizador se siga ejecutando.
    return TRUE;
}


void pausar_cronometro(GtkWidget *boton, gpointer datos) {
    tiempo *cronometro = (tiempo *) datos;
    gtk_timeout_remove(cronometro->id);
}


/*
 *@brief reanuda el cronometro cada segundo
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param boton, variable tipo GtkWidget
 *@param datos, variable tipo puntero
 *@return vacio
*/
void reanudar_cronometro(GtkWidget *boton, gpointer datos) {
    tiempo *cronometro = (tiempo *) datos;
  
    // Establece el temporizador para que se actualice el reloj cada segundo.
    cronometro->id = gtk_timeout_add(1000, respetar, cronometro);
}


/*
 *@brief inicia el temporizador cuando se inicia el juego y se actualiza cada segundo
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param boton, variable tipo GtkWidget
 *@param datos, variable tipo puntero
 *@return vacio
*/
void iniciar_cronometro(GtkWidget *boton, gpointer datos) {
    tiempo *cronometro = (tiempo *) datos;

    // Establece el temporizador para que se actualice el reloj cada segundo.
    cronometro->segundos = 0;
    cronometro->minutos = 0;
    cronometro->horas = 0;
    cronometro->id= gtk_timeout_add(1000, actualizarReloj, cronometro);
}


/*
 *@brief reinicia el cronometro
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param boton, variable tipo GtkWidget
 *@param datos, variable tipo puntero
 *@return vacio
*/
void reiniciar_cronometro(GtkWidget *boton, gpointer datos) {
    tiempo *cronometro = (tiempo *) datos;

    // Detener el temporizador actual.
    gtk_timeout_remove(cronometro->id);

    // Reiniciar los valores del cronómetro.
    cronometro->segundos = 0;
    cronometro->minutos = 0;
    cronometro->horas = 0;

    // Actualizar la etiqueta del cronómetro.
    gtk_label_set_text(GTK_LABEL(cronometro->etiqueta), "00:00:00");
}