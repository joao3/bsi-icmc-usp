#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

typedef struct node_st NODE;

struct node_st
{
    void *dado;
    NODE *proximo;
};

struct lista_st
{
    NODE *inicio;
    NODE *fim;
    int tamanho;
};

LISTA * lista_criar()
{
    LISTA *lista = (LISTA *) calloc(1, sizeof(LISTA));
    if (lista == NULL)
    {
        exit(-1);
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

void lista_destruir(LISTA **lista)
{
    if (*lista != NULL && lista_vazia(*lista))
    {
        free(*lista);
        *lista = NULL;
    }
}

NODE * node_criar()
{
    NODE *node = (NODE *) calloc(1, sizeof(NODE));
    if (node == NULL)
    {
        exit(-1);
    }
    return node;
}

void node_destruir(NODE **node)
{
    if (*node != NULL)
    {
        free(*node);
        *node = NULL;
    }
}

boolean lista_vazia(LISTA *lista)
{
    if (lista != NULL)
    {
        return lista->inicio == NULL;
    }
    return ERRO;
}

int lista_tamanho(LISTA *lista)
{
    if(lista != NULL)
    {
        return lista->tamanho;
    }
    return ERRO;
}

void lista_inserir_fim(LISTA *lista, void *dado)
{
    if (lista != NULL)
    {
        NODE *novo_node = node_criar();
        novo_node->dado = dado;
        novo_node->proximo = NULL;
        if (lista_vazia(lista))
        {
            lista->inicio = novo_node;
        }
        else
        {
            lista->fim->proximo = novo_node;
        }
        lista->fim = novo_node;
        lista->tamanho++;
    }
}

void lista_inserir_inicio(LISTA *lista, void *dado)
{
    if (lista != NULL)
    {
        NODE *novo_node = node_criar();
        novo_node->dado = dado;
        novo_node->proximo = lista->inicio;
        if (lista_vazia(lista))
        {
            lista->fim = novo_node;
        }
        lista->inicio = novo_node;
        lista->tamanho++;
    }
}

void * lista_pegar_enesimo_dado(LISTA *lista, int n)
{
    if (lista != NULL)
    {
        if (n > lista->tamanho || n <= 0)
        {
            printf("n invalido\n");
            return NULL;
        }
        int percorridos = 0;
        NODE *node_atual = lista->inicio;
        while (node_atual != NULL)
        {
            percorridos++;
            if (percorridos == n)
            {
                return node_atual->dado;
            }
            node_atual = node_atual->proximo;
        }
    }
    return NULL;
}

void lista_remover_enesimo_node(LISTA *lista, int n)
{
    if (lista != NULL)
    {
        if (n > lista->tamanho || n <= 0)
        {
            printf("n invalido\n");
        }
        int percorridos = 1;
        NODE *node_atual = lista->inicio;
        NODE *node_anterior = NULL;
        while (node_atual != NULL && percorridos != n)
        {
            percorridos++;
            node_anterior = node_atual;
            node_atual = node_atual->proximo;
        }
        if (node_atual != NULL)
        {
            if (node_atual == lista->inicio)
            {
                lista->inicio = node_atual->proximo;
                node_atual->proximo = NULL;
            }
            else
            {
                node_anterior->proximo = node_atual->proximo;
                node_atual->proximo = NULL;
            }
            if (lista->fim == node_atual)
            {
                lista->fim = node_anterior;
            }
            node_destruir(&node_atual);
        }
    }
}