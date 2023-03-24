#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "quick.h"
#include "ponto.h"

float distancia(ponto a, ponto b);
float min(float a, float b);
float menor_distancia(ponto *pontos, int n);
float menor_distancia_recursao(ponto *pontos, int c, int f);
float solucao_quadratica(ponto *pontos, int c, int f);

int main()
{
    int n;
    scanf("%d", &n);
    ponto *pontos = (ponto *) malloc(n * sizeof(ponto));
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &pontos[i].x, &pontos[i].y);
    }
    quick_sort(pontos, n);
    printf("%.6f\n", menor_distancia(pontos, n));
    free(pontos);
}

float distancia(ponto a, ponto b)
{
    return sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}

float min(float a, float b)
{
    return (a < b) ? a : b;
}

float menor_distancia(ponto *pontos, int n)
{
    if (n == 1)
        return 0;
    return menor_distancia_recursao(pontos, 0, n - 1);
}

float menor_distancia_recursao(ponto *pontos, int c, int f)
{
    if (c == f)
        printf("AQUI");
    if (f - c <= 2)
    {
        return solucao_quadratica(pontos, c, f);
    }
    int m = (c + f) / 2;
    float de = menor_distancia_recursao(pontos, c, m);
    float dd = menor_distancia_recursao(pontos, m + 1, f);
    float d = min(de, dd);

    int indice = 0;
    ponto aux[f-c+1];
    for (int i = c; i <= f; i++)
    {
        if (fabs(pontos[i].x - pontos[m].x) < d)
        {
            aux[indice] = pontos[i];
            indice++;
        }
    }
    for (int i = 0; i < indice; i++)
    {
        for (int j = i + 1; j < indice; j++)
        {
            float dist = distancia(aux[i], aux[j]);
            if (dist < d)
            {
                d = dist;
            }
        }
    }

    return d;
}

float solucao_quadratica(ponto *pontos, int c, int f)
{
    float menor;
    for (int i = c; i <= f; i++)
    {
        for (int j = i + 1; j <= f; j++)
        {
            float dist = distancia(pontos[i], pontos[j]);
            if ((i == c && j == c + 1) || dist < menor)
            {
                menor = dist;
            }
        }
    }
    return menor;
}