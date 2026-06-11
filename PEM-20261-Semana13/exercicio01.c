#include <stdio.h>

int main()
{
    int inteiro = 5;
    float decimal = 7.9;
    char caracter = 'A';

    int *ptr_inteiro = &inteiro;
    float *ptr_decimal = &decimal;
    char *ptr_caracter = &caracter;

    printf("EXERCICIO 01: \n");
    printf("________________________________________ \n\n");
    
    // Valor da variável
    printf("VALORES DAS VARIAVEIS: \n");
    printf("Valor da variavel int: %d \n", inteiro);
    printf("Valor da variavel float: %f \n", decimal);
    printf("Valor da variavel char: %c \n", caracter);
    printf("________________________________________ \n\n");

    // Endereço de memória da variável
    printf("ENDERECOS DE MEMORIA DAS VARIAVEIS:\n");
    printf("Endereco de memoria de int: %p \n", &inteiro);
    printf("Endereco de memoria de float: %p \n", &decimal);
    printf("Endereco de memoria de char: %p \n", &caracter);
    printf("________________________________________ \n\n");

    // Endereço armazenado no ponteiro
    printf("ENDERECOS ARMAZENADOS EM PONTEIRO:\n");
    printf("Endereco armazenado no ponteiro int: %p \n", ptr_inteiro);
    printf("Endereco armazenado no ponteiro float: %p \n", ptr_decimal);
    printf("Endereco armazenado no ponteiro char: %p \n", ptr_caracter);
    printf("________________________________________ \n\n");

    // Valor obtido a partir do ponteiro
    printf("VALORES OBTIDOS A PARTIR DE PONTEIRO:\n");
    printf("Valor obtido via ponteiro int: %d\n", *ptr_inteiro);
    printf("Valor obtido via ponteiro float: %f\n", *ptr_decimal);
    printf("Valor obtido via ponteiro char: %c\n", *ptr_caracter);
    printf("________________________________________ \n\n");

    return 0;
}