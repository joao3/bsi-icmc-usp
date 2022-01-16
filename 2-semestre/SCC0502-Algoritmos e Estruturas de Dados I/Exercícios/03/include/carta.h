#ifndef CARTA_H
#define CARTA_H

#define TAMANHO_NAIPE 8
#define TAMANHO_NOME 3

typedef struct carta_st CARTA;

CARTA * carta_criar();
void carta_definir(CARTA *carta, char naipe[], char nome[]);
char * carta_pegar_naipe(CARTA *carta);
char * carta_pegar_nome(CARTA *carta);
void carta_excluir(CARTA **carta);

#endif //CARTA_H