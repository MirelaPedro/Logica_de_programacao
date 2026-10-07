//Elabore um algoritimo que, dada a idade de um nadador, classifique-o em uma das seguintes categorias:
/*
    IDADE               CATEGORIA
    5 até 7 anos        Infantil A
    8 até 10 anos       Infantil B
    11 até 13 anos      Juvenil A
    14 até 17 anos      Juvenil B
    Maior de 18 anos    Adulto
*/

#include <stdio.h>

int main(){
    int idade;

    printf("Digite a idade do nadador: ");
    scanf("%i", &idade);

    
    if(idade < 5){
        printf("Não há uma categoria listada para tal idade!");
    }

    if(idade >= 5 && idade < 8){
        printf("Categoria: Infantil A");
    }

    if(idade >= 8 && idade < 11){
        printf("Categoria: Infantil B");
    }

    if(idade >= 11 && idade < 14){
        printf("Categoria: Juvenil A");
    }

    if(idade >= 14 && idade < 18){
        printf("Categoria: Juvenil B");
    }

    if(idade >= 18){
        printf("Categoria: Adulto");
    }

    printf("\n");
    
    return 0;
}

