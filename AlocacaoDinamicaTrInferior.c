#include <stdio.h>
#include <stdlib.h>

float **ti_cria(int n);
void ti_atribui(int i, int j, float x, float **mat);
float ti_acessa(int i, int j, float **mat);
void ti_libera(int n, float **mat);

void main(void)
{
	int ordem, numAtrib, i, j;

	scanf("%d %d", &ordem, &numAtrib);

	float **matA, elemento;
	matA = ti_cria(ordem);
	int indexI, indexJ;

	while (numAtrib > 0)
	{
		scanf("%d%d%f", &indexI, &indexJ, &elemento);
		ti_atribui(indexI, indexJ, elemento, matA);

		numAtrib--;
	}
	for (i = 0; i < ordem; i++)
	{
		for (j = 0; j < ordem; j++)
		{
			printf("%.2f ", ti_acessa(i, j, matA));
		}
		printf("\n");
	}

	ti_libera(ordem, matA);
}
float **ti_cria(int n)
{
	int i;
	float **matriz;
	matriz = malloc(n * sizeof(float *));
	for (i = 0; i < n; i++)
	{
		matriz[i] = malloc(n * sizeof(float));
	}
	return matriz;
}
void ti_atribui(int i, int j, float x, float **mat)
{
	if (i >= j)
	{
		mat[i][j] = x;
	}
	else
	{
		mat[j][i] = x;
	}
	
}
float ti_acessa(int i, int j, float **mat)
{
	float elemento;

	elemento = mat[i][j];

	return elemento;
}
void ti_libera(int n, float **mat)
{
	int i;

	for (i = 0; i < n; i++)
	{
		free(mat[i]);
	}
	free(mat);
}