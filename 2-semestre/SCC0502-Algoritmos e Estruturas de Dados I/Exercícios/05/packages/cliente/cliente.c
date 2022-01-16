#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cliente.h"
#include "../util/utilString.h"

struct cliente_st
{
    BIGNUMBER *cpf;
    char *nome;
    int idade;
    float saldo;
};

CLIENTE * cliente_criar()
{
    CLIENTE *cliente = (CLIENTE *) malloc(1 * sizeof(CLIENTE));
    if (cliente == NULL)
    {
        exit(-1);
    }
    cliente->cpf = NULL;
    cliente->nome = NULL;
    cliente->idade = -1;
    cliente->saldo = 0;
    return cliente;
}

void cliente_destruir(void **cliente)
{
    if (*cliente != NULL)
    {
        CLIENTE **cliente_cast = (CLIENTE **) cliente;
        bignumber_destruir(&((*cliente_cast)->cpf));
        string_destruir(&((*cliente_cast)->nome));
        free(*cliente_cast);
        *cliente_cast = NULL;
    }
}

void cliente_definir_cpf(CLIENTE *cliente, BIGNUMBER *cpf)
{
    if (cliente != NULL)
    {
        cliente->cpf = cpf;
    }
}

void cliente_definir_nome(CLIENTE *cliente, char *nome)
{
    if (cliente != NULL && nome != NULL)
    {
        cliente->nome = string_criar(TAMANHO_STRING);
        strcpy(cliente->nome, nome);
    }
}

void cliente_definir_idade(CLIENTE *cliente, int idade)
{
    if (cliente != NULL)
    {
        cliente->idade = idade;
    }
}

void cliente_definir_saldo(CLIENTE *cliente, float saldo)
{
    if (cliente != NULL)
    {
        cliente->saldo = saldo;
    }
}

void cliente_imprimir_cpf(void *cliente)
{
    if (cliente != NULL)
    {
        CLIENTE *cliente_cast = (CLIENTE *) cliente;
        bignumber_imprimir(cliente_cast->cpf);
        printf("\n");
    }
}

boolean cliente_cpf_eh_maior(void *cliente1, void *cliente2)
{
    if (cliente1 != NULL && cliente2 != NULL)
    {
        CLIENTE *cliente1_cast = (CLIENTE *) cliente1;
        CLIENTE *cliente2_cast = (CLIENTE *) cliente2;
        return bignumber_maior(cliente1_cast->cpf, cliente2_cast->cpf);
    }
    return ERRO_CLIENTE;
}