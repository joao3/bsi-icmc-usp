#include "stdlib.h"

#include "../include/util.h"

char * string_criar(int tamanho)
{
    char *string = (char *) calloc(tamanho, sizeof(char));
    if (string == NULL)
    {
        exit(-1);
    }

    return string;
}

void string_destruir(char **string)
{
    if (*string != NULL)
    {
        free(*string);
        *string = NULL;
    }
}