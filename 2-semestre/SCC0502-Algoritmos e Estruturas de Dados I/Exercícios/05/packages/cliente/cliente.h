#ifndef __CLIENTE_H__
#define __CLIENTE_H__

#include "../bignumber/bignumber.h"
#include "../util/utilBoolean.h"

#define ERRO_CLIENTE -7777

typedef struct cliente_st CLIENTE;

CLIENTE * cliente_criar();
void cliente_destruir(void **cliente);
void cliente_definir_cpf(CLIENTE *cliente, BIGNUMBER *cpf);
void cliente_definir_nome(CLIENTE *cliente, char *nome);
void cliente_definir_idade(CLIENTE *cliente, int idade);
void cliente_definir_saldo(CLIENTE *cliente, float saldo);
void cliente_imprimir_cpf(void *cliente);
boolean cliente_cpf_eh_maior(void *cliente1, void *cliente2);

#endif // __CLIENTE_H__