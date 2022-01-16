#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "packages/registro/registro.h"
#include "packages/cliente/cliente.h"
#include "packages/util/utilString.h"

void loop_leitura(REGISTRO *registro, int n);
void cadastrar_cliente(REGISTRO *registro, char *cpf, char *nome, int idade, float saldo);
void cpf_remover_pontos(char *cpf_string);
void operacoes(REGISTRO *registro);

int main()
{
    REGISTRO *registro = registro_criar();
    int n;
    scanf("%d", &n);
    loop_leitura(registro, n);
    operacoes(registro);
    printf("\n");
    registro_destruir(&registro);
}

void loop_leitura(REGISTRO *registro, int n)
{
    for (int i = 0; i < n; i++)
    {
        char *linha = string_criar(TAMANHO_STRING);
        scanf(" %[^(\r|\n)]", linha);
        char *linha_backup = linha;

        int contador = 0;
        while (linha[contador] != ';')
        {
            contador++;
        }
        char *cpf = string_criar(TAMANHO_CPF);
        strncpy(cpf, linha, contador);
        cpf_remover_pontos(cpf);
        linha += contador + 1;

        contador = 0;
        while (linha[contador] != ';')
        {
            contador++;
        }
        char *nome = string_criar(TAMANHO_STRING);
        strncpy(nome, linha, contador);
        linha += contador + 1;

        contador = 0;
        while (linha[contador] != ';')
        {
            contador++;
        }
        char *idade_string  = string_criar(10);
        strncpy(idade_string, linha, contador);
        int idade = atoi(idade_string);
        linha += contador + 1;

        char *saldo_string = string_criar(25);
        strcpy(saldo_string, linha);
        float saldo = (float) atof(saldo_string);

        cadastrar_cliente(registro, cpf, nome, idade, saldo);

        string_destruir(&cpf);
        string_destruir(&nome);
        string_destruir(&idade_string);
        string_destruir(&saldo_string);
        string_destruir(&linha_backup);
    }
}

void cpf_remover_pontos(char *cpf_string)
{
    int tamanho_string = (int) strlen(cpf_string);
    int contador = 0;
    while (cpf_string[contador] != '\0')
    {
        if (cpf_string[contador] == '.' || cpf_string[contador] == '-')
        {
            for (int i = contador; i < tamanho_string; i++)
            {
                cpf_string[i] = cpf_string[i + 1];
            }
        }
        contador++;
    }
}

void cadastrar_cliente(REGISTRO *registro, char *cpf, char *nome, int idade, float saldo)
{
    CLIENTE *cliente = cliente_criar();
    cliente_definir_cpf(cliente, cpf);
    cliente_definir_nome(cliente, nome);
    cliente_definir_idade(cliente, idade);
    cliente_definir_saldo(cliente, saldo);
    registro_inserir_cliente(registro, cliente);
}

void operacoes(REGISTRO *registro)
{
    getchar();
    char operacao;
    scanf("%c", &operacao);
    if (operacao == 'I')
    {
        loop_leitura(registro, 1);

        printf("Preorder\n");
        registro_imprimir_cpf_preordem(registro);
    }
    else if (operacao == 'R')
    {
        char *cpf_buscado = string_criar(TAMANHO_CPF);
        scanf("%s", cpf_buscado);
        cpf_remover_pontos(cpf_buscado);

        CLIENTE *cliente = registro_buscar_cliente_por_cpf(registro, cpf_buscado);
        if (cliente != NULL)
        {
            cliente_imprimir(cliente);
            registro_remover_cliente_por_cpf(registro, cpf_buscado);
        }
        else
        {
            printf("Pessoa nao encontrada.\n");
        }
        printf("Preorder\n");
        registro_imprimir_cpf_preordem(registro);

        string_destruir(&cpf_buscado);
    }
    else if (operacao == 'B')
    {
        char *cpf_buscado = string_criar(TAMANHO_CPF);
        scanf("%s", cpf_buscado);
        cpf_remover_pontos(cpf_buscado);

        CLIENTE *cliente = registro_buscar_cliente_por_cpf(registro, cpf_buscado);
        if (cliente != NULL)
        {
            cliente_imprimir(cliente);
        }
        else
        {
            printf("Pessoa nao encontrada.\n");
        }

        string_destruir(&cpf_buscado);
    }
}