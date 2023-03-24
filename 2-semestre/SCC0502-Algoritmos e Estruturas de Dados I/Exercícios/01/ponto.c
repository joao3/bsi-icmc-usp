#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ponto.h"

struct ponto_st
{
    float x, y;
};

PONTO *aloca_pontos(int quantidade_pontos)
{
    PONTO *pontos = (PONTO *)malloc(sizeof(PONTO) * quantidade_pontos);
    if (pontos == NULL)
    {
        exit(-1);
    }

    return pontos;
}

void le_ponto(PONTO *pontos, int i)
{
    scanf("%f %f", &pontos[i].x, &pontos[i].y);
}

float calcula_distancia_pontos(PONTO *pontos, int i)
{
    float x1, y1, x2, y2;
    x1 = pontos[i].x;
    y1 = pontos[i].y;
    x2 = pontos[i + 1].x;
    y2 = pontos[i + 1].y;

    float distancia_pontos;
    distancia_pontos = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    return distancia_pontos;
}

void desaloca_pontos(PONTO *pontos)
{
    free(pontos);
}