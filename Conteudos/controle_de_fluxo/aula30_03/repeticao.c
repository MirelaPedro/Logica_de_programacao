#include <stdio.h>


int main(){

    //Laço de repetição infinito
    /*while(1){ //Se colocar 0 nunca será executado, pois é sempre falso
        printf("Estou no while!\n");
    }*/
    //qualquer coisa diferente de 0 é verdadeiro, mesmo que seja -1 ou 5

    char response = 's';

    while (response == 's'){
        printf("Oiii \n Estou no while!!\n");

        printf("Digite s para continuar:");
        scanf("%c", &response); // response = getchar() -> NÃO utlizar por ser uma função insegura
        getchar(); //se não colocar o enter vai e s + enter != de s //buffer do teclado = uma memória extremamente volátil
    }

    return 0;
}

/*
LAÇOS DE REPETIÇÃO
 -> teste no inicio           -> while(){}
 -> teste no fim              -> do{} while()
 -> com variáveis de controle -> for(){}
*/

