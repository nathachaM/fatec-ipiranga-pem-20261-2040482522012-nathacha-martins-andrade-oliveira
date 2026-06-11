#include <stdio.h>

int main() {
    float peso, altura, imc;

  
    printf("Digite o peso em kg: ");
    scanf("%f", &peso);
    
    printf("Digite a altura em metros: ");
    scanf("%f", &altura);

  
    if (peso <= 0 || altura <= 0) {
        printf("Erro: Entradas invalidas. O peso e a altura devem ser maiores que 0.\n");
    } else {
 
        imc = peso / (altura * altura);

     
        printf("IMC: %.2f\n", imc);
        printf("Classificacao: ");

        if (imc < 18.5) {
            printf("Abaixo do peso\n");
        } else if (imc < 25.0) {
        
            printf("Peso normal\n");
        } else if (imc < 30.0) {
      
            printf("Sobrepeso\n");
        } else {
      
            printf("Obesidade\n");
        }
    }

    return 0;
}