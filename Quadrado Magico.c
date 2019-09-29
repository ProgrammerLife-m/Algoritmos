#include <stdio.h>

void quadMagico(int tam, int mat[][tam]);

void main(void)
{
	int tam;

	scanf("%d", &tam);

	while(tam > 0)
	{
		int mat[tam][tam], i, j;

		for(i = 0; i < tam; i++)
		{
			for(j = 0; j < tam; j++)
			{
				scanf("%d", &mat[i][j]);
			}
		}

		quadMagico(tam, mat);

		scanf("%d", &tam);
	}
}

void quadMagico(int tam, int mat[][tam])
{
	int i, j, k, aux, aux2, aux3 = 0, cont = 0, compara = 0;

	//Verifica se todos os valores da matriz são diferentes e se estão no intervalo [1, tamanho*tamanho]
	
	for(i = 0; i < tam; i++)
	{
		for(j = 0; j < tam; j++)
		{
			if(mat[i][j] > 0 && mat[i][j] <= (tam*tam))
			{
				if(aux3 == 0)
				{
					compara = mat[i][j];
					aux3 = 1;
				}
				else if(compara == mat[i][j] && aux3 != 2)
				{
					aux3 = 2;	
				}
			}
		}
	}
	if(aux3 == 1)
	{
		//Acumula a soma dos valores das linhas e das colunas e compara
		
		for(i = 0; i < tam; i++)
		{
			aux = 0;
			aux2 = 0;
			for(j = 0; j < tam; j++)
			{
				aux += mat[i][j];
				aux2 += mat[j][i];
			}

			if(aux == aux2)
			{
				cont += 2;
			}
		}
		//Acumula a soma dos valores das diagonais e compara
		
		aux = 0;
		aux2 = 0;
		k = tam - 1;
		for(i = 0; i < tam; i++)
		{
			j = i;
			aux += mat[i][j];
			aux2 += mat[i][k];
			k--;
		}
		if(aux == aux2)
		{
			cont += 2;
		}
		//Verifica se o acumulador cont é igual a soma das linhas com as colunas e as diagonas
		
		if(cont == 2*(tam + 1))
		{
			printf("sim\n");
		}
		else
		{
			printf("nao\n");
		}
	}
	else
	{
		printf("nao\n");
	}

}