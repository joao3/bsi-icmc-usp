#ifndef STUDENT_H
#define STUDENT_H

#define NAME_SIZE 15
#define SURNAME_SIZE 15
#define COURSE_SIZE 30
#define ERROR -333

typedef struct student_st STUDENT;

STUDENT * STUDENT_create();
STUDENT * STUDENT_createFilled(int nUsp, const char * name, const char *surname, const char *course, float grade);
void STUDENT_destroy(STUDENT **student);
int STUDENT_getNUSP(const STUDENT *student);
void STUDENT_setNUSP(STUDENT *student, int nUSP);
char * STUDENT_getName(STUDENT *student);
void STUDENT_setName(STUDENT *student, const char *name);
char * STUDENT_getSurname(STUDENT *student);
void STUDENT_setSurname(STUDENT *student, const char *surname);
char * STUDENT_getCourse(STUDENT *student);
void STUDENT_setCourse(STUDENT *student, const char *course);
float STUDENT_getGrade(const STUDENT *student);
void STUDENT_setGrade(STUDENT *student, float grade);
int sizeofStudent();
void STUDENT_print(const STUDENT *student);

#endif //STUDENT_H