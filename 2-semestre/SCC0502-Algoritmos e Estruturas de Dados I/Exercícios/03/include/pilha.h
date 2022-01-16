#ifndef PILHA_H
#define PILHA_H

#include "util.h"

#define PILHA_ERRO (-300)

typedef struct pilha_st PILHA;

PILHA * pilha_criar();
void pilha_apagar(PILHA **pilha);
boolean pilha_vazia();
int pilha_tamanho();
void * pilha_topo();
void pilha_empilhar(PILHA *pilha, void *dado);
void * pilha_desempilhar(PILHA *pilha);

#endif //PILHA_H