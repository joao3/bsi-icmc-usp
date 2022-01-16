#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "include/util.h"
#include "include/catalogo.h"
#include "include/jogo.h"

void ler_catalogo_csv(CATALOGO *catalogo, FILE *csv_entrada);
void loop_catalogo_operacoes(CATALOGO *catalogo);

int main()
{
    FILE *csv_entrada = fopen("CSV.csv", "r");
    CATALOGO *catalogo = catalogo_criar();
    ler_catalogo_csv(catalogo, csv_entrada);
    loop_catalogo_operacoes(catalogo);
    catalogo_destruir(&catalogo);
    fclose(csv_entrada);
}

void ler_catalogo_csv(CATALOGO *catalogo, FILE *csv_entrada)
{
    fseek(csv_entrada, 3, SEEK_SET);

    while (!feof(csv_entrada))
    {
        char *linha = string_criar(TAM_MAX_STRING);
        fgets(linha, TAM_MAX_STRING, csv_entrada);

        if (*linha == '\0')
        {
            string_destruir(&linha);
            break;
        }

        char *linha_manipular = linha;

        int contador = 0;
        while (linha_manipular[contador] != ';')
        {
            contador++;
        }
        char *nome = string_criar(TAM_MAX_STRING);
        strncpy(nome, linha_manipular, contador);
        linha_manipular += contador + 1;

        contador = 0;
        while (linha_manipular[contador] != ';')
        {
            contador++;
        }
        char *string_ano = string_criar(8);
        strncpy(string_ano, linha_manipular, contador);
        int ano = atoi(string_ano);
        linha_manipular += contador + 1;

        char *produtora = string_criar(TAM_MAX_STRING);
        strcpy(produtora, linha_manipular);
        produtora[strcspn(produtora, "\r\n")] = 0;

        JOGO *jogo = jogo_criar();
        jogo_definir_nome(jogo, nome);
        jogo_definir_ano(jogo, ano);
        jogo_definir_produtora(jogo, produtora);
        catalogo_inserir_jogo(catalogo, jogo);

        string_destruir(&linha);
        string_destruir(&nome);
        string_destruir(&string_ano);
        string_destruir(&produtora);
    }
}

void loop_catalogo_operacoes(CATALOGO *catalogo)
{
    char operacao[5];
    do
    {
        scanf("%s", operacao);
        if (strcmp(operacao, "r") == 0)
        {
            catalogo_remover_jogos_repetidos(catalogo);
        }
        else if (strcmp(operacao, "p") == 0)
        {
            char *produtora = string_criar(TAM_MAX_STRING);
            scanf(" %[^(\r|\n)]", produtora);
            catalogo_imprimir_jogos_de_produtora(catalogo, produtora);
            string_destruir(&produtora);
        }
        else if (strcmp(operacao, "a") == 0)
        {
            int ano_buscado;
            scanf("%d", &ano_buscado);
            catalogo_imprimir_jogos_de_ano(catalogo, ano_buscado);
        }
        else if (strcmp(operacao, "i") == 0)
        {
            catalogo_imprimir_todos_jogos(catalogo);
        }
        else if (strcmp(operacao, "u") == 0)
        {
            int indice;
            scanf("%d", &indice);
            catalogo_imprimir_jogo_por_indice(catalogo, indice);
        }
        else if (strcmp(operacao, "mr") == 0)
        {
            int i, n;
            scanf("%d %d", &i, &n);
            catalogo_mover_jogo_n_posicoes_direita(catalogo, i, n);
        }
        else if (strcmp(operacao, "ml") == 0)
        {
            int i, n;
            scanf("%d %d", &i, &n);
            catalogo_mover_jogo_n_posicoes_esquerda(catalogo, i, n);
        }
    } while (strcmp(operacao, "f") != 0);
}