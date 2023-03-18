#include <stdlib.h>
#include <stdio.h>

#include "indexList.h"

struct indexList_st
{
    INDEX **indexes;
    int size;
};

INDEX_LIST * INDEX_LIST_create()
{
    INDEX_LIST *indexList = malloc(1 * sizeof(INDEX_LIST));
    if (indexList == NULL)
    {
        printf("Allocation error\n");
        exit(-1);
    }
    indexList->indexes = NULL;
    indexList->size = 0;
    return indexList;
}

void INDEX_LIST_destroy(INDEX_LIST **list)
{
    if (*list != NULL)
    {
        for (int i = 0; i < (*list)->size; i++)
        {
            INDEX_destroy(&((*list)->indexes[i]));
        }
        free((*list)->indexes);
        (*list)->indexes = NULL;
        free(*list);
        *list = NULL;
    }
}

void INDEX_LIST_insertSorted(INDEX_LIST *list, INDEX *index, int (*compare)(INDEX *, INDEX *))
{
    if (list != NULL && index != NULL && compare != NULL)
    {
        list->indexes = realloc(list->indexes, (list->size + 1) * sizeof(INDEX *));
        (list->size)++;
        int i;
        for (i = list->size - 2; i >= 0 && compare(list->indexes[i], index) > 0; i--)
        {
            list->indexes[i + 1] = list->indexes[i];
        }
        list->indexes[i + 1] = index;
    }
}

INDEX * INDEX_LIST_getNth(INDEX_LIST *list, int n)
{
    if (list != NULL)
    {
        return list->indexes[n];
    }
    return NULL;
}

int INDEX_LIST_size(INDEX_LIST *list)
{
    if (list != NULL)
    {
        return list->size;
    }
    return -1;
}

int INDEX_LIST_searchByKey(INDEX_LIST *list, int keySearched)
{
    if (list != NULL)
    {
        int left = 0;
        int right = list->size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int key = INDEX_getKey(list->indexes[mid]) ;
            if (keySearched == key)
            {
                return mid;
            }
            else if (keySearched < key)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;       
    }
    return -1;
}

void INDEX_LIST_deleteNth(INDEX_LIST *list, int n)
{
    if (list != NULL)
    {
        INDEX_destroy(&(list->indexes[n]));
        for (int i = n; i < list->size - 1; i++)
        {
            list->indexes[i] = list->indexes[i + 1];
        }
        list->indexes = realloc(list->indexes, (list->size - 1) * sizeof(INDEX *));
        (list->size)--;
    }
}