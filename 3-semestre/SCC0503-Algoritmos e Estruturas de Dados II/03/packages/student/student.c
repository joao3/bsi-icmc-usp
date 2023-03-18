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
    // Aloca memória
    STUDENT *student = calloc(1, sizeof(STUDENT));

    // Se falhou a alocação, interrompe
    if (student == NULL)
    {
        printf("Allocation error");
        exit(-1);
    }
    
    return student;
}

STUDENT * STUDENT_createFilled(int nUsp, const char * name, const char *surname, const char *course, float grade)
{
    // Aloca memória
    STUDENT *student = calloc(1, sizeof(STUDENT));
    
    // Se falhou a alocação, interrompe
    if (student == NULL)
    {
        printf("Allocation error\n");
        exit(-1);
    }

    // Preenche dados
    student->nUSP = nUsp;
    strncpy(student->name, name, NAME_SIZE);
    strncpy(student->surname, surname, SURNAME_SIZE);
    strncpy(student->course, course, COURSE_SIZE);
    student->grade = grade;
    
    return student;
}

void STUDENT_destroy(STUDENT **student)
{
    // Se o ponteiro é inválido, sai
    if (*student == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Desaloca memória
    free(*student);
    // Remove enderço de memória desalocada
    *student = NULL;
}

int STUDENT_getNUSP(const STUDENT *student)
{
    // Se o ponteiro é inválido, retorna erro
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return ERROR;
    }

    // Retorna nusp
    return student->nUSP;
}

void STUDENT_setNUSP(STUDENT *student, int nUSP)
{
    // Se o ponteiro é inválido, sai
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Define nusp
    student->nUSP = nUSP;
}

char * STUDENT_getName(STUDENT *student)
{
    // Se o ponteiro é inválido, retorna nulo
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return NULL;
    }

    // Retorna nome
    return student->name;
}

void STUDENT_setName(STUDENT *student, const char *name)
{
    // Se o ponteiro é inválido, sai
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Define nome
    strcpy(student->name, name);
}

char * STUDENT_getSurname(STUDENT *student)
{
    // Se o ponteiro é inválido, retorna nulo
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return NULL;
    }

    // Retorna sobrenome
    return student->surname;
}

void STUDENT_setSurname(STUDENT *student, const char *surname)
{
    // Se o ponteiro é inválido, sai
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }
    
    // Define sobrenome
    strcpy(student->surname, surname);
}

char * STUDENT_getCourse(STUDENT *student)
{
    // Se o ponteiro é inválido, retorna nulo
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return NULL;
    }

    // Retorna curso
    return student->course;
}

void STUDENT_setCourse(STUDENT *student, const char *course)
{
    // Se o ponteiro é inválido, sai
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Define curso
    strcpy(student->course, course);
}

float STUDENT_getGrade(const STUDENT *student)
{
    // Se o ponteiro é inválido, retorna erro
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return ERROR;
    }

    // Retorna nota
    return student->grade;
}

void STUDENT_setGrade(STUDENT *student, float grade)
{
    // Se o ponteiro é inválido, sai
    if (student == NULL)
    {
       printf("Invalid pointer\n");
       return;
    }

    // Define nota
    student->grade = grade;
}

int sizeofStudent()
{
    return sizeof(STUDENT);
}

void STUDENT_print(const STUDENT *student)
{
    if (student != NULL)
    {
        printf("-------------------------------\n");
        printf("nUSP: %d\n", student->nUSP);
        printf("Nome: %s\n", student->name);
        printf("Sobrenome: %s\n", student->surname);
        printf("Curso: %s\n", student->course);
        printf("Nota: %.2f\n", student->grade);
        printf("-------------------------------\n");
    }
}