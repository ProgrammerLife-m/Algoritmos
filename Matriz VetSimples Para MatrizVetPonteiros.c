#include <stdio.h>
#include <stdlib.h>

float** converte_a (int m, int n, float* mat);
void ler_matriz(int m, int n, float* mat);
void imprime_matriz(int m, int n, float** mat);
void libera(int n, float **mat);

void main(void)
{
	int linhas, colunas, i, j;

	scanf("%d%d", &linhas, &colunas);

	float* mat;
	float** matA;
	mat = malloc(linhas*colunas*sizeof(mat));

	ler_matriz(linhas, colunas, mat);
	matA = converte_a(linhas, colunas, mat);
	imprime_matriz(linhas, colunas, matA);
	
	free(mat);
	libera(linhas, matA);

}
float** converte_a (int m, int n, float* mat)
{
	int i, j;

	float** cvMat;
	cvMat = malloc(m*sizeof(float*));

	for(i = 0; i < m; i++)
	{
		cvMat[i] = malloc(n*sizeof(float));
	}
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cvMat[i][j] = mat[i * n + j];
		}
	}
	return cvMat;
}
void ler_matriz(int m, int n, float* mat)
{
	int i, j;

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%f", &mat[i * n + j]);
		}
	}
}
void imprime_matriz(int m, int n, float** mat)
{
	int i, j;

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%.2f ", mat[i][j]);
		}	
		printf("\n");
	}	
}
void libera(int n, float **mat)
{
	int i;

	for(i = 0; i < n; i++)
	{
		free(mat[i]);
	}
	free(mat);
}


