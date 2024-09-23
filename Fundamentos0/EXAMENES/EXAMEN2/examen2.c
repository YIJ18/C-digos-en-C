#include <stdio.h>

void ingre(int arr[], int *n);
void calc(int arr[], int num, int *medi, double *medp, double *prom, int *moda);

int main(void)
{
    int arr[10], num, x;
    int a = 0, d = 0;
    double b = 0, c = 0;
    ingre(arr, &num);

    calc(arr, num, &a, &b, &c, &d);

    printf("\nTu promedio es : %.2f", c);
    printf("\nTu moda es : %d", d);
    x = num % 2;
    if (x == 0)
    {
        printf("\nTu mediana es : %.2f\n", b);
    }
    else if (x != 0)
    {
        printf("\nTu mediana es : %d\n", a);
    }

    return 0;
}

/*
Parametro: enterero arreglo, donde se guada todo, puntero n, numero inicial
Return: No retorna nada
*/
void ingre(int arr[], int *n)
{
    int no;

    do
    {
        printf("Ingresa un número del 1 al 10: ");
        scanf("%d", &no);
    } while (no < 1 || no > 10);

    printf("Ingresa %d números: ", no);
    printf("\n");
    for (int i = 0; i < no; i++)
    {
        printf("\tIngresa el número: ");
        scanf("%d", &arr[i]);
        *n = no;
    }
}

/*
Parametro: enterero arreglo, donde se guada todo, entero numero, punteros medi,, prom, moda
Return: No retorna nada
*/
void calc(int arr[], int num, int *medi, double *medp, double *prom, int *moda)
{
    // variables promedio
    double suma = 0;
    double j = 0;

    // Variables medianas
    int z, x;
    double mepar;
    int w = num;
    int temp;

    // variables moda
    int y = 0; 
    int a = 0; 
    int mod;

    // Mediana
    for (int x = 0; x < num; x++)
    {
        for (int y = x; y < num; y++)
        {
            if (arr[y] < arr[x])
            {
                z = arr[y];
                arr[y] = arr[x];
                arr[x] = z;
            }
        }
    }

    printf("\nLos números son:\n");
    for (int x = 0; x < num; x++)
    {
        printf("%i, ", arr[x]);
    }

    x = num % 2;
    temp = num / 2;
    if (x != 0)
    {
        for (int i = 0; i < num; i++)
        {
            w--;
            if (arr[w] == arr[i] && w == i)
            {
                *medi = arr[w];
            }
        }
    }
    if (x == 0)
    {
        *medp = (arr[temp] + arr[temp - 1]) / 2;
    }

    // Moda
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (arr[i] == arr[j])
            {
                y = y + 1;
            }
        }
        if (y > a)

        {
            mod = arr[i];
        }
        a = y;
        y = 0;
    }
    *moda = mod;

    // Promedio

    for (int i = 0; i < num; i++)
    {
        suma = arr[i] + j;
        arr[i] = j;
        j = suma;
    }
    *prom = suma / num;
}