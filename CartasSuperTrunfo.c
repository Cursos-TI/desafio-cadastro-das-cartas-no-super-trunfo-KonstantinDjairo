#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

int main(void) {
    char buffer[MAX_LEN];

    /* Dados da Carta 1 */
    char estado1[3];
    char codigo1[4];
    char nome1[MAX_LEN];
    int pop1;
    float area1, pib1;
    int pontos1;
    float dens1, percap1;

    printf("\n--- Carta 1 ---\n");

    printf("Estado: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(estado1, buffer, 2); estado1[2] = '\0';

    printf("Código: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(codigo1, buffer, 3); codigo1[3] = '\0';

    printf("Nome da Cidade: ");
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = '\0';

    printf("População: ");
    fgets(buffer, sizeof(buffer), stdin);
    pop1 = atoi(buffer);

    printf("Área (km²): ");
    fgets(buffer, sizeof(buffer), stdin);
    area1 = atof(buffer);

    printf("PIB (bilhões): ");
    fgets(buffer, sizeof(buffer), stdin);
    pib1 = atof(buffer);

    printf("Número de Pontos Turísticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    pontos1 = atoi(buffer);

    /* Cálculos */
    dens1 = pop1 / area1;
    percap1 = (pib1 * 1e9f) / pop1;

    /* Dados da Carta 2 */
    char estado2[3];
    char codigo2[4];
    char nome2[MAX_LEN];
    int pop2;
    float area2, pib2;
    int pontos2;
    float dens2, percap2;

    printf("\n--- Carta 2 ---\n");

    printf("Estado: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(estado2, buffer, 2); estado2[2] = '\0';

    printf("Código: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(codigo2, buffer, 3); codigo2[3] = '\0';

    printf("Nome da Cidade: ");
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    printf("População: ");
    fgets(buffer, sizeof(buffer), stdin);
    pop2 = atoi(buffer);

    printf("Área (km²): ");
    fgets(buffer, sizeof(buffer), stdin);
    area2 = atof(buffer);

    printf("PIB (bilhões): ");
    fgets(buffer, sizeof(buffer), stdin);
    pib2 = atof(buffer);

    printf("Número de Pontos Turísticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    pontos2 = atoi(buffer);

    /* Cálculos */
    dens2 = pop2 / area2;
    percap2 = (pib2 * 1e9f) / pop2;

    /* Exibição do Resumo */
    printf("\n=== Resumo das Cartas ===\n\n");

    printf("Carta 1:\n");
    printf(" Estado: %s\n", estado1);
    printf(" Código: %s\n", codigo1);
    printf(" Nome da Cidade: %s\n", nome1);
    printf(" População: %d\n", pop1);
    printf(" Área: %.2f km²\n", area1);
    printf(" PIB: %.2f bilhões de reais\n", pib1);
    printf(" Pontos Turísticos: %d\n", pontos1);
    printf(" Densidade Populacional: %.2f hab/km²\n", dens1);
    printf(" PIB per Capita: %.2f reais\n\n", percap1);

    printf("Carta 2:\n");
    printf(" Estado: %s\n", estado2);
    printf(" Código: %s\n", codigo2);
    printf(" Nome da Cidade: %s\n", nome2);
    printf(" População: %d\n", pop2);
    printf(" Área: %.2f km²\n", area2);
    printf(" PIB: %.2f bilhões de reais\n", pib2);
    printf(" Pontos Turísticos: %d\n", pontos2);
    printf(" Densidade Populacional: %.2f hab/km²\n", dens2);
    printf(" PIB per Capita: %.2f reais\n", percap2);

    return 0;
}
