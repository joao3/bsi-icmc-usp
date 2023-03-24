#include <stdio.h>

#include "includes/bignumber.h"

int main()
{
    char str[TAM_MAX_STRING];
    scanf(" %s", str);
    BIGNUMBER *bignumber = bignumber_criar();
    converter_string_para_bignumber(str, bignumber);
    bignumber_imprimir(bignumber);
}