#ifndef LISTA_H
#define LISTA_H

#include "../includes/util.h"

#define ERRO (-7777)

typedef struct lista_st LISTA;

LISTA * lista_criar();
boolean lista_vazia(LISTA *lista);
int lista_tamanho(LISTA *lista);
void lista_inserir(LISTA *lista, void *dado);
void * lista_pegar_enesimo_dado(LISTA *lista, int n);
void print(LISTA *lista);

#endif //LISTA_H