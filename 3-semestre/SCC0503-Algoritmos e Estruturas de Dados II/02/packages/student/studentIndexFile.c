#include <stdio.h>

#include "studentIndexFile.h"
#include "studentFileHandler.h"
#include "../index/indexList.h"
#include "../index/indexFileHandler.h"
#include "../index/index.h"

void studentIndexFileInsert(char *studentFileName, char *indexFileName, STUDENT *student)
{
    int key = STUDENT_getNUSP(student);

    // Checks if the key is already in the index file
    FILE *indexFile = fopen(indexFileName, "rb");
    INDEX_LIST *indexList;
    if (indexFile != NULL)
    {
        indexList = readIndexListFromFile(indexFile);

        if (INDEX_LIST_searchByKey(indexList, key) >= 0)
        {
            printf("O Registro ja existe!\n");
            INDEX_LIST_destroy(&indexList);
            fclose(indexFile);
            return;
        }
        INDEX_LIST_destroy(&indexList);
        fclose(indexFile);
    }

    // Get the rrn of the student to be inserted
    int rrn;
    FILE *studentFile = fopen(studentFileName, "rb");
    if (studentFile != NULL)
    {
        rrn = numberOfStudentsInFile(studentFile);
        fclose(studentFile);
    }
    else
    {
        rrn = 0;
    }

    // Write the student in the file
    studentFile = fopen(studentFileName, "ab");
    writeStudentInFile(student, studentFile);
    fclose(studentFile);

    indexFile = fopen(indexFileName, "rb");
    // If not the first index, the list must be read
    if (indexFile != NULL)
    {
        indexList = readIndexListFromFile(indexFile);
        fclose(indexFile);
    }
    // Else, the list must be created
    else
    {
        indexList = INDEX_LIST_create();
    }

    // Overwrite the indexFile with the updated list
    indexFile = fopen(indexFileName, "wb");
    INDEX *index = INDEX_create();
    INDEX_setRRN(index, rrn);
    INDEX_setKey(index, key);
    INDEX_LIST_insertSorted(indexList, index, &INDEX_compareByKey);
    writeIndexListInFile(indexList, indexFile);
    INDEX_LIST_destroy(&indexList);
    fclose(indexFile);
}

void studentIndexFileSearch(char *studentFileName, char *indexFileName, int key)
{
    FILE *indexFile = fopen(indexFileName, "rb");
    // If index file doesnt exists, return
    if (indexFile == NULL)
    {
        printf("Registro nao encontrado!\n");
        return;
    }

    // Load the list and search
    INDEX_LIST *indexList = readIndexListFromFile(indexFile);
    int n = INDEX_LIST_searchByKey(indexList, key);

    // The key is not in the list
    if (n < 0)
    {
        printf("Registro nao encontrado!\n");
        fclose(indexFile);
        INDEX_LIST_destroy(&indexList);
        return;
    }

    // Get the corresponding rrn
    INDEX *index = INDEX_LIST_getNth(indexList, n);
    int rrn = INDEX_getRRN(index);
    fclose(indexFile);
    INDEX_LIST_destroy(&indexList);

    // Read and print student by rrn
    FILE *studentFile = fopen(studentFileName, "rb");
    STUDENT *student = readStudentFromFileByRRN(studentFile, rrn);
    fclose(studentFile);
    STUDENT_print(student);
    STUDENT_destroy(&student);
}

void studentIndexFileDelete(char *studentFileName, char *indexFileName, int key)
{
    FILE *indexFile = fopen(indexFileName, "rb");
    // If index file doesnt exists, return
    if (indexFile == NULL)
    {
        return;
    }

    // Load the list and search
    INDEX_LIST *indexList = readIndexListFromFile(indexFile);
    int n = INDEX_LIST_searchByKey(indexList, key);

    // The key is not in the list
    fclose(indexFile);
    if (n < 0)
    {
        INDEX_LIST_destroy(&indexList);
        return;
    }

    // Get the corresponding rrn
    INDEX *index = INDEX_LIST_getNth(indexList, n);
    int rrn = INDEX_getRRN(index);

    // Logical delete
    FILE *studentFile = fopen(studentFileName, "rb+");
    logicalDeleteByRRN(studentFile, rrn);
    fclose(studentFile);

    // Remove index from list
    INDEX_LIST_deleteNth(indexList, n);

    // Overwrite the indexFile with the updated list
    indexFile = fopen(indexFileName, "wb");
    writeIndexListInFile(indexList, indexFile);
    INDEX_LIST_destroy(&indexList);
    fclose(indexFile);
}