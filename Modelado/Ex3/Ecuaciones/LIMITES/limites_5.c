#include <stdio.h>

float funcion(float x);
float funcion2(float x);

int main(void)
{
    float y,x;

    for (x = 1; x <= 3; x=x+0.1)
    {
        if (x < 2)
            y = funcion(x);
        if (x >= 2)
        {
            if (x == 2)
                printf("-------------x <= 1---------------\n");
            y = funcion2(x);
        }
        printf("x = %lf, y = %lf\n", x, y);
    }
}

float funcion(float x)
{
    return (x * x);
}

float funcion2(float x)
{
    return 1 / x;
}