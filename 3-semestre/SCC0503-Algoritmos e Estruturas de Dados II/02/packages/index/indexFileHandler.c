
#include "indexFileHandler.h"

void writeIndexInFile(INDEX *index, FILE *file)
{
    if (index != NULL && file != NULL)
    {
        int key = INDEX_getKey(index);
        fwrite(&key, sizeof(int), 1, file);

        int rrn = INDEX_getRRN(index);
        fwrite(&rrn, sizeof(int), 1, file);
    }
}

void writeIndexListInFile(INDEX_LIST *list, FILE *file)
{
    if (list != NULL && file != NULL)
    {
        for (int i = 0; i < INDEX_LIST_size(list); i++)
        {
            writeIndexInFile(INDEX_LIST_getNth(list, i), file);
        }
    }
}

INDEX * readNextIndexFromFile(FILE *file)
{
    if (file != NULL)
    {
        int key;
        fread(&key, sizeof(int), 1, file);

        int rrn;
        fread(&rrn, sizeof(int), 1, file);

        INDEX *index = INDEX_create();
        INDEX_setKey(index, key);
        INDEX_setRRN(index, rrn);
        return index;
    }
    return NULL;
}

INDEX_LIST * readIndexListFromFile(FILE *file)
{
    if (file != NULL)
    {
        fseek(file, 0, SEEK_SET);
        INDEX_LIST *list = INDEX_LIST_create();
        int n = numberOfIndexesInFile(file);
        for (int i = 0; i < n; i++)
        {
            INDEX *index = readNextIndexFromFile(file);
            INDEX_LIST_insertSorted(list, index, &INDEX_compareByKey);
        }
        return list;
    }
    return NULL;
}

int numberOfIndexesInFile(FILE *file)
{
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        int n = ftell(file) / sizeofIndex();
        fseek(file, 0, SEEK_SET);
        return n;
    }
    return -1;
}