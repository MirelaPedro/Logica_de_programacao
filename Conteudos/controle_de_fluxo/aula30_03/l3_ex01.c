#include <stdio.h>

int main(){
    int soma = 0;
    int number;

    do{
        //Perguntando o número ao usuário
        printf("Digite um número inteiro positivo: ");
        scanf("%i", &number);

        //conferindose ele é positivo
        if(number > 0){
            soma += number;
        }

    // conferindo se ele é o comando de saída
    } while(number != -1);

    //mostrando o valor da soma ao usuário
    printf("o resultado da soma é: %i\n", soma);

    return 0;
}