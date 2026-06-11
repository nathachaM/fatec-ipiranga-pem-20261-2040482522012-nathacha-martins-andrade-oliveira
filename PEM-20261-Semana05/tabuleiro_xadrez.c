/*
Nome: Nathacha Martins Andrade Oliveira
Curso: ADS Tarde
Disciplina: Programação Estruturada e Modular
Professor: Carlos Veríssimo
Descrição: Simulação do Xeque Pastor utilizando matriz multidimensional
*/

#include <stdio.h>
#include <string.h>

#define TAM 8 // Tamanho do tabuleiro
#define TAM_STR 5 // Tamanho máximo de cada posição incluindo '\0'

// Protótipos
void inicializarTabuleiro(char tab[TAM][TAM][TAM_STR]); //Monta o tabuleiro inicial
void mostrarTabuleiro(char tab[TAM][TAM][TAM_STR]); //Exibe o tabuleiro no terminal
// Funções responsáveis pelas jogadas do Xeque Pastor
void jogada1(char tab[TAM][TAM][TAM_STR]);
void jogada2(char tab[TAM][TAM][TAM_STR]);
void jogada3(char tab[TAM][TAM][TAM_STR]);
void jogada4(char tab[TAM][TAM][TAM_STR]);

int main() {
    // Declaração da matriz multidimensional (tabuleiro)
    char tabuleiro[TAM][TAM][TAM_STR];
    // Inicializa o tabuleiro com as peças nas posições iniciais
    inicializarTabuleiro(tabuleiro);
    // Exibe o tabuleiro inicial
    printf("\nTABULEIRO INICIAL:\n");
    mostrarTabuleiro(tabuleiro);
    // Executa e exibe a Jogada 1
    printf("\nJOGADA 1:\n");
    jogada1(tabuleiro);
    mostrarTabuleiro(tabuleiro);
    // Executa e exibe a Jogada 2
    printf("\nJOGADA 2:\n");
    jogada2(tabuleiro);
    mostrarTabuleiro(tabuleiro);
    // Executa e exibe a Jogada 3
    printf("\nJOGADA 3:\n");
    jogada3(tabuleiro);
    mostrarTabuleiro(tabuleiro);
    // Executa e exibe a Jogada 4
    printf("\nJOGADA 4 - XEQUE MATE:\n");
    jogada4(tabuleiro);
    mostrarTabuleiro(tabuleiro);

    return 0;
}

// Inicializa o tabuleiro com peças
void inicializarTabuleiro(char tab[TAM][TAM][TAM_STR]) {

    // Preenche vazio
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            strcpy(tab[i][j], "  ");
        }
    }

    // Peças pretas
    strcpy(tab[0][0], "TP"); // Torre
    strcpy(tab[0][1], "CP"); // Cavalo
    strcpy(tab[0][2], "BP"); // Bispo
    strcpy(tab[0][3], "DP"); // Dama 
    strcpy(tab[0][4], "RP"); // Rei
    strcpy(tab[0][5], "BP"); // Bispo
    strcpy(tab[0][6], "CP"); // Cavalo
    strcpy(tab[0][7], "TP"); // Torre

    // Posiciona peões pretos
    for(int j=0;j<TAM;j++){
        strcpy(tab[1][j], "PP");
    }

    // Peças brancas
    strcpy(tab[7][0], "TB"); // Torre
    strcpy(tab[7][1], "CB"); // Cavalo
    strcpy(tab[7][2], "BB"); // Bispo
    strcpy(tab[7][3], "DB"); // Dama
    strcpy(tab[7][4], "RB"); // Rei
    strcpy(tab[7][5], "BB"); // Bispo
    strcpy(tab[7][6], "CB"); // Cavalo
    strcpy(tab[7][7], "TB"); // Torre

    // Posiciona peões brancos
    for(int j=0;j<TAM;j++){
        strcpy(tab[6][j], "PB");
    }
}

// Mostra o tabuleiro
void mostrarTabuleiro(char tab[TAM][TAM][TAM_STR]) {
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            printf("%s ", tab[i][j]);
        }
        printf("\n");
    }
}

// Jogada 1: Peão branco e preto
void jogada1(char tab[TAM][TAM][TAM_STR]) {

    // Peão branco e2 -> e4
    strcpy(tab[6][4], "..."); 
    strcpy(tab[4][4], "PB");

    // Peão preto e7 -> e5
    strcpy(tab[1][4], "..."); 
    strcpy(tab[3][4], "PP");
}

// Jogada 2
void jogada2(char tab[TAM][TAM][TAM_STR]) {

    // Bispo branco f1 -> c4
    strcpy(tab[7][5], "...");
    strcpy(tab[4][2], "BB");

    // Cavalo preto b8 -> c6
    strcpy(tab[0][1], "...");
    strcpy(tab[2][2], "CP");
}

// Jogada 3
void jogada3(char tab[TAM][TAM][TAM_STR]) {

    // Dama branca d1 -> h5
    strcpy(tab[7][3], "...");
    strcpy(tab[3][7], "DB");

    // Cavalo preto g8 -> f6
    strcpy(tab[0][6], "...");
    strcpy(tab[2][5], "CP");
}

// Jogada 4 (Xeque Mate)
void jogada4(char tab[TAM][TAM][TAM_STR]) {

    // Dama captura em f7
    strcpy(tab[3][7], "...");
    strcpy(tab[1][5], "DB");
}