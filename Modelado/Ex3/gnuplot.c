void graficar_1_linea(char *archivo);
void graficar_2_lineas(char *arch1, char *arch2);
void graficar_3_lineas(char *arch1, char *arch2, char *arch3);
void graficar_4_lineas(char *arch1, char *arch2, char *arch3, char *arch4);
void graficar_5_lineas(char *arch1, char *arch2, char *arch3, char *arch4, char *arch5);

#include <stdio.h>
#include <math.h>
#include <string.h>
/**
 * Grafica una línea desde un archivo de datos utilizando Gnuplot.
 * 
 * @param archivo Nombre del archivo de datos.
 */
void graficar_1_linea(char *archivo)
{
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

    if (!gnuplotPipe)
    {
        fprintf(stderr, "Error al abrir la tubería a Gnuplot.\n");
        return;
    }

    // Configurar el aspecto de la gráfica
    fprintf(gnuplotPipe, "set title 'Mi primera gráfica'\n");
    fprintf(gnuplotPipe, "set xlabel 'Eje X'\n");
    fprintf(gnuplotPipe, "set ylabel 'Eje Y'\n");

    // Graficar la función desde el archivo de datos, se cabia por el nombre de la gráfica que quiera
    fprintf(gnuplotPipe, "plot '%s' with linespoints title 'runge_kutta.txt'\n", archivo);

    // Cerrar la tubería
    pclose(gnuplotPipe);
}

/**
 * Grafica dos líneas desde archivos de datos diferentes utilizando Gnuplot.
 * 
 * @param arch1 Nombre del primer archivo de datos.
 * @param arch2 Nombre del segundo archivo de datos.
 */
void graficar_2_lineas(char *arch1, char *arch2)
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

    // Graficar las funciones desde los archivos de datos
    fprintf(gnuplotPipe, "plot '%s' with linespoints title 'eu_y.txt', \
                               '%s' with linespoints title 'eu_y_corrector.txt'\n",
            arch1, arch2);

    // Cerrar la tubería
    pclose(gnuplotPipe);
}

/**
 * Grafica tres líneas desde archivos de datos diferentes utilizando Gnuplot.
 * 
 * @param arch1 Nombre del primer archivo de datos.
 * @param arch2 Nombre del segundo archivo de datos.
 * @param arch3 Nombre del tercer archivo de datos.
 */
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

/**
 * Grafica cuatro líneas desde archivos de datos diferentes utilizando Gnuplot.
 * 
 * @param arch1 Nombre del primer archivo de datos.
 * @param arch2 Nombre del segundo archivo de datos.
 * @param arch3 Nombre del tercer archivo de datos.
 * @param arch4 Nombre del cuarto archivo de datos.
 */
void graficar_4_lineas(char *arch1, char *arch2, char *arch3, char *arch4)
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

    // Graficar las funciones desde los archivos de datos
    fprintf(gnuplotPipe, "plot '%s' with linespoints title 'Función 1', \
                               '%s' with linespoints title 'Función 2', \
                               '%s' with linespoints title 'Función 3', \
                               '%s' with linespoints title 'Función 4'\n",
            arch1, arch2, arch3, arch4);

    // Cerrar la tubería
    pclose(gnuplotPipe);
}

/**
 * Grafica cinco líneas desde archivos de datos diferentes utilizando Gnuplot.
 * 
 * @param arch1 Nombre del primer archivo de datos.
 * @param arch2 Nombre del segundo archivo de datos.
 * @param arch3 Nombre del tercer archivo de datos.
 * @param arch4 Nombre del tercer archivo de datos.
 * @param arch5 Nombre del tercer archivo de datos.
 */
void graficar_5_lineas(char *arch1, char *arch2, char *arch3, char *arch4, char *arch5)
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

    // Graficar las funciones desde los archivos de datos
    fprintf(gnuplotPipe, "plot '%s' with linespoints title 'y.txt', \
                               '%s' with linespoints title 'pm.txt', \
                               '%s' with linespoints title 'error.txt', \
                               '%s' with linespoints title 'error_pm.txt', \
                               '%s' with linespoints title 'real.txt'\n",
            arch1, arch2, arch3, arch4, arch5);

    // Cerrar la tubería
    pclose(gnuplotPipe);
}

