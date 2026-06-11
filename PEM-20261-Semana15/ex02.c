#include <stdio.h>

int main()
{
    int distanciaCm;
    float distanciaM;
    double distanciaKm, distanciaMi;

    while (1)
    {
        printf("Insira uma distância em centímetros:\n");
        scanf("%d", &distanciaCm);

        if (distanciaCm < 0)
        {
            printf("Valor inválido, por favor insira um número inteiro positivo!\n");
        }
        else
        {
            distanciaM = distanciaCm / 100.0;
            distanciaKm = distanciaCm / 100000.0;
            distanciaMi = distanciaKm / 1.60934;

            printf("\nSua distância de %d centímetros em outras unidades:\n", distanciaCm);

            printf("Metros: %f m\n", distanciaM);
            printf("Quilômetros: %5lf km\n", distanciaKm);
            printf("Milhas: %5lf mi\n", distanciaMi);

            // Cada tipo de dado tem um limite máximo de caracteres para representar um valor matemático.
            // Então quando transformamos 50 cm em metros ou quilometros chegaremos em um ponto que faltarão 
            //casas para a conversão. Então quanto mais específica a grandeza, de mais espaço precisaremos, 
            //com float armazenando 4 bytes e double 8.

            break;
        }
    }

    return 0;
}