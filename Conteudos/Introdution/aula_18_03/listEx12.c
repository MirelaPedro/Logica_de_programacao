#include <stdio.h>

int a,b,c;

int main(){

    printf("Digite um número inteiro para a variável a: ");
    scanf("%i", &a);

    printf("Digite um número inteiro para a variável b: ");
    scanf("%i", &b);

    c = a;
    a = b;
    b = c;

    printf("O valor de a é: %i", a);
    printf("O valor de b é: %i", b);

    return 0;
}
