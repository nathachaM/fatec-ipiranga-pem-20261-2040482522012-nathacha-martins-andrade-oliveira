/* Matéria: Programação Estrutirda e Modular
   Aluno: Nathacha Martins Andrade Oliveira
   RA: 2040482522012
   Atividade: Gestão de Cargas em Logística (ponteiro e vetores) */


#include <stdio.h>

#define pacote 10

void processarCarga(float *vetor, int tamanho) {
    float media = 0;
    for(int i = 0; i < 10; i++){
        media= media + *(vetor + i);
    }
    media = media / 10;
    printf("\nA media e: %.2f\n", media); // Calcula media
    
    
    media = ((media * 10) / 100) + media;
    printf("Excedem %.2f", media); // Calcula pesos que excedem a media
    
    for(int i = 0; i < 10; i++){
        if (*(vetor + i) > media){
            *(vetor + i) = *(vetor + i) * 0.95;
        }
    }
    
}

int main(){
    float peso[10]={10.0, 11.75, 8.0, 5.4, 12.0, 7.55, 13.0, 4.5, 7.7, 9.25};
    
    printf("Estados do vetor antes do processamento:\n");
    for(int i =0; i < 10; i++){
        printf("%.2f ", peso[i]);
    }
    processarCarga(peso, pacote);
    printf("\nEstados do vetor depois do processamento:\n");
    for(int i =0; i < 10; i++){
        printf("%.2f ", peso[i]);
    }
    return 0;
 }