#include <stdlib.h>

#include "registro.h"
#include "../arvoreBinaria/arvoreBinaria.h"

struct registro_st
{
    ARVORE_BINARIA *clientes;
    int quantidade_clientes;
};

REGISTRO * registro_criar()
{
    REGISTRO *registro = (REGISTRO *) malloc(1 * sizeof(REGISTRO));
    if (registro == NULL)
    {
        exit(-1);
    }
    registro->clientes = arvore_binaria_criar();
    registro->quantidade_clientes = 0;
    return registro;
}

void registro_destruir(REGISTRO **registro)
{
    if (registro != NULL)
    {
        arvore_binaria_destruir(&((*registro)->clientes), &cliente_destruir);
        free(*registro);
        *registro = NULL;
    }
}

void registro_inserir_cliente(REGISTRO *registro, CLIENTE *cliente)
{
    if (registro != NULL && cliente != NULL)
    {
        if (registro->quantidade_clientes > 0)
        {
            arvore_binaria_inserir_ordenado(registro->clientes, cliente, &cliente_cpf_eh_maior);
        }
        else
        {
            arvore_binaria_inserir_raiz(registro->clientes, cliente);
        }
        registro->quantidade_clientes++;
    }
}

void registro_imprimir_cpf_emordem(REGISTRO *registro)
{
    if (registro != NULL)
    {
        arvore_binaria_emordem(registro->clientes, &cliente_imprimir_cpf);
    }
}

void registro_imprimir_cpf_preordem(REGISTRO *registro)
{
    if (registro != NULL)
    {
        arvore_binaria_preordem(registro->clientes, &cliente_imprimir_cpf);
    }
}

void registro_imprimir_cpf_posordem(REGISTRO *registro)
{
    if (registro != NULL)
    {
        arvore_binaria_posordem(registro->clientes, &cliente_imprimir_cpf);
    }
}