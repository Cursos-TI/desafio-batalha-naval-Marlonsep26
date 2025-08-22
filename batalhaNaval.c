#include <stdio.h>

#define TAM 10     // tamanho do tabuleiro (10x10)
#define NAVIO 3    // tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];  
    int navioH[NAVIO] = {3, 3, 3};  // navio horizontal
    int navioV[NAVIO] = {3, 3, 3};  // navio vertical

    // 1. Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionar navio horizontal (linha 2, começando na coluna 1)
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[2][1 + i] = navioH[i];
    }

    // 3. Posicionar navio vertical (coluna 7, começando na linha 5)
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[5 + i][7] = navioV[i];
    }

    // 4. Exibir o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
