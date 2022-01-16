#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "packages/registro/registro.h"
#include "packages/cliente/cliente.h"
#include "packages/util/utilString.h"

void loop_leitura(REGISTRO *registro);
void cadastrar_cliente(REGISTRO *registro, BIGNUMBER *cpf, char *nome, int idade, float saldo);
BIGNUMBER * cpf_string_para_bignumber(char *cpf_string);
void loop_impressao(REGISTRO *registro);

int main()
{
    REGISTRO *registro = registro_criar();
    loop_leitura(registro);
    loop_impressao(registro);
    registro_destruir(&registro);
}

void loop_leitura(REGISTRO *registro)
{
    int n;
    scanf("%d", &n);
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
        char *cpf_string = string_criar(15);
        strncpy(cpf_string, linha, contador);
        BIGNUMBER *cpf = cpf_string_para_bignumber(cpf_string);
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
        char *idade_string  = string_criar(15);
        strncpy(idade_string, linha, contador);
        int idade = atoi(idade_string);
        linha += contador + 1;

        char *saldo_string = string_criar(25);
        strcpy(saldo_string, linha);
        float saldo = atof(saldo_string);

        cadastrar_cliente(registro, cpf, nome, idade, saldo);

        string_destruir(&cpf_string);
        string_destruir(&nome);
        string_destruir(&idade_string);
        string_destruir(&saldo_string);
        string_destruir(&linha_backup);
    }
}

BIGNUMBER * cpf_string_para_bignumber(char *cpf_string)
{
    int tamanho_string = strlen(cpf_string);
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
    BIGNUMBER *cpf = bignumber_criar();
    converter_string_para_bignumber(cpf_string, cpf);
    return cpf;
}

void cadastrar_cliente(REGISTRO *registro, BIGNUMBER *cpf, char *nome, int idade, float saldo)
{
    CLIENTE *cliente = cliente_criar();
    cliente_definir_cpf(cliente, cpf);
    cliente_definir_nome(cliente, nome);
    cliente_definir_idade(cliente, idade);
    cliente_definir_saldo(cliente, saldo);
    registro_inserir_cliente(registro, cliente);
}

void loop_impressao(REGISTRO *registro)
{
    printf("Inorder\n");
    registro_imprimir_cpf_emordem(registro);
    printf("\n");
    printf("Preorder\n");
    registro_imprimir_cpf_preordem(registro);
    printf("\n");
    printf("Postorder\n");
    registro_imprimir_cpf_posordem(registro);
    printf("\n");
}