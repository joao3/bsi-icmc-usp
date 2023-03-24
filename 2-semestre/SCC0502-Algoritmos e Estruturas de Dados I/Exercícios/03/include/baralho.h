#ifndef BARALHO_H
#define BARALHO_H

#include "../include/carta.h"
#include "util.h"

#define BARALHO_TAMANHO_MAX 52
#define BARALHO_ERRO (-3333)

typedef struct baralho_st BARALHO;

BARALHO * baralho_criar();
void baralho_inserir_carta(BARALHO *baralho, char naipe[], char nome[]);
int baralho_pegar_tamanho_maximo(BARALHO *baralho);
int baralho_pegar_tamanho_atual(BARALHO *baralho);
boolean baralho_vazio(BARALHO *baralho);
boolean baralho_cheio(BARALHO *baralho);
CARTA * baralho_retirar_carta_topo(BARALHO *baralho);
void baralho_excluir(BARALHO **baralho);

#endif //BARALHO_H