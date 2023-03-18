#ifndef INDEX_LIST_H
#define INDEX_LIST_H

#include "index.h"

typedef struct indexList_st INDEX_LIST;

INDEX_LIST * INDEX_LIST_create();
void INDEX_LIST_destroy(INDEX_LIST **list);
void INDEX_LIST_insertSorted(INDEX_LIST *list, INDEX *index, int (*compare)(INDEX *, INDEX *));
INDEX * INDEX_LIST_getNth(INDEX_LIST *list, int n);
int INDEX_LIST_size(INDEX_LIST *list);
int INDEX_LIST_searchByKey(INDEX_LIST *list, int keySearched);
void INDEX_LIST_deleteNth(INDEX_LIST *list, int n);

#endif // INDEX_LIST_H