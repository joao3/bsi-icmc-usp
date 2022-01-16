#include <stdlib.h>

#include "../include/pilha.h"
#include "../include/baralho.h"


struct baralho_st
{
    PILHA *cartas;
    int tamanho_maximo;
};

BARALHO * baralho_criar()
{
    BARALHO *baralho = (BARALHO *) malloc(sizeof(BARALHO) * 1);
    if (baralho == NULL)
    {
        exit(-1);
    }
    baralho->cartas = pilha_criar();
    baralho->tamanho_maximo = BARALHO_TAMANHO_MAX;
    return baralho;
}

void baralho_inserir_carta(BARALHO *baralho, char naipe[], char nome[])
{
    if (!baralho_cheio(baralho))
    {
        CARTA *carta_nova = carta_criar();
        carta_definir(carta_nova, naipe, nome);
        pilha_empilhar(baralho->cartas, carta_nova);
    }
}

int baralho_pegar_tamanho_maximo(BARALHO *baralho)
{
    if (baralho != NULL)
    {
        return baralho->tamanho_maximo;
    }
    return BARALHO_ERRO;
}

int baralho_pegar_tamanho_atual(BARALHO *baralho)
{
    if (baralho != NULL)
    {
        return pilha_tamanho(baralho->cartas);
    }
    return BARALHO_ERRO;
}

boolean baralho_vazio(BARALHO *baralho)
{
    if (baralho != NULL)
    {
        return pilha_vazia(baralho->cartas);
    }
    return BARALHO_ERRO;
}

boolean baralho_cheio(BARALHO *baralho)
{
    if (baralho != NULL)
    {
        return pilha_tamanho(baralho->cartas) >= baralho->tamanho_maximo;
    }
    return BARALHO_ERRO;
}

CARTA * baralho_retirar_carta_topo(BARALHO *baralho)
{
    if (baralho != NULL)
    {
        return (CARTA *) pilha_desempilhar(baralho->cartas);
    }
    return NULL;
}

void baralho_excluir(BARALHO **baralho)
{
    if (*baralho != NULL)
    {
        while(!baralho_vazio(*baralho))
        {
            CARTA *carta = baralho_retirar_carta_topo(*baralho);
            carta_excluir(&carta);
        }
        pilha_apagar(&((*baralho)->cartas));
        free(*baralho);
        *baralho = NULL;
    }
}