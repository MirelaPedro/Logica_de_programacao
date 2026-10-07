#include <stdio.h>

int main(){
    char response = 'n';

    do{
        printf("Oieeee!!! \nHellooooo World!!!\n");

        printf("Digite s se deseja continuar: ");
        scanf("%c", &response);
        getchar();

    } while(response == 's'); //condição

    return 0;
}