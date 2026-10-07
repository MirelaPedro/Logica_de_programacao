#include <stdio.h>

int v1,v2,v3,v4, comparacao;

int main()
{
    printf("Digite o primeiro valor inteiro: ");
    scanf("%i", &v1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%i", &v2);

    printf("Digite o terceiro valor inteiro: ");
    scanf("%i", &v3);

    printf("Digite o quarto valor inteiro: ");
    scanf("%i", &v4);

    comparacao = v2 >= v1 || v4 <= v3;

    printf("Comparação : %i\n\n", comparacao); 

    return 0;
}