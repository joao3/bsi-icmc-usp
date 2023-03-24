#ifndef __BIGNUMBER_H__
#define __BIGNUMBER_H__

#include "../util/utilBoolean.h"

#define MAX_DE_DIGITOS 50

typedef struct bignumber_st BIGNUMBER;

BIGNUMBER * bignumber_criar();
void converter_string_para_bignumber(char *string, BIGNUMBER *bignumber);
void bignumber_imprimir(BIGNUMBER *bignumber);
void bignumber_print(BIGNUMBER *bignumber);
int bignumber_quantidade_digitos(BIGNUMBER *bignumber);
boolean bignumber_igual(BIGNUMBER *bignumber_1, BIGNUMBER *bignumber_2);
boolean bignumber_maior(BIGNUMBER *bignumber_1, BIGNUMBER *bignumber_2);
boolean bignumber_menor(BIGNUMBER *bignumber_1, BIGNUMBER *bignumber_2);
BIGNUMBER * bignumber_somar(BIGNUMBER *bignumber_1, BIGNUMBER *bignumber_2);
void bignumber_destruir(BIGNUMBER **bignumber);
int * digito_criar();
void digito_destruir(int **digito);

#endif // __BIGNUMBER_H__