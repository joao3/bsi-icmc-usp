#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../catalogo/catalogo.h"
#include "../arvoreAVL/arvoreAVL.h"

struct catalogo_st
{
    ARVORE_AVL *jogos;
    int quantidade_jogos;
};

CATALOGO * catalogo_criar()
{
    CATALOGO *catalogo = (CATALOGO *) malloc(1 * sizeof(CATALOGO));
    if (catalogo == NULL)
    {
        exit(-1);
    }
    catalogo->jogos = arvore_avl_criar();
    catalogo->quantidade_jogos = 0;
    return catalogo;
}

void catalogo_destruir(CATALOGO **catalogo)
{
    if (*catalogo != NULL)
    {
        arvore_avl_destruir(&((*catalogo)->jogos), &jogo_destruir);
        free(*catalogo);
        *catalogo = NULL;
    }
}

void catalogo_inserir_jogo(CATALOGO *catalogo, JOGO *jogo)
{
    if (catalogo != NULL && jogo != NULL)
    {
        if (catalogo->quantidade_jogos == 0)
        {
            arvore_avl_inserir_raiz(catalogo->jogos, jogo);
        }
        else
        {
            arvore_avl_inserir(catalogo->jogos, jogo, &jogo_chave_eh_maior);
        }
        catalogo->quantidade_jogos++;
    }
}

void catalogo_remover_jogo_por_ano(CATALOGO *catalogo, int *ano)
{
    if (catalogo != NULL && ano != NULL)
    {
        int removeu = 1;
        while (removeu)
        {
            removeu = arvore_avl_remover(catalogo->jogos, ano, &jogo_ano_eh_igual_campo, &jogo_ano_eh_maior_campo, jogo_destruir);
        }
    }
}

void catalogo_imprimir_nomes_preordem(CATALOGO *catalogo)
{
    if (catalogo != NULL)
    {
        arvore_avl_preordem(catalogo->jogos, &jogo_imprimir_nome);
    }
}

void catalogo_imprimir_nomes_emordem(CATALOGO *catalogo)
{
    if (catalogo != NULL)
    {
        arvore_avl_emordem(catalogo->jogos, &jogo_imprimir_nome);
    }
}

void catalogo_imprimir_nomes_posordem(CATALOGO *catalogo)
{
    if (catalogo != NULL)
    {
        arvore_avl_posordem(catalogo->jogos, &jogo_imprimir_nome);
    }
}