#ifndef STUDENT_FILE_HANDLER_H
#define STUDENT_FILE_HANDLER_H

#include <stdio.h>

#include "student.h"

void writeStudentInFile(const STUDENT *student, FILE *file);
void writeStudentInFileByRRN(const STUDENT *student, FILE *file, long rrn);
STUDENT * readNextStudentFromFile(FILE *file);
STUDENT * readStudentFromFileByRRN(FILE *file, long rrn);
long numberOfStudentsInFile(FILE *file);

#endif // STUDENT_FILE_HANDLER_H