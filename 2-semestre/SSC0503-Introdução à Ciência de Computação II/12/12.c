#include <stdio.h>
#include <stdlib.h>

int ** aloca_matriz(int n, int m);
void desaloca_matriz(int **matriz, int n, int m);
int max(int a, int b);
int posicao_eh_valida(int i, int j, int n, int m);
int maximo_amigos(int **cache, int **ruas, int n, int m, int i, int j);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int n_esquinas = n * m;
    int n_ruas = ((n - 1) * m) + ((m - 1) * n);

    int **ruas = aloca_matriz(n_esquinas, n_esquinas);
    for (int i = 0; i < n_ruas; i++)
    {
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        ruas[a][b] = x;
    }

    int **cache = aloca_matriz(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cache[i][j] = -1;
        }
    }

    int max_amigos = maximo_amigos(cache, ruas, n, m, 0, 0);
    printf("%d\n", max_amigos);

    desaloca_matriz(cache, n, m);
    desaloca_matriz(ruas, n_esquinas, n_esquinas);
}

int ** aloca_matriz(int n, int m)
{
    int **matriz = (int **) calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int *) calloc(m, sizeof(int));
    }
    return matriz;
}

void desaloca_matriz(int **matriz, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int posicao_eh_valida(int i, int j, int n, int m)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i >= n || j >= m)
    {
        return 0;
    }
    return 1;
}

int maximo_amigos(int **cache, int **ruas, int n, int m, int i, int j)
{
    if (cache[i][j] == -1)
    {
        if (!posicao_eh_valida(i, j, n, m))
        {
            return 0;
        }

        int mover_direita = 0;
        if (posicao_eh_valida(i, j + 1, n, m))
        {
            mover_direita = ruas[i * m + j][i * m + j + 1] + maximo_amigos(cache, ruas, n, m, i, j + 1);
        }

        int mover_baixo = 0;
        if (posicao_eh_valida(i + 1, j, n, m))
        {
            mover_baixo = ruas[i * m + j][i * m + j + m] + maximo_amigos(cache, ruas, n, m, i + 1, j);
        }   
        int ans = max(mover_direita, mover_baixo);
        cache[i][j] = ans;
        return ans;
    }
    return cache[i][j];
}