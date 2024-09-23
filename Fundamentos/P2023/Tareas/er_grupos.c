/*
  @file: er_grupos.c
  @brief:  Este programa calcula el porcentaje de hombres y mujeres que se encuentran inscritos en un grupo. El usuario debe de darte la cantidad de estudiantes en un grupo y la cantidad de mujeres que hay
  @details: Este programa tiene 3 entradas: tres etradas enteras. Aqui vamos a realizar una transformación, de las tres variables, sale solo dos.



  @author: Iris Ylit Jasso Cortes
  date: 12-02-2023



**************************************************************************************
ESPECIFICACIÓN DE REQUERIMIENTOS



Título: Calculadora Porcentual



Descripción general:


Se desea un programa que calculeel porcentaje de hombres y mujeres que se encuentran inscritos en un grupo.



El programa será utilizado para una escuela y ver el porcentaje de niños y niñas. Es un requerimiento que los números ingresados no sean flotante, ni negativos, para sacar el porciento se hara un a regla de 3 (Num_muj*100/Num_est) y (Num_hom*100/Num_est)




Comportamiento detallado:



1) El programa solicita y lee el valor de las mujeres (Num_muj), el número de los estudiante (Num_est), el número de los hombres(Num_est)
2) El programa calculala (Num_muj*100/Num_est) y (Num_hom*100/Num_est)
3) El programa despliega el resultado de operación asignada en pantalla.



                ----------------------------------


Entradas



Numero de mujeres(Num_muj), Numero de hombres (Num_hom), Numero de estudiantes (Num_est).



Salidas



Resultado de operación asignada (Mujeres)
Resultado de operación asignada (Hombres)


Procesos



1) Solicitar número de Estudantes (Num_est), número de mujeres (Num_muj) y número de hombres (Num_hom)
2) Calcular la operación (Mujeres)
3) Calcular la operación (Hombres)
4) Desplegar los resultados (Hombres, Mujeres) calculado
                ----------------------------------
Alcances y limitaciones


El programa solo realiza una operación donde su entrada solo puede ser un cáracter (+, -, *, /), solo sirve para calcular suma, resta, multiplicación y división, en donde sus entradas permiten números decimales.




El programa hace un tipo de validación. Si el usuario introduce un número flotante, un número negativo o mayor hombres y mujeres que estudiantes, desplegara un error.



Diseño de pantalla



$./area_trian



   Bienvenido. Este programa calcula el porcentaje de hombres y mujeres dentro de un salón.



   Dame el número de estudiantes: 10
   Dame el número de mujeres: 5
   Dame tu número de hombres: 5



   El porcentaje de mujeres es: 50%
   El porcentaje de hombres es: 50%



   Adiós. Vuelve pronto...
$
**************************************************************************************
DISEÑO ARQUITECTÓNICO

Alto nivel

Num_est, Num_muj, Num_hom (ENTRADAS) -> Calcular el porcentaje(PROCESO) -> Hombres, Mujeres (SALIDAS)

Bajo nivel

Pedir Num_est, Num_muj, Num_hom (PROCESO)  -> (SALIDAS) Num_est, Num_muj, Num_hom (ENTRADAS) -> Calcular el porcentaje (PROCESOS) -> (SALIDAS) Hombres, Mujeres (ENTRADAS) -> Imprimir  resultado (PROCESO)


*/

#include <stdio.h>

void Solicitar_Numeros(int *Num_muj, int *Num_hom, int *Num_est);
void Calcular_Porcentaje(int Num_muj, int Num_hom, int Num_est, int *Hombres, int *Mujeres);
void Desplegar_Resultado(int Hombres, int Mujeres);

int main(void)
{
  int Num_muj, Num_hom, Num_est, Hombres, Mujeres;
  Solicitar_Numeros(&Num_muj, &Num_hom, &Num_est);
  Calcular_Porcentaje(Num_muj, Num_hom, Num_est, &Hombres, &Mujeres);
  Desplegar_Resultado(Hombres, Mujeres);
  return 0;
}

void Solicitar_Numeros(int *Num_muj, int *Num_hom, int *Num_est)
{
  printf("Introduce el número de estudiantes: ");
  scanf("%d", Num_est);
  printf("Introduce el número de mujeres: ");
  scanf("%d", Num_muj);
  printf("Introduce el número de hombres: ");
  scanf("%d", Num_hom);
}

void Calcular_Porcentaje(int Num_muj, int Num_hom, int Num_est, int *Hombres, int *Mujeres)
{
  if (Num_muj + Num_hom != Num_est)
  {
    printf("Tu total de alumnos no coincide con la suma de número de alumnas y alumnos.\n");
    *Hombres = -1;
    *Mujeres = -1;
  }

  else
  {
    *Hombres = (Num_hom * 100) / Num_est;
    *Mujeres = (Num_muj * 100) / Num_est;
  }
}

void Desplegar_Resultado(int Hombres, int Mujeres)
{
  if (Mujeres == -1 && Hombres == -1)
  {
    printf("Favor de ingresar un número valido.\n");
  }
  else
  {
    printf("Son %% %d de mujeres\n", Mujeres);
    printf("Son %% %d de hombres\n", Hombres);
  }
}