#include <stdio.h>
#include <stdlib.h>

int main() {
    int nota = 0, maior = 0, count = 0, menor = 0;

    while (nota >= 0) {
        printf("Nota (numero negativo para parar): \n");
        scanf("%d", &nota);
        if (count == 0 && nota < 0) {
            printf("Nenhuma nota digitada\n");
            exit(0);
        }


        if (nota > maior) {
            maior = nota;
        }
        if (((nota < menor) && (nota >= 0)) || count == 0) {
            menor = nota;
        }
        count += 1;
    }

    printf("Maior: %d Menor: %d\n", maior, menor);

}