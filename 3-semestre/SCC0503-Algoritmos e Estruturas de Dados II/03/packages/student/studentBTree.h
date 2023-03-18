#ifndef STUDENT_BTREE_H
#define STUDENT_BTREE_H

#define STUDENT_FILENAME "student.dat"

#include "student.h"

void insert(const STUDENT *student);
void search(int key);
void update(const STUDENT *student);

#endif //STUDENT_BTREE_H