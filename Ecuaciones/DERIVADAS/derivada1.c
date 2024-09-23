#include <stdio.h>
#include <math.h>

// cuando es float se pone un a f mayuscula al final de define
#define a 3.0F
#define h 0.01F
// define F(X) pow(x,2) esto es o mismo que lo anterior
float F(float x);

int main(void)
{
        for (a = 0; a < 5; a += 0.5)
        printf("para a=%.2f : %.2f\n", a, df(a, h));
    float df = (F(a + h) - F(a)) / h;
    printf("F(%.0f): %f\n", a, df);
}

float F(float x)
{
    return pow(x, 2);
}