#include "studentFileHandler.h"

void writeStudentInFile(const STUDENT *student, FILE *file)
{
    // Se um dos ponteiros for nulo, sai
    if (student == NULL || file == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Escreve registro no arquivo
    fwrite(student, sizeofStudent(), 1, file);
}

void writeStudentInFileByRRN(const STUDENT *student, FILE *file, long rrn)
{
    // Se um dos ponteiros for nulo, sai
    if (student == NULL || file == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Move o ponteiro do arquivo para o começo
    fseek(file, 0, SEEK_SET);
    // Move o ponteiro do arquivo para a posição correta pelo rrn
    fseek(file, rrn * sizeofStudent(), SEEK_SET);
    // Escreve
    writeStudentInFile(student, file);
}

STUDENT * readNextStudentFromFile(FILE *file)
{
    // Seo o ponteiro é inválido, sai
    if (file == NULL)
    {
        printf("Invalid pointer\n");
        return NULL;
    }

    // Aloca espaço para novo registro
    STUDENT *student = STUDENT_create();
    // Lê registro
    fread(student, sizeofStudent(), 1, file);

    return student;
}

STUDENT * readStudentFromFileByRRN(FILE *file, long rrn)
{
    // Se o ponteiro é inválido, retorna nulo
    if (file == NULL)
    {
        printf("Invalid pointer\n");
        return NULL;
    }

    // Move o ponteiro do arquivo para a posição correta pelo rrn
    fseek(file, rrn * sizeofStudent(), SEEK_SET);
    // Lê
    STUDENT *student = readNextStudentFromFile(file);
    
    return student;
}

long numberOfStudentsInFile(FILE *file)
{
    // Se o ponteiro é inválido, retorna erro
    if (file == NULL)
    {
        printf("Invalid pointer\n");
        return -1;
    }

    // Move o ponteiro do arquivo para o final
    fseek(file, 0, SEEK_END);
    // Quantidade de registros = tamanhoTotal / tamanhoPorRegistro
    long n = ftell(file) / sizeofStudent();
    // Volta ao começo
    fseek(file, 0, SEEK_SET);
    
    return n;
}