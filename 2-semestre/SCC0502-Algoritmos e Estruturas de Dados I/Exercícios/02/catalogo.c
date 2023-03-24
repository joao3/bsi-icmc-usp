#include <stdlib.h>

#include "jogo.h"
#include "catalogo.h"

struct catalogo_st
{
    JOGO **jogos;
    int tamanho_catalogo;
};

CATALOGO * catalogo_criar()
{
    CATALOGO *catalogo = (CATALOGO *) malloc(sizeof(CATALOGO) * 1);
    if (catalogo == NULL)
    {
        exit(-1);
    }
    catalogo->tamanho_catalogo = 0;
    catalogo->jogos = NULL;
    return catalogo;
}

void catalogo_inserir_jogo(CATALOGO *catalogo, char nome[], char produtora[], int ano)
{

    jogo_realocar_vetor(&catalogo->jogos, catalogo->tamanho_catalogo);
    jogo_inserir_no_vetor(catalogo->jogos, catalogo->tamanho_catalogo, nome, produtora, ano);
    catalogo->tamanho_catalogo++;
}

void catalogo_buscas(CATALOGO *catalogo, char operacao)
{
        if (operacao == 'A')
        {
            jogo_buscar_por_ano_no_vetor(catalogo->jogos, catalogo->tamanho_catalogo);
        }
        else if (operacao == 'E')
        {
            jogo_buscar_por_produtora_no_vetor(catalogo->jogos, catalogo->tamanho_catalogo);
        }
}

void catalogo_excluir(CATALOGO **catalogo)
{
    if (*catalogo != NULL)
    {
        jogo_excluir_vetor(&(*catalogo)->jogos, (*catalogo)->tamanho_catalogo);
        free(*catalogo);
        *catalogo = NULL;
    }
}