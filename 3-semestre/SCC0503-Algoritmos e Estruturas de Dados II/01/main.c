#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "packages/aluno/aluno.h"
#include "packages/aluno/alunoManipuladorArquivo.h"
#include "packages/aluno/alunoLista.h"

#define MAX_STR 1024
#define NOME_ARQUIVO "reg.dat"

void ReadStudentInput(ALUNO_LISTA *alunos);
void escrever_alunos(FILE *file_pointer, ALUNO_LISTA *alunos);
void ler_dez_ultimos_alunos(FILE *file_pointer, ALUNO_LISTA *alunos);
void imprimir_alunos(ALUNO_LISTA *alunos);

int main()
{
    // Le alunos do stdin para alunos_escrita
    ALUNO_LISTA *alunos_escrita = aluno_lista_criar();
    ReadStudentInput(alunos_escrita);

    // Escreve alunos de arquivo_escrita para NOME_ARQUIVO (wb)
    FILE *arquivo_escrita = arquivo_abrir(NOME_ARQUIVO, "wb");
    escrever_alunos(arquivo_escrita, alunos_escrita);
    arquivo_fechar(arquivo_escrita);
    aluno_lista_destruir(&alunos_escrita);

    // Le os 10 ultimos alunos de NOME_ARQUIVO (rb) para alunos_leitura
    FILE *arquivo_leitura = arquivo_abrir(NOME_ARQUIVO, "rb");
    ALUNO_LISTA *alunos_leitura = aluno_lista_criar();
    ler_dez_ultimos_alunos(arquivo_leitura, alunos_leitura);
    arquivo_fechar(arquivo_leitura);

    // Imprime alunos_leitura
    imprimir_alunos(alunos_leitura);
    aluno_lista_destruir(&alunos_leitura);
}

void ReadStudentInput(ALUNO_LISTA *alunos){
    char line[MAX_STR];
    char final_char = 0xA;
    while (final_char == 0xA){
        fgets(line, MAX_STR, stdin);
        final_char = line[strlen(line) - 1];

        int nUSP;
        char nome[TAMANHO_STRING], curso[TAMANHO_STRING];
        float nota;
        sscanf(line, "%d,%[^,],%[^,],%f", &nUSP, nome, curso, &nota);

        ALUNO *aluno = aluno_criar();
        aluno_definir_nUSP(aluno, nUSP);
        aluno_definir_nome(aluno, nome);
        aluno_definir_curso(aluno, curso);
        aluno_definir_nota(aluno, nota);
        aluno_lista_inserir(alunos, aluno);


        memset(line, 0, sizeof(char)*MAX_STR);
    }
}

void escrever_alunos(FILE *file_pointer, ALUNO_LISTA *alunos)
{
    for (int i = 0; i < aluno_lista_tamanho(alunos); i++)
    {
        arquivo_escrever_aluno(file_pointer, aluno_lista_pegar_iesimo(alunos, i));
    }
}

void ler_dez_ultimos_alunos(FILE *file_pointer, ALUNO_LISTA *alunos)
{
    arquivo_deslocar_nposicoes(file_pointer, arquivo_quantidade_alunos(file_pointer) - 10);
    for (int i = 0; i < 10; i++)
    {
        ALUNO *aluno = aluno_criar();
        arquivo_ler_proximo_aluno(file_pointer, aluno);
        aluno_lista_inserir(alunos, aluno);
    }
}

void imprimir_alunos(ALUNO_LISTA *alunos)
{
    int n = aluno_lista_tamanho(alunos);
    for (int i = 0; i < n; i++)
    {
        aluno_imprimir(aluno_lista_pegar_iesimo(alunos, i));
        if (i != n - 1)
        {
            printf("\n");
        }
    }
}