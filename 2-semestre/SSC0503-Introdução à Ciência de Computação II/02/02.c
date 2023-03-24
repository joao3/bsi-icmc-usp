#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int v[], int n)
{
    int t = 0, c = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = v[i];
        t++;
        while (j >= 0 && v[j] > x)
        {
            c++;
            v[j + 1] = v[j];
            t++;
            j--;
        }
        if (j >= 0)
        {
            c++;
        }
        v[j + 1] = x;
        t++;
    }
    printf("I %d %d %d\n", n, t, c);
}

void merge(int v[], int a[], int e1, int d1, int e2, int d2, int *t, int *c)
{
    int i1 = e1;
    int i2 = e2;
    int j = 0;
    while (i1 <= d1 && i2 <= d2)
    {
        if (v[i1] <= v[i2])
        {
            a[j] = v[i1];
            (*t)++;
            i1++;
            j++;
        }
        else
        {
            a[j] = v[i2];
            (*t)++;
            i2++;
            j++;
        }
        (*c)++;
    }

    while (i1 <= d1)
    {
        a[j] = v[i1];
        (*t)++;
        j++;
        i1++;
    }
    while (i2 <= d2)
    {
        a[j] = v[i2];
        (*t)++;
        j++;
        i2++;
    }

    j = 0;
    for (int i = e1; i <= d2; i++, j++)
    {
        v[i] = a[j]; 
        (*t)++;
    }
}

void merge_(int v[], int a[], int e, int d, int *t, int *c)
{
    if (e >= d)
    {
        return;
    }
    int m = (e + d) / 2;
    merge_(v, a, e, m, t, c);
    merge_(v, a, m + 1, d, t, c);

    merge(v, a, e, m, m + 1, d, t, c);
}

void merge_sort(int v[], int n)
{
    int t = 0, c = 0;
    int *a = (int *) malloc(sizeof(int) * n);
    merge_(v, a, 0, n - 1, &t, &c);

    printf("M %d %d %d\n", n, t, c);

    free(a);
}

int main()
{
    int q;
    scanf("%d", &q);
    int *n = (int *) malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &n[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int *v1 = (int *) malloc(sizeof(int) * n[i]);
        int *v2 = (int *) malloc(sizeof(int) * n[i]);
        for (int j = 0; j < n[i]; j++)
        {
            scanf("%d", &v1[j]);
        }
        for (int j = 0; j < n[i]; j++)
        {
            v2[j] = v1[j];
        }
        insertion_sort(v1, n[i]);
        merge_sort(v2, n[i]);
        free(v1);
        free(v2);
    }
    free(n);
}