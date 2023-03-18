#ifndef STUDENT_FILE_HANDLER_H
#define STUDENT_FILE_HANDLER_H

#include <stdio.h>

#include "student.h"

void writeStudentInFile(STUDENT *student, FILE *file);
STUDENT * readNextStudentFromFile(FILE *file);
STUDENT * readStudentFromFileByRRN(FILE *file, int rrn);
// Includes logically deleted students
int numberOfStudentsInFile(FILE *file);
void logicalDeleteByRRN(FILE *file, int rrn);

#endif // STUDENT_FILE_HANDLER_H