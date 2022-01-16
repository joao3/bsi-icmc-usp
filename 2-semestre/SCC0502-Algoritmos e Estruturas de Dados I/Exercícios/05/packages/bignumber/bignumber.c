#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bignumber.h"
#include "../lista/lista.h"

struct bignumber_st
{
    LISTA *digitos;
    int negativo;
};

BIGNUMBER * bignumber_criar()
{
    BIGNUMBER *bignumber = (BIGNUMBER *) calloc(1, sizeof(BIGNUMBER));
    if (bignumber == NULL)
    {
        exit(-1);
    }
    bignumber->digitos = lista_criar();
    bignumber->negativo = 0;
    return bignumber;
}

void bignumber_destruir(BIGNUMBER **bignumber)
{
    if (*bignumber != NULL)
    {
        int *digito_atual = (int *) lista_pegar_enesimo_dado((*bignumber)->digitos, 1);
        while (digito_atual != NULL)
        {
            digito_destruir(&digito_atual);
            lista_remover_enesimo_node((*bignumber)->digitos, 1);
            digito_atual = (int *) lista_pegar_enesimo_dado((*bignumber)->digitos, 1);
        }
        lista_destruir(&((*bignumber)->digitos));
        free(*bignumber);
        *bignumber = NULL;
    }
}

int * digito_criar()
{
    int *digito = (int *) calloc(1, sizeof(int));
    if (digito == NULL)
    {
        exit(-1);
    }
    return digito;
}

void digito_destruir(int **digito)
{
    if (*digito != NULL)
    {
        free(*digito);
        *digito = NULL;
    }
}

void converter_string_para_bignumber(char *string, BIGNUMBER *bignumber)
{
    if (string[0] == '-')
    {
        bignumber->negativo = 1;
        string++;
    }

    //Remove zeros a esquerda
    int zero_a_esquerda = 1;
    while (zero_a_esquerda)
    {
        if (*string == '0')
        {
            string++;
            continue;
        }
        zero_a_esquerda = 0;
    }
    //Caso em que somente zeros foram inseridos
    if (*string == '\0')
    {
        int *digito = digito_criar();
        *digito = 0;
        lista_inserir_fim(bignumber->digitos, digito);
    }

    while (*string != '\0')
    {
        int *digito = digito_criar();
        *digito = *string - '0';
        lista_inserir_fim(bignumber->digitos, digito);
        string++;
    }
}

int bignumber_quantidade_digitos(BIGNUMBER *bignumber)
{
    if (bignumber != NULL)
    {
        return lista_tamanho(bignumber->digitos);
    }
    return ERRO;
}

void bignumber_imprimir(BIGNUMBER *bignumber)
{
    if (bignumber->negativo)
    {
        printf("-");
    }
    for (int i = 1; i <= bignumber_quantidade_digitos(bignumber); i++)
    {
        int *digito = (int *) lista_pegar_enesimo_dado(bignumber->digitos, i);
        printf("%d", *digito);
    }
}

boolean bignumber_igual(BIGNUMBER *bignumber_1, BIGNUMBER *bignumber_2)
{
    if (bignumber_quantidade_digitos(bignumber_1) != bignumber_quantidade_digitos(bignumber_2))
    {
        return FALSE;
    }
    if (bignumber_1->negativo != bignumber_2->negativo)
    {
        return FALSE;
    }

    for (int i = 1; i <= bignumber_quantidade_digitos(bignumber_1); i++)
    {
        int *digitos_1 = (int *) lista_pegar_enesimo_dado(bignumber_1->digitos, i);
        int *digitos_2 = (int *) lista_pegar_enesimo_dado(bignumber_2->digitos, i);
        if (*digitos_1 != *digitos_2)
        {
            return FALSE;
        }
    }

    return TRUE;
}

boolean bignumber_maior(BIGNUMBER *bignumber_1, BIGNUMBER *bignumber_2)
{
    if (bignumber_1->negativo != bignumber_2->negativo)
    {
        if (bignumber_2->negativo)
        {
            return TRUE;
        }
        return FALSE;
    }

    if (bignumber_quantidade_digitos(bignumber_2) > bignumber_quantidade_digitos(bignumber_1))
    {
        return FALSE;
    }
    else if (bignumber_quantidade_digitos(bignumber_1) > bignumber_quantidade_digitos(bignumber_2))
    {
        return TRUE;
    }

    for (int i = 1; i <= bignumber_quantidade_digitos(bignumber_1); i++)
    {
        int *node_1 = (int *) lista_pegar_enesimo_dado(bignumber_1->digitos, i);
        int *node_2 = (int *) lista_pegar_enesimo_dado(bignumber_2->digitos, i);
        if (*node_1 > *node_2)
        {
            return TRUE;
        }
        else if (*node_1 < *node_2)
        {
            return FALSE;
        }
    }
    return FALSE;
}

boolean bignumber_menor(BIGNUMBER *bignumber_1, BIGNUMBER *bignumber_2)
{
    if (bignumber_1->negativo != bignumber_2->negativo)
    {
        if (bignumber_2->negativo)
        {
            return FALSE;
        }
        return TRUE;
    }

    if (bignumber_quantidade_digitos(bignumber_2) > bignumber_quantidade_digitos(bignumber_1))
    {
        return TRUE;
    }
    else if (bignumber_quantidade_digitos(bignumber_1) > bignumber_quantidade_digitos(bignumber_2))
    {
        return FALSE;
    }

    for (int i = 1; i <= bignumber_quantidade_digitos(bignumber_1); i++)
    {
        int *node_1 = (int *) lista_pegar_enesimo_dado(bignumber_1->digitos, i);
        int *node_2 = (int *) lista_pegar_enesimo_dado(bignumber_2->digitos, i);
        if (*node_1 > *node_2)
        {
            return FALSE;
        }
        else if (*node_1 < *node_2)
        {
            return TRUE;
        }
    }
    return FALSE;
}

BIGNUMBER * bignumber_somar(BIGNUMBER *bignumber_1, BIGNUMBER *bignumber_2)
{
    BIGNUMBER *soma = bignumber_criar();
    int percorrido_1 = 0, percorrido_2 = 0;
    int tamanho_1 = bignumber_quantidade_digitos(bignumber_1);
    int tamanho_2 = bignumber_quantidade_digitos(bignumber_2);
    int carry = 0;
    while (percorrido_1 < tamanho_1 && percorrido_2 < tamanho_2)
    {
        int *n1 = (int *) lista_pegar_enesimo_dado(bignumber_1->digitos, tamanho_1 - percorrido_1);
        int *n2 = (int *) lista_pegar_enesimo_dado(bignumber_2->digitos, tamanho_2 - percorrido_2);
        int *digito_soma = digito_criar();
        *digito_soma = (*n1 + *n2 + carry) % 10;
        lista_inserir_inicio(soma->digitos, digito_soma);
        carry = (*n1 + *n2 + carry) / 10;
        percorrido_1++;
        percorrido_2++;
    }
    while (percorrido_1 < tamanho_1)
    {
        int *n1 = (int *) lista_pegar_enesimo_dado(bignumber_1->digitos, tamanho_1 - percorrido_1);
        int *digito_soma = digito_criar();
        *digito_soma = (*n1 + carry) % 10;
        lista_inserir_inicio(soma->digitos, digito_soma);
        carry = (*n1 + carry) / 10;
        percorrido_1++;
    }
    while (percorrido_2 < tamanho_2)
    {
        int *n2 = (int *) lista_pegar_enesimo_dado(bignumber_2->digitos, tamanho_2 - percorrido_2);
        int *digito_soma = digito_criar();
        *digito_soma = (*n2 + carry) % 10;
        lista_inserir_inicio(soma->digitos, digito_soma);
        carry = (*n2 + carry) / 10;
        percorrido_2++;
    }
    if (carry > 0)
    {
        int *digito = digito_criar();
        *digito = carry;
        lista_inserir_inicio(soma->digitos, digito);
    }
    return soma;
}