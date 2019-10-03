#include <stdio.h>

int verificaSubstring(char* palavra, char* frase)
{
	int i, j, p = 0, cont = 0, aux = 0, acum = 0;

	for(i = 0; palavra[i] != 0; i++)
	{
		cont++;
	}

	for(i = 0; frase[i] != 0; i++)
	{
		aux = 0;
		if(frase[i] == palavra[0])
		{
			acum = 1;
			p = 1;
			for(j = 1; j < cont; j++)
			{
				if(frase[p+i] == palavra[j] && aux == 0)
				{
					acum++;
				}
				else 
				{
					aux = 1;
					acum = 0;
				}
				p++;
			}
			if(acum == cont)
			{
				return 1;
			}
		}
	}
	return 0;
}
void resposta(int resp)
{
	if(resp == 0)
	{
		printf("o texto nao fala sobre patronos\n");
	}
	else
	{
		printf("o texto fala sobre patronos\n");
	}
}
void main(void)
{
	char palavra[201];
	char frase[201];
	scanf("%s\n", palavra);
	fgets(frase, 200, stdin);
	resposta(verificaSubstring(palavra, frase));
}