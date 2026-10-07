//Só se pode fazer switch de um nº inteiro ou de um char
#include <stdio.h>

int main(){

    int menu, a, b, operation;
    
    //MENU
    printf("MENU \n\n1 - Somar dois números inteiros \n");
    printf("2 - Subtrair dois números inteiros \n");
    printf("3 - Multiplicar dois números inteiros \n");
    printf("4 - Dividir dois números inteiros \n\nOpção: ");
    scanf("%i", &menu);

    switch(menu){

        //ADIÇÃO
        case 1:
            printf("OPÇÃO 1\n\n");

            printf("Digite o 1° nº: ");
            scanf("%i", &a);

            printf("Digite o 2° nº: ");
            scanf("%i", &b);

            operation = a + b;

            printf("Resultado da operação: %i", operation);
            break;

        //SUBTRAÇÃO
        case 2:
            printf("OPÇÃO 2\n\n");
            
            printf("Digite o 1° nº: ");
            scanf("%i", &a);

            printf("Digite o 2° nº: ");
            scanf("%i", &b);

            operation = a - b;

            printf("Resultado da operação: %i", operation);
            break;

        //MULTIPLICAÇÃO
        case 3:
            printf("OPÇÃO 3\n\n");
            
            printf("Digite o 1° nº: ");
            scanf("%i", &a);

            printf("Digite o 2° nº: ");
            scanf("%i", &b);

            operation = a * b;

            printf("Resultado da operação: %i", operation);
            break;

        //DIVISÃO
        case 4:
            printf("OPÇÃO 4\n\n");
            
            printf("Digite o numerador: ");
            scanf("%i", &a);

            printf("Digite o denominador: ");
            scanf("%i", &b);

            //Verificando se o denominador não é nulo
            if(b == 0){
                printf("O denomidanor não pode ser 0");
                break;
            }

            operation = a / b;

            //no print é dito ao usuário que apenas a parte inteira será recebida
            printf("Resultado aproximado da operação (apenas a parte inteira): %i", operation);
            break;

        default:
            printf("Opção inválida!!");
    }

    printf("\n\n");

    return 0;
}


//Seleção de múlplica escolha
//O switch realiza todos os comandos abaixo do case true encontrado
