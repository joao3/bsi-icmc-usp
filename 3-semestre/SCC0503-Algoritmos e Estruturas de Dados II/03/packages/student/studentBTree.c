// Este módulo é responsável por integrar a escrita de registros em arquivo secundário e a indexação dos mesmos em árvore B
// insert, search e update são as funções mais abstratas do sistema

#include "studentBTree.h"
#include "studentFileHandler.h"
#include "../bTree/bTree.h"

static long getNewStudentRRN()
{
    // Abre o arquivo de registros para leitura
    FILE *fp = fopen(STUDENT_FILENAME, "rb");
    // Verifica a abertura do arqujivo
    if (fp == NULL)
    {
        printf("File error\n");
        return -1;
    }
    // O rrn do registro a ser inserido é igual a quantidade de registros existentes
    long rrn = numberOfStudentsInFile(fp);
    // Fecha o arquivo
    fclose(fp);

    return rrn;
}

static void writeNewStudent(const STUDENT *student)
{
    // Abre o arquivo de registros no modo de acrescentar
    FILE *fp = fopen(STUDENT_FILENAME, "ab");
    // Verifica a abertura do arquivo
    if (fp == NULL)
    {
        printf("File error\n");
        return;
    }
    // Escreve registro no final do arquivo
    writeStudentInFile(student, fp);
    // Fecha arquivo
    fclose(fp);
}

void insert(const STUDENT *student)
{
    // Se o ponteiro é inválido, sai
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // A chave será o nusp
    int key = STUDENT_getNUSP(student);

    // Se a busca retornar um rrn válido, o registro já existe
    if (bTreeSearch(FILE_NAME, key) >= 0)
    {
        printf("O Registro ja existe!\n");
        return;
    }

    // Acha o rrn do registro que será inserido
    long rrn = getNewStudentRRN();

    // Escreve novo registro
    writeNewStudent(student);

    // Insere indice na árvore B
    bTreeInsert(FILE_NAME, key, rrn);
}

void search(int key)
{
    // Busca o rrn pela chave na árvore B
    long rrn = bTreeSearch(FILE_NAME, key);
    // Se o rrn for inválido, o registro não está na árvore
    if (rrn < 0)
    {
        printf("Registro nao encontrado!\n");
        return;
    }

    // Abre o arquivo de registros para leitura
    FILE *fp = fopen(STUDENT_FILENAME, "rb");
    // Verifica a abertura do arquivo
    if (fp == NULL)
    {
        printf("File error\n");
        return;
    }
    // Le o registro pelo rrn acado na árvore
    STUDENT *student = readStudentFromFileByRRN(fp, rrn);
    // Fecha o arquivo
    fclose(fp);

    STUDENT_print(student);
    STUDENT_destroy(&student);
}

void update(const STUDENT *student)
{
    // Se o ponteiro for inválido, sai
    if (student == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Busca o rrn pela chave na árvore B
    long rrn = bTreeSearch(FILE_NAME, STUDENT_getNUSP(student));
    // Se o rrn for inválido, o registro não está na árvore
    if (rrn < 0)
    {
        printf("Registro nao encontrado!\n");
        return;
    }

    // Abre o arquivo de registros para leitura e escrita
    FILE *fp = fopen(STUDENT_FILENAME, "rb+");
    // Verifica a abertura do arquivo
    if (fp == NULL)
    {
        printf("File error\n");
        return;
    }
    // Escreve o novo registro 
    writeStudentInFileByRRN(student, fp, rrn);
    fclose(fp);
}