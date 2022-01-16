#include <stdlib.h>
#include <stdio.h>

#include "../includes/lista.h"

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
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA) * 1);
    if (lista == NULL)
    {
        exit(-1);
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
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

void lista_inserir(LISTA *lista, void *dado)
{
    if (lista != NULL)
    {
        NODE *novo_node = (NODE *) malloc(sizeof(NODE));
        if (novo_node == NULL)
        {
            exit(-1);
        }
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

void print(LISTA *lista)
{
    NODE *node_atual = lista->inicio;
    while (node_atual != NULL)
    {
        int *num = (int *) (node_atual->dado);
        printf("%d ", *num);
        node_atual = node_atual->proximo;
    }
}

void * lista_pegar_enesimo_dado(LISTA *lista, int n)
{
    if (lista != NULL)
    {
        if (n > lista->tamanho)
        {
            int contador = 0;
            NODE *node_atual = lista->inicio;
            while (node_atual != NULL)
            {
                contador++;
                if (contador == n)
                {
                    return node_atual->dado;
                }
                node_atual = node_atual->proximo;
            }
        }
    }
    return NULL;
}