#include "quick.h"

static void quick_recursao(int *v, int c, int f);

void quick_sort(int *v, int n)
{
    quick_recursao(v, 0, n - 1);
}

static void quick_recursao(int *v, int c, int f)
{
    if (c >= f)
    {
        return;
    }
    int m = (c + f) / 2;
    int pivot = v[m];
    int i = c;
    int j = f;
    while (1)
    {
        while (v[i] < pivot)
        {
            i++;
        }
        while (v[j] > pivot)
        {
            j--;
        }
        if (j <= i)
        {
            break;
        }
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
    quick_recursao(v, c, j);
    quick_recursao(v, j + 1, f);
}