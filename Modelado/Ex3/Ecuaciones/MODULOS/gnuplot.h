/*** PARTE PUBLICA ***/
/***
 *   Módulo gnuplot.
     Proporciona las funciones necesarias para graficar desde C en gnuplot.
*/

void datos_Graficar(double (*func)(double), double x0, double xf, double h, char *nomArchivo);
void graficar_3_lineas(char *arch1, char *arch2, char *arch3);
