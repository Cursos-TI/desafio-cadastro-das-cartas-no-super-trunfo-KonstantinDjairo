#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100


/* explicacao:
tentei evitar ao maximo o uso do scanf por conta de problemas de seguranca.
e como o programa eh interativo, entao eu tive a ideia de criar um loop interativo tambem ,
e para evitar repeticoes nas declaracoes das variavies, usei arrays 2D
 */


int main(void) {
    char buffer[MAX_LEN];
    int populacao[2];
    float area[2], pib[2];
    char codigoCidade[2][4];
    char cidadeNome[2][MAX_LEN];
    int pontoTuristico[2];
    char estado[2][3];

    for (int i = 0; i < 2; ++i) {
        printf("\n--- Carta %d ---\n", i + 1);

        // Estado
        printf("Insira o Estado: ");
        if (fgets(buffer, sizeof(buffer), stdin)) {
            buffer[strcspn(buffer, "\n")] = '\0';
            strncpy(estado[i], buffer, sizeof(estado[i]) - 1);
            estado[i][sizeof(estado[i]) - 1] = '\0';
        }

        // Código da cidade
        printf("Insira o codigo: ");
        if (fgets(buffer, sizeof(buffer), stdin)) {
            buffer[strcspn(buffer, "\n")] = '\0';
            strncpy(codigoCidade[i], buffer, sizeof(codigoCidade[i]) - 1);
            codigoCidade[i][sizeof(codigoCidade[i]) - 1] = '\0';
        }

        // Nome da cidade
        printf("Insira o nome da cidade: ");
        if (fgets(cidadeNome[i], sizeof(cidadeNome[i]), stdin)) {
            cidadeNome[i][strcspn(cidadeNome[i], "\n")] = '\0';
        }

        // Leitura genérica via fgets + conversão; evita repeticao de codigo
        #define READ_NUM(type, dest)                  \
          do {                                        \
            printf("Insira " #dest ": ");             \
            if (fgets(buffer, sizeof(buffer), stdin)) {    \
              if (buffer[strcspn(buffer, "\n")] != '\n') { \
                int c; while ((c = getchar()) != '\n' && c != EOF); \
              }                                       \
              dest = (type) atof(buffer);             \
            }                                         \
          } while (0)

        READ_NUM(int, populacao[i]);
        READ_NUM(float, area[i]);
        READ_NUM(float, pib[i]);
        READ_NUM(int, pontoTuristico[i]);
    }

    // Exibe resumo
    printf("\n--- Resumo das Cartas ---\n");
    for (int i = 0; i < 2; ++i) {
        printf("Carta %d: %s-%s, %s, pop: %d, area: %.2f, PIB: %.2f, pontos: %d\n",
               i+1, estado[i], codigoCidade[i], cidadeNome[i],
               populacao[i], area[i], pib[i], pontoTuristico[i]);
    }

    return 0;
}
