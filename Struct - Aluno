#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;

struct aluno{

	char nome[81];

	char matricula[8];

	char turma;

	float p1;

	float p2;

	float p3;

};

void imprime_aprovados(int n, Aluno** turmas)
{
	int i;
	float media = 0;

	for(i = 0; i < n; i++)
	{
		media = ((turmas[i] -> p1) + (turmas[i] -> p2) + (turmas[i] -> p3))/3;
		if(media >= 6)
		{
			printf("%s\n", (turmas[i] -> nome));
			printf("%s\n", (turmas[i] -> matricula));
			printf("%c\n", (turmas[i] -> turma));
			printf("%.2f\n", media);
			printf("\n");
		}
	}
}
void inicializa(int n, Aluno** turmas)
{
	int i;
	for(i = 0; i < n; i++)
	{
		turmas[i] = NULL;
	}
}
void preenche (int n, Aluno** turmas)
{
	int i;

	for(i = 0; i < n; i++)
	{
		turmas[i] = (Aluno*) malloc(4*sizeof(Aluno));
	}


	for(i = 0; i < n; i++)
	{
		scanf("%s ", &(turmas[i] -> nome));
		scanf("%s ", &(turmas[i] -> matricula));
		scanf(" %c", &(turmas[i] -> turma));
		scanf("%f %f %f", &(turmas[i] -> p1), &(turmas[i] -> p2), &(turmas[i] -> p3));
	}

}
void retira (int n, Aluno** turmas)
{
	int i;

	for(i = 0; i < n; i++)
	{
		free(turmas[i]);
	}
}

void main(void)
{
	int numAlunos;
	scanf("%d", &numAlunos);

	Aluno* turmas[numAlunos];
	inicializa(numAlunos, turmas);	
	preenche(numAlunos, turmas);
	imprime_aprovados(numAlunos, turmas);
	retira(numAlunos, turmas);

}
