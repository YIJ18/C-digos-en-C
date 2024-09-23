#include <stdio.h>
#include <stdio_ext.h>

#define MAX_COL 100
#define MIN_COL 5

int Pedir_tamanio(int Min, int Max);
int Pedir_numero(int i, float Num);
void Calcular_mayor(int i, int Columna, float Matriz[MAX_COL], float Num); // Lista, pero matriz, tecnicamente, entonces matriz.
void Calcular_menor(int i, int Columna, float Matriz[MAX_COL], float Num);
void Desplegar_matriz(int Columna, float Matriz[MAX_COL]);

int main(void)
{
    int Columna, i, j, r;

    float Matriz[MAX_COL];
    float Num;

    i = 0;
    j = i + 1;

    Columna = Pedir_tamanio(MIN_COL, MAX_COL);

    do
    {

        Matriz[i] = Pedir_numero(i, Num);

        Calcular_mayor(i, Columna, Matriz, Num);

        // Calcular_menor(i, Columna, Matriz, Num);
        printf("La lista va: \n");
        for (r = 0; r < Columna; r++)
            printf("%.2f\n", Matriz[r]);

        i++;
        j++;
    } while (i <= Columna);
    Desplegar_matriz(Columna, Matriz);

    return 0;
}

int Pedir_tamanio(int Min, int Max)
{
    int Numero;

    do
    {
        printf("Dame el tamaño de la lista (entre 5 y 100): ");
        scanf("%d", &Numero);
        __fpurge(stdin);

        if (Numero < Min || Numero > Max)
            printf("Numero fuera de rango, intenta nuevamente...\n");
    } while (Numero < Min || Numero > Max);

    return Numero;
}

int Pedir_numero(int i, float Num)
{

    // SE LEE POR PARTE EL NUMERO

    printf("Lista[%d]= ", i);
    scanf("%f", &Num);
    __fpurge(stdin);

    return Num;
}

void Calcular_mayor(int i, int Columna, float Matriz[MAX_COL], float Num)
{
    int a, j, Banco;

    for (a = 0; a < Columna - 1; a++)
    {
        for (j = a + 1; j < Columna; j++)
        {
            if (Num < Matriz[a])
            {
                Banco = Matriz[j];
                Matriz[j] = Matriz[a];
                Matriz[j + 1] = Banco;
                Matriz[a] = Num;
            }
        }
    }
}

void Calcular_menor(int i, int Columna, float Matriz[MAX_COL], float Num)
{
    int a, j, Banco;

    for (a = 0; a < Columna; a++)
    {
        for (j = a + 1; j < Columna + 1; j++)
        {
            if (Num > Matriz[a])
            {
                Banco = Matriz[j];
                Matriz[j] = Matriz[a];
                Matriz[j + 1] = Banco;
                Matriz[a] = Num;
            }
        }
    }
}

void Desplegar_matriz(int Columna, float Matriz[MAX_COL])
{
    int i;

    for (i = 0; i < Columna; i++)
    {
        printf("La lista final es: %.2f\t\n", Matriz[i]);
    }
    printf("\n");
}