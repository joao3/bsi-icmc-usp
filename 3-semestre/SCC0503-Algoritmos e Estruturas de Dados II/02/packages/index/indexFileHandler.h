#ifndef INDEX_FILE_HANDLER_H
#define INDEX_FILE_HANDLER_H

#include <stdio.h>

#include "index.h"
#include "indexList.h"

void writeIndexInFile(INDEX *index, FILE *file);
void writeIndexListInFile(INDEX_LIST *list, FILE *file);
INDEX * readNextIndexFromFile(FILE *file);
INDEX_LIST * readIndexListFromFile(FILE *file);
int numberOfIndexesInFile(FILE *file);


#endif // INDEX_FILE_HANDLER_H