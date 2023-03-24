#include <stdio.h>

#include "include/carta.h"
#include "include/baralho.h"
#include "include/blackjack.h"

void loop_leitura(BARALHO *baralho);

int main()
{
    BARALHO *baralho = baralho_criar();
    loop_leitura(baralho);
    blackjack_jogar(baralho);
    baralho_excluir(&baralho);
}

void loop_leitura(BARALHO *baralho)
{
    int tamanho_maximo = baralho_pegar_tamanho_maximo(baralho);
    for (int i = 1; i <= tamanho_maximo; i++)
    {
        char naipe[TAMANHO_NAIPE];
        char nome[TAMANHO_NOME];
        scanf("%s %s", naipe, nome);
        baralho_inserir_carta(baralho, naipe, nome);
    }
}