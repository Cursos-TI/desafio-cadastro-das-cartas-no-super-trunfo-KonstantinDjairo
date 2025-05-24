#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100
#define NUM_CARTAS 2

typedef struct {
    char estado[3];
    char codigo[4];
    char nome[MAX_LEN];
    unsigned long populacao;
    float area;
    float pib;              // em bilhões
    int pontosTuristicos;
    float densidade;        // hab/km²
    float pibPerCapita;     // reais
    float superPoder;
} Carta;

void lerString(const char *prompt, char *dest, size_t maxlen) {
    char buffer[MAX_LEN];
    printf("%s", prompt);
    if (!fgets(buffer, sizeof(buffer), stdin)) return;
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(dest, buffer, maxlen - 1);
    dest[maxlen - 1] = '\0';
}

unsigned long lerULong(const char *prompt) {
    char buffer[MAX_LEN];
    printf("%s", prompt);
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0;
    return strtoul(buffer, NULL, 10);
}

float lerFloat(const char *prompt) {
    char buffer[MAX_LEN];
    printf("%s", prompt);
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0.0f;
    return strtof(buffer, NULL);
}

int lerInt(const char *prompt) {
    char buffer[MAX_LEN];
    printf("%s", prompt);
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0;
    return atoi(buffer);
}

void exibirComparacao(const char *atributo, float valor1, float valor2, int menorVence) {
    int vencedor = 0;
    if ((menorVence && valor1 < valor2) || (!menorVence && valor1 > valor2))
        vencedor = 1;
    else
        vencedor = 2;

    printf("%-25s Carta %d venceu\n", atributo, vencedor);
}

int main(void) {
    Carta cartas[NUM_CARTAS];

    /* Leitura dos dados */
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\n--- Dados da Carta %d ---\n", i + 1);
        lerString("Estado (2 letras): ", cartas[i].estado, sizeof(cartas[i].estado));
        lerString("Código da Carta:    ", cartas[i].codigo, sizeof(cartas[i].codigo));
        lerString("Nome da Cidade:     ", cartas[i].nome, sizeof(cartas[i].nome));
        cartas[i].populacao      = lerULong("População:          ");
        cartas[i].area           = lerFloat("Área (km²):         ");
        cartas[i].pib            = lerFloat("PIB (bilhões R$):   ");
        cartas[i].pontosTuristicos = lerInt("Pontos Turísticos:  ");
    }

    /* Cálculo de densidade, PIB per capita e Super Poder */
    for (int i = 0; i < NUM_CARTAS; i++) {
        cartas[i].densidade    = cartas[i].populacao / cartas[i].area;
        cartas[i].pibPerCapita = (cartas[i].pib * 1e9f) / cartas[i].populacao;
        cartas[i].superPoder =
            (float)cartas[i].populacao
          + cartas[i].area
          + cartas[i].pib
          + (float)cartas[i].pontosTuristicos
          + cartas[i].pibPerCapita
          + (1.0f / cartas[i].densidade);
    }

    /* Exibição dos dados completos */
    printf("\n=== Resumo das Cartas ===\n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf(" Estado:                  %s\n", cartas[i].estado);
        printf(" Código:                  %s\n", cartas[i].codigo);
        printf(" Nome da Cidade:          %s\n", cartas[i].nome);
        printf(" População:               %lu\n", cartas[i].populacao);
        printf(" Área:                    %.2f km²\n", cartas[i].area);
        printf(" PIB:                     %.2f bilhões de reais\n", cartas[i].pib);
        printf(" Pontos Turísticos:       %d\n",  cartas[i].pontosTuristicos);
        printf(" Densidade Populacional:  %.2f hab/km²\n", cartas[i].densidade);
        printf(" PIB per Capita:          %.2f reais\n", cartas[i].pibPerCapita);
        printf(" Super Poder:             %.2f\n", cartas[i].superPoder);
    }

    /* Comparações */
    printf("\n=== Comparação de Cartas ===\n\n");
    exibirComparacao("População:",            cartas[0].populacao,    cartas[1].populacao,    0);
    exibirComparacao("Área:",                 cartas[0].area,         cartas[1].area,         0);
    exibirComparacao("PIB:",                  cartas[0].pib,          cartas[1].pib,          0);
    exibirComparacao("Pontos Turísticos:",    cartas[0].pontosTuristicos, cartas[1].pontosTuristicos, 0);
    exibirComparacao("Densidade Populacional:", cartas[0].densidade,   cartas[1].densidade,    1); // menor vence
    exibirComparacao("PIB per Capita:",       cartas[0].pibPerCapita, cartas[1].pibPerCapita, 0);
    exibirComparacao("Super Poder:",          cartas[0].superPoder,   cartas[1].superPoder,   0);

    return 0;
}
