#include <stdio.h>

int main() {
    char opcao;

    for (int i = 1; i <= 10; i++) {
        printf("\n=== Tabuada do %d ===\n", i);
        
        int j = 1;

        while (j <= 10) {
            printf("%2d x %2d = %3d\n", i, j, i * j);
            j++;
        }

        do {
            printf("\nDeseja continuar para a proxima? (S/N): ");
            scanf(" %c", &opcao); 
            
           
            if (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n') {
                printf("Entrada invalida. Por favor, digite 'S' ou 'N'.\n");
            }
       
        } while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n');

  
        if (opcao == 'N' || opcao == 'n') {
            printf("Programa encerrado pelo usuario.\n");
            break; 
        }
        

        if (i == 10 && (opcao == 'S' || opcao == 's')) {
            printf("\nTodas as tabuadas de 1 a 10 foram exibidas!\n");
        }
    }

    return 0;
}