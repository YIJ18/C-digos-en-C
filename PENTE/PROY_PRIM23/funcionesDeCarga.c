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
void AsignarSolucionCaracol(GtkWidget * boton, gpointer info);
void AsignarSolucionVerical(GtkWidget * boton, gpointer info);
void AsignarSolucionHorizontal(GtkWidget * boton, gpointer info);
void asignarSolucion(matrizDeJuego *juego, char solucion);
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
 *@brief crea una ventana de dialogo que pide el guardado de un archivo
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param button, variable tipo GtkWidget
 *@param info, variable tipo puntero
 *@return vacio
*/
void rutinaDeCargado(GtkButton *button, gpointer info) {


    juegoYMenus *ventana2 = (juegoYMenus * ) info;
     GtkWidget *parent_window = GTK_WIDGET(ventana2->ventana);

    GtkWidget *ventanaDeArchivos, *selectorDeArchivo;
    GtkFileFilter *extension;
    gchar *nombreDeArchivo;
    gint response;
    FILE *fp;
    infoNodoDoble datos;
    juegoBase partida;
    int x,y;


    ventanaDeArchivos = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ventanaDeArchivos), "Cagado de Partida");
    gtk_container_set_border_width(GTK_CONTAINER(ventanaDeArchivos), 10);
    g_signal_connect(G_OBJECT(ventanaDeArchivos), "destroy", G_CALLBACK(gtk_widget_destroy), ventanaDeArchivos);

    selectorDeArchivo = gtk_file_chooser_dialog_new("Partida a cargar", GTK_WINDOW(ventanaDeArchivos), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);

    // Establece la carpeta por defecto
    gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(selectorDeArchivo), "partidas");

    // Agrega un filtro por extensión
    extension = gtk_file_filter_new();
    gtk_file_filter_add_pattern(extension, "*.pzz");
    gtk_file_filter_set_name(extension, "Partidas");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(selectorDeArchivo), extension);

    response = gtk_dialog_run(GTK_DIALOG(selectorDeArchivo));

    if (response == GTK_RESPONSE_ACCEPT) {
        nombreDeArchivo = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(selectorDeArchivo));
        g_print("Partida a cargar: %s\n", nombreDeArchivo);

        fp = fopen(nombreDeArchivo,"rb");
        if (fp == NULL){
          return;
        }

        printf("\n\n\n");
        fread(&partida,sizeof(juegoBase),1, fp);


      cargarTablero(ventana2, partida);

        g_free(nombreDeArchivo); 
    
    }




    gtk_widget_destroy(selectorDeArchivo);
    gtk_widget_destroy(ventanaDeArchivos);

   
}



void movSig(GtkButton *button, gpointer data) {
    // Destruye la ventana de diálogo
    gtk_widget_destroy(GTK_WIDGET(data));
}

void crearVentanaMovSig() {
    // Crea una nueva ventana de diálogo
    GtkWidget *ventanaDeDialogo = gtk_dialog_new();

    // Crea un botón "OK" y lo agrega a la ventana de diálogo
    GtkWidget *botonOk = gtk_button_new_with_label("Siguiente movimiento");
    gtk_container_add(GTK_CONTAINER(GTK_DIALOG(ventanaDeDialogo)->action_area), botonOk);
    g_signal_connect(G_OBJECT(botonOk), "clicked", G_CALLBACK(movSig), ventanaDeDialogo);
    // Muestra la ventana de diálogo
    gtk_widget_show_all(ventanaDeDialogo);
}

    

/*
 *@brief  carga la partida desde un archivo
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param button, variable tipo GtkWidget
 *@param info, variable tipo apuntador
 *@return vacio
*/
void cargarPartida(GtkButton *button, gpointer info) {

    GtkWidget *ventanaDeDialogoPrincipal;
    GtkWidget *areaDeContenidoP;
    GtkWidget *descripcionP;
    GtkWidget *entryBox;
    gint respuesta;
    const gchar *text; 

    juegoYMenus *ventana2 = (juegoYMenus * ) info;

    
     GtkWidget *parent_window = GTK_WIDGET(ventana2->ventana);

     // Crear una nueva etiqueta de texto con el mensaje de advertencia
    descripcionP = gtk_label_new("Si cargas una partida anterior perderas\ntodo tu progreso en la partida actual.\n\n¿Desea continuar?\n");
    // Crear una nueva ventana de diálogo
    ventanaDeDialogoPrincipal = gtk_dialog_new_with_buttons("Advertencia", GTK_WINDOW(parent_window), GTK_DIALOG_MODAL, "Cancelar", GTK_RESPONSE_CANCEL, "Cargar", GTK_RESPONSE_YES, NULL);

    // Obtener la caja de contenido de la ventana de diálogo
    areaDeContenidoP = gtk_dialog_get_content_area(GTK_DIALOG(ventanaDeDialogoPrincipal));

    // Agregar la etiqueta de texto a la caja de contenido de la ventana de diálogo
    gtk_container_add(GTK_CONTAINER(areaDeContenidoP), descripcionP);
    gtk_widget_show(descripcionP);

    // Mostrar la ventana de diálogo y esperar a que se cierre
    respuesta = gtk_dialog_run(GTK_DIALOG(ventanaDeDialogoPrincipal));

    if (respuesta == GTK_RESPONSE_YES) {
        gtk_widget_destroy (ventanaDeDialogoPrincipal);
        rutinaDeCargado(NULL, ventana2);
    
    }

    else if (respuesta == GTK_RESPONSE_CANCEL) {
    gtk_widget_destroy (ventanaDeDialogoPrincipal);
    }
}




/*
 *@brief carga el tablero guardado en el juego nuevo
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param datos, variable tipo puntero
 *@param juegoCargado, variable tipo JuegoBase
 *@return vacio
*/
void cargarTablero(gpointer datos, juegoBase juegoCargado)
{

  int i,j;
  juegoYMenus *ventana2 = (juegoYMenus * ) datos;
  matrizDeJuego *juegoNuevo;
  char buffer[30];
 juegoNuevo = malloc(sizeof(matrizDeJuego));


  gtk_widget_destroy(ventana2->tablero->tabla);
  gtk_widget_destroy(ventana2->tablero->contadorDeJugadas);
  gtk_widget_destroy(ventana2->tablero->cronometro.etiqueta);

 for(i=0; i<4; i++){
  for(j=0; j<4; j++){
    juegoNuevo->juegoActual[i][j] = juegoCargado.matrizInicial[i][j];
  }
 }

  imprimirMatriz (juegoCargado.matrizInicial);
  printf ("\n");
  imprimirMatriz (juegoNuevo->juegoActual);
  crearTabla(juegoNuevo);  
    for (i = 0; i < 16; i++) {
   g_signal_connect(G_OBJECT(juegoNuevo->boton[i]), "clicked", G_CALLBACK(mover),ventana2);
  }
  
  if(juegoCargado.tipoDeJuego == 'h'){
    strcpy(juegoNuevo->tipoDeJuego, "horizontal");
  }
  else if(juegoCargado.tipoDeJuego == 'v'){
    strcpy(juegoNuevo->tipoDeJuego, "vertical");
  }
  else if(juegoCargado.tipoDeJuego == 'c'){
    strcpy(juegoNuevo->tipoDeJuego, "caracol");
  }

  juegoNuevo->numeroDeJugadas = juegoCargado.numeroDeJugadas;

  juegoNuevo->cronometro.segundos = juegoCargado.segundos;
  juegoNuevo->cronometro.minutos = juegoCargado.minutos;
  juegoNuevo->cronometro.horas = juegoCargado.horas;
  asignarSolucion(juegoNuevo, juegoCargado.tipoDeJuego);

  juegoNuevo->nodo2= NULL;
  juegoNuevo->inicio = NULL;
  //juegoNuevo->aux->ant= NULL;
  sprintf(buffer, "Jugadas realizadas\n\n%d", juegoCargado.numeroDeJugadas);
  juegoNuevo->contadorDeJugadas = gtk_label_new(buffer);
  juegoNuevo->cronometro.etiqueta = gtk_label_new(juegoCargado.tiempo); 
  reanudar_cronometro(NULL, &ventana2->tablero->cronometro);




  ventana2->tablero = juegoNuevo;
   gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),juegoNuevo->cronometro.etiqueta);
   gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),juegoNuevo->contadorDeJugadas);
 
  gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalIzquierda),ventana2->tablero->tabla);
  gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),ventana2->tipoDeJuego);
  gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),ventana2->tablero->cronometro.etiqueta);
  gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),ventana2->tablero->contadorDeJugadas);
  gtk_widget_show_all(ventana2->tablero->tabla);
  gtk_widget_show_all(ventana2->cajaVerticalDerecha);
}
