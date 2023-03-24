#include "quick.h"

static void quick_recursao(ponto *v, int c, int f);

void quick_sort(ponto *v, int n)
{
    quick_recursao(v, 0, n - 1);
}

static void quick_recursao(ponto *v, int c, int f)
{
    if (c >= f)
    {
        return;
    }
    int m = (c + f) / 2;
    float pivot = v[m].x;
    int i = c;
    int j = f;
    while (1)
    {
        while (v[i].x < pivot)
        {
            i++;
        }
        while (v[j].x > pivot)
        {
            j--;
        }
        if (j <= i)
        {
            break;
        }
        ponto temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
    quick_recursao(v, c, j);
    quick_recursao(v, j + 1, f);
}