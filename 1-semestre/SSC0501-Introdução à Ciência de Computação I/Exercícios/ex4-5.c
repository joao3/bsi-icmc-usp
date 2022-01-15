#include <stdio.h>
#include <conio.h>

int main() {
    char op;
    float n1, n2, resultado;

    printf("Digite um numero: ");
    scanf("%f", &n1);
    printf("Operacao (+ - * /): ");
    op = getche();
    printf("\nDigite outro numero: ");
    scanf("%f", &n2);

    switch (op) {
        case '+':
            resultado = n1 + n2;
            break;

        case '-':
            resultado = n1 - n2;
            break;

        case '*':
            resultado = n1 * n2;
            break;

        case '/':
            resultado = n1 / n2;
            break;

        default:
            printf("Operaçao invalida\n");
    }
    printf("%f %c %f = %f", n1, op, n2, resultado);

}