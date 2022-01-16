#include <stdio.h>
#include <stdlib.h>

void counting(int *v, int k, int n);

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    counting(v, k, n);
    free(v);
}

void counting(int *v, int k, int n)
{
    int *contadores = (int *) malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        contadores[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        contadores[v[i]]++;
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
        printf("%d %d\n", v[i], contadores[v[i]]);
        auxiliar[contadores[v[i]]] = v[i];
        contadores[v[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = auxiliar[i];
    }
    free(contadores);
    free(auxiliar);
}