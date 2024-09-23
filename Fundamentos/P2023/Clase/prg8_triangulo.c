/*
  @file: prg8_triangulo.c
  @brief: En este archivo se genera la primera especificación de requerimientos básica del semestre. El problema a resolver es calcular el área de un triángulo rectángulo.
  @details: Revisar las secciones de la especificación de requerimientos que se va a desrrollar a continuación. Son 8 secciones las que se deben de considerar: título, descripción general, comportamiento detallado, salidas, entradas, procesos, alcances y limitaciones, y diseño de pantalla.

  Se agrego el diseño arquitectonico al igual que el diseño detallado que es el pseudocódigo


  @author: Iris Ylit Jasso Cortes
  date: 7-febrero-2023



******************************
ESPECIFICACIÓN DE REQUERIMIENTOS



Título: Área de un triángulo rectángulo



Descripción general:


Se desea un programa que calcule el área de un triángulo rectángulo. El programa solicita la base (b) y la altura (h) del triángulo rectángulo y posteriormente, el programa despliega el resultado del área en la pantalla.


El programa será utilizado para las clases de geometría de secundaria. Es un requerimiento que el área de un triánulo se calcule con la fórmula (b*h)/2, y que tanto la base como la altura sean números enteros.


Comportamiento detallado:



1) El programa solicita y lee los valores de la base (b) y la altura (h).
2) El programa calcula el área del triángulo rectángulo usando la fórmula (b*h)/2.
3) El programa despliega el área calculada en pantalla.



                ----------------------------------
(No importa el orden del desarrollo de estas secciones)



Entradas



Base (b) y altura (h)



Salidas



Área del triángulo (A)



Procesos



1) Solicitar base (b) y altura (h)
2) Calcular el área (A)
3) Desplegar el área (A) calculada
                ----------------------------------
Alcances y limitaciones



El programa solo sirve para calcular áreas de triángulos rectángulo, en donde sus entradas son de tipo entero.



El programa no hace ningún tipo de validación. Si el usuario introduce una base y/o altura negativos, el programa desplegará un resultado incorrecto.



Diseño de pantalla



$./area_trian



   Bienvenido. Este programa calcula el área de un triángulo rectángulo.



   Dame base: 5
   Dame altura: 3



   El área resultante es: 7.5



   Adiós. Vuelve pronto...
$
******************************
DISEÑO ARQUITECTÓNICO

Alto nivel

b,h (ENTRADAS) -> Área de un triángulo rectangulo (PROCESO) -> A (SALIDAS)

Bajo nivel

Pedir b y a (PROCESO)  -> (SALIDAS) b, h (ENTRADAS) -> calcular área (PROCESOS) -> (SALIDAS) A (ENTRADAS) -> Imprimir  resultado (PROCESO)

******************************
DISEÑO DETALLADO(PSEUDOCÓDIGO)

FUNCIÓN PRINCIPAL(|) // int main (void)
INICIO//{

    int base, Altura;// Base, Altura -> entero
    float Area;// Area -> flotante
    //Llamadas a las funciones
    Pedir_area_y_altura (| &Base, &Altura)
    Calcular_area( Base,  Altura | &Area)
    Desplegar_area( Area |)

FIN//}

Función Pedir_area_y_altura (| int *Base, int *Altura)//(|*Base, *Altura -> Entero)
INICIO//{
  printf("Dame base");
  scanf("%d", Base);
  printf("Dame Altura");
  scanf("%d", Altura)
FIN//}
//Este caso no funciona porque la dirección de memoria en donde nos interesa guardar los valores principales . Al poner esta sintaxis, lo que sucede es que estos parametros de salida que guardan la direccion de memoria se van a sustituit por un número enetero y marcara error de que no encuentra dicha dirección de memoria(esto se debe porque es número entero).
//El esqueleto de la función significa que slamente voy a poner el encabezado de éstas(significa que se pone el identificador o nombre, y/o los parámetros tanto de entrada como de salida. No se ponen ninguna instruciión o sentencia dentro de ella)

Función Calcular_area(int Base, int Altura | float *Area)
INICIO//{
 *Area= (Base * ALtura)/2.0;
FIN//}

Función Desplegar_area(int Area |)
INICIO//{
 printf("El resultado del área calculada es: %.2f", Area);
FIN//}

*/

#include <stdio.h>
#include <stdio_ext.h>

// función Pedir_area_y_altura (| int *Base, int *Altura);
void Pedir_area_y_altura(int *Base, int *Altura);
// función Calcular_area(int Base, int Altura | float *Area);
void Calcular_area(int Base, int Altura, float *Area);
//función Desplegar_area(int Area |);
void Desplegar_area(float Area);

int main(void)
{
    int Base;
    int Altura;
    float Area;

Pedir_area_y_altura(&Base, &Altura);
Calcular_area(Base, Altura, &Area);
Desplegar_area(Area);

    return 0;
}

void Pedir_area_y_altura(int *Base, int *Altura){
printf("Dame Base: ");
scanf("%d", Base);
printf("Dame Altura: ");
scanf("%d", Altura);

}

void Calcular_area(int Base, int Altura, float *Area){
*Area = (Base * Altura) / 2.0;
}

void Desplegar_area(float Area){
printf("\nEl resultado del área calculada es: %.2f", Area);
printf("\n");
}