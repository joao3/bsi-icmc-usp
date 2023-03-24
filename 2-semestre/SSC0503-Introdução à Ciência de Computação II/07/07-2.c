#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *v, int e, int n);
void counting_sort(int *v, int k, int n, int expoente, int posicao);
int pegar_digito(int x, int expoente, int mascara, int posicao);
void imprimir_vetor(int *v, int n);
int maior_vetor(int *v, int n);

int main()
{
    int e, n;
    scanf("%d %d", &e, &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    radix_sort(v, e, n);
    free(v);
}

void radix_sort(int *v, int e, int n)
{
    int base = 1;
    for (int i = 0; i < e; i++)
    {
        base *= 2;
    }
    int passadas = 0;
    int x = maior_vetor(v, n);
    while (x > 0)
    {
        x /= base;
        passadas++;
    }
    for (int i = 0; i < passadas; i++)
    {
        counting_sort(v, base, n, e, i);
        imprimir_vetor(v, n);
    }
}

void counting_sort(int *v, int k, int n, int expoente, int posicao)
{
    int *contadores = (int *) malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        contadores[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int mascara = ((1 << expoente) - 1);
        contadores[pegar_digito(v[i], expoente, mascara, posicao)]++;
    }
    for (int i = 1; i < k; i++)
    {
        contadores[i] += contadores[i-1];
    }
    for (int i = k - 1; i > 0; i--)
    {
        contadores[i] = contadores[i - 1];
    }
    contadores[0] = 0;
    int *auxiliar = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int mascara = ((1 << expoente) - 1);
        auxiliar[contadores[pegar_digito(v[i], expoente, mascara, posicao)]] = v[i];
        contadores[pegar_digito(v[i], expoente, mascara, posicao)]++;
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = auxiliar[i];
    }
    free(contadores);
    free(auxiliar);
}

int pegar_digito(int x, int expoente, int mascara, int posicao)
{
    return ((x >> (posicao * expoente)) & mascara);
}

void imprimir_vetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int maior_vetor(int *v, int n)
{
    int maior = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > maior)
        {
            maior = v[i];
        }
    }
    return maior;
}