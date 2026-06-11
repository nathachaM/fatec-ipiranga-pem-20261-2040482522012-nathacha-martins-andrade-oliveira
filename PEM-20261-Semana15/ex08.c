#include <stdio.h>

#define N 8

int main() {
    int vetor[N], vetor_inverso[N];
    int maior, menor, indice_maior, indice_menor;
    int pares = 0, impares = 0;
    int valor_busca, encontrado = 0;

    printf("--- Preenchimento do Vetor ---\n");
    for (int i = 0; i < N; i++) {
        printf("Digite o valor para a posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor original: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    
    maior = vetor[0];
    menor = vetor[0];
    indice_maior = 0;
    indice_menor = 0;

   
    for (int i = 0; i < N; i++) {
       
        if (vetor[i] > maior) {
            maior = vetor[i];
            indice_maior = i;
        }
        
       
        if (vetor[i] < menor) {
            menor = vetor[i];
            indice_menor = i;
        }

        
        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        vetor_inverso[i] = vetor[N - 1 - i];
    }

    
    printf("\n--- Resultados da Analise ---\n");
    printf("Maior valor armazenado: %d (Indice: %d)\n", maior, indice_maior);
    printf("Menor valor armazenado: %d (Indice: %d)\n", menor, indice_menor);
    printf("Quantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);

    printf("\nSegundo vetor (ordem inversa): ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor_inverso[i]);
    }
    printf("\n");


    printf("\n--- Busca Linear ---\n");
    printf("Digite um valor para procurar no vetor original: ");
    scanf("%d", &valor_busca);

    for (int i = 0; i < N; i++) {
        if (vetor[i] == valor_busca) {
            printf("Valor %d encontrado! Ele esta no indice [%d].\n", valor_busca, i);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Aviso: O valor %d nao existe no vetor original.\n", valor_busca);
    }

    return 0;
}