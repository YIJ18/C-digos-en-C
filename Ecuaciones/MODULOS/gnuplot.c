/*** PARTE PUBLICA ***/
/***
 *   Módulo gnuplot.
     Proporciona las funciones necesarias para graficar desde C en gnuplot.
*/

void datos_Graficar(double (*func)(double), double x0, double xf, double h, char *nomArchivo);
void graficar_3_lineas(char *arch1, char *arch2, char *arch3);

/*** PARTE PRIVADA ***/
#include <stdio.h>
#include <math.h>

void datos_Graficar(double (*func)(double), double x0, double xf, double h, char *nomArchivo)
{
  int i, iter;
  double x;
  FILE *archivo;

  x = x0;
  iter = (int)round((xf - x0) / h);
  archivo = fopen(nomArchivo, "wt");
  for (i = 0; i <= iter; i++)
  {
    fprintf(archivo, "%lf %lf\n", x, func(x));
    x += h;
  }
  fclose(archivo);
}

void graficar_3_lineas(char *arch1, char *arch2, char *arch3)
{
  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

  if (!gnuplotPipe)
  {
    fprintf(stderr, "Error al abrir la tubería a Gnuplot.\n");
    return;
  }

  // Configurar el aspecto de la gráfica
  fprintf(gnuplotPipe, "set title 'Mis primeras gráficas'\n");
  fprintf(gnuplotPipe, "set xlabel 'Eje X'\n");
  fprintf(gnuplotPipe, "set ylabel 'Eje Y'\n");

  // Graficar las funciones desde el archivo de datos
  fprintf(gnuplotPipe, "plot '%s' with linespoints title 'Función 1', \
                               '%s' with linespoints title 'Función 2', \
                               '%s' with linespoints title 'Función 3'\n",
          arch1, arch2, arch3);

  // Cerrar la tubería
  pclose(gnuplotPipe);
}
