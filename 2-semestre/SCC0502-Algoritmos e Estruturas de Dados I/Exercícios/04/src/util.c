#include <stdio.h>

#include "../includes/util.h"

void boolean_print(boolean bool)
{
    if (bool == 0)
    {
        printf("FALSE\n");
    }
    else if (bool == 1)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("ERRO\n");
    }
}