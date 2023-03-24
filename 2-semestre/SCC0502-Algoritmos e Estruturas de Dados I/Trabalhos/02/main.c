#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "packages/util/utilString.h"
#include "packages/catalogo/catalogo.h"
#include "packages/jogo/jogo.h"

void ler_catalogo_csv(CATALOGO *catalogo, FILE *csv_entrada);
void divide_linha_e_cadastra_jogo(CATALOGO *catalogo, char *linha);
void operacoes(CATALOGO *catalogo);

int main()
{
    FILE *csv_entrada = fopen("CSV.csv", "r");
    CATALOGO *catalogo = catalogo_criar();
    ler_catalogo_csv(catalogo, csv_entrada);
    operacoes(catalogo);
    catalogo_destruir(&catalogo);
    fclose(csv_entrada);
}

void ler_catalogo_csv(CATALOGO *catalogo, FILE *csv_entrada)
{
    fseek(csv_entrada, 3, SEEK_SET);

    while (!feof(csv_entrada))
    {
        char *linha = NULL;
        char caractere;
        int i = 0;
        do
        {
            caractere = (char) fgetc(csv_entrada);
            linha = (char *) realloc(linha, (i + 1) * sizeof(char ));
            linha[i] = caractere;
            i++;
            if (caractere == '\r')
            {
                caractere = (char) fgetc(csv_entrada);
            }
        } while((caractere != '\n') && (caractere != EOF));
        linha[--i] = '\0';
        divide_linha_e_cadastra_jogo(catalogo, linha);
        string_destruir(&linha);
    }
}

void divide_linha_e_cadastra_jogo(CATALOGO *catalogo, char *linha)
{
    if (*linha == '\0')
    {
        return;
    }

    char *linha_manipular = linha;

    int contador = 0;
    while (linha_manipular[contador] != ';')
    {
        contador++;
    }
    char *nome = string_criar(contador + 1);
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

    char *produtora = string_criar(strlen(linha_manipular) + 1);
    strcpy(produtora, linha_manipular);
    produtora[strcspn(produtora, "\r\n")] = 0;


    JOGO *jogo = jogo_criar();
    jogo_definir_nome(jogo, nome);
    jogo_definir_ano(jogo, ano);
    jogo_definir_produtora(jogo, produtora);
    catalogo_inserir_jogo(catalogo, jogo);

    string_destruir(&nome);
    string_destruir(&string_ano);
    string_destruir(&produtora);
}

void operacoes(CATALOGO *catalogo)
{
    if (catalogo != NULL)
    {
        int travessia;
        scanf("%d", &travessia);

        char linha[15];
        scanf("%s", linha);

        while (strcmp(linha, "F"))
        {
            int *ano = (int *) malloc(1 * sizeof(int));
            *ano = atoi(linha);
            catalogo_remover_jogo_por_ano(catalogo, ano);
            scanf("%s", linha);
            free(ano);
        }

        if (travessia == 1)
        {
            catalogo_imprimir_nomes_preordem(catalogo);
        }
        else if (travessia == 2)
        {
            catalogo_imprimir_nomes_emordem(catalogo);
        }
        else if (travessia == 3)
        {
            catalogo_imprimir_nomes_posordem(catalogo);
        }
    }
}