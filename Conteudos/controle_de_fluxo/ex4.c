//Faça um algoritimo que receba como entrada o ano de nascimento de uma pessoa, calcule e mostre sua idade. Verifique também se a pessoa já tem idade para votar, ou seja, 
// se tem 16 ou mais anos e se pode tirar habilitação, ou seja, 18 anos ou mais.

#include <stdio.h>

int main(){
    int idade;
    printf("Idade: ");
    scanf("%i", &idade);

    //VOTO
    if(idade >= 16){
        printf("Pode votar");

        //HABILITAÇÃO
        if(idade >= 18){
            printf(" e pode tirar a habilitação!");
        } else{
            printf(", mas não pode tirar a habilitação!");
        }

    } else{
        printf("Não pode nem votar, nem tirar a habilitação!");
    }

    printf("\n");

    return 0;
}


//Fazer com duas variáveis para receber a comparação das idades, retornando um valor lógico
