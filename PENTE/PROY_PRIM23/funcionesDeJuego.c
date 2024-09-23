#include "header.h"
/*
 *@brief 
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
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
//void rehacerInsercion(nodoDoble **inicio, nodoDoble **aux, nodoDoble **nodo2);
                


/*
void recorrerListaOriginal(nodoDoble *inicio) {

  printf("\n");
  while (inicio != NULL) {
    printf("%d, ", inicio->valor);
    inicio = inicio->sig;
  }
  printf("\n");
}

void recorrerListaParcial(nodoDoble *inicio, nodoDoble *aux) {

  printf("\n");

  while (inicio != aux) {
    printf("%d, ", inicio->valor);
    inicio = inicio->sig;
  }

  printf("\n");
}

*/

/*
 *@brief libera el espacio de la lista doble
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param button, variable tipo GtkButton
 *@param data, variable tipo apuntador
 *@return vacio
*/
void liberarEspacio(GtkButton *button, gpointer data) {
  juegoYMenus *ventana2 = (juegoYMenus*)data;

  nodoDoble *aux,*nodo;
  nodo= ventana2->tablero->inicio;
  int i=1;

  aux = nodo;

  while (aux != NULL) {
    nodo = (nodoDoble *)nodo->sig;
    printf("\n(%d)-> Valor %d, coordenada original (%d,%d),  coordenanada actual (%d,%d)\n", i, aux->datos.valor, aux->datos.original.x,aux->datos.original.y, aux->datos.actual.x, aux->datos.actual.y);
    free(aux);
    aux = nodo;
    i++;
  }
}


/*
 *@brief calcula el puntaje total al ganar el juego
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param tiempo, variable tipo entero
 *@param jugadas, variable tipo entero
 *@return vacio
*/
int calcularScore(int tiempo, int jugadas){

  int score;
  
  score = ((1000/tiempo) + (1000/jugadas) * 200);

  return score;
}


/*
 *@brief detecta la posicion del 0 y si esta en un renglon par
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param a, arreglo doble tipo entero
 *@return vacio
*/
int ceroPar(int a[4][4])
{
    //se define row que es el renglón más abajo pues se checa desde el renglón inferior
    int i,j, row = 3;
    for(i=0;i < 4;i++)
	{
        for(j=0;j < 4;j++)
        {
            if(a[row][j] == 0)
            {
                return i+1;
            }
        }
            row = row-1;    
	}
}


/*
 *@brief revisa cada posicicion del arreglo y los numeros mayores previos a este
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param a, arreglo doble tipo entero
 *@return vacio
*/
int inversiones(int a[4][4]) {
    int inversiones = 0;
    int puzzleUnaD[16];
    int k = 0;
    
    // Convertir la matriz en un arreglo de una dimensión
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            puzzleUnaD[k] = a[i][j];
            k++;
        }
    }
    
    // Contar el número de inversiones en el arreglo
    for (int i = 0; i < 15; i++) {
        for (int j = i+1; j < 16; j++) {
            if (puzzleUnaD[i] > puzzleUnaD[j] && puzzleUnaD[j] != 0) {
                inversiones++;
            }
        }
    }
    
    return inversiones;
}


/*
 *@brief revisa si la matriz generada aleatoriamente es resolvible
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param a, arreglo doble tipo entero
 *@return vacio
*/
int checaResolvible(int a[4][4])
{
    int par, inv;
    par = ceroPar(a);
    inv = inversiones(a);
    if (par%2 == 0 && inv%2 == 1 || par%2 == 1 && inv%2 == 0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*
 *@brief devuelve las coordenadas a las que se puede hacer un movimiento
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param actual, arreglo doble tipo entero
 *@param coordenadas0 coordenadas, variable tipo coordena
 *@return vacio
*/
//devuelve las coordenadas originales (anteriores) del boton y las corndenadas actuales del boton en formato de array (y,x)
int modificarArray(int actual[4][4], coordenada * coordenadas, coordenada *coordenadasO, int dato) {

  int temporal;
  int i, x;

  for (x = 0; x < 4; x++) {
    for (i = 0; i < 4; i++) {

      if (dato == actual[x][i]) {

        if (i == 0 && x == 0) {

          if (actual[x][i + 1] == 0) {
            coordenadas -> x = i + 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i + 1] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x + 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x + 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x + 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }
          
        } else if (i == 3 && x == 0) {

          if (actual[x][i - 1] == 0) {
            coordenadas -> x = i - 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i - 1] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x + 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x + 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x + 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }
          
        } else if (i == 0 && x == 3) {

          if (actual[x][i + 1] == 0) {
            coordenadas -> x = i + 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i + 1] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x - 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x - 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x - 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }
        } else if (i == 3 && x == 3) {

          if (actual[x][i - 1] == 0) {
            coordenadas -> x = i - 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i - 1] = dato;
            actual[x][i] = 0;
            return 1;
          }
          else if (actual[x - 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x - 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x - 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }
        } else if ((i == 0) && (x == 1 || x == 2)) {

          if (actual[x][i + 1] == 0) {
            coordenadas -> x = i + 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i + 1] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x - 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x - 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x - 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x + 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x + 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x + 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }

        } else if ((i == 3) && (x == 1 || x == 2)) {

          if (actual[x][i - 1] == 0) {
            coordenadas -> x = i - 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i - 1] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x - 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x - 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x - 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x + 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x + 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x + 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }

        } else if ((x == 0) && (i == 1 || i == 2)) {

          if (actual[x][i - 1] == 0) {
            coordenadas -> x = i - 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i - 1] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x][i + 1] == 0) {
            coordenadas -> x = i + 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i + 1] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x + 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x + 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x + 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }

        } else if ((x == 3) && (i == 1 || i == 2)) {

          if (actual[x][i - 1] == 0) {
            coordenadas -> x = i - 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i - 1] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x][i + 1] == 0) {
            coordenadas -> x = i + 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i + 1] = dato;
            actual[x][i] = 0;
            return 1;
          }

          else if (actual[x - 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x - 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x - 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }
        } else {

          if (actual[x][i - 1] == 0) {
            coordenadas -> x = i - 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i - 1] = dato;
            actual[x][i] = 0;
            return 1;
          } else if (actual[x][i + 1] == 0) {
            coordenadas -> x = i + 1;
            coordenadas -> y = x;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x][i + 1] = dato;
            actual[x][i] = 0;
            return 1;
          } else if (actual[x - 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x - 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x - 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          } else if (actual[x + 1][i] == 0) {
            coordenadas -> x = i;
            coordenadas -> y = x + 1;
            coordenadasO->x = i;
            coordenadasO->y = x;
            actual[x + 1][i] = dato;
            actual[x][i] = 0;
            return 1;
          }
        }
      }
    }
  }
  return 0;
} 


/*
 *@brief imprime la matriz de juego en terminal
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param matriz, arreglo doble tipo entero
 *@return vacio
*/
void imprimirMatriz(int matriz[4][4]) {

  int i, x;

  for (x = 0; x < 4; x++) {
    for (i = 0; i < 4; i++) {
      printf("%d  ", matriz[x][i]);
    }
    printf("\n");
  }

}


/*
 *@brief genera una matriz con numeros aleatorios del 0 al 15
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param arreglo, arreglo tipo entero
 *@param n, variable tipo entero
 *@return vacio
*/
void barajarArreglo(int arreglo[], int n) {
  int i, j, tmp;

  for (i = n - 1; i > 0; i--) {
    j = rand() % (i + 1);
    tmp = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = tmp;
  }
}


/*
 *@brief genera la matriz 
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param matriz matrizInicial, arreglo doble tipo entero
 *@return vacio
*/
void generarMatriz(int matriz[4][4], int matrizInicial[4][4]) {
  int i, j, k = 0;
  int numeros[16];

    // Llena el arreglo con los números del 0 al 15
  for (i = 0; i < 16; i++) {
    numeros[i] = i;
  }

    	// Baraja el arreglo de manera aleatoria
  srand(time(NULL)); // Inicializa la semilla del generador de números aleatorios
  barajarArreglo(numeros, 16);
  
        for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      matriz[i][j] = numeros[k];
      k++;
    }
  }
                
     while((checaResolvible(matriz) == 0)){

        barajarArreglo(numeros, 16);
        k=0;
  
        for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      matriz[i][j] = numeros[k];
      matrizInicial[i][j] = numeros[k];
      k++;
    }

     }
     }
  

}


/*
 *@brief verifica si el jugador gano, comparando el arreglo en cada movimiento
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param juego, variable tipo matrizDeJuego
 *@return entero
*/
int verificar(matrizDeJuego *juego){

  int i,j;

  for (i=0; i<4; i++){
    for(j=0; j<4; j++){

       if ( juego->solucion[i][j] != juego->juegoActual[i][j]){
        return 0;
       }

    }
  
  }

  return 1;
}


/*
 *@brief crea una tabla grafica mediante un arreglo bidimensional
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param juego, variable tipo matrizDeJuego
 *@return vacio
*/
void crearTabla(matrizDeJuego * juego) {

  int i, x, y, z, reflejo;
  char nombreBoton[12];

  juego -> tabla = gtk_table_new(4, 4, TRUE);
  strcpy(juego -> archivoBonton, "/home/ic22iph/PROY_PRIM23/botones/button0.png");

  for (i = 0; i < 16; i++) {

    juego -> boton[i] = gtk_button_new();
    juego -> imagen[i] = gtk_image_new_from_file(juego -> archivoBonton);
    gtk_button_set_image(GTK_BUTTON(juego -> boton[i]), juego -> imagen[i]);
    juego -> archivoBonton[40]++;

  }
  //imprimirMatriz(juego->juegoActual);

 //printf ("\nDespues de la asignacion\n");
  for (x = 0; x < 4; x++) {

    for (y = 0; y < 4; y++) {

      reflejo = juego -> juegoActual[x][y];
      printf ("reflejo de: (%d)(%d) : %d \n", x, y, reflejo); 

      if (reflejo != 0) {
        sprintf(nombreBoton, "%d,%d/%d/", x, y, reflejo);
        gtk_widget_set_name(juego -> boton[reflejo], nombreBoton);
        gtk_table_attach_defaults(GTK_TABLE(juego -> tabla), juego -> boton[reflejo], y, y + 1, x, x + 1);
      }
    }
  }
  //imprimirMatriz(juego->juegoActual);
}



/*
 *@brief permite abrir otra ventana
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param button, variable tipo GtkButton
 *@param data, variable tipo puntero
 *@return vacio
*/
void ventanaSiguiente(GtkButton *button, gpointer data)
{
    GtkWidget *window1 = GTK_WIDGET(data); // obtener la ventana 1
    GtkWidget *window2 = GTK_WIDGET(g_object_get_data(G_OBJECT(button), "ventana2")); // obtener la ventana 2
    gtk_widget_destroy(window1); // ocultar ventana 1
    gtk_widget_show_all(window2); // mostrar ventana 2
  
}


/*
 *@brief permite salir del programa
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param widget, variable tipo GtkWidget
 *@param info, variable tipo puntero
 *@return vacio
*/
void funcionSalir(GtkWidget *widget, gpointer info)
{
  gtk_main_quit();
}


/*
 *@brief regresa un FALSE para que no permita cerrar la ventana
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param widget, variable tipo GtkWidget
 *@param event, variable tipo GdkEvent
 *@param info, variable tipo puntero
 *@return gboolean
*/
gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer info)
{
  return FALSE;
}


/*
 *@brief crea el tablero de juego
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param datos, variable tipo puntero
 *@return vacio
*/
void crearTablero(gpointer datos)
{
  int i;

  juegoYMenus *ventana2 = (juegoYMenus * ) datos;

  matrizDeJuego *juegoNuevo;

 juegoNuevo = malloc(sizeof(matrizDeJuego));
  
 generarMatriz(juegoNuevo->juegoActual, juegoNuevo->juegoInicial);
 crearTabla(juegoNuevo);  
    
    for (i = 0; i < 16; i++) {
   g_signal_connect(G_OBJECT(juegoNuevo->boton[i]), "clicked", G_CALLBACK(mover),ventana2);
  }

  asignarSolucion(juegoNuevo,'h');
  strcpy(juegoNuevo->tipoDeJuego, "caracol");

  juegoNuevo->numeroDeJugadas = 0;

  juegoNuevo->cronometro.segundos = 0;
  juegoNuevo->cronometro.minutos = 0;
  juegoNuevo->cronometro.horas = 0;

  juegoNuevo->nodo2= NULL;
  juegoNuevo->inicio = NULL;
  //juegoNuevo->aux->ant= NULL;

  juegoNuevo->contadorDeJugadas = gtk_label_new("Jugadas realizadas\n\n0");
  juegoNuevo->cronometro.etiqueta = gtk_label_new( "00:00:00");

   gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),juegoNuevo->cronometro.etiqueta);
   gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),juegoNuevo->contadorDeJugadas);
   gtk_label_set_label(GTK_LABEL(ventana2->tipoDeJuego), "Tipo de juego \n-- horizontal-- ");
   
  ventana2->tablero = juegoNuevo;
  
  gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalIzquierda),ventana2->tablero->tabla);
  gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),ventana2->tipoDeJuego);
  gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),ventana2->tablero->cronometro.etiqueta);
  gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalDerecha),ventana2->tablero->contadorDeJugadas);
  gtk_widget_show_all(ventana2->cajaVerticalDerecha);
}


/*
 *@brief borra un boton de la tabla
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param table, variable tipo GtkWidget
 *@return vacio
*/
void remove_all_widgets(GtkWidget *table)
{
    GList *children, *iter;
    children = gtk_container_get_children(GTK_CONTAINER(table));
    for(iter = children; iter != NULL; iter = g_list_next(iter))
    {
        gtk_container_remove(GTK_CONTAINER(table), GTK_WIDGET(iter->data));
    }
    g_list_free(children);
}



/*
 *@brief reinicia el tablero de juego
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param widget, variable tipo GtkWidget
 *@return vacio
*/
void reiniciarJuego(GtkWidget *widget, gpointer info)
{

  juegoYMenus *ventana2 = (juegoYMenus* ) info;

  reiniciar_cronometro(NULL, &ventana2->tablero->cronometro);
  printf("- Acabas de entrar a la funcion de reiniciar juego ");
  printf("- %d - ", ventana2->tablero->juegoActual[1][1]);
  gtk_widget_destroy(ventana2->tablero->tabla);
  gtk_widget_destroy(ventana2->tablero->contadorDeJugadas);
  gtk_widget_destroy(ventana2->tablero->cronometro.etiqueta);
  crearTablero(ventana2);
  gtk_widget_show_all(ventana2->tablero->tabla);
  g_print(" - click en el boton de reinicio - " );

} 

/*
 *@brief abre una ventana emergente
 *@author Ivan Perfecto, Pedro Segura, Lorenzo Oroco, Pablo Garcia
 *@param button, variable tipo GtkButton
 *@param data, variable tipo puntero
 *@return vacio
*/
void funcionPopOut(GtkButton *button, gpointer data)
{
    GtkWidget *window1 = GTK_WIDGET(data); // obtener la ventana 1
    GtkWidget *window2 = GTK_WIDGET(g_object_get_data(G_OBJECT(button), "popOut")); // obtener la ventana 2
    gtk_widget_show_all(window2); // mostrar ventana 2
}