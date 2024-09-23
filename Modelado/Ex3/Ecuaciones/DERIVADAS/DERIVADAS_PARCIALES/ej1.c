#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define h 0.01

double F(double x, double y, double z);
double x_derivada_atras(double x, double y, double z, int n);
double y_derivada_atras(double x, double y, double z, int n);
double z_derivada_atras(double x, double y, double z, int n);
double zz_derivada_atras(double x, double y, double z, int n);
double y_x_derivada_atras(double x, double y, double z, int n);
double x_y_derivada_atras(double x, double y, double z, int n);
double x_z_derivada_atras(double x, double y, double z, int n);
double z_x_derivada_atras(double x, double y, double z, int n);
double y_z_derivada_atras(double x, double y, double z, int n);
double z_y_derivada_atras(double x, double y, double z, int n);
double Fxz(double x, double y, double z);

int main(void)
{
    double x = 0.0, y = 0.0, z = 0.0;

    printf("Dame el valor de x: ");
    scanf("%lf", &x);
    printf("Dame el valor de y: ");
    scanf("%lf", &y);
    printf("Dame el valor de z: ");
    scanf("%lf", &z);

    printf("\n--------------------------------------\n");
    printf(" Derivada (x = %.2lf) (y = %.2lf) (z = %.2lf)\n", x, y, z);
    printf("--------------------------------------\n");
    printf("\t Fx = %.6lf\n", x_derivada_atras(x, y, z, 1));
    printf("\t Fy = %.6lf\n", y_derivada_atras(x, y, z, 1));
    printf("\t Fz = %.6lf\n", z_derivada_atras(x, y, z, 1));
    printf("\n");
    printf("\t Fzz = %.6lf\n", zz_derivada_atras(x, y, z, 1));
    printf("\t Fxx = %.6lf\n", x_derivada_atras(x, y, z, 2));
    printf("\t Fyy = %.6lf\n", y_derivada_atras(x, y, z, 2));
    printf("\n");
    printf("\t Fxy = %.6lf\n", x_y_derivada_atras(x, y, z, 2));
    printf("\t Fyx = %.6lf\n", y_x_derivada_atras(x, y, z, 2));
    printf("\n");
    printf("\t Fxz = %.6lf\n", x_z_derivada_atras(x, y, z, 1));
    printf("\t Fzx = %.6lf\n", z_x_derivada_atras(x, y, z, 1));
    printf("\n");
    printf("\t Fyz = %.6lf\n", y_z_derivada_atras(x, y, z, 1));
    printf("\t Fzy = %.6lf\n", z_y_derivada_atras(x, y, z, 1));

    printf("\n--------------------------------------\n");

    printf("\t Fxz = %.6lf\n", Fxz(x, y, z));

    printf("\n");
    return 0;
}

double F(double x, double y, double z)
{
    return pow((x * x) + (y * y) + (z * z), 0.5);
}

double x_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (x_derivada_atras(x, y, z, n - 1) - x_derivada_atras(x - h, y, z, n - 1)) / h;
}

double y_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (y_derivada_atras(x, y, z, n - 1) - y_derivada_atras(x, y - h, z, n - 1)) / h;
}

double z_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (z_derivada_atras(x, y, z, n - 1) - z_derivada_atras(x, y, z - h, n - 1)) / h;
}

double zz_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (z_derivada_atras(x, y, z + h, n - 1) - 2 * z_derivada_atras(x, y, z, n - 1) + z_derivada_atras(x, y, z - h, n - 1)) / (h * h);
}

double x_y_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (F(x + h, y + h, z) - F(x + h, y - h, z) - F(x - h, y + h, z) + F(x - h, y - h, z)) / (4 * h * h);
}

double y_x_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (F(x + h, y + h, z) - F(x + h, y - h, z) - F(x - h, y + h, z) + F(x - h, y - h, z)) / (4 * h * h);
}

double x_z_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (F(x + h, y + h, z) - F(x + h, y - h, z) - F(x - h, y + h, z) + F(x - h, y - h, z)) / (4 * h * h);
}

double z_x_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (F(x + h, y + h, z) - F(x + h, y - h, z) - F(x - h, y + h, z) + F(x - h, y - h, z)) / (4 * h * h);
}

double y_z_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (F(x + h, y + h, z) - F(x + h, y - h, z) - F(x - h, y + h, z) + F(x - h, y - h, z)) / (4 * h * h);
}

double z_y_derivada_atras(double x, double y, double z, int n)
{
    if (n == 0)
        return F(x, y, z);
    else
        return (F(x + h, y + h, z) - F(x + h, y - h, z) - F(x - h, y + h, z) + F(x - h, y - h, z)) / (4 * h * h);
}

double Fxz(double x, double y, double z)
{
       return (F(x + h, y, z + h) - F(x, y, z + h) - F(x + h, y, z) + F(x, y, z)) / (h * h);
}
