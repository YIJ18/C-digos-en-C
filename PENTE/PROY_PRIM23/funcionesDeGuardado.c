#include "header.h"

/*
 *@brief 
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param 
 *@param 
 *@return vacio
*/

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
 *@brief abre una ventana de dialogo cuando se ingresa la opcion 'Nuevo'
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param button, variable tipo GtkButton
 *@param info, variable tipo apuntador
 *@return vacio
*/
void rutinaDeGuardado1(GtkButton *button, gpointer info) {

    GtkWidget *ventanaDeDialogoPrincipal;
    GtkWidget *areaDeContenidoP;
    GtkWidget *descripcionP;
    GtkWidget *entryBox;
    gint respuesta;
    const gchar *text; 

    juegoYMenus *ventana2 = (juegoYMenus * ) info;

    
     GtkWidget *parent_window = GTK_WIDGET(ventana2->ventana);

     // Crear una nueva etiqueta de texto con el mensaje de advertencia
    descripcionP = gtk_label_new("Si reinicias la partida perderas tu progreso\n\n¿Desea continuar?\n");
    // Crear una nueva ventana de diálogo
    ventanaDeDialogoPrincipal = gtk_dialog_new_with_buttons("Advertencia", GTK_WINDOW(parent_window), GTK_DIALOG_MODAL, "Cancelar", GTK_RESPONSE_CANCEL, "Guardar", GTK_RESPONSE_YES, "Continuar", GTK_RESPONSE_NO, NULL);

    // Obtener la caja de contenido de la ventana de diálogo
    areaDeContenidoP = gtk_dialog_get_content_area(GTK_DIALOG(ventanaDeDialogoPrincipal));

    // Agregar la etiqueta de texto a la caja de contenido de la ventana de diálogo
    gtk_container_add(GTK_CONTAINER(areaDeContenidoP), descripcionP);
    gtk_widget_show(descripcionP);

    // Mostrar la ventana de diálogo y esperar a que se cierre
    respuesta = gtk_dialog_run(GTK_DIALOG(ventanaDeDialogoPrincipal));

    if (respuesta == GTK_RESPONSE_YES) {
      gtk_widget_destroy (ventanaDeDialogoPrincipal);
      guardarDatos(NULL, ventana2);
      reiniciarJuego(NULL, ventana2);
    
    }
    else if (respuesta == GTK_RESPONSE_NO) {
      gtk_widget_destroy (ventanaDeDialogoPrincipal);
      reiniciarJuego(NULL, ventana2);
    }

    else if (respuesta == GTK_RESPONSE_CANCEL) {
      gtk_widget_destroy (ventanaDeDialogoPrincipal);
    }
}


/*
 *@brief abre una ventana de dialogo para guardar la partida
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param button, variable tipo GtkButton
 *@param info, variable tipo apuntador
 *@return vacio
*/
void guardarDatos(GtkButton *button, gpointer info){
  GtkWidget *entry;
  GtkWidget *areaDeContenido;
  GtkWidget *ventanaDeCapturaDeDatos;
  GtkWidget *ventanaDeDialogo;
  GtkWidget *descripcion;
  const gchar *text;
  gint respuesta;
  juegoBase infoPatida;
  FILE *fp;
  int i,x;
  char buffer[200];

  GtkWidget *parent_window = GTK_WIDGET(info);


  juegoYMenus *ventana2 = (juegoYMenus*) info;
  ventanaDeDialogo = gtk_dialog_new_with_buttons("Advertencia", GTK_WINDOW(parent_window), GTK_DIALOG_MODAL, "Guardar", GTK_RESPONSE_ACCEPT, NULL);


  entry = gtk_entry_new();
  areaDeContenido = gtk_dialog_get_content_area(GTK_DIALOG(ventanaDeDialogo));

  descripcion = gtk_label_new("\nIngresa un nombre para tu partida\n");
  gtk_container_add(GTK_CONTAINER(areaDeContenido), descripcion);
  gtk_container_add(GTK_CONTAINER(areaDeContenido), entry);
  gtk_widget_show_all(ventanaDeDialogo);

  respuesta = gtk_dialog_run(GTK_DIALOG(ventanaDeDialogo));

  if (respuesta == GTK_RESPONSE_ACCEPT) {
    text = gtk_entry_get_text(GTK_ENTRY(entry));
    sprintf(buffer,"/home/ic22iph/PROY_PRIM23/partidas/%s.pzz",text);
    fp = fopen(buffer,"wb");
    g_print ("Partida guardada con nombre %s" ,buffer);

  if(fp == NULL){
  
  }
  //guarda el estado del juego y todos los movimientos en una lista doblemente encadenada
  for ( i = 0; i < 4; i++)
  {
    for ( x = 0; x< 4; x++)
    {
      infoPatida.matrizInicial[i][x] = ventana2->tablero->juegoInicial[i][x];
    }
  }

  infoPatida.segundos = ventana2->tablero->cronometro.segundos;
  infoPatida.minutos = ventana2->tablero->cronometro.minutos;
  infoPatida.horas = ventana2->tablero->cronometro.horas;

  infoPatida.numeroDeJugadas = ventana2->tablero->numeroDeJugadas;
  strcpy (infoPatida.tiempo, ventana2->tablero->cronometro.display);
  infoPatida.tipoDeJuego =  ventana2->tablero->tipoDeJuego; 

  fwrite (&infoPatida, sizeof(juegoBase),1,fp);

  nodoDoble *nodoT;

  nodoT = ventana2->tablero->inicio;

  int i=1;

  nodoDoble *aux,*nodo;
  nodo= ventana2->tablero->inicio;
  
/*
  aux = nodo;
  while (aux != NULL) {
    nodo = (nodoDoble *)nodo->sig;
    fwrite (&aux->datos , sizeof(infoNodoDoble),1,fp);
    free(aux);
    aux = nodo;
  }
  */

  fclose(fp);
   

  //mensaje emergente de partida guardada  
  ventanaDeCapturaDeDatos = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Partida %s gardada con exito", text);
  gtk_window_set_title(GTK_WINDOW(ventanaDeCapturaDeDatos ), "Guardado de partida");
  gtk_dialog_run(GTK_DIALOG(ventanaDeCapturaDeDatos ));
  gtk_widget_destroy(ventanaDeCapturaDeDatos );

   //gtk_widget_destroy(ventanaDeCapturaDeDatos);
  gtk_widget_destroy (ventanaDeDialogo);
                                          
  }
}

