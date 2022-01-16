#ifndef LISTA_H
#define LISTA_H

#include "util.h"

#define ERRO_LISTA 3333

typedef struct lista_st LISTA;

LISTA * lista_criar();
void lista_destruir(LISTA **lista);
boolean lista_vazia(LISTA *lista);
void lista_inserir_fim(LISTA *lista, void *dado);
int lista_tamanho(LISTA *lista);
void * lista_pegar_dado_por_indice(LISTA *lista, int indice);
void lista_excluir_node_por_indice(LISTA *lista, int indice);
void lista_mover_node_n_posicoes(LISTA *lista, int indice, int n);

#endif //LISTA_H