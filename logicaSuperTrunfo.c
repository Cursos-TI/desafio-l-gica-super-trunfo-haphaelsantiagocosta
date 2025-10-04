#include <stdio.h>
#include <string.h>
struct Carta {
     char estado[3];
     char codigo[10];
     char nomeCidade[50];
     int populacao; 
     float area;  
      float pib;
        int pontosTuristicos;
         float densidade; 
         float pibPerCapita;  
         };
         void calcularIndicadores(struct Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}
void exibirCarta(struct Carta carta) {
    printf("%s (%s):\n", carta.nomeCidade, carta.estado);
    printf("  População: %d\n", carta.populacao);
    printf("  Área: %.2f km²\n", carta.area);
    printf("  PIB: %.2f milhões\n", carta.pib);
    printf("  Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("  PIB per capita: %.6f milhões/hab\n\n", carta.pibPerCapita);
}
void compararCartas(struct Carta c1, struct Carta c2) {
    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");

    printf("Carta 1 - ");
    exibirCarta(c1);

    printf("Carta 2 - ");
    exibirCarta(c2);

    printf("Resultado: ");
    if (c1.pibPerCapita > c2.pibPerCapita) {
        printf("Carta 1 (%s) venceu!\n", c1.nomeCidade);
    } else if (c2.pibPerCapita > c1.pibPerCapita) {
        printf("Carta 2 (%s) venceu!\n", c2.nomeCidade);
    } else {
        printf("Empate!\n");
    }
}
int main() {
      struct Carta carta1 = {
        "SP", "C01", "São Paulo", 12300000, 1521.11, 799000.00, 50
    };
    struct Carta carta2 = {
        "RJ", "C02", "Rio de Janeiro", 6700000, 1200.27, 390000.00, 40
    };
      calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);
      compararCartas(carta1, carta2);
       return 0;
}