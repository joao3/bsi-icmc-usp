#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produtos {
    char nome[30]; 
    int codigo, estoque; 
    float preco;
};

struct vendas {
    char nome[30]; 
    int codigo, quantidade;
    char data[11];
};

int main() {
    FILE *arq;

    struct produtos p[50];
    struct vendas v[50];

    int op, count = 0, countv = 0; // op: operação | count: quantidade de produtos cadastrados | countv: quantidade de vendas cadastradas

    // Se o arquivo já existe lê os dados, se não existe cria o arquivo
    arq = fopen("arq.txt", "rb");
    if (arq != NULL) {
        fread(p, sizeof(struct produtos), 50, arq);
        fread(v, sizeof(struct vendas), 50, arq);
        fread(&count, sizeof(int), 1, arq);
        fread(&countv, sizeof(int), 1, arq);
        fclose(arq);
    } else {
        fopen("arq.txt", "wb+");
        fclose(arq);
    }

    while (1) {
        printf("------------------------------------------------\n");
        printf("1: Cadastrar produto\n");
        printf("2: Listar produtos\n");
        printf("3: Editar produto\n");
        printf("4: Eliminar produto\n");
        printf("5: Registrar venda\n");
        printf("6: Vendas realizdas em um mes\n");
        printf("7: Vendas de um produto\n");
        printf("8: Ranking de produtos mais vendidos\n");
        printf("0: Sair\n");
        printf("Digite a operacao que deseja fazer: ");
        scanf("%d", &op);
        printf("------------------------------------------------\n");

        // Cadastrar
        if (op == 1) {    
            printf("Nome: ");
            scanf("%s", p[count].nome);
            printf("Codigo: ");
            scanf("%d", &p[count].codigo);
            printf("Preco: ");
            scanf("%f", &p[count].preco);
            printf("Estoque: ");
            scanf("%d", &p[count].estoque);

            count++;    
        } 
        
        // Listar
        else if (op == 2) {   
            for (int i = 0; i < count; i++) {
                printf("Nome: %s Codigo: %d  Preco: %.2f Estoque: %d", p[i].nome, p[i].codigo, p[i].preco, p[i].estoque);
                printf("\n");
            }
        } 
        
        // Editar
        else if (op == 3) {             
            int n;
            printf("Codigo do produto que desaja editar: ");
            scanf("%d", &n);

            // Busca o produto com o código inserido
            for (int i = 0; i < count; i++) {  
                if (n == p[i].codigo) {
                    printf("Novo nome: ");
                    scanf("%s", p[i].nome);
                    printf("Novo codigo: ");
                    scanf("%d", &p[i].codigo);
                    printf("Novo preco: ");
                    scanf("%f", &p[i].preco);
                    printf("Novo estoque: ");
                    scanf("%d", &p[i].estoque);

                    break;
                }
                if (i == count - 1) printf("Produto nao encontrado\n"); // Se chegou até aqui, o produto de codigo n não está no cadastro
            }
        } 
        
        // Eliminar
        else if (op == 4) {             
            int n;
            printf("Codigo do produto que deseja remover: ");
            scanf("%d", &n);

            for (int i = 0; i < count; i++) {
                if (n == p[i].codigo) {
                    // Sobrescreve o produto a ser removido com o último produto, e diminui o contador
                    p[i].codigo = p[count - 1].codigo;
                    p[i].preco = p[count - 1].preco;
                    p[i].estoque = p[count - 1].estoque;
                    strcpy(p[i].nome, p[count - 1].nome);
                    count--;

                    // Zera o último produto
                    p[count].codigo = 0;
                    p[count].preco = 0;
                    p[count].estoque = 0;
                    strcpy(p[count].nome, "");  

                    break;
                }
                if (i == count - 1) printf("Produto nao encontrado\n"); // Se chegou até aqui, o produto de codigo n não está no cadastro
            }
        } 
        
        // Vender
        else if (op == 5) {             
            int n;
            printf("Codigo do produto que deseja vender: ");
            scanf("%d", &n);

            for (int i = 0; i < count; i++) {
                if (p[i].codigo == n) {
                    int qnt;
                    printf("Quantidade: ");
                    scanf("%d", &qnt);

                    if (qnt > p[i].estoque) {
                        printf("Sem estoque o suficiente\n");
                        break;
                    } else {
                        p[i].estoque -= qnt;
                        
                        printf("Data da venda (dd/mm/aaaa): ");
                        scanf("%s", v[countv].data);
                        v[countv].codigo = n;
                        v[countv].quantidade = qnt;
                        strcpy(v[countv].nome, p[i].nome);
                        countv++;
                        
                        break;
                    }
                }
                
                if (i == count - 1) printf("Produto nao encontrado\n"); // Se chegou até aqui, o produto de codigo n não está no cadastro
            }
        } 
        
        // Vendas no mês
        else if (op == 6) {             
            char d[8];
            printf("Mes (mm/aaaa): ");
            scanf("%s", d);

            for (int i = 0; i < countv; i++) {
                // Índices das datas: d = 01/3456 v.data = 01/34/6789
                if (d[0] == v[i].data[3] && d[1] == v[i].data[4] && d[3] == v[i].data[6] && d[4] == v[i].data[7] && d[5] == v[i].data[8] && d[6] == v[i].data[9]){
                    printf("Nome: %s Codigo: %d Quantidade: %d Data: %s\n", v[i].nome, v[i].codigo, v[i].quantidade, v[i].data);
                }
            }
        } 
        
        // Vendas de um produto
        else if (op == 7) {
            int n;
            printf("Codigo do produto: ");
            scanf("%d", &n);

            for (int i = 0; i < countv; i++) {
                if (n == v[i].codigo) {
                    printf("Nome: %s Codigo: %d Quantidade: %d Data: %s\n", v[i].nome, v[i].codigo, v[i].quantidade, v[i].data);
                }
            }
        } 
        
        // Ranking
        else if (op == 8) {
            int vet[100]; // vet[n] = código do produto | vet[n+1] = quantidade de vendas do produto de codigo vet[n]
            int c = 0; // c: controle dos dados cadastrados, para não usar posições não preenchidas que contêm lixo de memória
            // Preenche vet
            for (int i = 0; i < countv; i++) {
                // Sempre preenche a primeira posição
                if (i == 0) {
                    vet[c] = v[i].codigo;
                    vet[c+1] = v[i].quantidade;
                    c += 2;
                    continue;
                }

                // Se o produto de código vet[n] já foi contabilizado, somente adiciona na quantidade em vet[n+1]
                for (int j = 0; j < c; j += 2) {
                    if (v[i].codigo == vet[j]) {
                        vet[j+1] += v[i].quantidade;
                        continue;
                    }
                }

                // Senão, contabiliza
                vet[c] = v[i].codigo;
                vet[c+1] = v[i].quantidade;
                c += 2;
            }

            // Acha os produtos mais vendidos
            int t[6]; // t: vetor com 3 duplas (codigo, qntidade) dos 3 prod mais vendidos| t[n]: codigo do prod mais vendido | t[n+1] qntidade de vendas
            for (int i = 0; i < 6; i += 2) {
                int maior = 0;
                for (int j = 1; j < c; j += 2) {
                    if (i == 0) {               // Acha o 1 mais vendido                                         
                        if ((vet[j] > maior)) {                              
                            t[i] = vet[j-1];
                            t[i+1] = vet[j];
                            maior = vet[j];
                        }
                    } else if (i == 2) {        // Acha o 2 mais vendido
                        if ((vet[j] > maior && vet[j-1] != t[0])) {
                            t[i] = vet[j-1];
                            t[i+1] = vet[j];
                            maior = vet[j];
                        }
                    } else {                    // Acha o 3 mais vendido
                        if ((vet[j] > maior && vet[j-1] != t[0] && vet[j-1] != t[2])) { 
                            t[i] = vet[j-1];
                            t[i+1] = vet[j];
                            maior = vet[j];
                        }
                    }
                }
            }

            // Imprime
            for (int i = 0; i < 6; i += 2) {
                // Acha o nome do prod de código t[i]
                char nome[30];
                for (int j = 0; j < count; j++) {
                    if (t[i] == p[j].codigo) {
                        strcpy(nome, p[j].nome);
                    }
                }
                
                printf("%d°: Código: %d Nome: %s Vendas: %d\n", (i+1)/2+1, t[i], nome,  t[i+1]);
            }
        } 
        
        // Sair
        else if (op == 0) {
            break;
        } 
        
        else {
            printf("Operacao invalida.");
        }
    }

    arq = fopen("arq.txt", "wb+");

    fwrite(p, sizeof(struct produtos), 50, arq);
    fwrite(v, sizeof(struct vendas), 50, arq);
    fwrite(&count, sizeof(int), 1, arq);
    fwrite(&countv, sizeof(int), 1, arq);

    fclose(arq);   
}