#ifndef STUDENT_H
#define STUDENT_H

#define NAME_SIZE 15
#define SURNAME_SIZE 15
#define COURSE_SIZE 30
#define ERROR -333

typedef struct student_st STUDENT;

STUDENT * STUDENT_create();
void STUDENT_destroy(STUDENT **student);
int STUDENT_getNUSP(STUDENT *student);
void STUDENT_setNUSP(STUDENT *student, int nUSP);
char * STUDENT_getName(STUDENT *student);
void STUDENT_setName(STUDENT *student, char *name);
char * STUDENT_getSurname(STUDENT *student);
void STUDENT_setSurname(STUDENT *student, char *surname);
char * STUDENT_getCourse(STUDENT *student);
void STUDENT_setCourse(STUDENT *student, char *course);
float STUDENT_getGrade(STUDENT *student);
void STUDENT_setGrade(STUDENT *student, float grade);
int sizeofStudent();
void STUDENT_print(STUDENT *student);

#endif //STUDENT_H