#include <stdio.h>

#define SIZE 3

int main() {
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];
    int C[SIZE][SIZE]; // Matriz resultante

    // 1. Leitura da Matriz A
    printf("--- Digite os valores para a Matriz A (3x3) ---\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // 2. Leitura da Matriz B
    printf("\n--- Digite os valores para a Matriz B (3x3) ---\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // 3. Calculo do Produto Matricial (C = A x B)
    /* * CORRESPONDENCIA ENTRE OS INDICES E A DEFINICAO ALGEBRICA:
     * A formula algebrica e: C[i][j] = Somatorio(A[i][k] * B[k][j])
     * * - Indice 'i' (Loop Externo): Representa a LINHA da matriz resultante C 
     * e a LINHA da primeira matriz A.
     * * - Indice 'j' (Loop Intermediario): Representa a COLUNA da matriz resultante C 
     * e a COLUNA da segunda matriz B.
     * * - Indice 'k' (Loop Interno): Representa a variavel do Somatorio (Sigma). 
     * Ele percorre simultaneamente as COLUNAS de A e as LINHAS de B, 
     * acumulando a soma das multiplicacoes (produto escalar).
     */
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Inicializa a posicao C[i][j] com zero antes de iniciar o somatorio
            C[i][j] = 0; 
            
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // 4. Exibicao das matrizes formatadas
    printf("\n--- Matriz A ---\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", A[i][j]); // %4d garante o alinhamento das colunas
        }
        printf("\n");
    }

    printf("\n--- Matriz B ---\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Matriz C (A x B) ---\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}