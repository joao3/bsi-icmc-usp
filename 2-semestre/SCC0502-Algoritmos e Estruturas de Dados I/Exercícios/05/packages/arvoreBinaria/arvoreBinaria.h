#ifndef __ARVORE_BINARIA_H__
#define __ARVORE_BINARIA_H__

#include "../util/utilBoolean.h"

typedef struct arvoreBinaria_st ARVORE_BINARIA;

ARVORE_BINARIA * arvore_binaria_criar();
void arvore_binaria_destruir(ARVORE_BINARIA **arvore, void (dado_destruir)(void **));
void arvore_binaria_inserir_raiz(ARVORE_BINARIA *arvore, void *dado);
void arvore_binaria_emordem(ARVORE_BINARIA *arvore, void (*dado_visitar)(void *));
void arvore_binaria_preordem(ARVORE_BINARIA *arvore, void (*dado_visitar)(void *));
void arvore_binaria_posordem(ARVORE_BINARIA *arvore, void (*dado_visitar)(void *));
void arvore_binaria_inserir_ordenado(ARVORE_BINARIA *arvore, void *dado, boolean (dado_eh_maior)(void *, void *));

/*
 * arvore_binaria_inserir_ordenado:
 *      Recebe por parâmetro, o ponteiro de uma função que deve interpretar e comparar dois dados, ao final retornar TRUE
 *      se o primeiro for maior que o segundo e FALSE se não. Assim, se o filho for maior que o pai, ele é inserido na
 *      direita, se for menor é inserido na esquerda. Então a árvore ficará ordenada de acordo com o campo desejado pelo
 *      módulo que está usando ela, no caso registro/cliente.
 *
 * funcoes_de_percurso:
 *      Recebem por parâemtro, o ponteiro de uma função que faz algo com o dado (visita), por exemplo imprimir.
 *
 * arvore_binaria_destruir:
 *      Recebe por parâmetro, o ponteiro de uma função que desaloca adequadamente a memória usado pelo dado.
 */


#endif // __ARVORE_BINARIA_H__
