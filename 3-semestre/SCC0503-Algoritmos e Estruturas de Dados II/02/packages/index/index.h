#ifndef INDEX_H
#define INDEX_H

typedef struct index_st INDEX;

INDEX * INDEX_create();
void INDEX_destroy(INDEX **index);
int INDEX_getKey(INDEX *index);
void INDEX_setKey(INDEX *index, int key);
int INDEX_getRRN(INDEX *index);
void INDEX_setRRN(INDEX *index, int RRN);
int INDEX_compareByKey(INDEX *index1, INDEX *index2);
int sizeofIndex();

#endif // INDEX_H