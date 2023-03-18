#ifndef BTREE_H
#define BTREE_H

#define PAGE_SIZE 4096
#define MAX_KEYS 168
#define FILE_NAME "btree.dat"
#define FREE_SPACE PAGE_SIZE - (sizeof(record) * MAX_KEYS + sizeof(long) * (MAX_KEYS + 1) + sizeof(short) + sizeof(char) + sizeof(long))

typedef struct record_st record;
typedef struct promotedKey_st promotedKey;
typedef struct btPage_st btPage;

void createBTree(const char *fileName);
void bTreeInsert(const char *fileName, int recordKey, long recordRRN);
long bTreeSearch(const char *fileName, int key);


#endif // BTREE_H