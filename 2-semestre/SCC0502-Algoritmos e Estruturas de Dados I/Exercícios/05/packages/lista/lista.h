#ifndef __LISTA_H__
#define __LISTA_H__

#include "../util/utilBoolean.h"

#define ERRO (-7777)

typedef struct lista_st LISTA;

LISTA * lista_criar();
boolean lista_vazia(LISTA *lista);
int lista_tamanho(LISTA *lista);
void lista_inserir_fim(LISTA *lista, void *dado);
void lista_inserir_inicio(LISTA *lista, void *dado);
void * lista_pegar_enesimo_dado(LISTA *lista, int n);
void lista_remover_enesimo_node(LISTA *lista, int n);
void lista_destruir(LISTA **lista);

#endif // __LISTA_H__