#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../jogo/jogo.h"
#include "../util/utilString.h"

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

    jogo->nome = NULL;
    jogo->produtora = NULL;

    return jogo;
}

void jogo_definir_nome(JOGO *jogo, char *nome)
{
    if (jogo != NULL)
    {
        jogo->nome = string_criar(strlen(nome) + 1);
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
        jogo->produtora = string_criar(strlen(produtora) + 1);
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

void jogo_destruir(void **jogo)
{
    if (*jogo != NULL)
    {
        JOGO **jogo_cast = (JOGO **) jogo;
        string_destruir(&((*jogo_cast)->produtora));
        string_destruir(&((*jogo_cast)->nome));
        free(*jogo_cast);
        *jogo_cast = NULL;
    }
}

void jogo_imprimir_nome(void *jogo)
{
    JOGO *jogo_cast = (JOGO *) jogo;
    printf("%s\n", jogo_cast->nome);
}

boolean jogo_ano_eh_igual(void *jogo1, void *jogo2)
{
    JOGO *jogo1_cast = (JOGO *) jogo1;
    JOGO *jogo2_cast = (JOGO *) jogo2;
    if (jogo1_cast->ano == jogo2_cast->ano)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

boolean jogo_ano_eh_igual_campo(void *jogo1, void *ano)
{
    JOGO *jogo1_cast = (JOGO *) jogo1;
    int *ano_cast = (int *) ano;
    if (jogo1_cast->ano == *ano_cast)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

boolean jogo_ano_eh_maior(void *jogo1, void *jogo2)
{
    JOGO *jogo1_cast = (JOGO *) jogo1;
    JOGO *jogo2_cast = (JOGO *) jogo2;
    if (jogo1_cast->ano > jogo2_cast->ano)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

boolean jogo_ano_eh_maior_campo(void *jogo1, void *ano)
{
    JOGO *jogo1_cast = (JOGO *) jogo1;
    int *ano_cast = (int *) ano;
    if (jogo1_cast->ano > *ano_cast)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

boolean jogo_nome_eh_maior(JOGO *jogo1, JOGO *jogo2)
{
    if (strcmp(jogo1->nome, jogo2->nome) > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

boolean jogo_chave_eh_maior(void *jogo1, void *jogo2)
{
    JOGO *jogo1_cast = (JOGO *) jogo1;
    JOGO *jogo2_cast = (JOGO *) jogo2;
    if (jogo1_cast->ano > jogo2_cast->ano)
    {
        return TRUE;
    }
    else if (jogo1_cast->ano < jogo2_cast->ano)
    {
        return FALSE;
    }
    else
    {
        return jogo_nome_eh_maior(jogo1_cast, jogo2_cast);
    }
}

