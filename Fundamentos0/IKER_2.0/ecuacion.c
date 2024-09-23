#include <stdio.h>
#include <math.h>

void eq_cuadr(int a, int b, int c, int *r1, int *r2);

int main(void)
{

    return 0;
}

void eq_cuadr(int a, int b, int c, int *r1, int *r2)
{
    *r1 = (-b + sqrt(b * b - 4 * a * c) / (2 * a));
    *r2 = (b + sqrt(b * b - 4 * a * c) / (2 * a));
}
