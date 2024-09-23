#include <stdio.h>
#include <stdio_ext.h>

void Pedir_Num(int *Num);
void Suma_1(int Num, int *Suma);
void Mayor1_1(int Num, int i, int *Mayor);
void Menor_1(int Num, int i, int *Menor);
float Promedio(int Suma, int i);
void Desplegar(int Mayor, int Menor, float Prom);

int main(void)
{
    int Num, Mayor = 0, Menor = 0, Cant, Suma = 0;
    float Prom;
    int i = 0, j = 0;
    printf("\n\nIngresa la cantidad de números a introducir: ");
    scanf("%d", &Cant);
    __fpurge(stdin);

    do
    {
        Pedir_Num(&Num);
        if (Num < 0)
        {
            do
            {
                printf("No ingreso un número válido. Ingreselo de nuevo\n");
                Pedir_Num(&Num);
            } while (Num < 0);
        }

        if (Num % 3 == 0)
        {
            i++;
            Mayor1_1(Num, i, &Mayor);
            Menor_1(Num, i, &Menor);
            Suma_1(Num, &Suma);
        }
        j++;
    } while (Cant > j);
    Prom = Promedio(Suma, i);
    Desplegar(Mayor, Menor, Prom);
    return 0;
}

void Pedir_Num(int *Num)
{
    printf("\nIngresa el número: ");
    scanf("%d", Num);
    __fpurge(stdin);
}

void Mayor1_1(int Num, int i, int *Mayor)
{
    if (i == 1)
        *Mayor = Num;
    else
    {
        if (Num < *Mayor)
            *Mayor = *Mayor;
        else
        {
            if (Num > *Mayor)
                *Mayor = Num;
        }
    }
}

void Menor_1(int Num, int i, int *Menor)
{
    if (i == 1)
        *Menor = Num;
    else
    {
        if (Num > *Menor)
            *Menor = *Menor;
        else
        {
            if (Num < *Menor)
                *Menor = Num;
        }
    }
}

void Suma_1(int Num, int *Suma)
{
    *Suma = Num + *Suma;
}

float Promedio(int Suma, int i)
{
    float prom;
    prom = (float)Suma / i;
    return prom;
}

void Desplegar(int Mayor, int Menor, float Prom)
{
    printf("\nMayor: %d, Menor: %d, promedio: %f\n\n", Mayor, Menor, Prom);
}