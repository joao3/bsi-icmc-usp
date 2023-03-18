#include <stdlib.h>
#include <stdio.h>

#include "index.h"

struct index_st
{
    int key;
    int rrn;
};

INDEX * INDEX_create()
{
    INDEX *index = malloc(1 * sizeof(INDEX));
    if (index == NULL)
    {
        printf("Allocation error\n");
        exit(-1);
    }
    return index;
}

void INDEX_destroy(INDEX **index)
{
    if (*index != NULL)
    {
        free(*index);
        *index = NULL;
    }
}

int INDEX_getKey(INDEX *index)
{
    if (index != NULL)
    {
        return index->key;
    }
    return -1;
}

void INDEX_setKey(INDEX *index, int key)
{
    if (index != NULL)
    {
        index->key = key;
    }
}

int INDEX_getRRN(INDEX *index)
{
    if (index != NULL)
    {
        return index->rrn;
    }
    return -1;
}

void INDEX_setRRN(INDEX *index, int RRN)
{
    if (index != NULL)
    {
        index->rrn = RRN;
    }
}

int INDEX_compareByKey(INDEX *index1, INDEX *index2)
{
    if (index1 != NULL && index2 != NULL)
    {
        if (index1->key < index2->key)
        {
            return -1;
        }
        else if (index1->key > index2->key)
        {
            return 1;
        }
        return 0;
    }
    return -333;
}

int sizeofIndex()
{
    return sizeof(INDEX);
}