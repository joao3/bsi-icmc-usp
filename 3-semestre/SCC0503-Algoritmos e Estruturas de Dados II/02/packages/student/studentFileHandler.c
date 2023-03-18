

#include "studentFileHandler.h"

void writeStudentInFile(STUDENT *student, FILE *file)
{
    if (student != NULL && file != NULL)
    {
        int nusp = STUDENT_getNUSP(student);
        fwrite(&nusp, sizeof(int), 1, file);
        char *name = STUDENT_getName(student);
        fwrite(name, sizeof(char), NAME_SIZE, file);
        char *surname = STUDENT_getSurname(student);
        fwrite(surname, sizeof(char), SURNAME_SIZE, file);
        char *course = STUDENT_getCourse(student);
        fwrite(course, sizeof(char), COURSE_SIZE, file);
        float grade = STUDENT_getGrade(student);
        fwrite(&grade, sizeof(float), 1, file);
    }
}

STUDENT * readNextStudentFromFile(FILE *file)
{
    if (file != NULL)
    {
        int nusp;
        fread(&nusp, sizeof(int), 1, file);
        char name[NAME_SIZE];
        fread(name, sizeof(char), NAME_SIZE, file);
        char surname[SURNAME_SIZE];
        fread(surname, sizeof(char), SURNAME_SIZE, file);
        char course[COURSE_SIZE];
        fread(course, sizeof(char), COURSE_SIZE, file);
        float grade;
        fread(&grade, sizeof(float), 1, file);

        STUDENT *student = STUDENT_create();
        STUDENT_setNUSP(student, nusp);
        STUDENT_setName(student, name);
        STUDENT_setSurname(student, surname);
        STUDENT_setCourse(student, course);
        STUDENT_setGrade(student, grade);

        return student;
    }
    return NULL;
}

STUDENT * readStudentFromFileByRRN(FILE *file, int rrn)
{
    if (file != NULL)
    {
        fseek(file, rrn * sizeofStudent(), SEEK_SET);
        STUDENT *student = readNextStudentFromFile(file);
        return student;
    }
    return NULL;
}

void logicalDeleteByRRN(FILE *file, int rrn)
{
    if (file != NULL)
    {
        fseek(file, rrn * sizeofStudent(), SEEK_SET);
        STUDENT *student = readNextStudentFromFile(file);
        STUDENT_setNUSP(student, -1);
        fseek(file, rrn * sizeofStudent(), SEEK_SET);
        writeStudentInFile(student, file);
        STUDENT_destroy(&student);
    }
}

// Includes logically deleted students
int numberOfStudentsInFile(FILE *file)
{
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        int n = ftell(file) / sizeofStudent();
        fseek(file, 0, SEEK_SET);
        return n;
    }
    return -1;
}