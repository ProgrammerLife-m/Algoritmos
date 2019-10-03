#include <stdio.h>
#include <stdlib.h>

int *mesclar(int tam1, int vetor1[], int tam2, int vetor2[]);

void main(void)
{
	int teste, i, m, n;

	scanf("%d", &teste);
	while (teste > 0)
	{
		scanf("%d", &m);
		
		int vetor1[m];
		for (i = 0; i < m; i++)
		{
			scanf("%d", &vetor1[i]);
		}

		scanf("%d", &n);
		
		int vetor2[n];
		for (i = 0; i < n; i++)
		{
			scanf("%d", &vetor2[i]);
		}

		int *vet;
		vet = mesclar(m, vetor1, n, vetor2);

		for (i = 0; i < (m+n); i++)
		{
			printf("%d ", vet[i]);
		}
		teste--;
		free(vet);
	}
}
int *mesclar(int tam1, int vetor1[], int tam2, int vetor2[])
{
	
	int i, contV = 0, contU = 0, aux = 1;
	int *vet;
	vet = malloc((tam1+tam2)*sizeof(int));

	for (i = 0; i < (tam1+tam2); i++)
	{
		if (vetor2[contU] >= vetor1[contV] && aux == 1)
		{
			vet[i] = vetor1[contV];
			contV++;
		}
		else if(aux == 1)
		{
			vet[i] = vetor2[contU];
			contU++;
		}
		if (contV == tam1 + 1 && contU < tam2)
		{
			vet[i] = vetor2[contU];
			contU++;
			aux = 0;
		}
		else if (contU == tam2 + 1 && contV < tam1)
		{
			vet[i] = vetor1[contV];
			contV++;
			aux = 0;
		}
	}
	return vet;
}
