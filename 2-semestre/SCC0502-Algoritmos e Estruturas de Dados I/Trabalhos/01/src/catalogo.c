#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/catalogo.h"
#include "../include/lista.h"

struct catalogo_st
{
    LISTA *jogos;
};

CATALOGO * catalogo_criar()
{
    CATALOGO *catalogo = (CATALOGO *) malloc(1 * sizeof(CATALOGO));
    if (catalogo == NULL)
    {
        exit(-1);
    }

    catalogo->jogos = lista_criar();

    return catalogo;
}

void catalogo_destruir(CATALOGO **catalogo)
{
    if (catalogo != NULL)
    {
        while (!lista_vazia((*catalogo)->jogos))
        {
            JOGO *jogo = (JOGO *) lista_pegar_dado_por_indice((*catalogo)->jogos, 0);
            jogo_destruir(&jogo);
            lista_excluir_node_por_indice((*catalogo)->jogos, 0);
        }
        lista_destruir(&((*catalogo)->jogos));
        free(*catalogo);
        *catalogo = NULL;
    }
}

void catalogo_inserir_jogo(CATALOGO *catalogo, JOGO *jogo)
{
    if (catalogo != NULL)
    {
        lista_inserir_fim(catalogo->jogos, jogo);
    }
}

int catalogo_tamanho(CATALOGO *catalogo)
{
    if (catalogo != NULL)
    {
        return lista_tamanho(catalogo->jogos);
    }
    return ERRO_LISTA;
}

void catalogo_remover_jogos_repetidos(CATALOGO *catalogo)
{
    for (int i = 0; i < catalogo_tamanho(catalogo); i++)
    {
        JOGO *jogo1 = (JOGO *) lista_pegar_dado_por_indice(catalogo->jogos, i);
        char *nome_jogo1 = jogo_pegar_nome(jogo1);
        for (int j = i + 1; j < catalogo_tamanho(catalogo); j++)
        {
            JOGO *jogo2 = (JOGO *) lista_pegar_dado_por_indice(catalogo->jogos, j);
            char *nome_jogo2 = jogo_pegar_nome(jogo2);
            if (strcmp(nome_jogo1, nome_jogo2) == 0)
            {
                catalogo_remover_jogo_por_indice(catalogo, j);
            }
        }
    }
}

void catalogo_imprimir_jogos_de_produtora(CATALOGO *catalogo, char *produtora_buscada)
{
    if (catalogo != NULL)
    {
        for (int i = 0; i < catalogo_tamanho(catalogo); i++)
        {
            JOGO *jogo = (JOGO *) lista_pegar_dado_por_indice(catalogo->jogos, i);
            char *nome_jogo = jogo_pegar_nome(jogo);
            char *produtora_jogo = jogo_pegar_produtora(jogo);
            if (strcmp((produtora_jogo), produtora_buscada) == 0)
            {
                printf("%s\n", nome_jogo);
            }
        }
    }
}

void catalogo_imprimir_jogos_de_ano(CATALOGO *catalogo, int ano_buscado)
{
    if (catalogo != NULL)
    {
        for (int i = 0; i < catalogo_tamanho(catalogo); i++)
        {
            JOGO *jogo = (JOGO *) lista_pegar_dado_por_indice(catalogo->jogos, i);
            int ano_jogo = jogo_pegar_ano(jogo);
            if (ano_jogo == ano_buscado)
            {
                printf("%s\n", jogo_pegar_nome(jogo));
            }
        }
    }
}

void catalogo_imprimir_todos_jogos(CATALOGO *catalogo)
{
    if (catalogo != NULL)
    {
        for (int i = 0; i < catalogo_tamanho(catalogo); i++)
        {
            JOGO *jogo = (JOGO *) lista_pegar_dado_por_indice(catalogo->jogos, i);
            char *nome = jogo_pegar_nome(jogo);
            printf("%s\n", nome);
        }
    }
}

void catalogo_imprimir_jogo_por_indice(CATALOGO *catalogo, int indice)
{
    JOGO *jogo = (JOGO *) lista_pegar_dado_por_indice(catalogo->jogos, indice);
    printf("%s\n", jogo_pegar_nome(jogo));
}

void catalogo_remover_jogo_por_indice(CATALOGO *catalogo, int indice)
{
    if (catalogo != NULL)
    {
        JOGO *jogo = (JOGO *) lista_pegar_dado_por_indice(catalogo->jogos, indice);
        jogo_destruir(&jogo);
        lista_excluir_node_por_indice(catalogo->jogos, indice);
    }
}

void catalogo_mover_jogo_n_posicoes_direita(CATALOGO *catalogo, int indice, int n)
{
    if (catalogo != NULL)
    {
        lista_mover_node_n_posicoes(catalogo->jogos, indice, n);
    }
}

void catalogo_mover_jogo_n_posicoes_esquerda(CATALOGO *catalogo, int indice, int n)
{
    if (catalogo != NULL)
    {
        n *= -1;
        lista_mover_node_n_posicoes(catalogo->jogos, indice, n);
    }
}