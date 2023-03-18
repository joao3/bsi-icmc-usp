#ifndef STUDENT_INDEX_FILE_H
#define STUDENT_INDEX_FILE_H

#include "student.h"

void studentIndexFileInsert(char *studentFileName, char *indexFileName, STUDENT *student);
void studentIndexFileSearch(char *studentFileName, char *indexFileName, int key);
void studentIndexFileDelete(char *studentFileName, char *indexFileName, int key);

#endif // STUDENT_INDEX_FILE_H