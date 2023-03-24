#include <stdlib.h>

#include "../include/pilha.h"

typedef struct node_st NODE;

struct node_st
{
    void *dado;
    NODE *anterior;
};

struct pilha_st
{
    NODE *topo;
    int tamanho;
};

PILHA * pilha_criar()
{
    PILHA *pilha = (PILHA *) malloc(sizeof(PILHA) * 1);
    if (pilha == NULL)
    {
        exit(-1);
    }
    pilha->tamanho = 0;
    pilha->topo = NULL;
    return pilha;
}

void pilha_apagar(PILHA **pilha)
{
    if ((*pilha != NULL) && (pilha_vazia(*pilha)))
    {
        free(*pilha);
        *pilha = NULL;
    }
}

boolean pilha_vazia(PILHA *pilha)
{
    if (pilha != NULL)
    {
        return pilha->tamanho <= 0;
    }
    return PILHA_ERRO;
}

int pilha_tamanho(PILHA *pilha)
{
    if (pilha != NULL)
    {
        return pilha->tamanho;
    }
    return PILHA_ERRO;
}

void * pilha_topo(PILHA *pilha)
{
    if ((pilha != NULL) && (!pilha_vazia(pilha)))
    {
        return pilha->topo->dado;
    }
    return NULL;
}

void pilha_empilhar(PILHA *pilha, void *dado)
{
    if (pilha != NULL)
    {
        NODE *novo_node = malloc(sizeof(NODE) * 1);
        novo_node->anterior = pilha->topo;
        novo_node->dado = dado;
        pilha->topo = novo_node;
        pilha->tamanho++;
    }
}

void * pilha_desempilhar(PILHA *pilha)
{
    if ((pilha != NULL) && (!pilha_vazia(pilha)))
    {
        NODE *desempilhado = pilha->topo;
        void *dado = pilha->topo->dado;
        pilha->topo = pilha->topo->anterior;
        desempilhado->anterior = NULL;
        free(desempilhado);
        desempilhado = NULL;
        pilha->tamanho--;
        return dado;
    }
    return NULL;
}