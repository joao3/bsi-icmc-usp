#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Peso (Kilos): ");
    scanf("%f", &peso);
    printf("Altura (Metros): ");
    scanf("%f", &altura);

    imc = (peso/(altura*altura));

    if (imc < 18.5) {
        printf("Abaixo do peso (IMC: %f)", imc);
    }
    else if (imc < 25) {
        printf("Saudável (IMC: %f)", imc);
    }
    else if (imc < 30) {
        printf("Peso em excesso (IMC: %f)", imc);
    }
    else if (imc < 35) {
        printf("Obesidade grau I (IMC: %f)", imc);
    }
    else if (imc < 40) {
        printf("Obesidade grau II (IMC: %f)", imc);
    }
    else {
        printf("Obesidade grau III (IMC: %f)", imc);
    }
}