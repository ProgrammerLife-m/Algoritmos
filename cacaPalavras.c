#include <stdio.h>
#define MAX 100
void imprimir_palavras(int n, char matrizGrid[][MAX + 1], int linha, char dicionario[][MAX + 1]);
int verificar_posicoes_palavras(char matriz[][MAX + 1], char dicionario[][MAX + 1], int indxP, int linha, int coluna);

void main(void)
{
    int tamDicio, l_grid, c_grid, i, j;

    scanf("%d", &tamDicio);
    // Preenche dicionario
    char dicionario[tamDicio][MAX + 1];

    for (i = 0; i < tamDicio; i++)
    {
        scanf("%s", dicionario[i]);
    }
    scanf("%d%d", &l_grid, &c_grid);
    // Preenche grid
    char matrizGrid[l_grid + 2][MAX + 1];
    for (i = 1; i <= l_grid; i++)
    {
        scanf("%100s", &matrizGrid[i][1]);
    }
    // Preenche a primeira e a última l_grid com  o sentinela 0
    for (j = 0; j <= c_grid; j++)
    {
        matrizGrid[0][j] = matrizGrid[l_grid + 1][j] = 0;
    }
    // Preenche a primeira e última c_grid com o sentinela 0
    for (i = 0; i <= l_grid + 1; i++)
    {
        matrizGrid[i][0] = matrizGrid[i][c_grid + 1] = 0;
    }
    imprimir_palavras(l_grid + 2, matrizGrid, tamDicio, dicionario);
}
void imprimir_palavras(int n, char matrizGrid[][MAX + 1], int linha, char dicionario[][MAX + 1])
{
    int i, j, k;

    for (i = 0; dicionario[i][0] != 0; i++)
    {
        for (j = 1; j < n; j++)
        {
            for (k = 1; matrizGrid[j][k] != 0; k++)
            {
                if (matrizGrid[j][k] == dicionario[i][0])
                {
                    if (verificar_posicoes_palavras(matrizGrid, dicionario, i, j, k) != -1)
                    {
                        printf("%s\n", dicionario[i]);
                    }
                }
            }
        }
    }
}
int verificar_posicoes_palavras(char matrizGrid[][MAX + 1], char dicionario[][MAX + 1], int indxP, int linha, int coluna)
{
    int i, j = 1, p, k = 1, cont = 0, aux1 = 0, acum1 = 0, inc_linha = 0, inc_coluna = 0;

    for (i = 0; dicionario[indxP][i] != 0; i++)
    {
        cont++;
    }
    inc_linha = -1;
    inc_coluna = 0;
    acum1 = 1;
    for (i = linha + inc_linha; matrizGrid[i][coluna] != 0; i--)
    {
        if (matrizGrid[i][coluna] == dicionario[indxP][j] && aux1 == 0)
        {
            acum1++;
            j++;
        }
        else
        {
            aux1 = 1;
        }

        if (acum1 == cont)
        {
            return indxP;
        }
    }
    inc_linha = 0;
    inc_coluna = 1;
    acum1 = 1;
    aux1 = 0;
    j = 1;
    for (i = coluna + inc_coluna; matrizGrid[linha][i] != 0; i++)
    {
        if (matrizGrid[linha][i] == dicionario[indxP][j] && aux1 == 0)
        {
            acum1++;
            j++;
        }
        else
        {
            aux1 = 1;
        }

        if (acum1 == cont)
        {
            return indxP;
        }
    }
    inc_linha = 1;
    inc_coluna = 0;
    acum1 = 1;
    aux1 = 0;
    j = 1;
    for (i = linha + inc_linha; matrizGrid[i][coluna] != 0; i++)
    {
        if (matrizGrid[i][coluna] == dicionario[indxP][j] && aux1 == 0)
        {
            acum1++;
            j++;
        }
        else
        {
            aux1 = 1;
        }

        if (acum1 == cont)
        {
            return indxP;
        }
    }
    inc_linha = 0;
    inc_coluna = -1;
    acum1 = 1;
    aux1 = 0;
    j = 1;
    for (i = coluna + inc_coluna; matrizGrid[linha][i] != 0; i--)
    {
        if (matrizGrid[linha][i] == dicionario[indxP][j] && aux1 == 0)
        {
            acum1++;
            j++;
        }
        else
        {
            aux1 = 1;
        }

        if (acum1 == cont)
        {
            return indxP;
        }
    }
    inc_linha = -1;
    inc_coluna = 1;
    acum1 = 1;
    aux1 = 0;
    k = 1;
    for (i = linha + inc_linha, p = coluna + inc_coluna; matrizGrid[i][p] != 0; i--, p++)
    {
        if (matrizGrid[i][p] == dicionario[indxP][k] && aux1 == 0)
        {
            acum1++;
            k++;
        }
        else
        {
            aux1 = 1;
        }

        if (acum1 == cont)
        {
            return indxP;
        }
    }
    inc_linha = 1;
    inc_coluna = 1;
    acum1 = 1;
    aux1 = 0;
    k = 1;
    for (i = linha + inc_linha, p = coluna + inc_coluna; matrizGrid[i][p] != 0; i++, p++)
    {
        if (matrizGrid[i][p] == dicionario[indxP][k] && aux1 == 0)
        {
            acum1++;
            k++;
        }
        else
        {
            aux1 = 1;
        }

        if (acum1 == cont)
        {
            return indxP;
        }
    }
    inc_linha = 1;
    inc_coluna = -1;
    acum1 = 1;
    aux1 = 0;
    k = 1;
    for (i = linha + inc_linha, p = coluna + inc_coluna; matrizGrid[i][p] != 0; i++, p--)
    {
        if (matrizGrid[i][p] == dicionario[indxP][k] && aux1 == 0)
        {
            acum1++;
            k++;
        }
        else
        {
            aux1 = 1;
        }

        if (acum1 == cont)
        {
            return indxP;
        }
    }
    inc_linha = -1;
    inc_coluna = -1;
    acum1 = 1;
    aux1 = 0;
    k = 1;
    for (i = linha + inc_linha, p = coluna + inc_coluna; matrizGrid[i][p] != 0; i--, p--)
    {
        if (matrizGrid[i][p] == dicionario[indxP][k] && aux1 == 0)
        {
            acum1++;
            k++;
        }
        else
        {
            aux1 = 1;
        }

        if (acum1 == cont)
        {
            return indxP;
        }
    }
    return -1;
}
