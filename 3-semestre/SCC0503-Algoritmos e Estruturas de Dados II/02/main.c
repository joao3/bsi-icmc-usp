#include <stdio.h>
#include <string.h>

#include "packages/student/studentIndexFile.h"
#include "packages/student/student.h"

#define STUDENT_FILE_NAME "student.dat"
#define INDEX_FILE_NAME "index.dat"

void input();

int main()
{
    input();
}

void input()
{
    char sOperacao[256] = {0};
    while (strncmp(sOperacao, "exit",4)) {
        scanf("%s", sOperacao);
        if (!strncmp(sOperacao, "insert", 6)) {
            int nusp;
            char name[NAME_SIZE], surname[SURNAME_SIZE], course[COURSE_SIZE];
            float grade;
            scanf("%d,%14[^,],%14[^,],%29[^,],%f", &nusp, name, surname, course, &grade);
            STUDENT *student = STUDENT_create();
            STUDENT_setNUSP(student, nusp);
            STUDENT_setName(student, name);
            STUDENT_setSurname(student, surname);
            STUDENT_setCourse(student, course);
            STUDENT_setGrade(student, grade);

            studentIndexFileInsert(STUDENT_FILE_NAME, INDEX_FILE_NAME, student);

            STUDENT_destroy(&student);

        } else if (!strncmp(sOperacao, "search", 6)) {
            int key;
            scanf("%d", &key);
            studentIndexFileSearch(STUDENT_FILE_NAME, INDEX_FILE_NAME, key);
        } else if (!strncmp(sOperacao, "delete", 6)) {
            int key;
            scanf("%d", &key);
            studentIndexFileDelete(STUDENT_FILE_NAME, INDEX_FILE_NAME, key);
        }
    }
}