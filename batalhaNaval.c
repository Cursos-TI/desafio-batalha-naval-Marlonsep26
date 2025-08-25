#include <stdio.h>

#define TAM 10     // tamanho do tabuleiro (10x10)
#define NAVIO 3    // tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];  

    // 1. Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Navio DIAGONAL (descendo para direita, começa em [2][1])
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[2 + i][1 + i] = 3;
    }

    // 3. Navio vertical (coluna 7, começando na linha 5)
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[5 + i][7] = 3;
    }

    // 4. Navio horizontal (linha 8, começando na coluna 4)
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[8][4 + i] = 3;
    }

    // 5. Navio DIAGONAL (descendo para esquerda, começa em [1][2])
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[1 + i][2 - i] = 3;
    }

    // 6. Exibir o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // ===== MATRIZES DE HABILIDADE =====
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Cone (ponta em cima, abre para baixo)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i && i < 5)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Cruz (centro da matriz, linhas e colunas centrais)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Octaedro (losango em volta do centro)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Exibir as matrizes de habilidade
    printf("\n=== MATRIZ CONE ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    printf("\n=== MATRIZ CRUZ ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    printf("\n=== MATRIZ OCTAEDRO ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }

    return 0;
}