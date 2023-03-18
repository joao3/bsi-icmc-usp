#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTADOS 10
#define MAX_TRANSICOES_ESTADO 50
#define MAX_TAMANHO_CADEIA 20

typedef struct transicao_st
{
    char simboloLido;
    char simboloEscrito;
    char movimentoCabeca;
    int indiceDestino;
} TRANSICAO;

typedef struct estado_st
{
    int ehFinal;
    int qtdTransicoes;
    TRANSICAO *transicoes[MAX_TRANSICOES_ESTADO];
} ESTADO;

typedef struct maquina_st
{
    int qtdEstados;
    int indiceEstadoAtual;
    char *simbolosTerminais;
    int qtdSimbolosTerminais;
    char *simbolosDeFita;
    int qtdSimbolosDeFita;
    ESTADO **estados;
    char fita[23];
    int indiceCabeca;
} MAQUINA;

// Aloca a maquina
MAQUINA * maquinaCriar();

// Le a definição da maquina
void maquinaLer(MAQUINA *maquina);

// Verifica se a maquina aceita a cadeia
int maquinaValidarCadeia(MAQUINA *maquina, char *cadeia);

// Parte recursiva da função de verificação da cadeia
int maquinaValidarCadeia_(MAQUINA *maquina);

// Desaloca a maquina
void maquinaDestruir(MAQUINA *maquina);

// Imprime variaveis da maquina
void maquinaImprimir(MAQUINA *maquina);

int main(int argc, char *argv[])
{   
    MAQUINA *maquina = maquinaCriar();
    maquinaLer(maquina);

    // Salva as cadeias na memória
    int n;
    scanf("%d ", &n);
    char **cadeias = malloc(n*(sizeof(char*)));
    if(cadeias == NULL){
        printf("Erro ao alocar array de cadeias!");
        exit(6);
    }
    for (int i = 0; i < n; i++)
    {
        cadeias[i] = malloc(MAX_TAMANHO_CADEIA*(sizeof(char)));
        if(cadeias[i] == NULL){
            printf("Erro ao alocar cadeia!");
            exit(7);
        }
        scanf("%s", cadeias[i]);
    }

    // Testa as cadeias
    for(int i = 0; i < n; i++)
    {
        if (maquinaValidarCadeia(maquina, cadeias[i]))
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

    maquinaDestruir(maquina);

    return 0;
}

MAQUINA * maquinaCriar()
{
    MAQUINA *maquina = malloc(1 * sizeof(MAQUINA));
    if(maquina == NULL){
        printf("Erro ao criar o maquina!");
        exit(1);
    }
    return maquina;
}

void maquinaLer(MAQUINA *maquina)
{
    maquina->indiceEstadoAtual = 0;
    maquina->indiceCabeca = 0;
    scanf("%d", &maquina->qtdEstados);

    // Aloca memória para o array de estados
    maquina->estados = malloc(maquina->qtdEstados * sizeof(ESTADO*));
    if(maquina->estados == NULL){
        printf("Erro ao alocar array de estados!");
        exit(2);
    }
    
    // Aloca memória e inicializa os estados
    for (int i = 0; i < maquina->qtdEstados; i++)
    {
        maquina->estados[i] = malloc(1 * sizeof(ESTADO));
        if(maquina->estados[i] == NULL){
            printf("Erro ao alocar estado!");
            exit(3);
        }
        maquina->estados[i]->ehFinal = 0;
        maquina->estados[i]->qtdTransicoes = 0;
    }

    // Le simbolos terminais
    scanf("%d", &maquina->qtdSimbolosTerminais);
    maquina->simbolosTerminais = malloc(maquina->qtdSimbolosTerminais * sizeof(char));
    if(maquina->simbolosTerminais == NULL){
        printf("Erro ao alocar array de simbolos terminais!");
        exit(5);
    }
    for (int i = 0; i < maquina->qtdSimbolosTerminais; i++)
    {
        scanf(" %c", &(maquina->simbolosTerminais[i]));
    }

    scanf("%d", &(maquina->qtdSimbolosDeFita));
    maquina->simbolosDeFita = malloc(maquina->qtdSimbolosDeFita*sizeof(char));
    if(maquina->simbolosDeFita == NULL){
        printf("Erro ao alocar array de simbolos de fita!");
        exit(4);
    }
    for (int i = 0; i < maquina->qtdSimbolosDeFita; i++)
    {
        scanf(" %c", &(maquina->simbolosDeFita[i]));
    }

    // Le estado de aceitacao
    int indiceEstadoAceitacao;
    scanf("%d", &indiceEstadoAceitacao);
    maquina->estados[indiceEstadoAceitacao]->ehFinal = 1;
    
    // Le transições
    int qtdTransicoes;
    scanf("%d", &qtdTransicoes);
    for (int i = 0; i < qtdTransicoes; i++)
    {
        int origem, destino;
        char simboloLido, simboloEscrito, movimentoCabeca;
        scanf("%d", &origem);
        scanf(" %c", &simboloLido);
        scanf(" %d", &destino);
        scanf(" %c", &simboloEscrito);
        scanf(" %c", &movimentoCabeca);
        
        ESTADO *estadoOrigem = maquina->estados[origem];
        int indiceTransicaoAtual = estadoOrigem->qtdTransicoes;


        TRANSICAO* transicaoAtual = malloc(1 * sizeof(TRANSICAO));
        if(transicaoAtual == NULL){
            printf("Erro ao alocar transicao!");
            exit(5);
        }

        transicaoAtual->simboloLido = simboloLido;
        transicaoAtual->simboloEscrito = simboloEscrito;
        transicaoAtual->movimentoCabeca = movimentoCabeca;
        transicaoAtual->indiceDestino = destino;

        estadoOrigem->transicoes[indiceTransicaoAtual] = transicaoAtual;
        estadoOrigem->qtdTransicoes = indiceTransicaoAtual+1;
    }
}

int maquinaValidarCadeia(MAQUINA *maquina, char *cadeia)
{
    maquina->indiceEstadoAtual = 0;
    maquina->indiceCabeca = 1;

    // Se a cadeia lida é vazia, preenche a fita com brancos
    if (!strcmp(cadeia, "-"))
    {
        memset(maquina->fita, 'B', 23);
    }
    else
    {
        maquina->fita[0] = 'B';
        maquina->fita[21] = 'B';
        maquina->fita[22] = '\0';
    
        strncpy(maquina->fita + 1, cadeia, 20);
        int len = strlen(cadeia);
        for (int i = len + 1; i < 22; i++)
        {
            maquina->fita[i] = 'B';
        }
    }
    
    

    return maquinaValidarCadeia_(maquina);
}

int maquinaValidarCadeia_(MAQUINA *maquina)
{
    int indice = maquina->indiceEstadoAtual;
    // estado abordado nessa recursão
    ESTADO *estadoAtual = maquina->estados[indice];
    
    if (estadoAtual->ehFinal) 
    {
        return 1;
    }
    
    // Caractere atual
    char c = maquina->fita[maquina->indiceCabeca];
    
    // Verifica todas as transições que saem do estado atual
    for (int i = 0; i < estadoAtual->qtdTransicoes; i++)
    {
        // Se o caractere da transição é mesmo que c
        if (c == estadoAtual->transicoes[i]->simboloLido)
        {
            // Muda o estado atual para o alvo da transição
            maquina->fita[maquina->indiceCabeca] = estadoAtual->transicoes[i]->simboloEscrito;
            if (estadoAtual->transicoes[i]->movimentoCabeca == 'R'){
              (maquina->indiceCabeca)++;
            }
            else if (estadoAtual->transicoes[i]->movimentoCabeca == 'L'){
              (maquina->indiceCabeca)--;
            }
            maquina->indiceEstadoAtual = estadoAtual->transicoes[i]->indiceDestino;

            // Chama a função recursivamente para a maquina com o novo estado e o proximo caractere da cadeia
            if (maquinaValidarCadeia_(maquina))
            {
                // Se todas as recursões retornarem positivo, quer dizer que a maquina aceita a cadeia
                return 1;
            }
        }
    }
    return 0;
}

void maquinaDestruir(MAQUINA *maquina)
{
    for (int i = 0; i < maquina->qtdEstados; i++)
    {
        ESTADO *estado = maquina->estados[i];
        for (int j = 0; j < estado->qtdTransicoes; j++)
        {
            free(estado->transicoes[j]);
        }
        free(estado);
    }
    free(maquina->estados);
    free(maquina->simbolosTerminais);
    free(maquina->simbolosDeFita);
    free(maquina);
}

void maquinaImprimir(MAQUINA *maquina)
{
    printf("Indice atual: %d\n", maquina->indiceEstadoAtual);
    printf("Transicoes:\n");
    for (int i = 0; i < maquina->qtdEstados; i++)
    {
        ESTADO *estado = maquina->estados[i];

        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("ESTADO %d:\n", i);
        printf("eh final: %d\n", estado->ehFinal);
        printf("%s\n", maquina->fita);
        printf("transicoes:\n");
        for (int j = 0; j < estado->qtdTransicoes; j++)
        {
            printf("%d %c %d %c %c\n", i, estado->transicoes[j]->simboloLido, estado->transicoes[j]->indiceDestino,
                estado->transicoes[j]->simboloEscrito, estado->transicoes[j]->movimentoCabeca);
        }
    }
}