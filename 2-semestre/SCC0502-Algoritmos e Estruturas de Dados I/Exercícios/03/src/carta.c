#include <stdlib.h>
#include <string.h>

#include "../include/carta.h"

struct carta_st
{
    char naipe[TAMANHO_NAIPE];
    char nome[TAMANHO_NOME];
};

CARTA * carta_criar()
{
    CARTA *carta = (CARTA *) malloc(sizeof(CARTA) * 1);
    if (carta == NULL)
    {
        exit(-1);
    }
    return carta;
}

void carta_definir(CARTA *carta, char naipe[], char nome[])
{
    if (carta != NULL)
    {
        strcpy(carta->naipe, naipe);
        strcpy(carta->nome, nome);
    }
}

char * carta_pegar_naipe(CARTA *carta)
{
    if (carta != NULL)
    {
        return carta->naipe;
    }
    return NULL;
}

char * carta_pegar_nome(CARTA *carta)
{
    if (carta != NULL)
    {
        return carta->nome;
    }
    return NULL;
}


void carta_excluir(CARTA **carta)
{
    if (*carta != NULL)
    {
        free(*carta);
        *carta = NULL;
    }
}