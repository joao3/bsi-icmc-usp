#include <stdlib.h>
#include <stdio.h>

#include "arvoreBinaria.h"

typedef struct node_st NODE;

struct node_st
{
    void *dado;
    NODE *esquerda;
    NODE *direita;
};

struct arvoreBinaria_st
{
    NODE *raiz;
};

static NODE * node_criar();
static void node_destruir(NODE **node, void (dado_destruir)(void **));
static NODE * inserir_ordenado_recursao(NODE *raiz, void *dado, boolean (dado_eh_maior)(void *, void *));
static void arvore_destruir_recursao(NODE **raiz, void (dado_destruir)(void **));
static void emordem_recursao(NODE *raiz, void (*dado_visitar)(void *));
static void preordem_recursao(NODE *raiz, void (*dado_visitar)(void *));
static void posordem_recursao(NODE *raiz, void (*dado_visitar)(void *));

ARVORE_BINARIA * arvore_binaria_criar()
{
    ARVORE_BINARIA *arvore = (ARVORE_BINARIA *) malloc(1 * sizeof(ARVORE_BINARIA));
    if (arvore == NULL)
    {
        exit(-1);
    }
    arvore->raiz = NULL;
    return arvore;
}

void arvore_binaria_destruir(ARVORE_BINARIA **arvore, void (dado_destruir)(void **))
{
    if (*arvore != NULL)
    {
        arvore_destruir_recursao(&((*arvore)->raiz), dado_destruir);
        free(*arvore);
        *arvore = NULL;
    }
}

void arvore_binaria_inserir_raiz(ARVORE_BINARIA *arvore, void *dado)
{
    if (arvore != NULL)
    {
        arvore->raiz = node_criar();
        arvore->raiz->dado = dado;
    }
}

void arvore_binaria_emordem(ARVORE_BINARIA *arvore, void (*dado_visitar)(void *))
{
    if (arvore != NULL && dado_visitar != NULL)
    {
        emordem_recursao(arvore->raiz, dado_visitar);
    }
}

static void emordem_recursao(NODE *raiz, void (*dado_visitar)(void *))
{
    if (raiz != NULL)
    {
        emordem_recursao(raiz->esquerda, dado_visitar);
        dado_visitar(raiz->dado);
        emordem_recursao(raiz->direita, dado_visitar);
    }
}

void arvore_binaria_preordem(ARVORE_BINARIA *arvore, void (*dado_visitar)(void *))
{
    if (arvore != NULL && dado_visitar != NULL)
    {
        preordem_recursao(arvore->raiz, dado_visitar);
    }
}

static void preordem_recursao(NODE *raiz, void (*dado_visitar)(void *))
{
    if (raiz != NULL)
    {
        dado_visitar(raiz->dado);
        preordem_recursao(raiz->esquerda, dado_visitar);
        preordem_recursao(raiz->direita, dado_visitar);
    }
}

void arvore_binaria_posordem(ARVORE_BINARIA *arvore, void (*dado_visitar)(void *))
{
    if (arvore != NULL && dado_visitar != NULL)
    {
        posordem_recursao(arvore->raiz, dado_visitar);
    }
}
static void posordem_recursao(NODE *raiz, void (*dado_visitar)(void *))
{
    if (raiz != NULL)
    {
        posordem_recursao(raiz->esquerda, dado_visitar);
        posordem_recursao(raiz->direita, dado_visitar);
        dado_visitar(raiz->dado);
    }
}

void arvore_binaria_inserir_ordenado(ARVORE_BINARIA *arvore, void *dado, boolean (dado_eh_maior)(void *, void *))
{
    if (arvore != NULL && dado_eh_maior != NULL)
    {
        inserir_ordenado_recursao(arvore->raiz, dado, dado_eh_maior);
    }
}

static NODE * inserir_ordenado_recursao(NODE *raiz, void *dado, boolean (dado_eh_maior)(void *, void *))
{
    if (raiz == NULL)
    {
        raiz = node_criar();
        raiz->dado = dado;
    }
    else if (dado_eh_maior(raiz->dado, dado))
    {
        raiz->esquerda = inserir_ordenado_recursao(raiz->esquerda, dado, dado_eh_maior);
    }
    else if (dado_eh_maior(dado, raiz->dado))
    {
        raiz->direita = inserir_ordenado_recursao(raiz->direita, dado, dado_eh_maior);
    }
    return raiz;
}

static NODE * node_criar()
{
    NODE *node = (NODE *) malloc(1 *sizeof(NODE));
    if (node == NULL)
    {
        exit(-1);
    }
    node->dado = NULL;
    node->direita = NULL;
    node->esquerda = NULL;
    return node;
}

static void node_destruir(NODE **node, void (dado_destruir)(void **))
{
    if (*node != NULL)
    {
        dado_destruir(&((*node)->dado));
        (*node)->dado = NULL;
        free(*node);
        *node = NULL;
    }
}

static void arvore_destruir_recursao(NODE **raiz, void (dado_destruir)(void **))
{
    if (*raiz != NULL)
    {
        arvore_destruir_recursao(&((*raiz)->esquerda), dado_destruir);
        arvore_destruir_recursao(&((*raiz)->direita), dado_destruir);
        node_destruir(raiz, dado_destruir);
        *raiz = NULL;
    }
}
