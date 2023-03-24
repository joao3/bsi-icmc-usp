#include <stdlib.h>

#include "../include/lista.h"

typedef struct node_st NODE;

struct node_st
{
    void *dado;
    NODE *anterior;
    NODE *proximo;
};

struct lista_st
{
    NODE *fim;
    int tamanho;
};

NODE * node_criar();
void node_destruir(NODE **node);
NODE * lista_pegar_node_por_indice(LISTA *lista, int indice);
NODE * lista_retirar_node_por_indice(LISTA *lista, int indice);

LISTA * lista_criar()
{
    LISTA *lista = (LISTA *) malloc(1 * sizeof(LISTA));
    if (lista == NULL)
    {
        exit(-1);
    }

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

boolean lista_vazia(LISTA *lista)
{
    if (lista != NULL)
    {
        return lista->tamanho <= 0;
    }
    return ERRO_LISTA;
}

void lista_inserir_fim(LISTA *lista, void *dado)
{
    if (lista != NULL)
    {
        NODE *node_novo = node_criar();
        node_novo->dado = dado;

        if (lista_vazia(lista))
        {
            node_novo->proximo = node_novo;
            node_novo->anterior = node_novo;
        }
        else
        {
            node_novo->proximo = lista->fim->proximo;
            node_novo->anterior = lista->fim;
            lista->fim->proximo->anterior = node_novo;
            lista->fim->proximo = node_novo;
        }

        lista->fim = node_novo;
        lista->tamanho++;
    }
}

int lista_tamanho(LISTA *lista)
{
    if (lista != NULL)
    {
        return lista->tamanho;
    }
    return ERRO_LISTA;
}

void * lista_pegar_dado_por_indice(LISTA *lista, int indice)
{
    if (lista != NULL && indice >= 0)
    {
        NODE *node = lista_pegar_node_por_indice(lista, indice);
        return node->dado;
    }
    return NULL;
}

void lista_excluir_node_por_indice(LISTA *lista, int indice)
{
    if (lista != NULL && indice >= 0)
    {
        NODE *node = lista_retirar_node_por_indice(lista, indice);
        node_destruir(&node);
    }
}

void lista_mover_node_n_posicoes(LISTA *lista, int indice, int n)
{
    if (lista != NULL && n != 0)
    {
        NODE *node = lista_pegar_node_por_indice(lista, indice + n);
        NODE *node_retirado = lista_retirar_node_por_indice(lista, indice);

        node_retirado->anterior = node;
        node_retirado->proximo = node->proximo;
        node->proximo->anterior = node_retirado;
        node->proximo = node_retirado;
        if (lista->fim == node)
        {
            lista->fim = node_retirado;
        }
        lista->tamanho++;
    }
}

// Funções internas

NODE * node_criar()
{
    NODE *node = (NODE *) malloc(1 * sizeof(NODE));
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

NODE * lista_pegar_node_por_indice(LISTA *lista, int indice)
{
    if (lista != NULL)
    {
        NODE *node_atual = lista->fim->proximo;
        int i = 0;
        if (indice >= 0)
        {
            while (i < indice)
            {
                node_atual = node_atual->proximo;
                i++;
            }
        }
        else
        {
            while (i > indice)
            {
                node_atual = node_atual->anterior;
                i--;
            }
        }
        return node_atual;
    }
    return NULL;
}

NODE * lista_retirar_node_por_indice(LISTA *lista, int indice)
{
    if (lista != NULL && indice >= 0)
    {
        NODE *node = lista_pegar_node_por_indice(lista, indice);
        if (lista->fim == node)
        {
            lista->fim = node->anterior;
        }
        node->anterior->proximo = node->proximo;
        node->proximo->anterior = node->anterior;
        lista->tamanho--;
        return node;
    }
    return NULL;
}