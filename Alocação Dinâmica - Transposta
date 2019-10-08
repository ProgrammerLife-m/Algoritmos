#include <stdio.h>
#include <stdlib.h>

float* transposta(int m,int n, float* mat);
void ler_matriz(int m, int n, float* mat);
void imprime_matriz(int m, int n, float* mat);

void main(void)
{
	int linhas, colunas;
	
	scanf("%d%d", &linhas, &colunas);
	
	float *mat; 
	float *trp;
	
	mat = malloc(linhas*colunas*sizeof(float));
	
	ler_matriz(linhas, colunas, mat);
	
	trp = transposta(linhas, colunas, mat);
	
	imprime_matriz(linhas, colunas, trp);
	
	free(mat);
	free(trp);
}
float* transposta(int m,int n, float* mat)
{
	int i, j;
	float *trp;
	trp = malloc(m*n*sizeof(float));
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			trp[j*m + i] = mat[i*n + j];
		}
	}
	
	return trp;
}
void ler_matriz(int m, int n, float* mat)
{
	int i, j;
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%f", &mat[i*n + j]);
		}
	}
}
void imprime_matriz(int m, int n, float* mat)
{
	int i, j;
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%.2f ", mat[i*n + j]);
		}
		printf("\n");
	}
}
