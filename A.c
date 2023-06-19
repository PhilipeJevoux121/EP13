#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 201

int compareWords(const void* a, const void* b) {
    return strcasecmp(*(const char**)a, *(const char**)b);
}

int main() {
    char palavra[MAX_WORD_LENGTH];
    char* palavras[MAX_WORDS];
    int numPalavras = 0;

    while (scanf("%200s", palavra) == 1) {
        int tamanho = strlen(palavra);
        int i, j = 0;
        int isPalavra = 0;

        for (i = 0; i < tamanho; i++) {
            if (isalpha(palavra[i])) {
                palavra[j++] = tolower(palavra[i]);
                isPalavra = 1;
            } else if (isPalavra) {
                palavra[j] = '\0';
                // Verifica se a palavra já existe no dicionário
                int isDuplicada = 0;
                for (int k = 0; k < numPalavras; k++) {
                    if (strcmp(palavra, palavras[k]) == 0) {
                        isDuplicada = 1;
                        break;
                    }
                }

                // Adiciona a palavra ao dicionário
                if (!isDuplicada) {
                    palavras[numPalavras] = malloc((j + 1) * sizeof(char));
                    strcpy(palavras[numPalavras], palavra);
                    numPalavras++;

                    // Verifica se o número máximo de palavras foi atingido
                    if (numPalavras == MAX_WORDS) {
                        break;
                    }
                }

                j = 0;
                isPalavra = 0;
            }
        }

        if (isPalavra) {
            palavra[j] = '\0';
            // Verifica se a palavra já existe no dicionário
            int isDuplicada = 0;
            for (int k = 0; k < numPalavras; k++) {
                if (strcmp(palavra, palavras[k]) == 0) {
                    isDuplicada = 1;
                    break;
                }
            }

            // Adiciona a palavra ao dicionário
            if (!isDuplicada) {
                palavras[numPalavras] = malloc((j + 1) * sizeof(char));
                strcpy(palavras[numPalavras], palavra);
                numPalavras++;

                // Verifica se o número máximo de palavras foi atingido
                if (numPalavras == MAX_WORDS) {
                    break;
                }
            }
        }
    }

    // Ordena as palavras em ordem alfabética
    qsort(palavras, numPalavras, sizeof(char*), compareWords);

    // Imprime as palavras ordenadas
    for (int i = 0; i < numPalavras; i++) {
        printf("%s\n", palavras[i]);
        free(palavras[i]);
    }

    return 0;
}