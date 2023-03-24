#ifndef __REGISTRO_H__
#define __REGISTRO_H__

#include "../cliente/cliente.h"

typedef struct registro_st REGISTRO;

REGISTRO * registro_criar();
void registro_destruir(REGISTRO **registro);
void registro_inserir_cliente(REGISTRO *registro, CLIENTE *cliente);
void registro_imprimir_cpf_preordem(REGISTRO *registro);
void registro_imprimir_cpf_emordem(REGISTRO *registro);
void registro_imprimir_cpf_posordem(REGISTRO *registro);
CLIENTE * registro_buscar_cliente_por_cpf(REGISTRO *registro, char *cpf_buscado);
void registro_remover_cliente_por_cpf(REGISTRO *registro, char *cpf_buscado);

#endif // __REGISTRO_H__