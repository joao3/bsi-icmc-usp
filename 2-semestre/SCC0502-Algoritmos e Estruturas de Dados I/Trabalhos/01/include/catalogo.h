#ifndef CATALOGO_H
#define CATALOGO_H

#include "jogo.h"

typedef struct catalogo_st CATALOGO;

CATALOGO * catalogo_criar();
void catalogo_destruir(CATALOGO **catalogo);
void catalogo_inserir_jogo(CATALOGO *catalogo, JOGO *jogo);
int catalogo_tamanho(CATALOGO *catalogo);
void catalogo_remover_jogos_repetidos(CATALOGO *catalogo);
void catalogo_imprimir_jogos_de_produtora(CATALOGO *catalogo, char *produtora_buscada);
void catalogo_imprimir_jogos_de_ano(CATALOGO *catalogo, int ano_buscado);
void catalogo_imprimir_todos_jogos(CATALOGO *catalogo);
void catalogo_imprimir_jogo_por_indice(CATALOGO *catalogo, int indice);
void catalogo_remover_jogo_por_indice(CATALOGO *catalogo, int indice);
void catalogo_mover_jogo_n_posicoes_direita(CATALOGO *catalogo, int indice, int n);
void catalogo_mover_jogo_n_posicoes_esquerda(CATALOGO *catalogo, int indice, int n);

#endif //CATALOGO_H
