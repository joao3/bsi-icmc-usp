#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cliente.h"
#include "../util/utilString.h"

struct cliente_st
{
    char *cpf;
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
        string_destruir(&((*cliente_cast)->cpf));
        string_destruir(&((*cliente_cast)->nome));
        free(*cliente_cast);
        *cliente_cast = NULL;
    }
}

void cliente_definir_cpf(CLIENTE *cliente, char *cpf)
{
    if (cliente != NULL)
    {
        cliente->cpf = string_criar(TAMANHO_STRING);
        strcpy(cliente->cpf, cpf);
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
        printf("%s\n", cliente_cast->cpf);
    }
}

void cliente_imprimir_cpf_formatado(void *cliente)
{
    if (cliente != NULL)
    {
        CLIENTE *cliente_cast = (CLIENTE *) cliente;
        char *cpf = cliente_cast->cpf;

        for (int i = 0; i < 3; i++)
        {
            printf("%c", cpf[i]);
        }
        printf(".");
        for (int i = 3; i < 6; i++)
        {
            printf("%c", cpf[i]);
        }
        printf(".");
        for (int i = 6; i < 9; i++)
        {
            printf("%c", cpf[i]);
        }
        printf("-");
        for (int i = 9; i < 11; i++)
        {
            printf("%c", cpf[i]);
        }
        printf("\n");
    }
}

boolean cliente_cpf_eh_maior(void *cliente1, void *cliente2)
{
    if (cliente1 != NULL && cliente2 != NULL)
    {
        CLIENTE *cliente1_cast = (CLIENTE *) cliente1;
        CLIENTE *cliente2_cast = (CLIENTE *) cliente2;

        for (int i = 0; i < 11; i++)
        {
            if ((cliente1_cast->cpf)[i] > cliente2_cast->cpf[i])
            {
                return TRUE;
            }
            else if ((cliente1_cast->cpf)[i] < cliente2_cast->cpf[i])
            {
                return FALSE;
            }
        }
        return FALSE;
    }
    return ERRO_CLIENTE;
}

boolean cliente_cpf_eh_maior_campo(void *cliente, void *cpf)
{
    if (cliente != NULL && cpf != NULL)
    {
        CLIENTE *cliente_cast = (CLIENTE *) cliente;
        char *cpf_cast = (char *) cpf;

        for (int i = 0; i < 11; i++)
        {
            if ((cliente_cast->cpf)[i] > cpf_cast[i])
            {
                return TRUE;
            }
            else if ((cliente_cast->cpf)[i] < cpf_cast[i])
            {
                return FALSE;
            }
        }
        return FALSE;
    }
    return ERRO_CLIENTE;
}

boolean cliente_cpf_eh_igual_campo(void *cliente, void *cpf)
{
    if (cliente != NULL && cpf != NULL)
    {
        CLIENTE *cliente_cast = (CLIENTE *) cliente;
        char *cpf_cast = (char *) cpf;

        for (int i = 0; i < 11; i++)
        {
            if ((cliente_cast->cpf)[i] != cpf_cast[i])
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    return ERRO_CLIENTE;
}

void cliente_imprimir(void *cliente)
{
    if (cliente != NULL)
    {
        CLIENTE *cliente_cast = (CLIENTE *) cliente;
        printf("Conta :: %s\n", cliente_cast->nome);
        printf("CPF :: ");
        cliente_imprimir_cpf_formatado(cliente);
        printf("Idade :: %d\n", cliente_cast->idade);
        printf("Saldo atual :: R$ %.2f\n", cliente_cast->saldo);
    }
}