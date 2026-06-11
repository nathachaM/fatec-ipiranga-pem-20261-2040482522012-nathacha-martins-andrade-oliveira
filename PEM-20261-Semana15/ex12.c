#include <stdio.h>

// 1. Função para trocar os valores de duas variáveis
void troca(int *a, int *b) {
    int temp = *a; // Salva o valor apontado por 'a' em uma variável temporária
    *a = *b;       // Coloca o valor apontado por 'b' no endereço de 'a'
    *b = temp;     // Coloca o valor temporário no endereço de 'b'
}

// 2. Função para encontrar o menor e o maior elemento de um vetor
// Note que 'v' age como um ponteiro para o primeiro elemento do vetor.
void minMax(int *v, int n, int *min, int *max) {
    if (n <= 0) return; // Proteção contra vetor vazio

    // Inicializa os valores apontados por min e max com o primeiro elemento do vetor
    *min = v[0]; 
    *max = v[0];

    // Percorre o resto do vetor para encontrar os reais extremos
    for (int i = 1; i < n; i++) {
        if (v[i] < *min) {
            *min = v[i]; // Atualiza o valor na memória original de 'min'
        }
        if (v[i] > *max) {
            *max = v[i]; // Atualiza o valor na memória original de 'max'
        }
    }
}

// 3. Função para normalizar um vetor de floats (intervalo [0, 1])
void normalizaVetor(float *v, int n) {
    if (n <= 0) return;

    // Primeiro passo: encontrar o maior valor do vetor
    float max_val = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max_val) {
            max_val = v[i];
        }
    }

    // Segundo passo: dividir cada elemento por esse maior valor
    // Evita divisão por zero caso o maior valor seja 0
    if (max_val != 0) {
        for (int i = 0; i < n; i++) {
            v[i] = v[i] / max_val; // Altera diretamente na memória original do vetor
        }
    }
}

int main() {
    // ==========================================
    // Demonstração 1: Função troca
    // ==========================================
    int x = 10, y = 99;
    printf("--- Teste da Funcao 'troca' ---\n");
    printf("Antes  : x = %d, y = %d\n", x, y);
    
    // Passamos os ENDEREÇOS (&) das variáveis
    troca(&x, &y); 
    
    printf("Depois : x = %d, y = %d\n\n", x, y);

    // ==========================================
    // Demonstração 2: Função minMax
    // ==========================================
    int vetorInt[] = {15, 3, 42, 8, -5, 21};
    int tamanhoInt = 6;
    int menor, maior; // Variáveis que vão receber os resultados
    
    printf("--- Teste da Funcao 'minMax' ---\n");
    printf("Vetor  : [ ");
    for(int i = 0; i < tamanhoInt; i++) printf("%d ", vetorInt[i]);
    printf("]\n");

    // Passamos o vetor (que já é um ponteiro para o 1º elemento) e os endereços de 'menor' e 'maior'
    minMax(vetorInt, tamanhoInt, &menor, &maior);

    printf("Menor  : %d\n", menor);
    printf("Maior  : %d\n\n", maior);

    // ==========================================
    // Demonstração 3: Função normalizaVetor
    // ==========================================
    float vetorFloat[] = {2.0, 4.0, 10.0, 8.0};
    int tamanhoFloat = 4;

    printf("--- Teste da Funcao 'normalizaVetor' ---\n");
    printf("Antes  : [ ");
    for(int i = 0; i < tamanhoFloat; i++) printf("%.2f ", vetorFloat[i]);
    printf("]\n");

    // Passamos o vetor original
    normalizaVetor(vetorFloat, tamanhoFloat);

    printf("Depois : [ ");
    for(int i = 0; i < tamanhoFloat; i++) printf("%.2f ", vetorFloat[i]);
    printf("]\n");

    return 0;
}