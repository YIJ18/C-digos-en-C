#include <stdio.h>

float funcion(float x);
float funcion2(float x);

int main(void)
{
    float y,x;

    for (x = 0; x <= 2; x=x+0.01)
    {
        if (x > 1)
            y = funcion(x);
        if (x <= 1)
        {
            if (x == 1)
                printf("-------------x <= 1---------------\n");
            y = funcion2(x);
        }
        printf("x = %lf, y = %lf\n", x, y);
    }
}

float funcion(float x)
{
    return (x * x) + (3 * x) - 3;
}

float funcion2(float x)
{
    return (3 / ((2 * x) + 1));
}