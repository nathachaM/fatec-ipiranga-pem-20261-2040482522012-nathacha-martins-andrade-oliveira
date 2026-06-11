#include <stdio.h>

int main()
{
    double n1, n2, n3;
    int p1, p2, p3;

    printf("Insira nota 1:\n");
    scanf("%lf", &n1);
    printf("Insira nota 2:\n");
    scanf("%lf", &n2);
    printf("Insira nota 3:\n");
    scanf("%lf", &n3);
    
    printf("Insira o peso da nota 1:\n");
    scanf("%d", &p1);
    printf("Insira o peso da nota 2:\n");
    scanf("%d", &p2);
    printf("Insira o peso da nota 3:\n");
    scanf("%d", &p3);

    double media = (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3);
    printf("Sua média final é de: %.2lf\n", media);
    
    printf("Tamanho em bytes do tipo double: %zu\n", sizeof(double));
    printf("Tamanho em bytes do tipo int: %zu\n", sizeof(int));

    return 0;
}