#include <stdio.h>
#include <stdlib.h>

float **ts_cria(int n);
void ts_atribui(int i, int j, float x, float **mat);
float ts_acessa(int i, int j, float **mat);
void ts_libera(int n, float **mat);

void main(void)
{
    int ordem, numAtrib, i, j;

    scanf("%d %d", &ordem, &numAtrib);

    float **matA, elemento;
    matA = ts_cria(ordem);
    int indexI, indexJ;

    while (numAtrib > 0)
    {
        scanf("%d%d%f", &indexI, &indexJ, &elemento);
        ts_atribui(indexI, indexJ, elemento, matA);

        numAtrib--;
    }
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("%.2f ", ts_acessa(i, j, matA));
        }
        printf("\n");
    }

    ts_libera(ordem, matA);
}
float **ts_cria(int n)
{
    int i, j;
    float **matriz;
    matriz = malloc(n * sizeof(float *));
    for (i = 0; i < n; i++)
    {
        matriz[i] = malloc(n * sizeof(float));
    }
    return matriz;
}
void ts_atribui(int i, int j, float x, float **mat)
{
    if (j >= i)
    {
        mat[i][j] = x;
    }
}
float ts_acessa(int i, int j, float **mat)
{
    float elemento;

    elemento = mat[i][j];

    return elemento;
}
void ts_libera(int n, float **mat)
{
    int i;

    for (i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);
}