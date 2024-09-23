#include <stdio.h>
#include <math.h>

float df(float ta, float h);
float F(float x);
int main(void)
{
    float a = 0.0f;
    float h = 0.01f;
    printf("para t = 0: %f\n", df(a, h));
    a = 4.0;
    printf("para t = 4: %f\n", df(a, h));
    printf("---------------------------\n");
    for (a = 0; a < 5; a += 0.5)
        printf("para a=%.2f : %.2f\n", a, df(a, h));
    return 0;
}

float df(float ta, float h)
{
    float t = ta + h;
    return (F(t) - F(ta)) / h;
}

float F(float x)
{
    return pow(x, 2) - 6.0 * x;
}