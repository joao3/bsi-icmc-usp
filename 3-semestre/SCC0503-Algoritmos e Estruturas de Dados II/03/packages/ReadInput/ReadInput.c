#include "ReadInput.h"
#include "../student/student.h"
#include "../student/studentBTree.h"
#include <string.h>
#define MAX_COMMAND_LENGTH 1024
#define MAX_STR_LENGTH 512

// Le os comandos dados conforme pedido
void ReadInput()
{
    while (1)
    {
        // Armazena o comando inteiro
        char full_command[MAX_COMMAND_LENGTH];

        // Armazena a operacao
        char operacao[MAX_COMMAND_LENGTH];

        // Dados do novo aluno a ser inserido
        int nUSP;
        char nome[MAX_STR_LENGTH] = {0};
        char sobrenome[MAX_STR_LENGTH] = {0};
        char curso[MAX_STR_LENGTH] = {0};
        float nota;
        STUDENT *Student = NULL;

        fgets(full_command, MAX_COMMAND_LENGTH, stdin);
        sscanf(full_command, "%s", operacao);

        if (!strcmp(operacao, "insert"))
        {
            sscanf(full_command, "%s %d,\"%512[^\"]\",\"%512[^\"]\",\"%512[^\"]\",%f", operacao, &nUSP, nome, sobrenome, curso, &nota);
            Student = STUDENT_createFilled(nUSP, nome, sobrenome, curso, nota);
            insert(Student);
            STUDENT_destroy(&Student);
        }
        else if (!strcmp(operacao, "search"))
        {
            sscanf(full_command, "%s %d", operacao, &nUSP);
            search(nUSP);
        }
        else if (!strcmp(operacao, "update"))
        {
            sscanf(full_command, "%s %d,\"%512[^\"]\",\"%512[^\"]\",\"%512[^\"]\",%f", operacao, &nUSP, nome, sobrenome, curso, &nota);
            Student = STUDENT_createFilled(nUSP, nome, sobrenome, curso, nota);
            update(Student);
            STUDENT_destroy(&Student);
        }
        else if (!strcmp(operacao, "exit"))
        {
            break;
        }
    }
}