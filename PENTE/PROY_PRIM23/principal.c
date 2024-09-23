#include "header.h" 

void esconderVentana(GtkButton *button, gpointer data){

    GtkWidget *ventana = (GtkWidget*)data;

    gtk_widget_hide(ventana);

}
//declaracion de funciones 
int modificarArray(int actual[4][4], coordenada * coordenadas, coordenada *coordenadasO, int dato);
void imprimirMatriz(int matriz[4][4]) ;
void barajarArreglo(int arreglo[], int n) ;
void generarMatriz(int matriz[4][4], int matrizInicial[4][4]);
void crearTabla(matrizDeJuego * juego);
void G_mover(coordenada coordenadasA,coordenada coordenadasO, juegoYMenus * juego, int numero, GtkWidget * boton);
void mover(GtkWidget * boton, gpointer info) ;
void ventanaSiguiente(GtkButton *button, gpointer data);
void funcionSalir(GtkWidget *widget, gpointer info);
void crearTablero(gpointer datos);
void reiniciarJuego(GtkWidget *widget, gpointer info);
void remove_all_widgets(GtkWidget *table);
void AsignarSolucionHorizontal(GtkWidget * boton, gpointer info);
void AsignarSolucionVerical(GtkWidget * boton, gpointer info);
void AsignarSolucionCaracol(GtkWidget * boton, gpointer info);
void rutinaDeGuardado1(GtkButton *button, gpointer info); 
void guardarDatos(GtkButton *button, gpointer info);
void liberarEspacio(GtkButton *button, gpointer data);
void deshacerInsercion(GtkButton *button, gpointer data);
void rehacerInsercion(GtkButton *boton, gpointer info);
void cargarPartida(GtkButton *button, gpointer info);
void funcionPopOut(GtkButton *button, gpointer data);

gint main(gint argc, gchar *argv[])
{
    char etiquetaDeElementoDeBarra[4][20] = {"Ayuda","Opciones de juego", "Herramientas", " Acerca de"};
    char etiquetaDeItemDeMenuElemento0[2][25] = {"Instrucciones generales", "Reglas del juego"};
    char etiquetaDeItemDeMenuElemento1[5][12] = {"Horizontal","Vertical", "Caracol","Deshacer","Rehacer"};
    char etiquetaDeItemDeMenuElemento2[5][12] = {"Nuevo","Guardar","Recuperar","Resolver","Terminar"};
    char etiquetaDeHerramienta[4][10] = {"Deshacer","Rehacer","Nuevo","Resolver"};
    char etiquetaDeItemDeMenuElemento3[20] = {"Desarrolladores"};
    char archivoBonton[50] = {"/home/ic22iph/PROY_PRIM23/botones/button0.png"};
    char archivoIconos[45] = {"/home/ic22iph/PROY_PRIM23/iconos/icono1.png"};
    
    //1-inicializar el ambiente   
    gtk_init(&argc, &argv);

    //2.1- crear Widgets 
    int i=0,x=0,b=0; 
    //ventana de presentacion
    
    juegoYMenus *ventana2 = malloc(sizeof(juegoYMenus));
    presentacion *ventana1 = malloc (sizeof(presentacion));
    generica *acercaDe = malloc (sizeof(generica));
    generica *reglasDeJuego = malloc (sizeof(generica));
    generica *informacion = malloc (sizeof(generica));
  
    if (ventana2 == NULL || ventana1 == NULL || reglasDeJuego  == NULL || acercaDe == NULL || informacion == NULL){
        printf("\nError en la ejecucion, memoria insuficiente\n");
        exit(1);
    }

    ventana1->ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    ventana1->cajaVertical = gtk_vbox_new(FALSE, 5);
    ventana1->titulo = gtk_label_new("\n\tPuzzle\n\n");
    ventana1->imagen[0] =  gtk_image_new_from_file("/home/ic22iph/PROY_PRIM23/imagenes/ventana1/presentacion.jpeg");
    ventana1->descripcion = gtk_label_new("\nProyecto de Programacion aplicada\n\nDesarrolladores:\n");
    ventana1->cajaHorizontal = gtk_hbox_new(FALSE, 5);
    ventana1->etiqueta[0]=  gtk_label_new("\tPedro Segura\t");
    ventana1->etiqueta[1]=  gtk_label_new("\tIvan Perfecto\t");
    ventana1->etiqueta[2]=  gtk_label_new("\tLorenzo Orozco\t");
    ventana1->etiqueta[3]=  gtk_label_new("\tPablo Garcia\t");
    ventana1->imagen[1]= gtk_image_new_from_file("/home/ic22iph/PROY_PRIM23/imagenes/ventana1/perfil1.jpeg");
    ventana1->imagen[2]= gtk_image_new_from_file("/home/ic22iph/PROY_PRIM23/imagenes/ventana1/perfil2.jpeg");
    ventana1->imagen[3]= gtk_image_new_from_file("/home/ic22iph/PROY_PRIM23/imagenes/ventana1/perfil3.jpeg");
    ventana1->imagen[4]= gtk_image_new_from_file("/home/ic22iph/PROY_PRIM23/imagenes/ventana1/perfil4.jpeg");
    ventana1->espaciador[0] = gtk_hseparator_new();
    ventana1->espaciador[1] = gtk_hseparator_new();
    ventana1->espaciador[2] = gtk_hseparator_new();
    ventana1->espaciador[3] = gtk_hseparator_new();
    ventana1->tablaDeIntegrantes = gtk_table_new(2, 4, FALSE);
    ventana1->boton = gtk_button_new_with_label("Continuar >>");


    //ventana de juego
    
    ventana2->ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    ventana2->cajaVerticalPrincipal = gtk_vbox_new(FALSE, 5);
    ventana2->barraDeMenu = gtk_menu_bar_new();
    ventana2->barraDeHerramientas = gtk_toolbar_new();
    ventana2->cajaVerticalDerecha = gtk_vbox_new(FALSE, 5);
    ventana2->cajaVerticalIzquierda = gtk_vbox_new(FALSE, 5);
    ventana2->cajaHoiontal = gtk_hbox_new(FALSE, 5);
    ventana2->espaciador[0]= gtk_hseparator_new();
    ventana2->espaciador[1]= gtk_hseparator_new();
    ventana2->espaciador[2]= gtk_hseparator_new();
    ventana2->espaciador[3]= gtk_hseparator_new();
    ventana2->tipoDeJuego  = gtk_label_new("Tipo de juego \n-- horizontal-- ");
    ventana2->itemDeMenuElemento3 = gtk_menu_item_new_with_label("Autores");


    //Se crean los items de menu
    for(i=0;i <= 3; i++){ 
        ventana2->elementoDeBarra[i] = gtk_menu_item_new_with_label(etiquetaDeElementoDeBarra[i]);  
        ventana2->menuDeElemento[i] = gtk_menu_new();
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(ventana2->elementoDeBarra[i]), ventana2->menuDeElemento[i]);
        gtk_menu_shell_append(GTK_MENU_SHELL(ventana2->barraDeMenu),ventana2->elementoDeBarra[i]);
    }

    for(i=0;i <= 1; i++){ //primer elemento de la barra
        ventana2->itemDeMenuElemento0[i] = gtk_menu_item_new_with_label(etiquetaDeItemDeMenuElemento0[i]);
        gtk_menu_shell_append(GTK_MENU_SHELL(ventana2->menuDeElemento[0]),ventana2->itemDeMenuElemento0[i]);
    }

    for(i=0;i <= 4; i++){ //items del primer y segundo submenu
        ventana2->itemDeMenuElemento1[i] = gtk_menu_item_new_with_label(etiquetaDeItemDeMenuElemento1[i]);
        ventana2->itemDeMenuElemento2[i] = gtk_menu_item_new_with_label(etiquetaDeItemDeMenuElemento2[i]);
        gtk_menu_shell_append(GTK_MENU_SHELL(ventana2->menuDeElemento[1]),ventana2->itemDeMenuElemento1[i]);
        gtk_menu_shell_append(GTK_MENU_SHELL(ventana2->menuDeElemento[2]),ventana2->itemDeMenuElemento2[i]);
    }

    for (int i = 0; i < 4; i++) { //creacion de botones de tablero
        // Crear botón y agregar imagen
        ventana2->herramienta[i] = gtk_button_new();
        ventana2->iconoDeHerramienta[i] = gtk_image_new_from_file(archivoIconos);
        gtk_button_set_image(GTK_BUTTON(ventana2->herramienta[i]), GTK_WIDGET(ventana2->iconoDeHerramienta[i]));
    
        // Agregar botón al toolbar
        gtk_container_add(GTK_CONTAINER(ventana2->barraDeHerramientas), ventana2->herramienta[i]);

        // Incrementar archivoIconos para apuntar al siguiente archivo de icono
        archivoIconos[38]++;
    }

    //ventana reglas de juego
    reglasDeJuego->ventana = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    reglasDeJuego->cajaVertical = gtk_vbox_new (FALSE, 5);
    reglasDeJuego->contenido [0] = gtk_label_new ("\n\t\t\tReglas del juego:\t\n\t1-Objetivo del juego: El objetivo del juego es mover las fichas numeradas en un tablero de 4x4 para que estén ordenadas en orden según\t\n\tsea el tipo de juego que el usuario decida, con una ficha vacía.\t\n\n\t2-Cómo jugar: Para mover las fichas, el jugador debe hacer clic en una ficha adyacente a la ficha vacía. \t\n\tLa ficha seleccionada se moverá a la posición vacía y la ficha vacía ocupará la posición anterior de la ficha seleccionada. \t\n\tEl jugador debe repetir este proceso hasta que todas las fichas están ordenadas.\t\n\n\tEl juego cuentas con distintos modos, los cuales son: ");
    reglasDeJuego->contenido [1] = gtk_label_new ("Horizontal");
    reglasDeJuego->contenido [2] = gtk_label_new ("Vertical");
    reglasDeJuego->contenido [3] = gtk_label_new ("Caracol");
    reglasDeJuego->boton = gtk_button_new_with_label ("OK");
    reglasDeJuego->imagen [0] = gtk_image_new_from_file ("/home/ic22iph/PROY_PRIM23/imagenes/soluciones/horizontal.png");
    reglasDeJuego->imagen [1] = gtk_image_new_from_file ("/home/ic22iph/PROY_PRIM23/imagenes/soluciones/vertical.png");
    reglasDeJuego->imagen [2] = gtk_image_new_from_file ("/home/ic22iph/PROY_PRIM23/imagenes/soluciones/caracol.png");
    reglasDeJuego->tabla = gtk_table_new (2,3, FALSE);

    //ventana de acerca de    
    acercaDe->ventana = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    acercaDe->cajaVertical = gtk_vbox_new (FALSE, 5);
    acercaDe->contenido [0] = gtk_label_new ("Creadores:\n*Lorenzo Orozo\n*Pedro Segura\n*Ivan Perfecto\n*Profesor Titular: Andres Tortolero Baena\n");
    acercaDe->boton = gtk_button_new_with_label ("OK");

    //ventana instrucciones generales
    informacion->ventana = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    informacion->cajaVertical = gtk_vbox_new (FALSE, 5);
    informacion->contenido [0] = gtk_label_new ("\n\tLa problemática del sistema consiste en realizar un juego en C utilizando GTK +, el cual consiste en un puzzle de números llamado “puzzle del 15”\t\n\tEl programa esta desarrollado en c implementando GTK 2.0 para la materia de Programacion Aplicada\t\n\tpara el semestre primavera 2023 impartida por el profesor Andres Tortolero Baena\t\n\n\tLas instrucciones del juego las puedes encontrar en este mismo menu en la opcion 'Reglas de juego'\t\n\tPara correr el programa, desde la terminal se debe teclear './programa.out' y se desplegara la pantalla de bienvenida\t\n\tLa informacion sobre el funcionamiento del sistema la puedes encontrar en el manual de usuario\t");
    informacion->boton = gtk_button_new_with_label ("OK");

    //2.2-Fijar atributos
        //ventana 1
    gtk_window_set_title(GTK_WINDOW(ventana1->ventana), "Proyecto final");

        //ventana 2
    gtk_window_set_title(GTK_WINDOW(ventana2->ventana), "Juego principal");

        //ventana reglas de juego
    gtk_window_set_title (GTK_WINDOW(reglasDeJuego->ventana), "Reglas de juego");

        //ventana acerca De
    gtk_window_set_title (GTK_WINDOW(acercaDe->ventana), "Creadores");

        //ventana instrucciones generales
    gtk_window_set_title (GTK_WINDOW(informacion->ventana), "Informacion General");

    //3-Registrar llamadas a funciones
        //ventana 1
    g_signal_connect(G_OBJECT(ventana1->boton), "clicked", G_CALLBACK(ventanaSiguiente), ventana1->ventana);
    

        //ventana2
    g_signal_connect(G_OBJECT(ventana2->ventana), "destroy", G_CALLBACK(funcionSalir),NULL);
    
    g_signal_connect(G_OBJECT(ventana2->itemDeMenuElemento2[0]), "activate", G_CALLBACK(rutinaDeGuardado1),ventana2);
    g_signal_connect(G_OBJECT(ventana2->itemDeMenuElemento2[1]), "activate", G_CALLBACK(guardarDatos),ventana2);

    g_signal_connect(G_OBJECT(ventana2->itemDeMenuElemento1[0]), "activate", G_CALLBACK(AsignarSolucionHorizontal),ventana2);
    g_signal_connect(G_OBJECT(ventana2->itemDeMenuElemento1[1]), "activate", G_CALLBACK(AsignarSolucionVerical),ventana2);
    g_signal_connect(G_OBJECT(ventana2->itemDeMenuElemento1[2]), "activate", G_CALLBACK(AsignarSolucionCaracol),ventana2);

    g_signal_connect(G_OBJECT(ventana2->itemDeMenuElemento2[2]), "activate", G_CALLBACK(liberarEspacio),ventana2);

    g_signal_connect(G_OBJECT(ventana2->itemDeMenuElemento1[3] ), "activate", G_CALLBACK(deshacerInsercion),ventana2);
    g_signal_connect(G_OBJECT(ventana2->itemDeMenuElemento1[4] ), "activate", G_CALLBACK(rehacerInsercion),ventana2);

    g_signal_connect(G_OBJECT(ventana2->itemDeMenuElemento2[2] ), "activate", G_CALLBACK(cargarPartida),ventana2);

    g_signal_connect(G_OBJECT(ventana2->herramienta[0]), "clicked", G_CALLBACK(deshacerInsercion), ventana2);
    g_signal_connect(G_OBJECT(ventana2->herramienta[1]), "clicked", G_CALLBACK(rehacerInsercion), ventana2);

    g_signal_connect(G_OBJECT(ventana2->herramienta[2]), "clicked", G_CALLBACK(rutinaDeGuardado1),ventana2);
    

        //ventana reglas de Juego
    g_signal_connect (ventana2->itemDeMenuElemento0 [1], "activate", G_CALLBACK(funcionPopOut), ventana1->ventana);
    g_object_set_data (G_OBJECT (ventana2->itemDeMenuElemento0[1]), "popOut", reglasDeJuego->ventana);
    g_signal_connect(G_OBJECT(reglasDeJuego->boton), "clicked", G_CALLBACK(esconderVentana),reglasDeJuego->ventana);
    g_signal_connect(G_OBJECT(acercaDe->boton), "clicked", G_CALLBACK(esconderVentana),acercaDe->ventana);
    g_signal_connect(G_OBJECT(informacion->boton), "clicked", G_CALLBACK(esconderVentana),informacion->ventana);


        //ventana acerca de
    g_signal_connect(ventana2->itemDeMenuElemento3, "activate", G_CALLBACK(funcionPopOut),ventana1->ventana);
    g_object_set_data(G_OBJECT(ventana2->itemDeMenuElemento3), "popOut", acercaDe->ventana);

        //ventana informacion general
    g_signal_connect (ventana2->itemDeMenuElemento0 [0], "activate", G_CALLBACK(funcionPopOut), ventana1->ventana);
    g_object_set_data (G_OBJECT (ventana2->itemDeMenuElemento0[0]), "popOut", informacion->ventana);


    //4-Definir la jerarquia
        //ventana 1
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaVertical),ventana1->titulo);
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaVertical),ventana1->espaciador[0]);
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaVertical),ventana1->imagen[0]);
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaVertical),ventana1->espaciador[1]);
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaVertical),ventana1->descripcion);
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaVertical),ventana1->espaciador[2]);
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaVertical),ventana1->cajaHorizontal);
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaHorizontal),ventana1->tablaDeIntegrantes);
    gtk_table_attach_defaults(GTK_TABLE(ventana1->tablaDeIntegrantes), ventana1->imagen[1], 0, 1, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(ventana1->tablaDeIntegrantes), ventana1->imagen[2], 2, 3, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(ventana1->tablaDeIntegrantes), ventana1->imagen[3], 4, 5, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(ventana1->tablaDeIntegrantes), ventana1->imagen[4], 6, 7, 0, 1);

    gtk_table_attach_defaults(GTK_TABLE(ventana1->tablaDeIntegrantes), ventana1->etiqueta[0], 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(ventana1->tablaDeIntegrantes), ventana1->etiqueta[1], 2, 3, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(ventana1->tablaDeIntegrantes), ventana1->etiqueta[2], 4, 5, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(ventana1->tablaDeIntegrantes), ventana1->etiqueta[3], 6, 7, 1, 2);
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaVertical),ventana1->espaciador[3]);
    gtk_box_pack_start_defaults(GTK_BOX(ventana1->cajaVertical),ventana1->boton);
    gtk_container_add(GTK_CONTAINER(ventana1->ventana), ventana1->cajaVertical);

        //ventana2
    gtk_menu_shell_append(GTK_MENU_SHELL(ventana2->menuDeElemento[3]),ventana2->itemDeMenuElemento3);

    gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalPrincipal),ventana2->barraDeMenu);
    gtk_container_add(GTK_CONTAINER(ventana2->ventana), ventana2->cajaVerticalPrincipal);
   
    // almacenar una referencia a la ventana 2 en el botón para poder acceder a ella desde la función on_button_clicked
    g_object_set_data(G_OBJECT(ventana1->boton), "ventana2", ventana2->ventana);


    gtk_box_pack_start_defaults(GTK_BOX(ventana2->cajaVerticalPrincipal), ventana2->barraDeHerramientas);       
    gtk_box_pack_start_defaults( GTK_BOX(ventana2->cajaVerticalPrincipal), ventana2->cajaHoiontal);
    gtk_box_pack_start_defaults( GTK_BOX(ventana2->cajaHoiontal), ventana2->cajaVerticalIzquierda);
    gtk_box_pack_start_defaults( GTK_BOX(ventana2->cajaHoiontal), ventana2->espaciador[1]);
    gtk_box_pack_start_defaults( GTK_BOX(ventana2->cajaHoiontal), ventana2->cajaVerticalDerecha);
    
    gtk_container_set_border_width(GTK_CONTAINER(ventana2->cajaVerticalDerecha), 20);

     //gtk_box_pack_start( GTK_BOX(ventana2->cajaVerticalDerecha), ventana2->tipoDeJuego,FALSE ,FALSE ,0);
    crearTablero(ventana2);

        //ventana reglas de juego
    gtk_table_attach_defaults (GTK_TABLE(reglasDeJuego->tabla), reglasDeJuego->contenido[1], 0,1,0,1);
    gtk_table_attach_defaults (GTK_TABLE(reglasDeJuego->tabla), reglasDeJuego->contenido[2], 1,2,0,1);
    gtk_table_attach_defaults (GTK_TABLE(reglasDeJuego->tabla), reglasDeJuego->contenido[3], 2,3,0,1);
    gtk_table_attach_defaults (GTK_TABLE(reglasDeJuego->tabla), reglasDeJuego->imagen[0], 0,1,1,2);
    gtk_table_attach_defaults (GTK_TABLE(reglasDeJuego->tabla), reglasDeJuego->imagen[1], 1,2,1,2);
    gtk_table_attach_defaults (GTK_TABLE(reglasDeJuego->tabla), reglasDeJuego->imagen[2], 2,3,1,2);

    gtk_box_pack_start_defaults (GTK_BOX(reglasDeJuego->cajaVertical), reglasDeJuego->contenido [0]);
    gtk_box_pack_start_defaults (GTK_BOX(reglasDeJuego->cajaVertical), reglasDeJuego->tabla);
    gtk_box_pack_start_defaults (GTK_BOX(reglasDeJuego->cajaVertical), reglasDeJuego->boton);

    gtk_container_add (GTK_CONTAINER(reglasDeJuego->ventana), reglasDeJuego->cajaVertical);


    //ventana acerca de
    gtk_box_pack_start_defaults (GTK_BOX(acercaDe->cajaVertical), acercaDe->contenido [0]);
    gtk_box_pack_start_defaults (GTK_BOX(acercaDe->cajaVertical), acercaDe->boton); 

    gtk_container_add (GTK_CONTAINER(acercaDe->ventana), acercaDe->cajaVertical);
    
    //ventana informacion general
    gtk_box_pack_start_defaults (GTK_BOX(informacion->cajaVertical), informacion->contenido[0]);
    gtk_box_pack_start_defaults (GTK_BOX(informacion->cajaVertical), informacion->boton);

    gtk_container_add (GTK_CONTAINER(informacion->ventana), informacion->cajaVertical);

    //5-Mostrar widgets
    gtk_widget_show_all(ventana1->ventana);


    gtk_main(); 
 
    return 0;
}   