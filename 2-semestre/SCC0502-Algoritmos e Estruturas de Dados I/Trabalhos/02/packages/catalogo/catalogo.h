#ifndef CATALOGO_H
#define CATALOGO_H

#include "../jogo/jogo.h"

typedef struct catalogo_st CATALOGO;

CATALOGO * catalogo_criar();
void catalogo_destruir(CATALOGO **catalogo);
void catalogo_inserir_jogo(CATALOGO *catalogo, JOGO *jogo);
void catalogo_remover_jogo_por_ano(CATALOGO *catalogo, int *ano);
void catalogo_imprimir_nomes_preordem(CATALOGO *catalogo);
void catalogo_imprimir_nomes_emordem(CATALOGO *catalogo);
void catalogo_imprimir_nomes_posordem(CATALOGO *catalogo);

#endif //CATALOGO_H
