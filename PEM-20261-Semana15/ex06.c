#include <stdio.h>

int main() {
    int n;
    int passos = 0;


    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);


    while (n <= 0) {
        printf("Valor invalido! A Conjectura de Collatz exige um inteiro positivo.\n");
        printf("Digite novamente: ");
        scanf("%d", &n);
    }

    printf("\nSequencia de Collatz: %d", n);


    while (n > 1) {

        if (n % 2 == 0) {
            n = n / 2;
        } 

        else {
            n = (3 * n) + 1;
        }
        
  
        printf(" -> %d", n);
        

        passos++;
    }

    printf("\n\nNumero de passos necessarios: %d\n", passos);

    return 0;
}