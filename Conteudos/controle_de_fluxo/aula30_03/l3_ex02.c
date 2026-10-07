#include <stdio.h>

int main(){
    float h = 0;
    int denominador;
    int aux = 1;

    printf("Digite o número do último denominador: ");
    scanf("%i", &denominador);

    while(aux <= denominador){

        h += 1/(float)aux; //Como a divisão é entre dois inteiros é necessário "mudar" para float

        aux++;
    }

    printf("O valor final de H é: %f\n", h);

    return 0;
}