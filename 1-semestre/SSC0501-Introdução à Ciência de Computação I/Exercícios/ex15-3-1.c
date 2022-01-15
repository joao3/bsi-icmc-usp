#include <stdio.h>
#include <string.h>

struct carro {
    char fabricante[15];
    char modelo[15];
    char cor[10];
    int ano;
    float preco;

};

void func(struct carro c) {
    if (c.ano < 2000) c.ano = 2000;
    if (strcmp(c.fabricante, "Chevrolet") == 0) strcpy(c.fabricante, "GM");

    printf("\nFabricante: %sModelo: %sCor: %sAno: %d\nPreco: %.2f\n", c.fabricante, c.modelo, c.cor, c.ano, c.preco);
}

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

    func(c1);

    printf("\n");
}