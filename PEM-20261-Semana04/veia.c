/*
Matéria: Programação Estruturada e Modular
Atividade semana 4
Aluna:Nathacha Martins Andrade Oliveira
*/
#include <stdio.h>

void matriz(char veia[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c ", veia[i][j]);
            if(j<2){
                printf("|");
            }
        }
        printf("\n");
        if(i < 2){
            printf("---+---+---\n");
        }
    }
}

int main(){
    
    char jogador_atual = 'x';
    char veia[3][3], vazio = ' ';
    int vencedor = 0;
    int linha, coluna;
    int jogadas = 0;

    // preencher tabuleiro vazio
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            veia[i][j] = vazio;
        }
    }

    while(vencedor == 0 && jogadas < 9){

        printf("\nJogador %c\n", jogador_atual);

        printf("Escolha uma linha de 0 a 2: ");
        scanf("%d", &linha);
        printf("Escolha uma coluna de 0 a 2: ");
        scanf("%d", &coluna);

        // verificar posição válida
        if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
            printf("Posicao invalida! Escolha entre 0 e 2\n");
            continue;
        }

        // verificar se está ocupada
        if(veia[linha][coluna] != vazio){
            printf("Posicao ocupada, escolha outra\n");
            continue;
        }

        // marcar posição
        veia[linha][coluna] = jogador_atual;
        jogadas++;

        matriz(veia);

        // verificar vencedor linhas e colunas
        for(int i=0; i<3; i++){

            // linha
            if(veia[i][0] == jogador_atual &&
               veia[i][1] == jogador_atual &&
               veia[i][2] == jogador_atual){
                vencedor = 1;
            }

            // coluna
            if(veia[0][i] == jogador_atual &&
               veia[1][i] == jogador_atual &&
               veia[2][i] == jogador_atual){
                vencedor = 1;
            }
        }

        // diagonais
        if(veia[0][0] == jogador_atual &&
           veia[1][1] == jogador_atual &&
           veia[2][2] == jogador_atual){
            vencedor = 1;
        }

        if(veia[0][2] == jogador_atual &&
           veia[1][1] == jogador_atual &&
           veia[2][0] == jogador_atual){
            vencedor = 1;
        }

        if(vencedor == 1){
            printf("\nJogador %c venceu!\n", jogador_atual);
            break;
        }

        // trocar jogador
        if(jogador_atual == 'x'){
            jogador_atual = 'o';
        }else {
            jogador_atual = 'x';
        }
    }

    if(vencedor == 0){
        printf("\nEmpate!\n");
    }

    return 0;

}

