#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "student.h"

struct student_st
{
    int nUSP;
    char name[NAME_SIZE];
    char surname[SURNAME_SIZE];
    char course[COURSE_SIZE];
    float grade;
};

STUDENT * STUDENT_create()
{
    STUDENT *student = malloc(1 * sizeof(STUDENT));
    if (student == NULL)
    {
        printf("Allocation error\n");
        exit(-1);
    }
    memset(student->name, 0, NAME_SIZE);
    memset(student->surname, 0, SURNAME_SIZE);
    memset(student->course, 0, COURSE_SIZE);
    return student;
}

void STUDENT_destroy(STUDENT **student)
{
    if (*student != NULL)
    {
        free(*student);
        *student = NULL;
    }
}

int STUDENT_getNUSP(STUDENT *student)
{
    if (student != NULL)
    {
        return student->nUSP;
    }
    return ERROR;
}

void STUDENT_setNUSP(STUDENT *student, int nUSP)
{
    if (student != NULL)
    {
        student->nUSP = nUSP;
    }
}

char * STUDENT_getName(STUDENT *student)
{
    if (student != NULL)
    {
        return student->name;
    }
    return NULL;
}

void STUDENT_setName(STUDENT *student, char *name)
{
    if (student != NULL)
    {
        strcpy(student->name, name);
    }
}

char * STUDENT_getSurname(STUDENT *student)
{
    if (student != NULL)
    {
        return student->surname;
    }
    return NULL;
}

void STUDENT_setSurname(STUDENT *student, char *surname)
{
    if (student != NULL)
    {
        strcpy(student->surname, surname);
    }
}

char * STUDENT_getCourse(STUDENT *student)
{
    if (student != NULL)
    {
        return student->course;
    }
    return NULL;
}

void STUDENT_setCourse(STUDENT *student, char *course)
{
    if (student != NULL)
    {
        strcpy(student->course, course);
    }
}

float STUDENT_getGrade(STUDENT *student)
{
    if (student != NULL)
    {
        return student->grade;
    }
    return ERROR;
}

void STUDENT_setGrade(STUDENT *student, float grade)
{
    if (student != NULL)
    {
        student->grade = grade;
    }
}

int sizeofStudent()
{
    return sizeof(STUDENT);
}

void STUDENT_print(STUDENT *student)
{
    if (student != NULL)
    {
        printf("-------------------------------\n");
        printf("USP number: %d\n", student->nUSP);
        printf("Name: %s\n", student->name);
        printf("Surname: %s\n", student->surname);
        printf("Course: %s\n", student->course);
        printf("Test grade: %.2f\n", student->grade);
        printf("-------------------------------\n");
    }
}