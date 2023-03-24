#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../includes/bignumber.h"
#include "../includes/lista.h"

struct bignumber_st
{
    LISTA *digitos;
    int negativo;
};

BIGNUMBER * bignumber_criar()
{
    BIGNUMBER *bignumber = (BIGNUMBER *) malloc(sizeof(BIGNUMBER) * 1);
    if (bignumber == NULL)
    {
        exit(-1);
    }
    bignumber->digitos = lista_criar();
    bignumber->negativo = 0;
    return bignumber;
}

void converter_string_para_bignumber(char *string, BIGNUMBER *bignumber)
{
    if (string[0] == '-')
    {
        bignumber->negativo = 1;
        string++;
    }
    int tamanho_string = strlen(string);
    if (tamanho_string % DIGITOS != 0)
    {
        char string_temporaria[TAM_MAX_STRING];
        strncpy(string_temporaria, string, tamanho_string % DIGITOS);
        int *valor = (int *) malloc(sizeof(int) * 1);
        *valor = atoi(string_temporaria);
        lista_inserir(bignumber->digitos, valor);
        string += tamanho_string % DIGITOS;
        tamanho_string = strlen(string);
    }
    int quantidade_itens = tamanho_string / DIGITOS;
    for (int i = 0; i < quantidade_itens; i++)
    {
        char string_temporaria[TAM_MAX_STRING];
        strncpy(string_temporaria, string, DIGITOS);
        string += DIGITOS;
        int *valor = (int *) malloc(sizeof(int) * 1);
        *valor = atoi(string_temporaria);
        lista_inserir(bignumber->digitos, valor);
    }
}

void bignumber_print(BIGNUMBER *bignumber)
{
    print(bignumber->digitos);
}

void bignumber_imprimir(BIGNUMBER *bignumber)
{
    char string[TAM_MAX_STRING];
    char *string_manipular = string;
    if (bignumber->negativo)
    {
        string_manipular[0] = '-';
        string_manipular++;
    }
    for (int i = 1; i <= lista_tamanho(bignumber->digitos); i++)
    {
        int *digito = (int *) lista_pegar_enesimo_dado(bignumber->digitos, i);
        if (i == 1)
        {
            sprintf(string_manipular, "%d", *digito);
        }
        else
        {
            char string_temporaria[TAM_MAX_STRING];
            sprintf(string_temporaria, "%d", *digito);
            strcat(string_manipular, string_temporaria);
        }
    }
    printf("%s\n", string);
}