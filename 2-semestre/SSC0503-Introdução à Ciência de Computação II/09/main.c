#include <stdio.h>
#include <stdlib.h>

#include "quick.h"

int busca_linear(int *v, int n, int x);
int busca_binaria(int *v, int n, int x);

int main()
{
    int n;
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    int k;
    scanf("%d", &k);

    int logn = 0;
    int x = n;
    while (x > 0)
    {
        x /= 2;
        logn++;
    }
    
    if (k >= logn)
    {
        quick_sort(v, n);
        for (int i = 0; i < k; i++)
        {
            int x;
            scanf("%d", &x);
            int achou = busca_binaria(v, n, x);
            printf("%d\n", achou);
        }
    }
    else
    {
        v = realloc(v, (n + 1) * sizeof(int));
       for (int i = 0; i < k; i++)
        {
            int x;
            scanf("%d", &x);
            int achou = busca_linear(v, n, x);
            printf("%d\n", achou);
        } 
    }
    free(v);
}

int busca_linear(int *v, int n, int x)
{
    v[n] = x;
    int i = 0;
    while (v[i] != x)
    {
        i++;
    }
    if (i < n)
    {
        return 1;
    }
    return 0;
}

int busca_binaria(int *v, int n, int x)
{
    int c = 0;
    int f = n - 1;
    while (c <= f)
    {
        int m = (c + f) / 2;
        if (v[m] == x)
        {
            return 1;
        }
        if (v[m] < x)
        {
            c = m + 1;
        }
        else
        {
            f = m - 1;
        }
    }
    return 0;
}