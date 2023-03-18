#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTADOS 10
#define MAX_TRANSICOES_ESTADO 50
#define MAX_TAMANHO_CADEIA 20

typedef struct transicao_st
{
    char c;
    int indiceDestino;
} TRANSICAO;

typedef struct estado_st
{
    int ehFinal;
    int qtdTransicoes;
    TRANSICAO *transicoes[MAX_TRANSICOES_ESTADO];
} ESTADO;

typedef struct automato_st
{
    int qtdEstados;
    int indiceEstadoAtual;
    char *simbolosTerminais;
    int qtdSimbolosTerminais;
    ESTADO **estados;
} AUTOMATO;

// Aloca o automato
AUTOMATO *automatoCriar();

// Le a definição do automato
void automatoLer(AUTOMATO *automato);

// Verifica se o automato aceita a cadeia
int automatoValidarCadeia(AUTOMATO *automato, char *cadeia);

// Parte recursiva da função de verificação da cadeia
int automatoValidarCadeia_(AUTOMATO *automato, char *cadeia);

// Desaloca o automato
void automatoDestruir(AUTOMATO *automato);

// Imprime variaveis do automato
void automatoImprimir(AUTOMATO *automato);

int main(int argc, char *argv[])
{
    AUTOMATO *automato = automatoCriar();
    automatoLer(automato);

    // Salva as cadeias na memória
    int n;
    scanf("%d ", &n);
    char **cadeias = malloc(n * (sizeof(char *)));
    if (cadeias == NULL)
    {
        printf("Erro ao alocar array de cadeias!");
        exit(6);
    }
    for (int i = 0; i < n; i++)
    {
        cadeias[i] = malloc(MAX_TAMANHO_CADEIA * (sizeof(char)));
        if (cadeias[i] == NULL)
        {
            printf("Erro ao alocar cadeia!");
            exit(7);
        }
        scanf("%s", cadeias[i]);
    }

    // Testa as cadeias
    for (int i = 0; i < n; i++)
    {
        if (automatoValidarCadeia(automato, cadeias[i]))
        {
            printf("aceita\n");
        }
        else
        {
            printf("rejeita\n");
        }
        free(cadeias[i]);
    }

    free(cadeias);

    automatoDestruir(automato);

    return 0;
}

AUTOMATO *automatoCriar()
{
    AUTOMATO *automato = malloc(1 * sizeof(AUTOMATO));
    if (automato == NULL)
    {
        printf("Erro ao criar o automato!");
        exit(1);
    }
    return automato;
}

void automatoLer(AUTOMATO *automato)
{
    automato->indiceEstadoAtual = 0;
    scanf("%d", &automato->qtdEstados);

    // Aloca memória para o array de estados
    automato->estados = malloc(automato->qtdEstados * sizeof(ESTADO *));
    if (automato->estados == NULL)
    {
        printf("Erro ao alocar array de estados!");
        exit(2);
    }

    // Aloca memória e inicializa os estados
    for (int i = 0; i < automato->qtdEstados; i++)
    {
        automato->estados[i] = malloc(1 * sizeof(ESTADO));
        if (automato->estados[i] == NULL)
        {
            printf("Erro ao alocar estado!");
            exit(3);
        }
        automato->estados[i]->ehFinal = 0;
        automato->estados[i]->qtdTransicoes = 0;
    }

    // Le simbolos terminais
    scanf("%d", &automato->qtdSimbolosTerminais);
    automato->simbolosTerminais = malloc(automato->qtdSimbolosTerminais * sizeof(char));
    if (automato->simbolosTerminais == NULL)
    {
        printf("Erro ao alocar array de simbolos terminais!");
        exit(4);
    }
    for (int i = 0; i < automato->qtdSimbolosTerminais; i++)
    {
        scanf(" %c", automato->simbolosTerminais);
    }

    // Le estados finais
    int qtdEstadosFinais;
    scanf("%d", &qtdEstadosFinais);
    for (int i = 0; i < qtdEstadosFinais; i++)
    {
        int indice;
        scanf("%d", &indice);
        automato->estados[indice]->ehFinal = 1;
    }

    // Le transições
    int qtdTransicoes;
    scanf("%d", &qtdTransicoes);
    for (int i = 0; i < qtdTransicoes; i++)
    {
        int origem, destino;
        char c;
        scanf("%d ", &origem);
        scanf(" %c", &c);
        scanf("%d ", &destino);

        ESTADO *estadoOrigem = automato->estados[origem];
        int indiceTransicaoAtual = estadoOrigem->qtdTransicoes;

        estadoOrigem->transicoes[indiceTransicaoAtual] = malloc(1 * sizeof(TRANSICAO));
        if (estadoOrigem->transicoes[indiceTransicaoAtual] == NULL)
        {
            printf("Erro ao alocar transicao!");
            exit(5);
        }

        estadoOrigem->transicoes[indiceTransicaoAtual]->c = c;
        estadoOrigem->transicoes[indiceTransicaoAtual]->indiceDestino = destino;
        estadoOrigem->qtdTransicoes = indiceTransicaoAtual + 1;
    }
}

int automatoValidarCadeia(AUTOMATO *automato, char *cadeia)
{
    int indice = automato->indiceEstadoAtual;

    // cadeia vazia
    if (strlen(cadeia) == 1 && cadeia[0] == '-')
    {
        if (automato->estados[indice]->ehFinal)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return automatoValidarCadeia_(automato, cadeia);
    }
}

int automatoValidarCadeia_(AUTOMATO *automato, char *cadeia)
{
    int indice = automato->indiceEstadoAtual;

    // Caso base
    if (cadeia[0] == '\0')
    {
        // Se o estado atual é um estado final retorna verdadeiro, senao retorna falso
        if (automato->estados[indice]->ehFinal)
        {
            return 1;
        }
        return 0;
    }

    // Caractere atual
    char c = *cadeia;

    // estado abordado nessa recursão
    ESTADO *estadoAtual = automato->estados[indice];

    // Verifica todas as transições que saem do estado atual
    for (int i = 0; i < estadoAtual->qtdTransicoes; i++)
    {
        // Se o caractere da transição é mesmo que c
        if (c == estadoAtual->transicoes[i]->c)
        {
            // Muda o estado atual para o alvo da transição
            automato->indiceEstadoAtual = estadoAtual->transicoes[i]->indiceDestino;

            // Chama a função recursivamente para o automato com o novo estado e o proximo caractere da cadeia
            if (automatoValidarCadeia(automato, cadeia + 1))
            {
                // Retorna o estado atual ao seu valor anterior
                automato->indiceEstadoAtual = indice;

                // Se todas as recursões retornarem positivo, quer dizer que o automato aceita a cadeia
                return 1;
            }
        }
        // Retorna o estado atual ao seu valor anterior
        automato->indiceEstadoAtual = indice;
    }
    return 0;
}

void automatoDestruir(AUTOMATO *automato)
{
    for (int i = 0; i < automato->qtdEstados; i++)
    {
        ESTADO *estado = automato->estados[i];
        for (int j = 0; j < estado->qtdTransicoes; j++)
        {
            free(estado->transicoes[j]);
        }
        free(estado);
    }
    free(automato->estados);
    free(automato->simbolosTerminais);
    free(automato);
}

void automatoImprimir(AUTOMATO *automato)
{
    printf("Indice atual: %d\n", automato->indiceEstadoAtual);
    printf("Transicoes:\n");
    for (int i = 0; i < automato->qtdEstados; i++)
    {
        ESTADO *estado = automato->estados[i];

        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("ESTADO %d:\n", i);
        printf("eh final: %d\n", estado->ehFinal);
        printf("transicoes:\n");
        for (int j = 0; j < estado->qtdTransicoes; j++)
        {
            printf("%d %c %d\n", i, estado->transicoes[j]->c, estado->transicoes[j]->indiceDestino);
        }
    }
}
