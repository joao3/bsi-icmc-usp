#include <stdio.h>

int main() {
    int km, litros;

    printf("Distancia percorrida (Km): ");
    scanf("%d", &km);
    printf("Litros de combustivel: ");
    scanf("%d", &litros);

    if (km/litros < 8) {
        printf("Venda o carro!");
    }
    else if (km/ litros < 12) {
        printf("Economico!");
    }
    else {
        printf("Super economico!");
    }

}