#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#define DIGITOS 8
#define TAM_MAX_STRING 50

typedef struct bignumber_st BIGNUMBER;

BIGNUMBER * bignumber_criar();
void converter_string_para_bignumber(char *string, BIGNUMBER *bignumber);
void bignumber_imprimir(BIGNUMBER *bignumber);
void bignumber_print(BIGNUMBER *bignumber);

#endif