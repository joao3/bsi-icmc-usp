#ifndef __CLIENTE_H__
#define __CLIENTE_H__

#include "../util/utilBoolean.h"

#define ERRO_CLIENTE -7777
#define TAMANHO_CPF 15

typedef struct cliente_st CLIENTE;

CLIENTE * cliente_criar();
void cliente_destruir(void **cliente);
void cliente_definir_cpf(CLIENTE *cliente, char *cpf);
void cliente_definir_nome(CLIENTE *cliente, char *nome);
void cliente_definir_idade(CLIENTE *cliente, int idade);
void cliente_definir_saldo(CLIENTE *cliente, float saldo);
void cliente_imprimir_cpf(void *cliente);
void cliente_imprimir_cpf_formatado(void *cliente);
void cliente_imprimir(void *cliente);
boolean cliente_cpf_eh_maior(void *cliente1, void *cliente2);
boolean cliente_cpf_eh_maior_campo(void *cliente, void *cpf);
boolean cliente_cpf_eh_igual_campo(void *cliente, void *cpf);

/*
 * cliente_cpf_eh_maior:
 *      verifica se cliente1->cpf > cliente2->cpf
 *
 * cliente_cpf_eh_maior_campo:
 *      verifica se cliente1->cpf > cpf
 *
 *
 * cliente_cpf_eh_igual_campo:
 *      verifica se cliente->cpf == cpf
 */


#endif // __CLIENTE_H__