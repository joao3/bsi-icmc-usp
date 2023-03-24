#include <stdlib.h>
#include <stdio.h>

#include "ponto.h"
#include "caminho.h"

struct caminho_st
{
    int quantidade_pontos;
    PONTO *pontos;
};

CAMINHO * cria_caminho()
{
    CAMINHO *caminho = (CAMINHO *) malloc(sizeof(CAMINHO) * 1);
    if (caminho == NULL) 
    {
        exit(-1);
    }

    scanf("%d", &caminho->quantidade_pontos);

    caminho->pontos = aloca_pontos(caminho->quantidade_pontos);

    return caminho;
}

void le_caminho(CAMINHO *caminho)
{
    for (int i = 0; i < caminho->quantidade_pontos; i++)
    {
        le_ponto(caminho->pontos, i);
    }
}

float calcula_distancia_total(CAMINHO *caminho)
{
    float distancia_total = 0;
    for (int i = 0; i < caminho->quantidade_pontos - 1; i++) 
    {
        distancia_total += calcula_distancia_pontos(caminho->pontos, i);
    }
    return distancia_total;
}

void exclui_caminho(CAMINHO *caminho)
{
    desaloca_pontos(caminho->pontos);
    free(caminho);
}
