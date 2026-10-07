//Escreva um algoritimo que leia três números inteiros diferentes e mostre os númeors em ordem decrescente

#include <stdio.h>

int main(){
    int a, b, c;

    printf("Número 1: ");
    scanf("%i", &a);

    printf("Número 2: ");
    scanf("%i", &b);

    printf("Número 3: ");
    scanf("%i", &c);

    //A sendo o maior nº
    if(a > b && a > c){
        if(b > c){
            printf("Ordem decrescente: %i > %i > %i", a, b, c);
        } else{
            printf("Ordem decrescente: %i > %i > %i", a, c, b);
        }
    }

    //B sendo o maior nº
    if(b > a && b > c){
        if(a > c){
            printf("Ordem decrescente: %i > %i > %i", b, a, c);
        } else{
            printf("Ordem decrescente: %i > %i > %i", b, c, a);
        }
    }

    //C sendo o maior nº
    if(c > a && c > b){
        if(a > b){
            printf("Ordem decrescente: %i > %i > %i", c, a, b);
        } else {
            printf("Ordem decrescente: %i > %i > %i", c, b, a);
        }
    }

    printf("\n");


    return 0;
}

//Fazer com uma variável auxiliar e precisa haver apenas 1 print
