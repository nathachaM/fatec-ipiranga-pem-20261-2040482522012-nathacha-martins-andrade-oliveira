#include <stdio.h>

#define SIZE 4

// 1. Função para exibir o tabuleiro formatado como grade
void exibirTabuleiro(int matriz[SIZE][SIZE]) {
    printf("--- Tabuleiro de Memoria (4x4) ---\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // O %2d alinha os numeros na grade
            printf("%2d ", matriz[i][j]); 
        }
        printf("\n");
    }
}

// 2. Função para verificar simetria em relação à diagonal principal
// Na matemática, isso significa verificar se a matriz é simétrica (M[i][j] == M[j][i])
int verificarSimetria(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                return 0; // Retorna 0 (Falso) assim que achar o primeiro erro
            }
        }
    }
    return 1; // Retorna 1 (Verdadeiro) se passou por tudo sem erros
}

// 3. Função para calcular e exibir as diagonais
void exibirDiagonais(int matriz[SIZE][SIZE]) {
    printf("\n--- Analise das Diagonais ---\n");
    
    // Diagonal Principal: a linha e a coluna possuem o mesmo índice (i == j)
    printf("Diagonal Principal:  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", matriz[i][i]);
    }
    
    // Diagonal Secundária: a soma dos índices é igual ao tamanho da matriz menos 1
    printf("\nDiagonal Secundaria: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", matriz[i][SIZE - 1 - i]);
    }
    printf("\n");
}

int main() {
    // Inicialização hardcoded do tabuleiro.
    // Os pares de 1 a 6 estão em posições simétricas (ex: [0][1] e [1][0] ambos são 1).
    // Os pares 7 e 8 estão alocados na própria diagonal principal.
    int tabuleiro[SIZE][SIZE] = {
        {7, 1, 2, 3},
        {1, 8, 4, 5},
        {2, 4, 7, 6},
        {3, 5, 6, 8}
    };

    // Chamada das funções
    exibirTabuleiro(tabuleiro);

    // Avalia o retorno da função de simetria
    if (verificarSimetria(tabuleiro)) {
        printf("\nResultado da Verificacao: TODOS os pares estao em posicoes simetricas!\n");
    } else {
        printf("\nResultado da Verificacao: Os pares NAO estao simetricos.\n");
    }

    exibirDiagonais(tabuleiro);

    return 0;
}