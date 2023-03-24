#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "jogo.h"

struct jogo_st
{
    char nome[NOME_TAMANHO_MAX];
    char produtora[NOME_TAMANHO_MAX];
    int ano;
};

JOGO * jogo_criar()
{
    JOGO *jogo = (JOGO *) malloc(sizeof(JOGO) * 1);
    if (jogo == NULL)
    {
        exit(-1);
    }
    return jogo;
}

void jogo_realocar_vetor(JOGO ***jogos, int quantidade_jogos)
{
    *jogos = (JOGO **) realloc(*jogos, sizeof(JOGO *) * (quantidade_jogos + 1));
    if (*jogos == NULL)
    {
        exit(-1);
    }
    (*jogos)[quantidade_jogos] = jogo_criar();
}

void jogo_inserir_no_vetor(JOGO **jogos, int i, char nome[], char produtora[], int ano)
{
    jogo_definir(jogos[i], nome, produtora, ano);
}

void jogo_definir(JOGO *jogo, char nome[], char produtora[], int ano)
{
    if (jogo != NULL)
    {
        strcpy(jogo->nome, nome);
        strcpy(jogo->produtora, produtora);
        jogo->ano = ano;
    }
}

void jogo_buscar_por_ano_no_vetor(JOGO **jogos, int tamanho_catalogo)
{
    int achou= 0;
    int ano_buscado;
    scanf("%d\n", &ano_buscado);
    for (int i = 0; i < tamanho_catalogo; i++)
    {
        if (jogos[i]->ano == ano_buscado)
        {
            printf("%s\n", jogos[i]->nome);
            achou = 1;
        }
    }
    if (!achou)
    {
        printf("Nada encontrado\n");
    }
}

void jogo_buscar_por_produtora_no_vetor(JOGO **jogos, int tamanho_catalogo)
{
    int achou = 0;
    char produtora_buscada[NOME_TAMANHO_MAX];
    scanf(" %[^(\r|\n)]", produtora_buscada);
    for (int i = 0; i < tamanho_catalogo; i++)
    {
        if (strcmp(jogos[i]->produtora, produtora_buscada) == 0)
        {
            printf("%s\n", jogos[i]->nome);
            achou = 1;
        }
    }
    if (!achou)
    {
        printf("Nada encontrado\n");
    }
}

void jogo_excluir_vetor(JOGO ***jogos, int tamanho_vetor)
{
    if (*jogos != NULL)
    {
        for (int i = 0; i < tamanho_vetor; i++)
        {
            jogo_excluir(&((*jogos)[i]));
        }
        free(*jogos);
        *jogos = NULL;
    }
}

void jogo_excluir(JOGO **jogo)
{
    if (*jogo != NULL)
    {
        free(*jogo);
        *jogo = NULL;
    }
}