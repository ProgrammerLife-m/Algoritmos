#include <stdio.h>

void resultante(int n, int *v, int *r);

void main(void)
{
    int n, i, cont, aux = 1;

    scanf("%d", &n);

    while (n != 0)
    {
        int vetA[n];
        cont = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &vetA[i]);
            if (vetA[i] != 0)
            {
                cont++;
            }
        }
        printf("Caso %d: ", aux++);
        int vetB[cont];
        
        resultante(n, vetA, vetB);
        for (i = 0; i < cont; i++)
        {
            printf("%d ", vetB[i]);
        }
        printf("\n");
        scanf("%d", &n);
    }
}
void resultante(int n, int *v, int *r)
{
    int i, j = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] != 0)
        {
            r[j] = v[i];
            j++;
        }
    }
}