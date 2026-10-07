#include <stdio.h>

char a,b;
int comp;

int main(){

    printf("Digite uma letra: ");
    scanf("%c", &a);
    getchar();

    printf("Digite outra letra: ");
    scanf("%c", &b);

    comp = a == b;

    printf("Comparação: %i \n\n", comp);

    return 0;
}
