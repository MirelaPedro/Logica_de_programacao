#include <stdio.h>

int main(){
    int response;

    do{
        printf("1. Listar\n");
        printf("2. Inserir\n");
        printf("3. Consultar\n");
        printf("4. Sair\n");
        
        printf("Opção: ");
        scanf("%i", &response);

    } while(response != 4);

    return 0;
}