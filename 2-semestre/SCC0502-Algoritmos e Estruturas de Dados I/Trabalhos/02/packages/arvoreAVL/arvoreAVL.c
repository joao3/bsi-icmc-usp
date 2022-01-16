#include <stdlib.h>
#include <stdio.h>

#include "arvoreAVL.h"

#define max(a, b) ((a > b) ? a : b)

typedef struct node_st NODE;

struct node_st
{
    void *dado;
    NODE *esquerda;
    NODE *direita;
    int altura;
};

struct arvoreAVL_st
{
    NODE *raiz;
};

static void arvore_avl_destruir_recursao(NODE **raiz, void (dado_destruir)(void **));
static NODE * node_criar();
static void node_destruir(NODE **node, void (dado_destruir)(void **));
static int node_altura(NODE *raiz);
static int fator_desbalanceamento(NODE *raiz);
static NODE * inserir_recursao(NODE *raiz, void *dado, boolean (dado_eh_maior)(void *, void *));
static NODE * balancear_insercao(NODE *raiz, void *dado, boolean (dado_eh_maior)(void *, void *));
static void emordem_recursao(NODE *raiz, void (*dado_visitar)(void *));
static void preordem_recursao(NODE *raiz, void (*dado_visitar)(void *));
static void posordem_recursao(NODE *raiz, void (*dado_visitar)(void *));
static NODE * arvore_buscar_node(NODE *raiz, void *campo_buscado, boolean (dado_eh_igual)(void *, void *), boolean (dado_eh_maior)(void *, void *));
static boolean arvore_remover_recursao(NODE **raiz, void *campo_buscado, boolean (dado_eh_igual)(void *, void *), boolean (dado_eh_maior)(void *, void *), void (dado_destruir)(void **));
static void trocar_maior_esquerda(NODE *maior, NODE *removido, void (dado_destruir)(void **));
static NODE * balancear_remocao(NODE *raiz);
static NODE * rodar_direita(NODE *a);
static NODE * rodar_esquerda(NODE *a);
static NODE * rodar_direita_esquerda(NODE *a);
static NODE * rodar_esquerda_direita(NODE *a);

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-ALOCAÇÂO-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
ARVORE_AVL * arvore_avl_criar()
{
    ARVORE_AVL *arvore = (ARVORE_AVL *) malloc(1 * sizeof(ARVORE_AVL));
    if (arvore == NULL)
    {
        exit(-1);
    }
    arvore->raiz = NULL;
    return arvore;
}

void arvore_avl_destruir(ARVORE_AVL **arvore, void (dado_destruir)(void **))
{
    if (*arvore != NULL)
    {
        arvore_avl_destruir_recursao(&((*arvore)->raiz), dado_destruir);
        free(*arvore);
        *arvore = NULL;
    }
}

static void arvore_avl_destruir_recursao(NODE **raiz, void (dado_destruir)(void **))
{
    if (*raiz != NULL)
    {
        arvore_avl_destruir_recursao(&((*raiz)->esquerda), dado_destruir);
        arvore_avl_destruir_recursao(&((*raiz)->direita), dado_destruir);
        node_destruir(raiz, dado_destruir);
        *raiz = NULL;
    }
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-NODE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
static NODE * node_criar()
{
    NODE *node = (NODE *) malloc(1 * sizeof(NODE));
    if (node == NULL)
    {
        exit(-1);
    }
    node->dado = NULL;
    node->direita = NULL;
    node->esquerda = NULL;
    node->altura = 0;
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

static int node_altura(NODE *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        return raiz->altura;
    }
}

static int fator_desbalanceamento(NODE *raiz)
{
    return node_altura(raiz->esquerda) - node_altura(raiz->direita);
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-INSERÇÂO-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void arvore_avl_inserir_raiz(ARVORE_AVL *arvore, void *dado)
{
    if (arvore != NULL)
    {
        arvore->raiz = node_criar();
        arvore->raiz->dado = dado;
    }
}

void arvore_avl_inserir(ARVORE_AVL *arvore, void *dado, boolean (dado_eh_maior)(void *, void *))
{
    if (arvore != NULL && dado_eh_maior != NULL)
    {
        arvore->raiz = inserir_recursao(arvore->raiz, dado, dado_eh_maior);
    }
}

static NODE * inserir_recursao(NODE *raiz, void *dado, boolean (dado_eh_maior)(void *, void *))
{
    if (raiz == NULL)
    {
        raiz = node_criar();
        raiz->dado = dado;
    }
    else if (dado_eh_maior(raiz->dado, dado))
    {
        raiz->esquerda = inserir_recursao(raiz->esquerda, dado, dado_eh_maior);
    }
    else if (dado_eh_maior(dado, raiz->dado))
    {
        raiz->direita = inserir_recursao(raiz->direita, dado, dado_eh_maior);
    }

    raiz->altura = max(node_altura(raiz->esquerda) + 1, node_altura(raiz->direita) + 1);

    raiz = balancear_insercao(raiz, dado, dado_eh_maior);

    return raiz;
}

static NODE * balancear_insercao(NODE *raiz, void *dado, boolean (dado_eh_maior)(void *, void *))
{
    if (fator_desbalanceamento(raiz) == -2)
    {
        if (dado_eh_maior(dado, raiz->direita->dado))
        {
            raiz = rodar_esquerda(raiz);
        }
        else
        {
            raiz = rodar_direita_esquerda(raiz);
        }
    }
    if (fator_desbalanceamento(raiz) == 2)
    {
        if (dado_eh_maior(dado, raiz->esquerda->dado))
        {
            raiz = rodar_esquerda_direita(raiz);
        }
        else
        {
            raiz = rodar_direita(raiz);
        }
    }
    return raiz;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-TRAVESSIA-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void arvore_avl_emordem(ARVORE_AVL *arvore, void (*dado_visitar)(void *))
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

void arvore_avl_preordem(ARVORE_AVL *arvore, void (*dado_visitar)(void *))
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

void arvore_avl_posordem(ARVORE_AVL *arvore, void (*dado_visitar)(void *))
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

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-BUSCA-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void * arvore_avl_buscar(ARVORE_AVL *arvore, void *dado_buscado, boolean (dado_eh_igual)(void *, void *), boolean (dado_eh_maior)(void *, void *))
{
    if (arvore != NULL)
    {
        NODE *node = arvore_buscar_node(arvore->raiz, dado_buscado, dado_eh_igual, dado_eh_maior);
        return node->dado;
    }
    return NULL;
}

static NODE * arvore_buscar_node(NODE *raiz, void *campo_buscado, boolean (dado_eh_igual)(void *, void *), boolean (dado_eh_maior)(void *, void *))
{

    if (raiz == NULL)
    {
        return NULL;
    }
    if (dado_eh_igual(raiz->dado, campo_buscado))
    {
        return raiz;
    }
    if (dado_eh_maior(raiz->dado, campo_buscado))
    {
        return arvore_buscar_node(raiz->esquerda, campo_buscado, dado_eh_igual, dado_eh_maior);
    }
    else
    {
        return arvore_buscar_node(raiz->direita, campo_buscado, dado_eh_igual, dado_eh_maior);
    }
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-REMOÇÂO-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
boolean arvore_avl_remover(ARVORE_AVL *arvore, void *campo_buscado, boolean (dado_eh_igual)(void *, void *), boolean (dado_eh_maior)(void *, void *), void (dado_destruir)(void **))
{
    if (arvore != NULL)
    {
        return arvore_remover_recursao(&(arvore->raiz), campo_buscado, dado_eh_igual, dado_eh_maior, dado_destruir);
    }
    return ERRO_ARVORE;
}

static boolean arvore_remover_recursao(NODE **raiz, void *campo_buscado, boolean (dado_eh_igual)(void *, void *), boolean (dado_eh_maior)(void *, void *), void (dado_destruir)(void **))
{
    NODE *node_removido;
    if (*raiz == NULL)
    {
        return FALSE;
    }
    if (dado_eh_igual((*raiz)->dado, campo_buscado))
    {
        if ((*raiz)->esquerda == NULL || (*raiz)->direita == NULL)
        {
            node_removido = *raiz;
            if ((*raiz)->esquerda == NULL)
            {
                *raiz = (*raiz)->direita;
            }
            else
            {
                *raiz = (*raiz)->esquerda;
            }
            node_destruir(&node_removido, dado_destruir);
        }
        else
        {
            trocar_maior_esquerda((*raiz)->esquerda, *raiz, dado_destruir);
        }
        if (*raiz != NULL)
        {
            (*raiz)->altura = max(node_altura((*raiz)->direita) + 1, node_altura((*raiz)->esquerda) + 1);
            *raiz = balancear_remocao(*raiz);
        }
        return TRUE;
    }
    else
    {
        if (dado_eh_maior((*raiz)->dado, campo_buscado))
        {
            boolean removeu = arvore_remover_recursao(&((*raiz)->esquerda), campo_buscado, dado_eh_igual, dado_eh_maior, dado_destruir);
            if (*raiz != NULL)
            {
                (*raiz)->altura = max(node_altura((*raiz)->direita) + 1, node_altura((*raiz)->esquerda) + 1);
                *raiz = balancear_remocao(*raiz);
            }
            return removeu;
        }
        else
        {
            boolean removeu = arvore_remover_recursao(&((*raiz)->direita), campo_buscado, dado_eh_igual, dado_eh_maior, dado_destruir);
            if (*raiz != NULL)
            {
                (*raiz)->altura = max(node_altura((*raiz)->direita) + 1, node_altura((*raiz)->esquerda) + 1);
                *raiz = balancear_remocao(*raiz);
            }
            return removeu;
        }
    }

}

static void trocar_maior_esquerda(NODE *maior, NODE *removido, void (dado_destruir)(void **))
{
    if (maior != NULL && removido != NULL)
    {

        NODE *anterior = maior;
        NODE *atual = anterior->direita;

        // Caso em que o filho a esquerda do removido não tem filho a direita.
        if (atual == NULL)
        {
            atual = anterior;
            anterior = removido;
            anterior->esquerda = atual->esquerda;
        }
        // Caso em que o filho a esquerda do removido tem filho a direita.
        else
        {
            while (atual->direita != NULL)
            {
                anterior = atual;
                atual = atual->direita;
            }
            anterior->direita = atual->esquerda;
        }

        void *dado_temporario = removido->dado;
        removido->dado = atual->dado;
        atual->dado = dado_temporario;
        node_destruir(&atual, dado_destruir);
    }
}

static NODE * balancear_remocao(NODE *raiz)
{
    if (fator_desbalanceamento(raiz) == -2)
    {
        if (fator_desbalanceamento(raiz->direita) <= 0)
        {
            raiz = rodar_esquerda(raiz);
        }
        else
        {
            raiz = rodar_direita_esquerda(raiz);
        }
    }
    if (fator_desbalanceamento(raiz) == 2)
    {
        if (fator_desbalanceamento(raiz->esquerda) >= 0)
        {
            raiz = rodar_direita(raiz);
        }
        else
        {
            raiz = rodar_esquerda_direita(raiz);
        }
    }
    return raiz;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-ROTAÇÕES-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
static NODE * rodar_direita(NODE *a)
{
    if (a != NULL)
    {
        NODE *b = a->esquerda;
        a->esquerda = b->direita;
        b->direita = a;
        a->altura = max(node_altura(a->esquerda), node_altura(a->direita) + 1);
        b->altura = max(node_altura(b->esquerda), a->altura + 1);
        return b;
    }
    return NULL;
}

static NODE * rodar_esquerda(NODE *a)
{
    if (a != NULL)
    {
        NODE *b = a->direita;
        a->direita = b->esquerda;
        b->esquerda = a;
        a->altura = max(node_altura(a->esquerda), node_altura(a->direita) + 1);
        b->altura = max(node_altura(b->direita), a->altura + 1);
        return b;
    }
    return NULL;
}

static NODE * rodar_esquerda_direita(NODE *a)
{
    if (a != NULL)
    {
        a->esquerda = rodar_esquerda(a->esquerda);
        return rodar_direita(a);
    }
    return NULL;
}

static NODE * rodar_direita_esquerda(NODE *a)
{
    if (a != NULL)
    {
        a->direita = rodar_direita(a->direita);
        return rodar_esquerda(a);
    }
    return NULL;
}