#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==========================================
// Variáveis Globais de Rastreamento
// ==========================================
int chamadas_busca = 0;
int prof_atual_busca = 0;
int prof_max_busca = 0;

int chamadas_soma = 0;
int prof_atual_soma = 0;
int prof_max_soma = 0;


// ==========================================
// 1. Busca Recursiva
// ==========================================
int buscaRec(int *v, int n, int chave) {
    // Atualiza estatísticas da Busca
    chamadas_busca++;
    prof_atual_busca++;
    if (prof_atual_busca > prof_max_busca) {
        prof_max_busca = prof_atual_busca;
    }

    int resultado;

    // --- CASO BASE ---
    // 1. O vetor acabou (n == 0) e não encontramos a chave
    if (n == 0) {
        resultado = -1;
    } 
    // 2. O primeiro elemento do subvetor atual é a chave
    else if (v[0] == chave) {
        resultado = 0; 
    } 
    // --- PASSO RECURSIVO ---
    else {
        // Passamos o ponteiro avançado (v + 1) e diminuímos o tamanho (n - 1)
        int sub_indice = buscaRec(v + 1, n - 1, chave);
        
        if (sub_indice == -1) {
            resultado = -1; // Se não encontrou no resto do vetor, propaga o -1
        } else {
            resultado = 1 + sub_indice; // Soma 1 para corrigir o deslocamento do índice original
        }
    }

    prof_atual_busca--; // Sai da função, diminui a profundidade atual
    return resultado;
}


// ==========================================
// 2. Soma por Divisão Sucessiva (Divide and Conquer)
// ==========================================
int somaRec(int *v, int ini, int fim) {
    // Atualiza estatísticas da Soma
    chamadas_soma++;
    prof_atual_soma++;
    if (prof_atual_soma > prof_max_soma) {
        prof_max_soma = prof_atual_soma;
    }

    int resultado;

    // --- CASO BASE ---
    // Quando o intervalo tem apenas 1 elemento (início e fim são iguais)
    if (ini == fim) {
        resultado = v[ini];
    } 
    // Condição de segurança caso o vetor seja inválido
    else if (ini > fim) {
        resultado = 0;
    } 
    // --- PASSO RECURSIVO ---
    else {
        // Divide o vetor em duas metades
        int meio = ini + (fim - ini) / 2;
        
        // Soma recursivamente cada metade e junta os resultados
        resultado = somaRec(v, ini, meio) + somaRec(v, meio + 1, fim);
    }

    prof_atual_soma--; // Sai da função, diminui a profundidade atual
    return resultado;
}


// ==========================================
// Função Principal
// ==========================================
int main() {
    int vetor[12];
    int n = 12;

    // Inicializa o gerador de números aleatórios com a semente do tempo atual
    srand(time(NULL));

    printf("--- Vetor Gerado ---\n[ ");
    for (int i = 0; i < n; i++) {
        // Gera números aleatórios entre 1 e 50 para facilitar a visualização e os testes
        vetor[i] = (rand() % 50) + 1; 
        printf("%d ", vetor[i]);
    }
    printf("]\n\n");

    // Teste da Soma Recursiva
    int soma_total = somaRec(vetor, 0, n - 1);
    printf("--- Resultados da Soma Recursiva ---\n");
    printf("Soma total do vetor : %d\n", soma_total);
    printf("Chamadas recursivas : %d\n", chamadas_soma);
    printf("Profundidade maxima : %d\n\n", prof_max_soma);

    // Teste da Busca Recursiva
    int chave, indice_encontrado;
    printf("--- Busca Recursiva ---\n");
    printf("Digite um valor para procurar no vetor: ");
    scanf("%d", &chave);

    indice_encontrado = buscaRec(vetor, n, chave);

    if (indice_encontrado != -1) {
        printf("\nO valor %d foi encontrado no INDICE [%d].\n", chave, indice_encontrado);
    } else {
        printf("\nMensagem: O valor %d NAO EXISTE no vetor.\n", chave);
    }

    printf("\n--- Estatisticas da Busca ---\n");
    printf("Chamadas recursivas : %d\n", chamadas_busca);
    printf("Profundidade maxima : %d\n", prof_max_busca);

    return 0;
}