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
void ganaste(int score);

/*
 *@brief asigna los movimientos realizados en el juego a una lista doble
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param boton, variable tipo GtkButton
 *@param info, apuntador
 *@return vacio
*/
void insertarElemento(GtkButton *boton, gpointer info) {

  juegoYMenus *ventana2 =  (juegoYMenus*) info;
  nodoDoble *aux2;

  nodoDoble *nodoNuevo = malloc(sizeof(nodoDoble));
    const char * nombreBoton;
    int xA,yA,xO,yO,num;

  nombreBoton =gtk_widget_get_name( GTK_WIDGET(boton));
  
  printf("\n\n\n Este boton ha sido insertado %s\n\n\n", nombreBoton);
  sscanf(nombreBoton, "%d,%d/%d/%d,%d", &xA,&yA,&num,&xO,&yO);

  if (nodoNuevo == NULL) {
    printf("Error en la asignacion de memoria");
  }

  nodoNuevo->datos.actual.x =xA;
  nodoNuevo->datos.actual.y =yA;
  nodoNuevo->datos.original.x =xO;
  nodoNuevo->datos.original.y =yO;
  nodoNuevo->datos.valor = num;
  
  nodoNuevo->sig = NULL;

  if (ventana2->tablero->inicio == NULL) {

    nodoNuevo->ant = NULL;
    ventana2->tablero->inicio = nodoNuevo;

    printf("Elemento 1 %d agregado en a lista", nodoNuevo->datos.valor);

  } else {

    if (ventana2->tablero->nodo2 != NULL) {
	
	  nodoNuevo->ant=  (struct nodoDoble *) ventana2->tablero->aux;
      ventana2->tablero->aux ->sig = (struct nodoDoble *) nodoNuevo;
      ventana2->tablero->aux  = nodoNuevo;

      aux2 = ventana2->tablero->nodo2 ;

      while (aux2 != NULL){
      ventana2->tablero->nodo2  =( nodoDoble *)  ventana2->tablero->nodo2->sig;
      free (aux2);
      aux2 = ventana2->tablero->nodo2 ;
      }
      
    ventana2->tablero->nodo2  = NULL;
      return;
    } else {
      nodoNuevo->ant = (struct nodoDoble *)ventana2->tablero->aux ;
      ventana2->tablero->aux ->sig = (struct nodoDoble *) nodoNuevo;

    printf("Elemento %d agregado en a lista", nodoNuevo->datos.valor);
    }
  }

  ventana2->tablero->aux = nodoNuevo;
}


/*
 *@brief localiza un boton en la tabla
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param widget, variable tipo GtkWidget
 *@param data, variable tipo apuntador
 *@return vacio
*/
void localizarWidget(GtkWidget *widget, gpointer data) {

  tableChild *hijo = (tableChild *)data;

  const gchar *name = gtk_widget_get_name(widget);

  int valor1, valor2;
  int r1,r2,r3,r4,r5,r6,r7,r8,r9,r10;
  //printf ("\nentre a la funcion de localizar widget y busco a widget con etiqueta %s la etiqueta proporcionada es %s ",hijo->nombre, name);
  sscanf(name ,"%d,%d/%d/%d,%d", &r1,&r2,&valor1,&r3,&r4);
  sscanf(hijo->nombre ,"%d,%d/%d/%d,%d", &r1,&r2,&valor2,&r3,&r4);
  
  if ( valor1 == valor2) {
    printf(" encontrado\n");
    hijo->direccion = widget;

    return;
  }

}


/*
 *@brief regresa la direccion de un widget en una tabla
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param table, variable tipo GtkWidget
 *@param widgetBuscado, variable tipo tableChild
 *@return vacio
*/
void obtenerWidget(GtkWidget *table, tableChild *widgetBuscado) {
  gtk_container_foreach(GTK_CONTAINER(GTK_TABLE(table)), localizarWidget, (gpointer)widgetBuscado);
}

/*
 *@brief deshace un movimiento del juego
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param button, variable tipo GtkButton
 *@param data, variable tipo apuntador
 *@return vacio
*/
void deshacerInsercion(GtkButton * button, gpointer data) {

  juegoYMenus * ventana2 = (juegoYMenus * ) data;

  tableChild widgetBuscado;
  GtkWidget * botonNuevo;
  coordenada actuales, originales;

  char nombreBoton[12];
  const char * nombre;
  int y, x, yO, xO, num;

  botonNuevo = gtk_button_new();

  if (ventana2 -> tablero -> aux->ant == NULL) {

  x = ventana2 -> tablero -> aux -> datos.actual.x;
  y = ventana2 -> tablero -> aux -> datos.actual.y;

  xO = ventana2 -> tablero -> aux -> datos.original.x;
  yO = ventana2 -> tablero -> aux -> datos.original.y;

  num = ventana2 -> tablero -> aux -> datos.valor;

  sprintf(widgetBuscado.nombre, "%d,%d/%d/%d,%d", x, y, num, xO, yO);
  gtk_button_set_image(GTK_BUTTON(botonNuevo), ventana2 -> tablero -> imagen[num]);

   printf("\nBuscando widget con nombre %s status ---->", widgetBuscado.nombre);
   obtenerWidget(ventana2 -> tablero -> tabla, & widgetBuscado);

  modificarArray(ventana2 -> tablero -> juegoActual, & actuales, & originales, num);

  sprintf(nombreBoton, "%d,%d/%d/%d,%d", actuales.y, actuales.x, num, originales.y, originales.x);
  printf("\nNUevo widget con nombre %s creado\n", nombreBoton);
    gtk_widget_set_name(botonNuevo, nombreBoton);

  //imprimirMatriz(ventana2 -> tablero -> juegoActual);
 
  gtk_widget_destroy(widgetBuscado.direccion);

  gtk_table_attach_defaults(GTK_TABLE(ventana2 -> tablero -> tabla), botonNuevo, yO, yO + 1, xO, xO + 1);


  g_signal_connect(G_OBJECT(botonNuevo), "clicked", G_CALLBACK(mover), ventana2);


  gtk_widget_show(botonNuevo);

  printf("\n\nboton nuevo creado, con valores de %s\n\n",nombreBoton );

    printf("\nYa no hay movimientos por deshacer \n");
    return;
  }

  g_print("\n\n///////////////////////////////////////////////////////\n\n");
  g_print("\n\n///////////////////////////////////////////////////////\n\n");

  x = ventana2 -> tablero -> aux -> datos.actual.x;
  y = ventana2 -> tablero -> aux -> datos.actual.y;

  xO = ventana2 -> tablero -> aux -> datos.original.x;
  yO = ventana2 -> tablero -> aux -> datos.original.y;

  num = ventana2 -> tablero -> aux -> datos.valor;

  sprintf(widgetBuscado.nombre, "%d,%d/%d/%d,%d", x, y, num, xO, yO);
  gtk_button_set_image(GTK_BUTTON(botonNuevo), ventana2 -> tablero -> imagen[num]);

   printf("\nBuscando widget con nombre %s status ---->", widgetBuscado.nombre);
   obtenerWidget(ventana2 -> tablero -> tabla, & widgetBuscado);

  modificarArray(ventana2 -> tablero -> juegoActual, & actuales, & originales, num);

  sprintf(nombreBoton, "%d,%d/%d/%d,%d", actuales.y, actuales.x, num, originales.y, originales.x);
  printf("\nNUevo widget con nombre %s creado\n", nombreBoton);
    gtk_widget_set_name(botonNuevo, nombreBoton);

  //imprimirMatriz(ventana2 -> tablero -> juegoActual);
 
  gtk_widget_destroy(widgetBuscado.direccion);

  gtk_table_attach_defaults(GTK_TABLE(ventana2 -> tablero -> tabla), botonNuevo, yO, yO + 1, xO, xO + 1);


  g_signal_connect(G_OBJECT(botonNuevo), "clicked", G_CALLBACK(mover), ventana2);


  ventana2 -> tablero -> aux = (nodoDoble * ) ventana2 -> tablero -> aux -> ant;
  ventana2 -> tablero -> nodo2 = (nodoDoble * ) ventana2 -> tablero -> aux -> sig;

  gtk_widget_show(botonNuevo);

  printf("\n\nboton nuevo creado, con valores de %s\n\n",nombreBoton );

g_print("\n\n///////////////////////////////////////////////////////\n\n");
g_print("\n\n///////////////////////////////////////////////////////\n\n");
}


/*
 *@brief rehace un movimiento del juego
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param boton, variable tipo GtkButton
 *@param info, variable tipo apuntador
 *@return vacio
*/
void rehacerInsercion(GtkButton *boton, gpointer info) {

  juegoYMenus *ventana2 = (juegoYMenus*)info;

  tableChild widgetBuscado;
  nodoDoble *generico;
  GtkWidget *botonNuevo;
  coordenada actuales, originales;
  

  char nombreBoton[12];
  const char * nombre;
  int y, x, yO, xO, num;

  botonNuevo = gtk_button_new();

  if (ventana2->tablero->aux->sig == NULL) {
  printf("\nYa no hay movimientos por rehacer \n");
    return;
  }
  generico = ventana2 -> tablero -> aux->sig;

  x = generico->datos.actual.x;
  y =  generico->datos.actual.y;

  xO =  generico->datos.original.x;
  yO = generico->datos.original.y;

  num = generico->datos.valor;

  sprintf(widgetBuscado.nombre, "%d,%d/%d/%d,%d", x, y, num, xO, yO);
  gtk_button_set_image(GTK_BUTTON(botonNuevo), ventana2 -> tablero -> imagen[num]);

  printf("\nBuscando widget con nombre %s status ---->", widgetBuscado.nombre);
  obtenerWidget(ventana2 -> tablero -> tabla, & widgetBuscado);

  modificarArray(ventana2 -> tablero -> juegoActual, & actuales, & originales, num);

  sprintf(nombreBoton, "%d,%d/%d/%d,%d", actuales.x, actuales.y, num, originales.x, originales.y);
  printf("\nNUevo widget con nombre %s creado\n", nombreBoton);
  gtk_widget_set_name(botonNuevo, nombreBoton);

  //imprimirMatriz(ventana2 -> tablero -> juegoActual);
 
  gtk_widget_destroy(widgetBuscado.direccion);

  gtk_table_attach_defaults(GTK_TABLE(ventana2 -> tablero -> tabla), botonNuevo, y, y+1, x, x+1);


  g_signal_connect(G_OBJECT(botonNuevo), "clicked", G_CALLBACK(mover), ventana2);

  ventana2->tablero->aux = ventana2->tablero->aux->sig;
   printf("\nmovimiento de %d rehecho \n",  ventana2->tablero->aux->datos.valor);
  ventana2->tablero->nodo2 = ventana2->tablero->nodo2->sig;


  gtk_widget_show(botonNuevo);
}


/*
 *@brief mueve un boton en la interfaz grafica
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param coordenadasA coordenadas O, variable de tipo coordenadas
 *@param juego, variable tipo JuegoYMenus
 *@numero, variable tipo int
 *@boton, variable tipo GtkWidget
 *@return vacio
*/
void G_mover(coordenada coordenadasA,coordenada coordenadasO, juegoYMenus * juego, int numero, GtkWidget * boton) {

  GtkWidget * botonNuevo;
  botonNuevo = gtk_button_new();
  char nombreBoton[12];

  gtk_button_set_image(GTK_BUTTON(botonNuevo), juego->tablero-> imagen[numero]);
  sprintf(nombreBoton, "%d,%d/%d/%d,%d", coordenadasA.y, coordenadasA.x, numero,coordenadasO.y,coordenadasO.x );
  g_print("boton clickeado %s", nombreBoton);
  gtk_widget_set_name(botonNuevo, nombreBoton);
  gtk_widget_destroy(boton);
  gtk_table_attach_defaults(GTK_TABLE(juego->tablero-> tabla), botonNuevo, coordenadasA.x, coordenadasA.x + 1, coordenadasA.y, coordenadasA.y + 1);
  g_signal_connect(G_OBJECT(botonNuevo), "clicked", G_CALLBACK(mover), juego);
  gtk_widget_show(botonNuevo);

  return;
}

void mostrarGanador() {
    GtkWidget *ventana;
    GtkWidget *label;
    GtkWidget *boton;
    
    gtk_init(NULL, NULL);

    ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ventana), "Ventana de felicitación");
    gtk_window_set_default_size(GTK_WINDOW(ventana), 300, 100);
    
    label = gtk_label_new("Felicidades, estás dentro del top 5!");
    
    boton = gtk_button_new_with_label("Aceptar");
    g_signal_connect(boton, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    
    GtkWidget *contenedor = gtk_vbox_new(TRUE, 5);
    gtk_container_add(GTK_CONTAINER(contenedor), label);
    gtk_container_add(GTK_CONTAINER(contenedor), boton);
    
    gtk_container_add(GTK_CONTAINER(ventana), contenedor);
    
    gtk_widget_show_all(ventana);
    gtk_main();
    
}
int checaGanador(int score)
{
  FILE *fp;
  arbol ganador; 
  int i = 1, j, temp;
  int top[100]; 
  int topgood[4];
  fp = fopen("Ganadores.bin", "rb");
  while(fread(&ganador, sizeof(arbol), 1, fp) != 0){
    top[0] = score;
    top[i] = ganador.puntuacion;
    //top le hacemos bubblesort y nos quedamos con el top 5
    i++;
  }
  fclose(fp);
  for(i=0; i<100; i++){
    for(j=i+1; j<100; j++){
      if(top[j] > top[i]){
        temp = top[i];
        top[i] = top[j];
        top[j] = temp;
      }
    }
  }
  for(i=0; i<5; i++){
    topgood[i] = top[i];
  }
    for(i=0; i<5; i++){
    if (topgood[i] == score){
      return 1;
    }
    else{
      return 0;
    }
    }
}
/*
 *@brief mueve el boton en la interfaz y en el arreglo, ademas de actualizar la tabla
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param boton, variable tipo GtkWidget
 *@param info, variable tipo apuntador
 *@return vacio
*/
void ganaste(int score){
    GtkWidget *ventana;
    GtkWidget *etiqueta;
    GtkWidget *entrada;
    GtkWidget *boton;
    GtkWidget *caja;
    FILE *fp;
    arbol ganador;
    int i;
    GtkWidget *caja_v;
    gchar *nombre;
    // Crear la ventana emergente
    ventana = gtk_dialog_new_with_buttons("Nombre de usuario",
                                          NULL,
                                          GTK_DIALOG_MODAL,
                                          GTK_STOCK_OK,
                                          GTK_RESPONSE_OK,
                                          NULL);

    caja_v = gtk_vbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(ventana)->vbox), caja_v, TRUE, TRUE, 0);

    etiqueta = gtk_label_new("Ingresa tu nombre:");
    gtk_box_pack_start(GTK_BOX(caja_v), etiqueta, TRUE, TRUE, 0);

    entrada = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(caja_v), entrada, TRUE, TRUE, 0);

    gtk_widget_show_all(ventana);
    gtk_dialog_run(GTK_DIALOG(ventana));

    nombre = g_strdup(gtk_entry_get_text(GTK_ENTRY(entrada)));

    gtk_widget_destroy(ventana);

    ganador.puntuacion = score;
    strcpy(ganador.nombre, nombre);
  fp = fopen("Ganadores.bin", "wb");
  fwrite(&ganador, sizeof(arbol), 1, fp);
  fclose(fp);
  i = checaGanador(score);
  if (i == 1){
    mostrarGanador();
  }
}


void mover(GtkWidget * boton, gpointer info) {

  const char * nombreBoton1;
  char nombreBoton[10];
  const char *text;
  int tiempo, horas, minutos, segundos, score, i;

  juegoYMenus *ventana2 = (juegoYMenus * ) info;

  coordenada coordenadas;
  coordenada coordenadasO;

  int verificador, x, y, num,xo,yo;
  char buffer[60] = {           };
  char buffer2[60] = {           };
  nombreBoton1 = gtk_widget_get_name(boton);
  strcpy(nombreBoton, nombreBoton1);
  sscanf(nombreBoton, "%d,%d/%d/%d,%d", &y, &x, & num, &yo, &xo);

  verificador = modificarArray(ventana2->tablero->juegoActual, & coordenadas, &coordenadasO, num);

  if (verificador == 1) {
    GtkWidget *ventanaDeDialogo, *contenido, *descripcion, *botonSi,*botonNo;
    G_mover(coordenadas,coordenadasO, ventana2, num, boton);
    sprintf(nombreBoton, "%d,%d/%d/%d,%d",coordenadas.y,coordenadas.x, num, coordenadasO.y, coordenadasO.x );
    gtk_widget_set_name(boton, nombreBoton);
    g_print("\nestoy e funcion mover y sali con coordenadas %s\n", nombreBoton);
    g_print("\n%s\n",nombreBoton );

    insertarElemento(GTK_BUTTON(boton), ventana2);

    printf("\n%d\n", verificador);
    printf("----------------------------------------\n");
    imprimirMatriz(ventana2->tablero-> juegoActual);
    printf("\n\n");
    imprimirMatriz(ventana2->tablero->solucion);

    if (ventana2->tablero->numeroDeJugadas == 0){
      iniciar_cronometro(NULL, &ventana2->tablero->cronometro);
    }

    ventana2->tablero->numeroDeJugadas ++;
    sprintf(buffer,"Jugadas realizadas\n\n%d", ventana2->tablero->numeroDeJugadas);
    gtk_label_set_text(GTK_LABEL( ventana2->tablero->contadorDeJugadas), buffer);
    gtk_widget_show(ventana2->tablero->contadorDeJugadas);
    if (verificar(ventana2->tablero) == 1){
    pausar_cronometro(NULL,&ventana2->tablero->cronometro);
    minutos = ventana2->tablero->cronometro.minutos * 60;
    horas = ventana2->tablero->cronometro.horas * 3600;
    tiempo = ventana2->tablero->cronometro.segundos+minutos+horas;
    
    score = calcularScore(tiempo, ventana2->tablero->numeroDeJugadas);
    
    sprintf(buffer2, "Felicidades ganaste, tu score fue de: %d\n", score );
    ganaste(score);
    ventanaDeDialogo = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, buffer2, text);
    //g_print ("Agregar nombre de jugador y puntuacion a arbol binario");
      
    gtk_window_set_title(GTK_WINDOW(ventanaDeDialogo ), "Guardado de partida");
    gtk_dialog_run(GTK_DIALOG(ventanaDeDialogo ));
    gtk_widget_destroy(ventanaDeDialogo );
    }
  printf("\n----------------------------------------\n");
  }
}


