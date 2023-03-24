#ifndef JOGO_H
#define JOGO_H

#define NOME_TAMANHO_MAX 50

typedef struct jogo_st JOGO;

JOGO * jogo_criar();
void jogo_realocar_vetor(JOGO ***jogos, int quantidade_jogos);
void jogo_inserir_no_vetor(JOGO **jogos, int i, char nome[], char produtora[], int ano);
void jogo_definir(JOGO *jogo, char nome[], char produtora[], int ano);
void jogo_buscar_por_ano_no_vetor(JOGO **jogos, int tamanho_catalogo);
void jogo_buscar_por_produtora_no_vetor(JOGO **jogos, int tamanho_catalogo);
void jogo_excluir_vetor(JOGO ***jogos, int tamanho_vetor);
void jogo_excluir(JOGO **jogo);

#endif //JOGO_H