#include <stdio.h>
#include <string.h>

#include "catalogo.h"
#include "jogo.h"

void loop_leitura(CATALOGO *catalogo);
void loop_buscas(CATALOGO *catalogo);

int main()
{
    CATALOGO *catalogo = catalogo_criar();
    loop_leitura(catalogo);
    loop_buscas(catalogo);
    catalogo_excluir(&catalogo);
}

void loop_leitura(CATALOGO *catalogo)
{
    int sair = 0;
    while (!sair)
    {
        char nome[NOME_TAMANHO_MAX];
        scanf(" %[^(\r|\n)]", nome);
        if (strcmp(nome, "F") == 0)
        {
            sair = 1;
        }
        else
        {
            char produtora[NOME_TAMANHO_MAX];
            scanf(" %[^(\r|\n)]", produtora);
            int ano;
            scanf("%d\n", &ano);
            catalogo_inserir_jogo(catalogo, nome, produtora, ano);
        }
    }
}

void loop_buscas(CATALOGO *catalogo)
{
    int sair = 0;
    while (!sair)
    {
        char operacao;
        scanf("%c", &operacao);
        if (operacao == 'F')
        {
            sair = 1;
        }
        else
        {
            catalogo_buscas(catalogo, operacao);
        }
    }
}