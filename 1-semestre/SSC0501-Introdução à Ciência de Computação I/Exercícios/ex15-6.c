#include <stdio.h>
#include <string.h>

struct funcionarios {
    int numero;
    char nome[30];
    int idade;
    int telefone;
    char cargo[15];
    float salario;
};

void inserir(struct funcionarios *pF, int *count) {
    printf("Numero: ");
    scanf("%d", &(pF->numero));
    getchar();

    printf("Nome: ");
    fgets(pF->nome, 30, stdin);
    size_t lengthN = strlen(pF->nome);
    if ((pF->nome)[lengthN - 1] == '\n')
        pF->nome[lengthN - 1] = '\0';

    printf("Idade: ");
    scanf("%d", &(pF->idade));
    getchar();

    printf("Telefone: ");
    scanf("%d", &(pF->telefone));
    getchar();

    printf("Cargo: ");
    fgets(pF->cargo, 15, stdin);
    size_t lengthC = strlen(pF->cargo);
    if ((pF->cargo)[lengthC - 1] == '\n')
        pF->cargo[lengthC - 1] = '\0';

    printf("Salario: ");
    scanf("%f", &(pF->salario));
    getchar();

    printf("\n");
}

void listar(struct funcionarios *pF, int *count) {
    for (int i = 0; i < *count; i++) {
        printf("%d %s %d %d %s %.2f\n", pF->numero, pF->nome, pF->idade, pF->telefone, pF->cargo, pF->salario);
        pF++;
    }
}

void proucurarNome(struct funcionarios *pF, int *count) {
    char nome[30];
    printf("Nome que deseja buscar: ");
    getchar();
    fgets(nome, 30, stdin);
    size_t length = strlen(nome);
    if (nome[length - 1] == '\n') nome[length - 1] = '\0';

    for (int i = 0; i < *count; i++) {
        if (strcmp(nome, pF->nome) == 0) {
            printf("Funcionario encontrado: %d %s %d %d %s %.2f\n", pF->numero, pF->nome, pF->idade, pF->telefone, pF->cargo, pF->salario);
            break;
        }
        pF += 1;
        if (i == (*count) - 1) printf("Funcionario nao encontrado\n");
    }
}

void proucurarNumero(struct funcionarios *pF, int *count) {
    int num;
    printf("Numero que deseja buscar: ");
    scanf("%d", &num);

    for (int i = 0; i < *count; i++) {
        if (num == pF->numero) {
            printf("Funcionario encontrado: %d %s %d %d %s %.2f\n", pF->numero, pF->nome, pF->idade, pF->telefone, pF->cargo, pF->salario);
            break;
        }
        pF += 1;
        if (i == (*count) - 1) printf("Funcionario nao encontrado\n");
    }
}

void eliminar(struct funcionarios *pF, int *count) {
    int aux;
    struct funcionarios *pUl = pF + *count - 1;
    printf("Numero do funcionario que deseja eliminar: ");
    scanf("%d", &aux);

    for (int i = 0; i < *count; i++) {
        if (aux == pF->numero) {
            printf("Funcionario eliminado: %d %s %d %d %s %.2f\n", pF->numero, pF->nome, pF->idade, pF->telefone, pF->cargo, pF->salario);

            pF->numero = pUl->numero;
            pF->numero = pUl->numero;
            pF->numero = pUl->numero;
            pF->numero = pUl->numero;
            pF->numero = pUl->numero;
            pF->numero = pUl->numero;
            (*count)--;

            break;
        }
        pF++;
        if (i == *count - 1) {
            printf("Funcionario nao encontrado");
        }
    }
}

void editar(struct funcionarios *pF, int *count) {
    int aux;
    printf("Numero do funcionario que deseja editar: ");
    scanf("%d", &aux);

    for (int i = 0; i < *count; i++) {
        if (aux == pF->numero) {
            printf("Funcionario encontrado: %d %s %d %d %s %.2f\n", pF->numero, pF->nome, pF->idade, pF->telefone, pF->cargo, pF->salario);
            inserir(pF, count);
            break;
        }
        pF++;
        if (i == *count - 1) {
            printf("Funcionario nao encontrado");
        }
    }
}

int main() {
    struct funcionarios f[100];
    int count = 0;

    while (1) {
        int op;

        printf("-=-=-=-=-=-=-=-=-=-=MENU=-=-=-=-=-=-=-=-=-=");
        printf("\n1: Inserir funcionario");
        printf("\n2: Listar os funcionarios cadastrados");
        printf("\n3: Proucurar funcionario pelo nome");
        printf("\n4: Proucurar funcionario pelo numero");
        printf("\n5: Eliminar funcionario");
        printf("\n6: Editar funcionario");
        printf("\n0: Sair");
        printf("\n------------------------------------------");

        printf("\nInsira o numero da operacao: ");
        scanf("%d", &op);
        printf("------------------------------------------\n");

        if (op == 0) {
            break;
        } else if (op == 1) {
            inserir(&f[count], &count);
            count++;
        } else if (op == 2) {
            listar(&f[0], &count);
        } else if (op == 3) {
            proucurarNome(&f[0], &count);
        } else if (op == 4) {
            proucurarNumero(&f[0], &count);
        } else if (op == 5) {
            eliminar(&f[0], &count);
        } else if (op == 6) {
            editar(&f[0], &count);
        } else {
            printf("Opracao invalida");
        }
    }
}