#include <stdio.h>
#include <stdlib.h>

void tabela_inserir(int *tabela, int m, int x);
int tabela_buscar(int *tabela, int m, int x);
void tabela_remover(int *tabela, int m, int x);
int hash(int x, int m);

int main()
{
    int m;
    scanf("%d", &m);
    int *tabela = (int *) malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        tabela[i] = -1;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        tabela_inserir(tabela, m, x);
    }
    int d;
    scanf("%d", &d);
    for (int i = 0; i < d; i++)
    {
        int x;
        scanf("%d", &x);
        tabela_remover(tabela, m, x);
    }
    int b;
    scanf("%d", &b);
    for (int i = 0; i < b; i++)
    {
        int x;
        scanf("%d", &x);
        int posicao = tabela_buscar(tabela, m, x);
        printf("%d ", posicao);
    }

    free(tabela);
}

void tabela_inserir(int *tabela, int m, int x)
{   
    int chave;
    int i = 0;
    do
    {
        chave = hash(x + i, m);
        if (tabela[chave] == x)
        {
            break;
        }
        i++;
    } while (tabela[chave] >= 0);

    tabela[chave] = x;
}

int tabela_buscar(int *tabela, int m, int x)
{
    int chave;
    int i = 0, chamadas = 0;
    do
    {
        chave = hash(x + i, m);
        if (tabela[chave] == x)
        {
            return chave;
        }
        if (tabela[chave] == -1)
        {
            return -1;
        }
        i++;
        chamadas++;
    } while (chamadas <= m);
    return -1;
}

void tabela_remover(int *tabela, int m, int x)
{
    int i = tabela_buscar(tabela, m, x);
    if (i != -1)
    {
        tabela[i] = -2;
    }
}

int hash(int x, int m)
{
    return x % m;
}