#include <stdio.h>
#include <math.h>

#define N 3

void jacobi(double A[N][N], double b[N], double x[N], int maxIter, double tol)
{
    int i, j, k;
    double x_new[N];

    for (k = 0; k < maxIter; k++)
    {
        for (i = 0; i < N; i++)
        {
            x_new[i] = b[i];
            for (j = 0; j < N; j++)
            {
                if (i != j)
                {
                    x_new[i] -= A[i][j] * x[j];
                }
            }
            x_new[i] /= A[i][i];
        }

        double max_diff = 0.0;
        for (i = 0; i < N; i++)
        {
            double diff = fabs(x_new[i] - x[i]);
            if (diff > max_diff)
            {
                max_diff = diff;
            }
        }

        for (i = 0; i < N; i++)
        {
            x[i] = x_new[i];
        }

        if (max_diff < tol)
        {
            break;
        }
    }
}

int main()
{
    double A[N][N] = {{4, -3, 1}, {-2, 3, -2}, {1, -2, 3}};
    double b[N] = {5, -4, 1};
    double x[N] = {0, 0, 0};
    int maxIter = 1000;
    double tol = 1e-6;

    jacobi(A, b, x, maxIter, tol);

    printf("Solución:\n");
    for (int i = 0; i < N; i++)
    {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}
