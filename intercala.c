#include <stdio.h>

void resultado(int n, int m, int p, int *v, int *u, int *w);

void main(void)
{
	int teste, i, n, m;

	scanf("%d", &teste);
	while (teste > 0)
	{
		scanf("%d", &n);
		int v[n];
		for (i = 0; i < n; i++)
		{
			scanf("%d", &v[i]);
		}

		scanf("%d", &m);
		int u[m];
		for (i = 0; i < m; i++)
		{
			scanf("%d", &u[i]);
		}

		int p = m + n, vet[p];
		resultado(n, m, p, v, u, vet);
		for (i = 0; i < p; i++)
		{
			printf("%d ", vet[i]);
		}

		teste--;
	}
}
void resultado(int n, int m, int p, int *v, int *u, int *w)
{
	
	int i, contV = 0, contU = 0, aux = 1;

	for (i = 0; i < p; i++)
	{
		if (u[contU] >= v[contV] && aux == 1)
		{
			w[i] = v[contV];
			contV++;
		}
		else if (aux == 1)
		{
			w[i] = u[contU];
			contU++;
		}
		if (contV == n + 1 && contU < m)
		{
			w[i] = u[contU];
			contU++;
			aux = 0;
		}
		else if (contU == m + 1 && contV < n)
		{
			w[i] = v[contV];
			contV++;
			aux = 0;
		}
	}
}
