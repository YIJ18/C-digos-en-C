#include <stdio.h>
#define inicio 0.0
#define final 6.0
#define numCuad 100000000
#define delta final/numCuad

double F(double x);
double integral();

int main(void)
{
    printf("Con la delta %lf\n", delta);
    printf("El resultado es : %lf\n", integral());
    return 0;
}

double F(double x)
{
    return 8 - ((x * x) / 2.0);
}

double integral()
{
    double i, res = 0.0;
    int ciclos = 0;
 
    for (i = inicio; i <= final; i += delta)
        res += F(i) * delta ;
    return res;
}