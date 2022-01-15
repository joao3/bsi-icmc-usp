#include <stdio.h>

struct carro {
    char fabricante[15];
    char modelo[15];
    char cor[10];
    int ano;
    float preco;

};

int main() {
    struct carro c1;

    printf("Fabricante: ");
    fgets(c1.fabricante, 15, stdin);
    printf("Modelo: ");
    fgets(c1.modelo, 15, stdin);
    printf("Cor: ");
    fgets(c1.cor, 10, stdin);
    printf("Ano: ");
    scanf("%d", &c1.ano);
    printf("Preco: ");
    scanf("%f", &c1.preco);

    printf("\n");

    printf("Fabricante: %sModelo: %sCor: %sAno: %d\nPreco: %.2f\n", c1.fabricante, c1.modelo, c1.cor, c1.ano, c1.preco);
}