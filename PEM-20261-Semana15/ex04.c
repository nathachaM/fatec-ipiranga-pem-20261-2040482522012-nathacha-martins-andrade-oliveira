#include <stdio.h>

int main()
{
    float x, y, z;
    float a, b, c;
    float a2, b2, c2;

    // Solicita a entrada dos três lados
    printf("Digite os tres lados do triangulo: ");
    scanf("%f %f %f", &x, &y, &z);

    // (Desigualdade Triangular)
    // Para existir, a soma de dois lados quaisquer deve ser MAIOR que o terceiro.
    if ((x + y > z) && (x + z > y) && (y + z > x))
    {
        printf("\nOs valores formam um triangulo valido.\n");

        // Classificação quanto aos LADOS (if-else-if encadeado)

        printf("- Classificacao por lados: ");

        // Se os três lados são idênticos:
        if (x == y && y == z)
        {
            printf("Equilatero\n");
        }
        // Se não são os três iguais, mas pelo menos dois são iguais entre si:
        else if (x == y || x == z || y == z)
        {
            printf("Isosceles\n");
        }
        // Se não caiu em nenhuma das anteriores, todos os lados são diferentes:
        else
        {
            printf("Escaleno\n");
        }

        // Preparação para classificação por ÂNGULOS
        // Precisamos descobrir qual é o maior lado e chamá-lo de 'a'
        if (x >= y && x >= z)
        {
            a = x;
            b = y;
            c = z;
        }
        else if (y >= x && y >= z)
        {
            a = y;
            b = x;
            c = z;
        }
        else
        {
            a = z;
            b = x;
            c = y;
        }

        // Calculando os quadrados uma vez para facilitar as comparações
        a2 = a * a;
        b2 = b * b;
        c2 = c * c;

        // Classificação quanto aos ÂNGULOS (if-else-if encadeado)
        printf("- Classificacao por angulos: ");

        // Se o quadrado do maior lado é igual à soma dos quadrados dos outros dois (Pitágoras):
        if (a2 == (b2 + c2))
        {
            printf("Retangulo\n");
        }
        // Se o quadrado do maior lado é maior que a soma dos quadrados dos outros dois:
        else if (a2 > (b2 + c2))
        {
            printf("Obtusangulo\n");
        }
        // Se o quadrado do maior lado for menor que a soma dos quadrados dos outros dois:
        else
        {
            printf("Acutangulo\n");
        }
    }
    else
    {
        // Bloco executado caso falhe na condição de desigualdade triangular
        printf("\nErro: Os valores informados NAO formam um triangulo.\n");
    }

    return 0;
}