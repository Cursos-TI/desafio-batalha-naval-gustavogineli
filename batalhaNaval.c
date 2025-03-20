#include <stdio.h>

#define LINHA 10
#define COLUNA 10

// Função para aplicar habilidade
void aplicarHabilidade(int tabuleiro[LINHA][COLUNA], int origemX, int origemY, int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Verifica se a posição da habilidade é válida
            if (habilidade[i][j] == 1) {
                // Verifica se a posição está dentro dos limites do tabuleiro
                if (origemX + i >= 0 && origemX + i < LINHA && origemY + j >= 0 && origemY + j < COLUNA) {
                    // Marca a posição como afetada pela habilidade
                    tabuleiro[origemX + i][origemY + j] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[LINHA][COLUNA] = {0}; 

    // Definindo a matriz de habilidade Cruz (3x3)
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Definindo a matriz de habilidade Cone (5x5)
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Definindo a matriz de habilidade Octaedro (5x5)
    int octaedro[5][5] = {
        {0, 0, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1}
    };

    // Posicionando os navios
    tabuleiro[1][3] = 3; 
    tabuleiro[1][4] = 3;
    tabuleiro[1][5] = 3;

    tabuleiro[5][6] = 3;  
    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;

    // Aplicando as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, 2, 2, cruz);  // Aplicando Cruz na posição (2, 2)
    aplicarHabilidade(tabuleiro, 4, 4, cone);  // Aplicando Cone na posição (4, 4)
    aplicarHabilidade(tabuleiro, 3, 3, octaedro);  // Aplicando Octaedro na posição (3, 3)

    // Exibindo o tabuleiro após aplicar as habilidades
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("1 ");  // Área afetada pela habilidade
            }
        }
        printf("\n");
    }

    return 0;
}
