#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/blackjack.h"

int blackjack_valor_carta(CARTA *carta)
{
    char *nome = carta_pegar_nome(carta);
    if ((strcmp(nome, "V") == 0) || (strcmp(nome, "D") == 0) || (strcmp(nome, "R") == 0))
    {
        return 10;
    }
    else
    {
        return atoi(nome);
    }
}

void blackjack_jogar(BARALHO *baralho)
{
    int soma = 0;
    int parar = 0;
    while (!parar)
    {
        CARTA *carta = baralho_retirar_carta_topo(baralho);
        soma += blackjack_valor_carta(carta);
        carta_excluir(&carta);
        if (soma >= 21)
        {
            if (soma == 21)
            {
                printf("Ganhou ;)\n");
            }
            else
            {
                printf("Perdeu :(\nSoma :: %d\n", soma);
            }
            parar = 1;
        }
    }
}