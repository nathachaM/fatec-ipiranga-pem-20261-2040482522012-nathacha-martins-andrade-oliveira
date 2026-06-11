/*
Matéria: Programação Estruturada e Modular
Atividade semana 3
Aluna:Nathacha Martins Andrade Oliveira
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main(){

    char produtos[MAX][50];
    int total = 0;
    int opcao;
    int i, pos;
    char nome[50];

    do{
        printf("\n1 - Inserir produto");
        printf("\n2 - Listar produtos");
        printf("\n3 - Editar produto");
        printf("\n4 - Deletar produto");
        printf("\n5 - Pesquisar produto");
        printf("\n0 - Sair");
        printf("\nOpcao: ");
        scanf("%d",&opcao);

        switch(opcao){

            case 1: // inserir
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", produtos[total]);
                total++;
                break;

            case 2: // listar
                printf("\nProdutos cadastrados:\n");
                for(i=0;i<total;i++){
                    printf("%d - %s\n", i, produtos[i]);
                }
                break;

            case 3: // editar
                printf("Digite a posicao do produto: ");
                scanf("%d",&pos);

                if(pos >= 0 && pos < total){
                    printf("Novo nome: ");
                    scanf(" %[^\n]", produtos[pos]);
                }else{
                    printf("Produto nao encontrado\n");
                }
                break;

            case 4: // deletar
                printf("Digite a posicao do produto: ");
                scanf("%d",&pos);

                if(pos >= 0 && pos < total){
                    for(i=pos;i<total-1;i++){
                        strcpy(produtos[i], produtos[i+1]);
                    }
                    total--;
                }else{
                    printf("Produto nao encontrado\n");
                }
                break;

            case 5: // pesquisar
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", nome);

                for(i=0;i<total;i++){
                    if(strcmp(produtos[i], nome) == 0){
                        printf("Produto encontrado na posicao %d\n", i);
                    }
                }
                break;
        }

    }while(opcao != 0);


}
