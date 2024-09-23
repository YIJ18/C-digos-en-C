#include<gtk-2.0/gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct def_coordenada
{
    int coordenada_fila;
    int coordenada_columna;
    struct def_coordenada *sig, *ant;
} coor;

typedef struct def_jugador
{
    char nombre[50];
    double tiempo;
    coor *juego;
    struct def_jugador *sig, *ant;
} info;

typedef struct{

int matrizInicial [20][20];
char tiempo [10];
int numeroDeJugadas;
char tipoDeJuego;
int segundos;
int minutos;
int horas;
int cargado;

}juegoBase;

typedef struct {
    int segundos;
    int minutos;
    int horas;
    char display[9];
    GtkWidget *etiqueta;
    gint id;
} tiempo;

typedef struct {
  
  char archivoBonton[50];
  GtkWidget *boton[16];
  GtkWidget *tabla;
  int juegoActual[20][20];
  int juegoInicial[20][20];
  int numeroDeJugadas;
  int score;
  GtkWidget *contadorDeJugadas; 
  tiempo cronometro;
  nodoDoble *inicio;
  nodoDoble *aux;
  nodoDoble *nodo2;

}
matrizDeJuego;

typedef struct {
    GtkWidget *display;
    gint seconds;
    guint timer_id;
} temp;

typedef struct {

    GtkWidget *ventana;
    GtkWidget *cajaVerticalPrincipal; 
    GtkWidget *barraDeMenu;
    GtkWidget *cajaHoiontal;
    GtkWidget *cajaVerticalDerecha;
    GtkWidget *cajaVerticalIzquierda;
    GtkWidget *botonInicio;
    GtkWidget *espaciador[4];

    GtkWidget *elementoDeBarra[4];
    GtkWidget *menuDeElemento[4];
    GtkWidget *itemDeMenuElemento0[2];
    GtkWidget *itemDeMenuElemento1[5];
    GtkWidget *itemDeMenuElemento2[5];
    GtkWidget *itemDeMenuElemento3;
    GtkWidget *timmerDisplay;
    GtkWidget *tipoDeJuego;
   
    matrizDeJuego *tablero;

    GtkWidget *barraDeHerramientas;
    GtkWidget *herramienta[5];
    GtkWidget *iconoDeHerramienta[5]; 

}juego_menu;

typedef struct {

    GtkWidget *ventana;
    GtkWidget *cajaVertical;
    GtkWidget *cajaHorizontal;
    GtkWidget *titulo;
    GtkWidget *descripcion;
    GtkWidget *imagen[5];
    GtkWidget *espaciador[4];
    GtkWidget *tablaDeIntegrantes;
    GtkWidget *etiqueta[4];
    GtkWidget *boton;

}presentacion;


typedef struct {

    GtkWidget *ventana;
    GtkWidget *cajaVertical;
    GtkWidget *tabla;
    GtkWidget *titulo;
    GtkWidget *contenido [5];
    GtkWidget *imagen [4];
    GtkWidget *boton;

}generica;


typedef struct{

char nombre[12];
GtkWidget *direccion;

}tableChild;

typedef struct nodo {
  char nombre[20];
  int puntuacion;
} arbol;