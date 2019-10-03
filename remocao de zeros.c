#include <stdio.h>

int remover_zeros(int tam, int vetor[], int res);
void vetorResultante(int n, int vetor[], int resultante[]);

void main(void)
{
    int n, i, aux = 1;

    scanf("%d", &n);

    while (n != 0)
    {
        int vetA[n], cont = 0;

        for (i = 0; i < n; i++)
        {
            scanf("%d", &vetA[i]);
        }
        printf("Caso %d: ", aux++);

        cont = remover_zeros(n, vetA, cont);
        int vetB[cont];
        vetorResultante(n, vetA, vetB);

        for(i = 0; i < cont; i++)
        {
            printf("%d ", vetB[i]);
        }
        
        printf("\n");
        scanf("%d", &n);
    }
}
int remover_zeros(int tam, int vetor[], int res)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        if (vetor[i] != 0)
        {
            res++;
        }
    }
    return res;
}
void vetorResultante(int n, int vetor[], int resultante[])
{
    int i, j = 0;

    for(i = 0; i < n; i++)
    {
        if(vetor[i] != 0)
        {
            resultante[j] = vetor[i];
            j++;
        }
    }
}