#include <stdio.h>
#include <stdlib.h>

// ==========================================
// PROTÓTIPOS DAS FUNÇÕES
// ==========================================
int calcularMDC(int a, int b);
long long calcularPotencia(int base, int expoente);
int verificarPrimo(int n);
char* decimalParaBinario(int n, char* buffer);


// ==========================================
// FUNÇÃO PRINCIPAL
// ==========================================
int main() {
    int opcao;

    do {
        printf("\n===================================\n");
        printf("    CALCULADORA MODULAR COM MENU   \n");
        printf("===================================\n");
        printf("1. Maximo Divisor Comum (MDC)\n");
        printf("2. Potencia Inteira\n");
        printf("3. Verificar Numero Primo\n");
        printf("4. Conversao Decimal -> Binario\n");
        printf("0. Sair do programa\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int num1, num2;
                printf("\n--- Maximo Divisor Comum ---\n");
                printf("Digite o primeiro numero: ");
                scanf("%d", &num1);
                printf("Digite o segundo numero: ");
                scanf("%d", &num2);
                printf("O MDC de %d e %d eh: %d\n", num1, num2, calcularMDC(num1, num2));
                break;
            }
            case 2: {
                int base, exp;
                printf("\n--- Potencia Inteira ---\n");
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite o expoente (>= 0): ");
                scanf("%d", &exp);
                if (exp < 0) {
                    printf("Erro: Para resultados inteiros, o expoente deve ser positivo ou zero.\n");
                } else {
                    printf("Resultado de %d^%d = %lld\n", base, exp, calcularPotencia(base, exp));
                }
                break;
            }
            case 3: {
                int n;
                printf("\n--- Verificador de Numero Primo ---\n");
                printf("Digite um inteiro positivo: ");
                scanf("%d", &n);
                if (verificarPrimo(n)) {
                    printf("O numero %d EH PRIMO.\n", n);
                } else {
                    printf("O numero %d NAO EH PRIMO.\n", n);
                }
                break;
            }
            case 4: {
                int n;
                // Buffer para armazenar até 32 bits + terminador nulo '\0'
                char buffer[33]; 
                printf("\n--- Conversao Decimal -> Binario ---\n");
                printf("Digite um inteiro positivo: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Erro: Digite apenas numeros positivos.\n");
                } else {
                    printf("A representacao binaria de %d eh: %s\n", n, decimalParaBinario(n, buffer));
                }
                break;
            }
            case 0:
                printf("\nSaindo da calculadora... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}


// ==========================================
// IMPLEMENTAÇÃO DAS FUNÇÕES
// ==========================================

/*
 * Função: calcularMDC
 * Descrição: Calcula o Máximo Divisor Comum de dois inteiros utilizando 
 * o tradicional Algoritmo de Euclides.
 * Parâmetros:
 * a (int) -> O primeiro número inteiro.
 * b (int) -> O segundo número inteiro.
 * Retorno: (int) O valor do Máximo Divisor Comum.
 * Complexidade Algorítmica: O(log(min(a, b))) - A cada iteração, o tamanho 
 * dos números é reduzido significativamente.
 */
int calcularMDC(int a, int b) {
    // Garante lidar com números negativos se o usuário inseri-los
    a = abs(a);
    b = abs(b);
    
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

/*
 * Função: calcularPotencia
 * Descrição: Realiza o cálculo de uma potência sem uso da biblioteca <math.h> e pow().
 * Parâmetros:
 * base (int) -> O número base.
 * expoente (int) -> A quantidade de vezes que a base será multiplicada por ela mesma.
 * Retorno: (long long) O resultado da operação matemática. Utiliza long long
 * para evitar transbordamento (overflow) rápido da memória.
 * Complexidade Algorítmica: O(n) onde 'n' é o expoente, pois o laço executa 'n' vezes.
 */
long long calcularPotencia(int base, int expoente) {
    long long resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

/*
 * Função: verificarPrimo
 * Descrição: Verifica matematicamente se um número possui apenas dois divisores (1 e ele mesmo).
 * Parâmetros:
 * n (int) -> O número a ser verificado.
 * Retorno: (int) Retorna 1 (Verdadeiro) se for primo, 0 (Falso) caso contrário.
 * Complexidade Algorítmica: O(sqrt(n)) - O laço verifica divisores apenas até a 
 * raiz quadrada do número, economizando processamento.
 */
int verificarPrimo(int n) {
    if (n <= 1) return 0; // Números menores ou iguais a 1 não são primos
    if (n == 2) return 1; // 2 é o único número par primo
    if (n % 2 == 0) return 0; // Elimina todos os outros pares imediatamente

    // Verifica apenas ímpares a partir do 3, até a raiz quadrada de n (i * i <= n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0; // Achou um divisor, não é primo
        }
    }
    return 1;
}

/*
 * Função: decimalParaBinario
 * Descrição: Converte um número na base decimal para a base binária armazenando-o
 * em uma string fornecida (buffer).
 * Parâmetros:
 * n (int) -> O número decimal a ser convertido.
 * buffer (char*) -> Ponteiro para o array de caracteres onde a string será montada.
 * Retorno: (char*) O ponteiro original para a string, permitindo uso direto em printf.
 * Complexidade Algorítmica: O(log n) - Representa o número de bits (divisões sucessivas por 2).
 */
char* decimalParaBinario(int n, char* buffer) {
    if (n == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }

    int indice = 0;
    
    // Calcula os bits (do menos significativo ao mais significativo)
    while (n > 0) {
        buffer[indice] = (n % 2) + '0'; // Adiciona '0' para converter o int em caractere ASCII
        n = n / 2;
        indice++;
    }
    buffer[indice] = '\0'; // Adiciona o terminador da string

    // Como o algoritmo extrai os números de trás pra frente, precisamos inverter a string
    int inicio = 0;
    int fim = indice - 1;
    while (inicio < fim) {
        char temp = buffer[inicio];
        buffer[inicio] = buffer[fim];
        buffer[fim] = temp;
        inicio++;
        fim--;
    }

    return buffer;
}