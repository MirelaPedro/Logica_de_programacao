#include <stdio.h>

int number, auxiliar;

int main(){

    printf("Digite um número inteiro positivo: ");
    scanf("%i", &number);

    //Verificando se o número é positivo
    if(number < 0){
        printf("O número deve ser positivo!");

        return 0;
    }

    //Verificando a divisibilidade por cada um dos números
    int verify_3 = (number % 3) == 0;
    int verify_5 = (number % 5) == 0;
    int verify_7 = (number % 7) == 0;

    //Mostrando o resultado de acordo com as condições de divisibilidade
    if(verify_3 && verify_5 && verify_7){
        printf("O número não pode ser divisível pelos três números ao mesmo tempo");
    }
    else if(verify_3 && verify_5 && !verify_7){
        printf("O número é divisível por 3 e 5");
    }
    else if(verify_3 && !verify_5 && verify_7){
        printf("O número é divisível por 3 e 7");
    }
    else if(!verify_3 && verify_5 && verify_7){
        printf("O número é divisível por 5 e 7");
    } 
    else if(verify_3 && !verify_5 && !verify_7){
        printf("O número é divisível por 3");
    }
    else if(!verify_3 && !verify_5 && verify_7){
        printf("O número é divisível por 7");
    }
    else if(!verify_3 && verify_5 && !verify_7){
        printf("O número é divisível por 5");
    }
    else {
        printf("O número  não é divisível por nenhum dos números!");
    }

    printf("\n");

    return 0;
}
