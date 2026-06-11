#include <stdio.h>

int main() {
    // Declaração do vetor e do ponteiro apontando para o primeiro elemento
    // (O uso de [] aqui é apenas para a declaração, o que é obrigatório)
    int vetor[6] = {5, 10, 15, 20, 25, 30};
    int *p = vetor; 
    int soma = 0;

    printf("--- Leitura, Enderecos e Soma ---\n");
    // Percorre usando o deslocamento *(p + i)
    for (int i = 0; i < 6; i++) {
        // (p + i) calcula o endereço, *(p + i) acessa o valor naquele endereço
        printf("Elemento %d: Valor = %2d | Endereco = %p\n", i, *(p + i), (void*)(p + i));
        soma += *(p + i);
    }
    printf("\n-> Soma total dos elementos: %d\n", soma);

    printf("\n--- Dobrando os valores in-place ---\n");
    // Percorre usando o incremento p++
    for (int i = 0; i < 6; i++) {
        *p = (*p) * 2; // Desreferencia para acessar o valor e o dobra
        p++;           // Avança o ponteiro fisicamente para a próxima posição de memória
    }

    // Como fizemos p++, o ponteiro agora aponta para fora do vetor. 
    // Precisamos "rebobinar" o ponteiro para o início para imprimir novamente.
    p = vetor; 

    printf("Novos valores no vetor: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    printf("\n--- Confirmacao da Aritmetica de Ponteiros ---\n");
    printf("Tamanho de um tipo 'int' no sistema (sizeof): %zu bytes\n", sizeof(int));
    
    // Confirma a diferença de memória entre os endereços
    for (int i = 0; i < 5; i++) {
        // Convertendo os ponteiros para (char*) garantimos que a matemática 
        // seja feita byte a byte, mostrando a distância real na memória RAM.
        long diferenca_bytes = (char*)(p + i + 1) - (char*)(p + i);
        
        printf("Distancia entre %p e %p = %ld bytes\n", 
               (void*)(p + i), (void*)(p + i + 1), diferenca_bytes);
    }

    return 0;
}