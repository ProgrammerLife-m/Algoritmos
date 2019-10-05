#include <stdio.h>

void imprimir_palavra(int m, char matriz[][m], int linha, int coluna, int inc_linha, int inc_coluna);

void main(void)
{
    int linhas, colunas, i, j;

    scanf("%d%d", &linhas, &colunas);
    char matriz[linhas + 2][colunas + 2];

    for (i = 1; i <= linhas; i++)
    {
        scanf("%s", &matriz[i][1]);
    }

    // Preenche a primeira e a última linhas
    for (j = 0; j <= colunas + 1; j++)
    {
        matriz[0][j] = matriz[linhas + 1][j] = 0;
    }
    // Preenche a primeira e última colunas
    for (i = 0; i <= linhas + 1; i++)
    {
        matriz[i][0] = matriz[i][colunas + 1] = 0;
    }

    int posxP, posyP, incL = 0, incC = 0;
    while (scanf("%d%d", &posxP, &posyP) != EOF)
    {
        printf("(%d, %d)\n", posxP, posyP);

        imprimir_palavra(colunas + 2, matriz, posxP, posyP, -1, 0);

        imprimir_palavra(colunas + 2, matriz, posxP, posyP, 0, 1);

        imprimir_palavra(colunas + 2, matriz, posxP, posyP, 1, 0);

        imprimir_palavra(colunas + 2, matriz, posxP, posyP, 0, -1);
    }
}

void imprimir_palavra(int m, char matriz[][m], int linha, int coluna, int inc_linha, int inc_coluna)
{
    int k;

    printf("%c", matriz[linha][coluna]);

    if (inc_linha == -1 && inc_coluna == 0)
    {
        for (k = linha + inc_linha; matriz[k][coluna] != 0; k--)
        {
            printf("%c", matriz[k][coluna]);
        }
    }
    else if (inc_linha == 0 && inc_coluna == 1)
    {
        for (k = coluna + inc_coluna; matriz[linha][k] != 0; k++)
        {
            printf("%c", matriz[linha][k]);
        }
    }
    else if (inc_linha == 1 && inc_coluna == 0)
    {
        for (k = linha + inc_linha; matriz[k][coluna] != 0; k++)
        {
            printf("%c", matriz[k][coluna]);
        }
    }
    else if (inc_linha == 0 && inc_coluna == -1)
    {
        for (k = coluna + inc_coluna; matriz[linha][k] != 0; k--)
        {
            printf("%c", matriz[linha][k]);
        }
    }
    printf("\n");
}
