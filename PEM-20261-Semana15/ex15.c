#include <stdio.h>
#include <math.h>

// Variável global para contar as execuções (já que a função retorna void)
int total_movimentos = 0;

// Assinatura da função exatamente como exigida
void hanoi(int n, char origem, char destino, char auxiliar) {
    // ---------------------------------------------------------
    // CASO BASE
    // ---------------------------------------------------------
    // Se houver apenas 1 disco, o problema é trivial: basta 
    // movê-lo diretamente do pino de origem para o de destino.
    if (n == 1) {
        printf("Mova disco 1 de [%c] para [%c]\n", origem, destino);
        total_movimentos++;
        return;
    }

    // ---------------------------------------------------------
    // PASSO RECURSIVO
    // ---------------------------------------------------------
    // Passo 1: Move os (n-1) discos que estão no topo para o pino 
    // auxiliar, usando o destino original como apoio provisório.
    hanoi(n - 1, origem, auxiliar, destino);

    // Passo 2: O maior disco (n) ficou livre. Movemos ele para o destino.
    printf("Mova disco %d de [%c] para [%c]\n", n, origem, destino);
    total_movimentos++;

    // Passo 3: Move os (n-1) discos que deixamos no pino auxiliar 
    // para o pino de destino, usando a origem original como apoio.
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n;

    // Leitura e validação de N (entre 1 e 10)
    do {
        printf("Digite o numero de discos (1 a 10): ");
        scanf("%d", &n);
        if (n < 1 || n > 10) {
            printf("Erro: O numero de discos deve estar entre 1 e 10.\n");
        }
    } while (n < 1 || n > 10);

    printf("\n--- Iniciando Torre de Hanoi para %d discos ---\n", n);
    
    // Chamada inicial: Pinos A (Origem), C (Destino) e B (Auxiliar)
    hanoi(n, 'A', 'C', 'B');

    // ==========================================
    // Análise Obrigatória
    // ==========================================
    // Calcula 2^n - 1. Usar a operação de bit shift (1 << n) é a forma
    // mais eficiente e segura em C para fazer potências de 2 com inteiros.
    int movimentos_esperados = (1 << n) - 1; 

    printf("\n--- Analise de Desempenho ---\n");
    printf("Movimentos realizados na pratica : %d\n", total_movimentos);
    printf("Movimentos previstos pela formula: %d (2^%d - 1)\n", movimentos_esperados, n);

    if (total_movimentos == movimentos_esperados) {
        printf("Conclusao: Os valores COINCIDEM. O algoritmo esta perfeitamente otimizado!\n");
    } else {
        printf("Conclusao: Erro inesperado. Os valores nao coincidem.\n");
    }

    return 0;
}