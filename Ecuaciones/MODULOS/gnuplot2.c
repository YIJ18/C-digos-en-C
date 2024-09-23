#include <stdio.h>
#include <math.h>

double euler(double (*f)(double, double), double xi, double yi, double h, int iter);
double eulerGauss(double (*f)(double, double), double xi, double yi, double h, int iter,
                  FILE *arch_yc, FILE *arch_yp);
double f(double x, double y);
double f1(double x, double y);
double f2(double x, double y);
double f3(double x, double y);
double f4(double x, double y);
double F(double x);
double F1(double x);
void graficar();

int main(void)
{

    double x0, xf, y0, x, y, h;
    int i, iter /* = (xf - x0) / h*/;
    FILE *archivo_yc, *archivo_yp, *archivo_yreal;

    archivo_yc = fopen("datos_yc.txt", "w");
    archivo_yp = fopen("datos_yp.txt", "w");
    archivo_yreal = fopen("datos_yreal.txt", "w");
    printf("Dame x0: ");
    scanf("%lf", &x0);
    printf("Dame xf: ");
    scanf("%lf", &xf);
    printf("Dame y(%.2lf): ", x0);
    scanf("%lf", &y0);
    printf("Dame el valor de h: ");
    scanf("%lf", &h);
    iter = round((xf - x0) / h);

    printf("Valores de Euler con eulerGauss()\n");
    printf("    x      Euler     Euler-Gauss\n");
    y = eulerGauss(f1, x0, y0, h, iter, archivo_yc, archivo_yp);

    printf("\nPara f, solución real");
    x = x0;
    printf("Valores reales\n");
    for (i = 0; i <= iter; i++)
    {
        printf("F(%.2lf) = %lf\n", x, F1(x));
        fprintf(archivo_yreal, "%lf %lf\n", x, F1(x));
        x += h;
    }
    fclose(archivo_yc);
    fclose(archivo_yp);
    fclose(archivo_yreal);
    graficar();
}

double f(double x, double y)
{
    return x + (2 * x * y);
}

double f1(double x, double y)
{
    return pow(x, 3) * exp(-2 * x) - 2 * y;
}

double f2(double x, double y)
{
    return -2 * pow(y, 2) + x * y + pow(x, 2);
}

double f3(double x, double y)
{
    return 2 * x * y + 1;
}

double f4(double x, double y)
{
    return -2 * pow(x, 3) + 12 * pow(x, 2) - 20 * x + 8.5;
}

double F(double x)
{
    return 1.5 * exp(pow(x, 2) - 0.25) - 0.5;
}

double F1(double x)
{
    return (exp(-2 * x) / 4) * (pow(x, 4) + 4);
}

double euler(double (*f)(double, double), double xi, double yi, double h, int iter)
{
    if (iter == 0)
    {
        // printf("%9.6lf %9.6lf\n", xi, yi);
        return yi;
    }
    else
    {
        // yi = yi + f(xi, yi) * h;
        // printf("%9.6lf %9.6lf\n", xi, yi);
        return euler(f, xi + h, yi + f(xi, yi) * h, h, iter - 1);
    }
}

double eulerGauss(double (*f)(double, double), double xi, double yi, double h, int iter,
                  FILE *arch_yc, FILE *arch_yp)
{
    double ypi1;

    // printf("EG1 E - ypi1 vale %lf, xi vale %lf, iter vale %d\n", yi, xi, iter);
    if (iter == 0)
    {
        printf("%9.6lf %9.6lf %9.6lf\n", xi, euler(f, xi, yi, h, 1), yi);
        fprintf(arch_yp, "%lf %lf\n", xi, euler(f, xi, yi, h, 1));
        fprintf(arch_yc, "%lf %lf\n", xi, yi);
        return yi;
    }
    else
    {
        // Llama a la función euler para obtener el término adicional
        // ypi1 = euler(f, xi, yi, h, 1);
        printf("%9.6lf %9.6lf %9.6lf\n", xi, euler(f, xi, yi, h, 1), yi);
        fprintf(arch_yp, "%lf %lf\n", xi, euler(f, xi, yi, h, 1));
        fprintf(arch_yc, "%lf %lf\n", xi, yi);
        // printf("EG1 S - ypi1 vale %lf, xi vale %lf, iter vale %d\n", yi, xi, iter);
        //  Calcula el siguiente paso en el método de Euler-Gauss
        return eulerGauss(f, xi + h, yi + (h / 2) * (f(xi, yi) + f(xi + h, euler(f, xi, yi, h, 1))), h,
                          iter - 1, arch_yc, arch_yp);
    }
}

void graficar()
{
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

    if (!gnuplotPipe)
    {
        fprintf(stderr, "Error al abrir la tubería a Gnuplot.\n");
        return;
    }

    // Configurar el aspecto de la gráfica
    fprintf(gnuplotPipe, "set title 'Examen'\n");
    fprintf(gnuplotPipe, "set xlabel 'Eje X'\n");
    fprintf(gnuplotPipe, "set ylabel 'Eje Y'\n");

    // Graficar las funciones desde el archivo de datos
    fprintf(gnuplotPipe, "plot 'datos_yp.txt' with linespoints title 'Función 1 - yp', \
                         'datos_yc.txt' with linespoints title 'Función 2 - yc', \
                         'datos_yreal.txt' with linespoints title 'Función 3 - y real'\n");

    // Cerrar la tubería
    pclose(gnuplotPipe);
}
