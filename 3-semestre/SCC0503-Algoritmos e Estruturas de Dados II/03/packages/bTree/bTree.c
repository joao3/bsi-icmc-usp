#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bTree.h"

struct promotedKey_st
{
    int key;
    long recordRRN;
    long childs[2];
};

struct record_st
{
    int key;
    long recordRRN;
};

struct btPage_st
{
    record *records;
    long *childs;
    short numberOfKeys;
    char isLeaf;
    long selfRRN;
};

record * recordsCreate(int n);
void recordsDestroy(record **records);
long * childsCreate(int n);
void childsDestroy(long **childs);

btPage * pageCreate()
{
    // Aloca memória
    btPage *page = calloc(1, sizeof(btPage));
    // Verifica alocação
    if (page == NULL)
    {
        printf("Allocation error\n");
        exit(-1);
    }

    // Aloca espaço para vetor de records
    page->records = recordsCreate(MAX_KEYS);
    // Aloca espaço para vetor de páginas filhas
    page->childs = childsCreate(MAX_KEYS + 1);

    // Inicializa valores
    page->numberOfKeys = 0;
    page->selfRRN = -1;
    
    return page;
}

void pageDestroy(btPage **page)
{
    // Verifica ponteiro
    if (*page == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Desaloca vetor de páginas filhas
    childsDestroy(&(*page)->childs);
    // Desaloca vetor de records
    recordsDestroy(&(*page)->records);
    // Desaloca página
    free(*page);
    // Remove endereço desalocado do ponteiro
    *page = NULL;
}

record * recordsCreate(int n)
{
    // Aloca espaço
    record *records = calloc(n, sizeof(record));
    // Verifica alocação
    if (records == NULL)
    {
        printf("Allocation error\n");
        exit(-1);
    }

    // Inicializa valores
    for (int i = 0; i < n; i++)
    {
        records[i].key = -1;
        records[i].recordRRN = -1;
    }

    return records;
}
void recordsDestroy(record **records)
{
    // Verifica ponteiro
    if (*records == NULL)
    {
       printf("Invalid pointer\n");
       return;
    }

    // Desaloca
    free(*records);
    // Remove endereço desalocado do ponteiro
    *records = NULL;
}

long * childsCreate(int n)
{
    // Aloca memória
    long *childs = calloc(n, sizeof(long));
    // Verifica alocação
    if (childs == NULL)
    {
        printf("Allocation error\n");
        exit(-1);
    }

    // Inicializa valores
    for (int i = 0; i < n; i++)
    {
        childs[i] = -1;
    }

    return childs;
}

void childsDestroy(long **childs)
{
    // Verifica ponteiro
    if (*childs == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Desaloca
    free(*childs);
    // Remove endereço desalocado do ponteiro
    *childs = NULL;
}

promotedKey * promotedKeyCreate()
{
    // Aloca memória
    promotedKey *key = calloc(1, sizeof(promotedKey));
    // Verifica alocação
    if (key == NULL)
    {
        printf("Allocation error\n");
        exit(-1);
    }

    // Inicializa valores
    key->recordRRN = -1;
    key->key = -1;
    key->childs[0] = -1;
    key->childs[1] = -1;
    
    return key;
}

void promotedKeyDestroy(promotedKey **key)
{
    // Verifica ponteiro
    if (*key == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Desaloca
    free(*key);
    // Remove endereço desalocado do ponteiro
    *key = NULL;
}

btPage * readPage(FILE *fp)
{
    // Verifica ponteiro
    if (fp == NULL)
    {
        printf("Invalid pointer\n");
        return NULL;
    }

    // Aloca nova página
    btPage *page = pageCreate();

    // Lê dados do arquivo
    fread(page->records, sizeof(record), MAX_KEYS, fp);
    fread(page->childs, sizeof(long), MAX_KEYS + 1, fp);
    fread(&(page->numberOfKeys), sizeof(short), 1, fp);
    fread(&(page->isLeaf), sizeof(char), 1, fp);
    fread(&(page->selfRRN), sizeof(long), 1, fp);

    return page;
}

btPage * readPageByRRN(FILE *fp, long RRN)
{
    // Verifica ponteiro
    if (fp == NULL)
    {
        printf("Invalid pointer\n");
        return NULL;
    }

    // Move ponteiro do arquivo para o começo
    fseek(fp, 0, SEEK_SET);
    // Move o ponteiro do arquivo para a posição do rrn
    fseek(fp, RRN * PAGE_SIZE, SEEK_SET);
    // Escreve
    btPage *page = readPage(fp);

    return page;
}

void writeNEmptyBytes(FILE *fp, int n)
{
    // Verifica ponteiro
    if (fp == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Cria vetor de n bytes vazios
    char emptyBytes[n];
    memset(emptyBytes, 0, n);
    // Escreve
    fwrite(emptyBytes, sizeof(char), n, fp);
}

void writePage(FILE *fp, btPage *page)
{
    // Verifica ponteiros
    if (fp == NULL || page == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // rrn da página que será inserida = totalBytesNoArquivo / btytesPorPagina 
    page->selfRRN = ftell(fp) / PAGE_SIZE;

    // Escreve dados no arquivo
    fwrite(page->records, sizeof(record), MAX_KEYS, fp);
    fwrite(page->childs, sizeof(long), MAX_KEYS + 1, fp);
    fwrite(&(page->numberOfKeys), sizeof(short), 1, fp);
    fwrite(&(page->isLeaf), sizeof(char), 1, fp);
    fwrite(&(page->selfRRN), sizeof(long), 1, fp);
    
    // Escreve bytes vazios até dar o tamanho da página
    writeNEmptyBytes(fp, FREE_SPACE);
}

void writePageByRRN(FILE *fp, btPage *page, long RRN)
{
    // Verifica ponteiros
    if (fp == NULL || page == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Move o ponteiro do arquivo para o começo
    fseek(fp, 0, SEEK_SET);
    // Move o ponteiro do arquivo para a posição do rrn
    fseek(fp, RRN * PAGE_SIZE, SEEK_SET);
    // Escreve
    writePage(fp, page);
}

void updatePage(FILE *fp, btPage *page)
{
    // Verifica ponteiros
    if (fp == NULL || page == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Reescreve a página que está carregada na ram, no arquivo
    writePageByRRN(fp, page, page->selfRRN);
}

long writeNewPage(FILE *fp, btPage *page)
{
    // Verifica ponteiro
    if (page == NULL || fp == NULL)
    {
        printf("Invalid pointer\n");
        return -1;
    }

    // Vai para o fim do arquivo
    fseek(fp, 0, SEEK_END);
    // rrnAtual = tamanhoTotalArquivo / tamanhoPorPagina
    long currentRRN = ftell(fp) / PAGE_SIZE;

    // Escreve a nova página no fim do arquivo
    writePage(fp, page);

    // Retorna o rrn da página escrita
    return currentRRN;
}

void writeHeader(FILE *fp, long RRN)
{
    // Verifica ponteiro
    if (fp == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }

    // Move o ponteiro do arquivo para o começo (header sempre é o primeiro bloco do arquivo)
    fseek(fp, 0, SEEK_SET);
    // Escreve rrn
    fwrite(&RRN, sizeof(long), 1, fp);
    // Escreve bytes vazios até dar o tamanho da página
    writeNEmptyBytes(fp, PAGE_SIZE - sizeof(long));
}

void writeNewRoot(const char *fileName, btPage *newRoot)
{
    // Verifica ponteiro
    if (newRoot == NULL)
    {
        printf("Invalid pointer\n");
        return;
    }
    // Abre arquivo para leitura e escrita
    FILE *fp = fopen(fileName, "rb+");
    // Verifica abertura do arquivo
    if (fp == NULL)
    {
        printf("File error\n");
        return;
    }

    // Escreve raíz e pega seu rrn
    long newRootRRN = writeNewPage(fp, newRoot);
    // Escreve o rrn da raíz no header
    writeHeader(fp, newRootRRN);
    fclose(fp);
}

void createBTree(const char *fileName)
{
    // Cria o arquivo
    FILE *fp = fopen(fileName, "wb");
    // Verifica abertura
    if (fp == NULL)
    {
        printf("File error\n");
        return;
    }

    // Escreve cabeçalho, ainda não tem raíz, então o rrn é -1
    writeHeader(fp, -1);
    fclose(fp);

    // Escreve raíz vazia
    btPage *page = pageCreate();
    page->isLeaf = 1;
    writeNewRoot(fileName, page);
    pageDestroy(&page);
}

long getRootRRN(const char *fileName)
{
    // Abre arquivo para leitura
    FILE *fp = fopen(fileName, "rb");
    // Verifica abertura
    if (fp == NULL) 
    {
        printf("File error\n");
        return -1;
    }

    // Le o rrn da raíz, que é o primeiro long escrito no arquivo
    long rootRRN = -1;
    fread(&rootRRN, sizeof(long), 1, fp);

    fclose(fp);
    return rootRRN;
}

btPage * getRoot(const char *fileName)
{
    // Pega o rrn da raíz
    long rootRRN = getRootRRN(fileName);
    // Se o rrn é igual a -1, não existe raiz
    if (rootRRN == -1)
    {
        return NULL;
    }

    // Abre arquivo para leitura
    FILE *fp = fopen(fileName, "rb");
    // Verifica abertura
    if (fp == NULL)
    {
        printf("File error\n");
        return NULL;
    }

    // Le a página que está no rrn achado (raíz)
    btPage *root = readPageByRRN(fp, rootRRN);

    fclose(fp);
    
    return root;
}

void insertInNodeWithNoOverflow(btPage *currentNode, const promotedKey *newKey)
{
    // Verifica ponteiros
    if (currentNode == NULL || newKey == NULL) 
        return;

    /*  
     * Insere ordenadamente a nova chave na página. Começa do fim do vetor da página, enquanto a nova chave for menor
     * que a chave atual do vetor, puxa a chave atual para a direita
     */
    int i;
    for (i = currentNode->numberOfKeys - 1; i >= 0 && currentNode->records[i].key > newKey->key; i--)
    {
        currentNode->records[i + 1] = currentNode->records[i];
        currentNode->childs[i + 2] = currentNode->childs[i + 1];
        currentNode->childs[i + 1] = currentNode->childs[i];
    }

    // Após puxar para a direita, (i + 1) é a posição correta para inserir a nova chave.
    currentNode->records[i + 1].key = newKey->key;
    currentNode->records[i + 1].recordRRN = newKey->recordRRN;
    currentNode->childs[i + 1] = newKey->childs[0];
    currentNode->childs[i + 2] = newKey->childs[1];
    currentNode->numberOfKeys++;
}

btPage * split(btPage *currentNode, const promotedKey *newKey, FILE *fp)
{
    // Aloca espaço para mais um registro
    currentNode->records = realloc(currentNode->records, (MAX_KEYS + 1) * sizeof(record));
    currentNode->childs = realloc(currentNode->childs, (MAX_KEYS + 2) * sizeof(long));
    
    // Terá um espaço vazio, então faz a inserção sem overflow
    insertInNodeWithNoOverflow(currentNode, newKey);

    // Meio do vetor, para fazer a divisão
    short mid = currentNode->numberOfKeys / 2;
    
    // Cria a nova página, se a atual for folha a nova também será, senão, não
    btPage *newNode = pageCreate();
    if (currentNode->isLeaf)
        newNode->isLeaf = 1;
    else
        newNode->isLeaf = 0;

    // Escreve a nova página no arquivo da árvore
    writeNewPage(fp, newNode);
    
    // Copia a fatia da direita da página atual para a nova 
    for (int i = mid, j = 0; i < currentNode->numberOfKeys; i++, j++)
    {
        newNode->records[j] = currentNode->records[i];
        newNode->numberOfKeys++;
        newNode->childs[j] = currentNode->childs[i];
        newNode->childs[j + 1] = currentNode->childs[i + 1];
        currentNode->records[i].key = -1;
        currentNode->records[i].recordRRN = -1;
    }

    currentNode->numberOfKeys = mid;

    // Volta o tamanho dos vetores da página inicial para o tamanho original
    currentNode->records = realloc(currentNode->records, MAX_KEYS * sizeof(record));
    currentNode->childs = realloc(currentNode->childs, (MAX_KEYS + 1) * sizeof(long));

    return newNode;
}

promotedKey * extractPromotedKey(const btPage *currentNode, btPage *newNode)
{
    // Cria promotedKey e pega o primeiro registro da página
    promotedKey *promoKey = promotedKeyCreate();
    promoKey->key = newNode->records[0].key;
    promoKey->recordRRN = newNode->records[0].recordRRN;
    // Filho da esquerda é o no atual. Filho da direita é o novo nó (criado depois do split)
    promoKey->childs[0] = currentNode->selfRRN;
    promoKey->childs[1] = newNode->selfRRN;

    // Depois de tirar o primeiro registro, arrasta todos a partir do segundo para a esquerda
    for (int i = 0; i < newNode->numberOfKeys - 1; i++)
    {
        newNode->records[i] = newNode->records[i + 1];
        newNode->childs[i] = newNode->childs[i + 1];
        newNode->childs[i + 1] = newNode->childs[i + 2];
    }

    // Atualiza quantidade de chaves
    newNode->numberOfKeys--;
    // Depois de arrastar para a esqueda, zera posição aonde estava o último registro
    newNode->records[newNode->numberOfKeys].key = -1;
    newNode->records[newNode->numberOfKeys].recordRRN = -1;
    newNode->childs[newNode->numberOfKeys + 1] = -1;

    return promoKey;
}

promotedKey * tryToInsert(btPage *currentNode, const promotedKey *newKey, FILE *fp)
{
    // Tem espaço
    if (currentNode->numberOfKeys < MAX_KEYS)
    {
        // Insere novo registro
        insertInNodeWithNoOverflow(currentNode, newKey);
        // Atualiza página no aqruivo
        updatePage(fp, currentNode);
        
        return NULL;
    }
    else
    {
        // Splita a página
        btPage *newNode = split(currentNode, newKey, fp);
        // Atualiza o nó atual
        updatePage(fp, currentNode);

        // Tira a chave promovida da nova página (primeiro registro da direita)
        promotedKey *promoKey = extractPromotedKey(currentNode, newNode);
        // Atualiza nova página
        updatePage(fp, newNode);
        // Desaloca
        pageDestroy(&newNode);

        // Retorna a chave promovida para a recursção
        return promoKey;
    }
}

promotedKey * bTreeInsertRecursion(btPage *currentNode, promotedKey *newKey, FILE *fp)
{
    // Verifica ponteiros
    if (newKey == NULL || fp == NULL)
        return NULL;

    // Se o nó atual é folha, tenta inserir
    if (currentNode->isLeaf)
        return tryToInsert(currentNode, newKey, fp);

    // Senão, busca a próxima página
    int nextNodeRRNIndex;
    for (nextNodeRRNIndex = 0; nextNodeRRNIndex < currentNode->numberOfKeys; nextNodeRRNIndex++)
    {
        // Quando a nova chave for menor qua a atual do vetor, deve descer para o filho
        if (newKey->key < currentNode->records[nextNodeRRNIndex].key)
        {
            break;
        }
    }
    // Pega o rrn da próxima página
    long nextNodeRRN = currentNode->childs[nextNodeRRNIndex];
    // Carrega a próxima página na ram
    btPage *nextNode = readPageByRRN(fp, nextNodeRRN);

    // Tenta inserir na próxima página
    promotedKey *promoKey = bTreeInsertRecursion(nextNode, newKey, fp);
    pageDestroy(&nextNode);

    // Se a inserção recursiva no nó filho retornou chave promovida, tenta inserir no nó atual
    if (promoKey != NULL)
    {
        promotedKey *newRoot = tryToInsert(currentNode, promoKey, fp);
        promotedKeyDestroy(&promoKey);
        return newRoot;
    }

    return NULL;
}

void setPromotedKeyAsRoot(const promotedKey *promoKey, FILE *fp)
{
    // Cria nova página
    btPage *root = pageCreate();

    // Copia valores da chave promovida para a nova páhina
    root->records[0].key = promoKey->key;
    root->records[0].recordRRN = promoKey->recordRRN;
    root->numberOfKeys = 1;
    root->childs[0] = promoKey->childs[0];
    root->childs[1] = promoKey->childs[1];
    root->isLeaf = 0;

    // Escreve a nova página (raíz) e pega seu rrn
    long newRootRRN = writeNewPage(fp, root);
    // Atualiza header
    writeHeader(fp, newRootRRN);

    pageDestroy(&root);
}

// Função mais abstrata de inserção
void bTreeInsert(const char *fileName, int recordKey, long recordRRN)
{
    // Cria e pega dados do índice a ser inserido
    promotedKey *newKey = promotedKeyCreate();
    newKey->key = recordKey;
    newKey->recordRRN = recordRRN;

    // Carrega raíz
    btPage *root = getRoot(fileName);
    // Carrega rrn da raíz
    long rootRRN = getRootRRN(fileName);

    // Abre aqruivo para leitura e escrita
    FILE *fp = fopen(fileName, "rb+");
    // Verifica abertura
    if (fp == NULL)
    {
        pageDestroy(&root);
        promotedKeyDestroy(&newKey);
        return;
    }

    // Posiciona ponteiro do arquivo na raíz
    fseek(fp, rootRRN * PAGE_SIZE, SEEK_SET);

    // Chama inserção recursiva
    promotedKey *promoKey = bTreeInsertRecursion(root, newKey, fp);

    // Se a inserção retornou uma promotedKey, tem uma nova raíz a ser definida
    if (promoKey != NULL)
    {
        setPromotedKeyAsRoot(promoKey, fp);
        promotedKeyDestroy(&promoKey);
    }

    pageDestroy(&root);
    promotedKeyDestroy(&newKey);
    fclose(fp);
}

long bTreeSearch(const char *fileName, int key)
{
    // Carrega raíz
    btPage *page = getRoot(fileName);
    // Verifica ponteiro
    if (page == NULL)
        return -1;

    // Abre arquivo para leitura e escrita
    FILE *fp = fopen(fileName, "rb+");
    // Verifica abertura
    if (fp == NULL) 
        return -1;
    
    while (1)
    {
        int i = 0;
        for (i = 0; i < page->numberOfKeys; i++)
        {
            // Achou a chave
            if (page->records[i].key == key)
            {
                long rrn = page->records[i].recordRRN;
                pageDestroy(&page);
                fclose(fp);
                return rrn;
            }
            // Se a chave atual da página for maior que a chave buscada, i = posição do rrn do filho que a busca deve descer
            if (page->records[i].key > key)
            {
                break;
            }
        }
        // Pega rrn da página filha
        long nextPageRRN = page->childs[i];
        // Se o rrn for igual a -1, não tem filho, então já buscou tudo e a chave não existe na árvore
        if (nextPageRRN == -1)
        {
            pageDestroy(&page);
            fclose(fp);
            return -1;
        }
        pageDestroy(&page);
        // Carrega a página filha
        page = readPageByRRN(fp, nextPageRRN);
    }
}