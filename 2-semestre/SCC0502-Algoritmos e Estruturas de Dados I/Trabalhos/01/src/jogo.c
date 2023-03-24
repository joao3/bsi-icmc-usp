#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/jogo.h"
#include "../include/util.h"

struct jogo_st
{
    char *nome;
    int ano;
    char *produtora;
};

JOGO * jogo_criar()
{
    JOGO *jogo = (JOGO *) malloc(1 * sizeof(JOGO));
    if (jogo == NULL)
    {
        exit(-1);
    }

    jogo->nome = string_criar(TAM_MAX_STRING);
    jogo->produtora = string_criar(TAM_MAX_STRING);

    return jogo;
}

void jogo_definir_nome(JOGO *jogo, char *nome)
{
    if (jogo != NULL)
    {
        strcpy(jogo->nome, nome);
    }
}

void jogo_definir_ano(JOGO *jogo, int ano)
{
    if (jogo != NULL)
    {
        jogo->ano = ano;
    }
}

void jogo_definir_produtora(JOGO *jogo, char *produtora)
{
    if (jogo != NULL)
    {
        strcpy(jogo->produtora, produtora);
    }
}

char * jogo_pegar_nome(JOGO *jogo)
{
    if (jogo != NULL)
    {
        return jogo->nome;
    }
    return NULL;
}

char * jogo_pegar_produtora(JOGO *jogo)
{
    if (jogo != NULL)
    {
        return jogo->produtora;
    }
    return NULL;
}

int jogo_pegar_ano(JOGO *jogo)
{
    if (jogo != NULL)
    {
        return jogo->ano;
    }
    return ERRO_JOGO;
}

void jogo_destruir(JOGO **jogo)
{
    if (*jogo != NULL)
    {
        string_destruir(&((*jogo)->produtora));
        string_destruir(&((*jogo)->nome));
        free(*jogo);
        *jogo = NULL;
    }
}